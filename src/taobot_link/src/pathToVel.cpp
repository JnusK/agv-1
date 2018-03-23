
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float32.h>
#include <iostream>
#include <math.h>
#include "serial/serial.h"
#include <taobot_link/Taobot.h>
#include <Eigen/Dense>
#include <nav_msgs/Path.h>
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


ros::Publisher move_base_path_pub;
ros::Subscriber move_base_path_sub;
void MovePathCallback(const nav_msgs::Path::ConstPtr& path_data);
double convertToEuclid(float x1, float y1, float x2, float y2);
void sendVelCommand(float x_start, float y_start, float x_end, float y_end);
uint8_t* changeToOmniSpeed(double verticalPress, double horizontalPress, double angle);
int count_average = 0;
double total_difference = 0;
// char reply[9];

double convertToEuclid(double x1, double y1, double x2, double y2){
    ROS_INFO("x1 is %f, y1 is %f, x2 is %f, y2 is %f",x1,y1,x2,y2);
    return sqrt(pow((x1 - x2),2) + pow((y1 - y2),2));
}

void movePathCallBack(const nav_msgs::Path::ConstPtr& path_data)
{
    int i;
    int len;
    int idx, flag, path_plan;
    //set the idealSpeed as a rando.
    double idealSpeed = 0.5;
    double eachTimeSlot;

    len = path_data->poses.size();
    ROS_INFO("break_1");
    double plan[4][len+101] = {{0}};
 ROS_INFO("break_2");
    double tsegc[len+100] = {0};

    double dis, dis2 = 0;
    double distanceToGoal;
    double timeForPath;
    double dsegc, dseg;

    // for (i = 0; i < len; i++){
    //      plan[0][i]=path_data->poses[i].pose.position.x;                 //x
    //      plan[1][i]=path_data->poses[i].pose.position.y;                 //y
    //      plan[2][i]=0;
    //      //plan[3][i]=Quat_to_Yaw(path_data->poses[i].pose.orientation);                    
    // }


 ROS_INFO("break_3");
        if (len>0){


        {
            distanceToGoal = convertToEuclid(path_data->poses[0].pose.position.x, path_data->poses[0].pose.position.y , 
                path_data->poses[len-2].pose.position.x, path_data->poses[len-2].pose.position.y);
	   ROS_INFO("distance to goal is %d", distanceToGoal);
            //dis2=DIS_XY(rc.x_c, rc.y_c, path_data->poses[len-1].pose.position.x, path_data->poses[len-1].pose.position.y); //last path point
            if (distanceToGoal >= 0 )
                path_plan = 1 ;
            else
                path_plan = 0 ;
        }

        if ( (len>0) && (path_plan==1) )
        {
            printf("START LOADING PATH, PLAN_SIZE=%d\n", len);
            for (i=0;i<len;i++)
            {
                plan[0][i]=path_data->poses[i].pose.position.x;                 //x
                plan[1][i]=path_data->poses[i].pose.position.y;                 //y
                plan[2][i]=0;    
                             		               //z
                //plan[3][i]=Quat_to_Yaw(path_data->poses[i].pose.orientation);   //angle(yaw)
                //printf("NUM=%d x=%+3.3f y=%+3.3f z=%+3.3f yaw=%+3.3f\n", i, plan[0][i],  q[1][i], plan[2][i], plan[3][i]);
            }
            for (i=len;i<len+100;i++)
            {
                plan[0][i]=path_data->poses[len-1].pose.position.x;                 //x
                plan[1][i]=path_data->poses[len-1].pose.position.y;                 //y
                plan[2][i]=0;                                                   //z
               // plan[3][i]=Quat_to_Yaw(path_data->poses[len-1].pose.orientation);   //angle(yaw)
                //printf("NUM=%d x=%+3.3f y=%+3.3f z=%+3.3f yaw=%+3.3f\n", i, plan[0][i], plan[1][i], plan[2][i], plan[3][i]);
            }

        }


            //making angle by path
            if (len>=2)
            {   
                timeForPath = distanceToGoal/idealSpeed;



                eachTimeSlot = timeForPath / len;

                ROS_INFO("Each time slot is %d, time for totalPath is %d,", eachTimeSlot, timeForPath);

                

               ;

                tsegc[0]=0.0;
                for (i=1; i < len; i++){
                    tsegc[i] = eachTimeSlot * i;
		 ROS_INFO("tsegc is %f",tsegc[i]);
                }
                

                dsegc=0.0;
                ros::Time current_time, start_time;
                ros::Duration time_elapsed;
                
                start_time = ros::Time::now();
                current_time = ros::Time::now();
                time_elapsed = current_time - start_time;
                for (i=0;i<len;i++)
                {
                    current_time = ros::Time::now();
                    time_elapsed = current_time - start_time;

                    dseg=convertToEuclid(plan[0][i],plan[1][i],plan[0][i-1],plan[1][i-1]);
                    dsegc=dsegc+dseg;

                    


                    while((time_elapsed.toSec()> tsegc[i] && time_elapsed.toSec() < tsegc[i+1])){

                    ROS_INFO("sending a vel command");
                    ROS_INFO("time elapsed is %f, tsegc[i] is %f, tsegc[i+1] is %f", time_elapsed, tsegc[i], tsegc[i+1]);

                    sendVelCommand(plan[0][i],plan[1][i],plan[0][i+1],plan[1][i+1]);
                    current_time = ros::Time::now();
                    time_elapsed = current_time - start_time;

                    }

                  

                }
                //DO ANGLE PLANNING skok LATER;
                //sendFinalAngleCommand(path_data->poses[len-1].pose.orientation);

            //     
            }

        }
            else printf("PLAN_SIZE ZERO\n");
    }



void sendVelCommand(float x_start, float y_start, float x_end, float y_end){
    geometry_msgs::Twist wlr_cmd;
    uint8_t reply[30];

    //NOT SURE WHY I NEED TO FLIP THIS
    wlr_cmd.linear.x         = x_end - x_start;
    wlr_cmd.linear.y        = y_end - y_start;
    wlr_cmd.angular.z = 0;

    move_base_path_pub.publish(wlr_cmd);
    //double directionToRotate = 0; 

}






int main(int argc, char** argv)
{

    ros::init(argc, argv, "Taobot_Info");
    ros::NodeHandle n;


    move_base_path_pub = n.advertise<geometry_msgs::Twist>("cmd_vel_path", 1000);
    
    move_base_path_sub  = n.subscribe<nav_msgs::Path>("/move_base_node/NavfnROS/plan", 1000, movePathCallBack);
    
  

    ros::Rate loop_rate(5);
    while (ros::ok()){

    ros::spin();
    }
    
    
    }