#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <iostream>
#include <math.h>
#include "serial/serial.h"
#include <axon_link/Taobot.h>
#include <Eigen/Dense>
#include <cmath>
using Eigen::MatrixXd;
using namespace std;




#define PI           3.14159265358979323846
#define RTD          180.0/PI       //Radian to Degree
#define DTR          PI/180.0       //Degree to Radian
#define TS 0.1                      //unit:s

// for SERIAL communication
#define TIMEOUT 1000
#define port "/dev/ttyUSB0"
#define baud 115200

void format(uint8_t* reply, int N);
void usart_send(char* toSend);
void sendCommand(uint8_t* arrayToSend, int length);
serial::Serial device(port, baud, serial::Timeout::simpleTimeout(1000));
ros::Publisher taobot_pub;
ros::Subscriber cmd_vel_sub_;

int count_average = 0;
double total_difference = 0;
// char reply[9];




void callback1(const ros::TimerEvent&)
{
    ROS_INFO("did not reac here?");
    uint8_t reply[44];
    uint8_t temp;
    try{ 

        device.read(reply, 44);
        ROS_INFO("Successful Read without Write!");
        format(reply, 43);
    // for (int i =0; i < 43; i ++){
    // //ROS_INFO("%c", reply[i]);}
    // temp=reply[i];
    // printf("0x%d%d\n", temp/16, temp % 16);

    // }
    }

    catch(exception& e)
    {
        ROS_FATAL("Failed to read the AXON serial port!!!");
        ROS_BREAK();
    }
}


void usart_send(uint8_t* toSend) 
	{
		size_t N;
        N = device.write(toSend, 1);
        
        //below is just testing purposes
		unsigned char temp, temp2;
        
		temp = toSend[0];
        temp2 = toSend[1];
		ROS_INFO("%d %d %d %d this is tosend updated", temp/16,temp%16, temp, N);
	}

//format the reply so that it becomes nice. checks if the data is formatted properly. throws away the last set of 
    //data for now
    //TODO: can we check if the last set of data can be read?, actually i think it works for now!
void format(uint8_t* reply, int N){
    int count = 0;
    axon_link::Taobot msg;

    for (int i = 0; i < N; i ++)
        if(reply[i] == 0xff && reply[i+11] == 0xff && reply[i+1] ==0xfe && reply[i+12] == 0xfe){
            ROS_INFO("%d set of data, i is %d", count + 1, i);
            count = count + 1;
            //assigning message here and publishing it here probably
            msg.motorA_encoder = reply[i+2];
            msg.motorA_dir     = reply[i+3];
            msg.motorB_encoder = reply[i+4];
            msg.motorB_dir     = reply[i+5];
            msg.motorC_encoder = reply[i+6];
            msg.motorC_dir     = reply[i+7];
            msg.voltage        = reply[i+10];
            taobot_pub.publish(msg);
        //print every set of correct messages
        for (int j = 0; j < 11; j ++){
            printf("0x%d%d\n", reply[i+j]/16, reply[i+j] % 16);
        }
        }

}
//send in an array of bytes and it will send for you;
void sendCommand(uint8_t* arrayToSend, int length){
    uint8_t toSend[1];
    for (int i = 0; i < length; i ++){
        toSend[0] = arrayToSend[i];
        usart_send(toSend);
        ROS_INFO("sending from here! %d %d", toSend[0]/16, toSend[0]%16);
    }
}

uint8_t* changeToOmniSpeed(double verticalPress, double horizontalPress, double angle){
    ROS_INFO("broke here");
    uint8_t* toSend;
    double radius, lengthToCenter, paramA, paramB;
    double motorA_speed, motorB_speed, motorC_speed, max;
    int count;

    radius = 5;
    paramA = 1/sqrt(3);
    paramB = 1/sqrt(9);
    lengthToCenter = 26.3;
    MatrixXd m(3,3);
    MatrixXd input(3,1);
    MatrixXd output(3,1);

    m(0,0) =  0;
  
    m(0,1) = -paramA*radius;
    m(0,2) = paramA*radius;
    m(1,0) = -2*paramB*radius;
    m(1,1) = paramB*radius;
    m(1,2) = paramB*radius; 
    m(2,0) = radius*paramB/lengthToCenter;
    m(2,1) = radius*paramB/lengthToCenter;
    m(2,2) = radius*paramB/lengthToCenter;
    input(0,0) = verticalPress;
    input(1,0) = horizontalPress;
    input(2,0) = angle;
    max = 0;
    output = m.inverse() * input;

    //find otu whats the max speed so i can normalize it
    for (int i = 0; i < 2; i++){
        if (std::abs(output(i,0)) > max){
            max = std::abs(output(i,0));
        }
    }
    count = 0;

    motorA_speed = output(0,0);
    motorB_speed = output(1,0);
    motorC_speed = output(2,0);

    //figure out the direction for each of the motor
    if (motorA_speed < 0) {count = count + 4;}
    if (motorB_speed < 0) {count = count + 2;}
    if (motorC_speed < 0) {count = count + 1;}

    //normalize the speed
    motorA_speed = std::abs(motorA_speed)/max;
    motorB_speed = std::abs(motorB_speed)/max;
    motorC_speed = std::abs(motorC_speed)/max;
    

    toSend[0] = 0xff;
    toSend[1] = 0xfe;
    toSend[2] = 2;
    toSend[3] = 0;
    toSend[4] = motorA_speed * 0xf;
    toSend[5] = 0;
    toSend[6] = motorB_speed * 0xf;

    toSend[7] = 0;
    
    toSend[8] = motorC_speed * 0xf; 

    toSend[9] = count;
    ROS_INFO("broke here2");
    return toSend;
}

