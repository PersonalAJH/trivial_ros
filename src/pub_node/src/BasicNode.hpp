#pragma once
#include <json/json.h>
#include <iostream>
#include <ros/ros.h>
#include <map>
#include "../ROSMessage.hpp"


using namespace std;

class BasicNode {
public:
    BasicNode(ROSMessage *m, bool param1, int version)
    {
        mbox_ = m;
        param1_ = param1;
        version_ = version;
    }

    Vector3f imu_update(){
        Vector3f result;
        // if update imu code exist 
        // code here..

        return result;
    }

    bool get_status1(){
        // if update status code exist
        // code here..
        return true;
    }

    bool get_status2(){
        // if update status code exist
        // code here..
        return false;
    }


    void publish_hub()
    {
        // update imu
        Vector3f tmp;
        tmp = imu_update();
        // Publish IMU
        mbox_->publishImuStatus(tmp(0), tmp(1), tmp(2));

    
        //Get Status
        bool tmp_st1, tmp_st2;
        tmp_st1 = get_status1();
        tmp_st2 = get_status2();
        mbox_->publishStatus(tmp_st1,tmp_st2);
    }

protected:
	ROSMessage			*mbox_;
    bool                param1_;
    int                 version_;
};
