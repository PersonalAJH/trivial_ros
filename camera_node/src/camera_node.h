#include <ros/ros.h>
#include <json/json.h>
#include <iostream>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>


class CameraNode
{
public:
    CameraNode();
    int run();

private:
    int test;
    Mat img;
};

