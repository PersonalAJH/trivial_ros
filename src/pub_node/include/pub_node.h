#include <json/json.h>
#include <iostream>
#include <ros/ros.h>
#include <map>
#include "message/messagebox.h"
#include "BasicNode.hpp"

using namespace std;

class ChildNode : public BasicNode {
public:
	ChildNode(ROSMessage *m, int param_v);
	void loop();

private:
	int test;
};

