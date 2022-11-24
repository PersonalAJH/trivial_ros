#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <jh_msgs/HeaderedString.h>
#include <std_msgs/String.h>
`
using namespace std;

class Message_CallBack{
    list<string> test_msg;

    void callback(const std_msgs::String::ConstPtr& msg){
        test_msg.push_back(msg->data);
    }

	bool Message_input(string &msg) {
		if(test_msg.empty() == true) {
			return false;
		}
		msg = test_msg.front();
    	test_msg.pop_front();
		return true;
	}
}


class ROSMessage{
public:
    //node handler
	ros::NodeHandle &nh; 
​
	// Publish
	ros::Publisher imuPub;
	ros::Publisher statusPub;
​

	Message_CallBack 				cmdCB;

	sensor_msgs::Imu 			imuMsg;
​
	ROSMessage(ros::NodeHandle &n):nh(n) {
		imuMsg.linear_acceleration_covariance = 0.0f;
​
		//Orientation - all these values must be float
		imuMsg.orientation.x = 0;
		imuMsg.orientation.y = 0;
		imuMsg.orientation.z = 0;
		imuMsg.orientation.w = 1;

		imuPub			= nh.advertise<sensor_msgs::Imu>(NSFinder::getNamespace("/imu"), 1);
		statusPub		= nh.advertise<torooc_msgs::HeaderedString>(NSFinder::getNamespace("/status"), 1);
	}


	void publishStatus(bool status1, bool status2) {
​
		jh_msgs::HeaderedString msg;    // or std_msgs::String str; -> time stamp 제거 및 string으로 publish
		Json::Value value;
​
		bool st1, st2;
		st1 = true;
		st2 = false;

		value["robot_status1"] = st1;
		value["robot_status2"]	 = st2;

		Json::StreamWriterBuilder builder;
		msg.header.stamp = ros::Time::now();
		msg.data = Json::writeString(builder, value);
		statusPub.publish(msg);
	}
​
	void publishImuStatus(float roll, float pitch, float yaw) {
		imuMsg.header.stamp= ros::Time::now();
		imuMsg.linear_acceleration.x = 0;
		imuMsg.linear_acceleration.y = 0;
		imuMsg.linear_acceleration.z = 0;
​
		//update IMU sensor data before publishImuStatus function
		imuMsg.angular_velocity.x = roll;
		imuMsg.angular_velocity.y = pitch;
		imuMsg.angular_velocity.z = 0;
​
		imuMsg.orientation.x = 0;
		imuMsg.orientation.y = 0;
		imuMsg.orientation.z = 0;
		imuMsg.orientation.w = 0;
​
		imuPub.publish(imuMsg);
	}

};
