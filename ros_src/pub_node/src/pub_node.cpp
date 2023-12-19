#include "pub_node.h"

PublisherNode::PublisherNode()
{
  pub_ = nh_.advertise<std_msgs::String>("pub_node", 1000);
}

void PublisherNode::run()
{
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    publishMessage();
    ros::spinOnce();
    loop_rate.sleep();
  }
}

void PublisherNode::publishMessage()
{
  std_msgs::String msg;
  msg.data = "Hello ROS!";
  pub_.publish(msg);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pub_node");
  
  PublisherNode pub;
  pub.run();

  return 0;
}
