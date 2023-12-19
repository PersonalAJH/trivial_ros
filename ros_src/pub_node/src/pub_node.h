#include "ros/ros.h"
#include "std_msgs/String.h"

class PublisherNode
{
public:
  PublisherNode();
  void run();

private:
  ros::NodeHandle nh_;
  ros::Publisher pub_;
  void publish_Message_1();
};

