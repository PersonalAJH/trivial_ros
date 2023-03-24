#include <../include/camera_node.h>

using namespace std;
using namespace cv;


CameraNode::CameraNode(){
   cap = cv::VideoCapture(0);
   cap.set(CV_CAP_PROP_FRAME_WIDTH, 1920);
   cap.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);
}

int CameraNode::run(){
   if (!cap.isOpened())
   {
      printf("camera closed \n");
      return -1;
   }

   cap >> img;
   imshow("camera imga", img);
   printf("test\n");
   return 0;
}



int main(int argc, char **argv){

   CameraNode camera_Node;
   ros::init(argc, argv, "camera_node_cpp");
   ros::NodeHandle nh;
   image_transport::ImageTransport it(nh);
   image_transport::Publisher pub = it.advertise("camera/image", 1);
   cv::Mat image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
   cv::waitKey(30);
   sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();


   ros::Time::init();
   ros::Rate loop_rate(25);


   while (ros::ok()) {
      camera_Node.run();
      pub.publish(msg);
      ros::spinOnce();
      loop_rate.sleep();
   }

}