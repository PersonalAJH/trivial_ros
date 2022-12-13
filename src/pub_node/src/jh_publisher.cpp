#include <jh_publisher.h>

namespace robot_node
{
  RobotNode::RobotNode(ros::NodeHandle nh)
  {
    ros::NodeHandle pnh("~");
    pnh.param("robot_version", a_, a_);
    pnh.param("test_param", b_, b_);

    timer_ = nh_.createTimer(ros::Duration(1.0 / rate), &RobotNode::timerCallback, this);
  }

  void RobotNode::start()
  {
    pub_ = nh_.advertise<robot_node::NodeExampleData>("example", 10);
  }

  void RobotNode::stop()
  {
    pub_.shutdown();
  }

  void RobotNode::timerCallback(const ros::TimerEvent &event __attribute__((unused)))
  {
    if (!enable_)
    {
      return;
    }

    robot_node::RobotNode msg;
    msg.message = message_;
    msg.a = a_;
    msg.b = b_;

    pub_.publish(msg);
  }
}

