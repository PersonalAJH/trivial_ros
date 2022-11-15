#include "listener.h"



Listener::Listener(){
    sub = n.subscribe("camera/image", 10, &Listener::exCallBack, this);
}

Listener::~Listener(){

}


void Listener::exCallBack(const std_msg::IMagePtr &msg){

}

void Listener::exCallBack(const geometry_msgs::Twist::ConstPtr& msg);{
    
}


