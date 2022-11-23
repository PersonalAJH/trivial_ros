#include <jh_publisher.h>

int main(int argc, char **argv)
{

  ros::init(argc, argv, "pub_node");
  ros::NodeHandle nh;


  node_example::ExampleTalker node(nh);

  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
}  // end main()
