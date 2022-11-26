#include <listener.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sub_node");
  ros::NodeHandle nh;

  Listner::Listner node(nh);

  ros::spin();

  return 0;
}
