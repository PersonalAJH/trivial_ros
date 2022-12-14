#ifndef PUB_NODE_H
#define PUB_NODE_H

// ROS includes.
#include <ros/ros.h>
#include <ros/time.h>


namespace jh_example
{
class RobotNode
{
 public:

  explicit RobotNode(ros::NodeHandle nh);

 private:
  void timerCallback(const ros::TimerEvent &event);

  void start();
  void stop();
  bool enable_;

  ros::NodeHandle nh_;
  ros::Timer timer_;
  ros::Publisher pub_;

};
}

#endif 
