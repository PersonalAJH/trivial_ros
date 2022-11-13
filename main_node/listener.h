#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <vector>
#include <string.h>
#include <iostream>



using namespace std;
sensor_msgs::Imu imu;

class Listner{
    private:
    ros::Publisher ex_pub;
    ros::Subscriber sub;
    ros::NodeHandle n;

    std::thread* thread_IMU;

    public:
    Listener();
    ~Listener();

    void exCallBack(const geometry_msgs::Twist::ConstPtr& msg);

    void loop();
}