void cmdVelReceived(const geometry_msgs::Twist::ConstPtr& cmd_vel){
    geometry_msgs::Twist wlr_cmd;
    double v_cmd = cmd_vel->linear.x * -1 ;
    double   w_cmd = cmd_vel->angular.z;
    uint8_t* arrayToSend;
    arrayToSend = changeToOmniSpeed(v_cmd, w_cmd, 0);
    sendCommand(arrayToSend, 10);
}

int main(int argc, char** argv)
{

    ros::init(argc, argv, "Taobot_Info");
    ros::NodeHandle n;

    //this channel publishes news recieved from the robot
    taobot_pub = n.advertise<axon_link::Taobot>("taobot_listener", 1000);

    //this channel is to subscribe to velocity commands from the joystick
    cmd_vel_sub_  = n.subscribe<geometry_msgs::Twist>("taobot_cmd_vel", 1000, cmdVelReceived);

    

    ros::Rate loop_rate(5);
    while (ros::ok()){
	uint8_t reply[44];
	uint8_t sendArray[10];


    int i;

	uint8_t temp;
    std::string serial_port;
    uint8_t firstByte[2], secondByte[1], thirdByte[1], fourthByte[1], fifthByte[1];
    uint8_t sixthByte[1], seventhByte[1], eigthByte[1], ninthByte[1], tenthByte[1];


    ROS_INFO("I get SerialPort: %s", port);

 
    ROS_INFO("I get BaudRate: %d", baud);

  

    // Change the next line according to your port name and baud rate
    if(device.isOpen()){
        ROS_INFO("serial is successful");
    }


    ROS_INFO("The AXON serial port is opened.");
    char send_speed1[] = { '0xFF', '0xFE', '2', '0', '72', '0', '0', '0', '44', '0x07', '\0'};

    ros::Rate r(10);

//this is for all the wheels to turn with a same speed. rotation ont he spot.
    firstByte[0] = 0xFF;
    secondByte[0] = 0xFE;
    thirdByte[0] = 2;
    fourthByte[0] = 0;
    fifthByte[0] = 0x00;
    sixthByte[0] = 0;
    seventhByte[0] = 0x00;
    eigthByte[0] = 0;
    ninthByte[0] = 0x00;
    tenthByte[0] = 0x07;

	usart_send(firstByte);
    usart_send(secondByte);
    usart_send(thirdByte);
    usart_send(fourthByte);
    usart_send(fifthByte);
    usart_send(sixthByte);
    usart_send(seventhByte);
    usart_send(eigthByte);
    usart_send(ninthByte);
    usart_send(tenthByte);

    sendArray[0] = 0xFF;
    sendArray[1] = 0xFE;
    sendArray[2] = 2;
    sendArray[3] = 0;
    sendArray[4] = 0x00;
    sendArray[5] = 0;
    sendArray[6] = 0x00;
    sendArray[7] = 0;
    sendArray[8] = 0x00;
    sendArray[9] = 0x07;
	
    sendCommand(sendArray, 10);

	try{ device.read(reply, 44);
    format(reply, 43);
	ROS_INFO("Successful Read without Write!");
    ROS_INFO("reached here");

	}

	catch(exception& e)
    {
        ROS_FATAL("Failed to read the AXON serial port!!!");
        ROS_BREAK();
    }
	ROS_INFO("reached here too");
    //comment out this first so i dont keep finding reply
    //ros::Timer timer1 = n.createTimer(ros::Duration(0.1), callback1);           //keep calling 1 and 3
    //ros::Timer timer2 = n.createTimer(ros::Duration(1.0), callback2);
    ROS_INFO("reached here 1");
    ros::spin();
    }
    
}