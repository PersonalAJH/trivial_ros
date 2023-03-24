#! /usr/bin/env python3

import time
import rospy
import cv2
import os
import torch
from geometry_msgs.msg import Twist

from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

if __name__=="__main__":
    cap = cv2.VideoCapture(0)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH,320)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT,240)

    model = torch.hub.load('ultralytics/yolov5', 'yolov5n') #web data에서 받아오는것 말고 저장된 데이터에서 받아오기->(load('./yolov5'))
        


    rospy.init_node('camera_node_py')
    bridge = CvBridge()

    pub = rospy.Publisher('cmd_vel', Twist, queue_size=10)
    rate = rospy.Rate(10)


    try:
        while not rospy.is_shutdown():
            ref,frame = cap.read()
            results = model(frame)


            if not ref:
                rospy.loginfo("Not Found Devices")
                break

            image_msg = bridge.cv2_to_imgmsg(frame,"bgr8")
            pub.publish(image_msg)
            rate.sleep()

    except KeyboardInterrupt:
        rospy.loginfo("Exiting Program")
    
    except Exception as exception_error:
        rospy.loginfo("Error occurred. Exiting Program")
        rospy.loginfo("Error: " + str(exception_error))
    
    finally:
        cap.release()
        pass


