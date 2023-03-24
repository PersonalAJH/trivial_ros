#include <ros/ros.h>
// #include <json/json.h>
#include <iostream>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>

using namespace cv;
class CameraNode
{
public:
    CameraNode();
    int run();

private:
    cv::VideoCapture cap;
    int test;
    Mat img;
};

