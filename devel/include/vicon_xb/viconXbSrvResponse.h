// Generated by gencpp from file vicon_xb/viconXbSrvResponse.msg
// DO NOT EDIT!


#ifndef VICON_XB_MESSAGE_VICONXBSRVRESPONSE_H
#define VICON_XB_MESSAGE_VICONXBSRVRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace vicon_xb
{
template <class ContainerAllocator>
struct viconXbSrvResponse_
{
  typedef viconXbSrvResponse_<ContainerAllocator> Type;

  viconXbSrvResponse_()
    : result(0)  {
    }
  viconXbSrvResponse_(const ContainerAllocator& _alloc)
    : result(0)  {
  (void)_alloc;
    }



   typedef uint8_t _result_type;
  _result_type result;





  typedef boost::shared_ptr< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct viconXbSrvResponse_

typedef ::vicon_xb::viconXbSrvResponse_<std::allocator<void> > viconXbSrvResponse;

typedef boost::shared_ptr< ::vicon_xb::viconXbSrvResponse > viconXbSrvResponsePtr;
typedef boost::shared_ptr< ::vicon_xb::viconXbSrvResponse const> viconXbSrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace vicon_xb

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'vicon_xb': ['/home/eee/lingfei_ws/agv/src/vicon_xb/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "25458147911545c320c4c0a299eff763";
  }

  static const char* value(const ::vicon_xb::viconXbSrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x25458147911545c3ULL;
  static const uint64_t static_value2 = 0x20c4c0a299eff763ULL;
};

template<class ContainerAllocator>
struct DataType< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "vicon_xb/viconXbSrvResponse";
  }

  static const char* value(const ::vicon_xb::viconXbSrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 result\n\
\n\
";
  }

  static const char* value(const ::vicon_xb::viconXbSrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.result);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct viconXbSrvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::vicon_xb::viconXbSrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::vicon_xb::viconXbSrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "result: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.result);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VICON_XB_MESSAGE_VICONXBSRVRESPONSE_H
