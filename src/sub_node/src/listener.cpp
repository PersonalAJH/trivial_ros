#include "listener.h"



Listener::Listener(){
    image_sub = n.subscribe("camera/image", 10, &Listener::exCallBack, this);
    imu_sub = n.subscribe("/imu", 10, &Listener::imu_CallBack, this);
}

Listener::~Listener(){

}


void Listener::exCallBack(const std_msg::IMagePtr &msg){

}

void Listener::imu_CallBack(const geometry_msgs::Twist::ConstPtr& msg);{
    
}


