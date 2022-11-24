#include <ros/ros.h>
#include <std_msgs/String.h>

#include "stdafx.h"

#include "ChildNode.h"
#include "ROSMessage.hpp"
#include "include/pub_node.h"

using namespace std;


class Param_class{
	public:
		int Param_class::getVersion(){
			return getParam("~version", 0)
		}

		int Param_class::getParam1(){
			return getParam("~param1", 0)
		}
}


ChildNode::ChildNode(ROSMessage *m, int param_v)
	: BasicNode(m, bool param1, int version)
{
	mbox_ = m;
}

void ChildNode::loop()
{
	publish_hub();
}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "pub_node");
	ros::NodeHandle nh("~");
	ros::Time::init();
	ros::Rate loop_rate(10); //100ms
	Param_class param_;

	if(param_.getVersion() == 0) {
		ChildNode node( new ROSMessageBox(nh), param, 0 );

		while (ros::ok()) {
			node.loop();
			ros::spinOnce();
			loop_rate.sleep();
		}
	}

	return 0;
}

