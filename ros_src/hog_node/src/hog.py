#!/usr/bin/env python

import rospy
import pyrealsense2 as rs
import numpy as np
import cv2
from sensor_msgs.msg import Image
from geometry_msgs.msg import Point
from cv_bridge import CvBridge

def detect_human_hog(cv_image):
    # HOG 디텍터 생성 및 SVM 학습 모델 로딩
    hog = cv2.HOGDescriptor()
    hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())

    # 이미지에서 사람 검출
    (rects, weights) = hog.detectMultiScale(cv_image, winStride=(4, 4), padding=(8, 8), scale=1.05)

    # 최고 신뢰도를 가진 사각형의 인덱스를 찾음
    if len(rects) > 0 and len(weights) > 0:
        highest_confidence_index = weights.argmax()
        x, y, w, h = rects[highest_confidence_index]
        cv2.rectangle(cv_image, (x, y), (x + w, y + h), (0, 255, 0), 2)
        
        # 사람의 중심 좌표 계산
        height, width = cv_image.shape[:2]
        cx = x + w / 2 - width / 2
        cy = y + h / 2 - height / 2

        return Point(x=cx, y=cy, z=0)

    return None

def run(pipeline, human_pub, rate):
    while not rospy.is_shutdown():
        frames = pipeline.wait_for_frames()
        color_frame = frames.get_color_frame()
        if not color_frame:
            continue

        # OpenCV 이미지로 변환
        cv_image = np.asanyarray(color_frame.get_data())

        # 사람 감지 및 결과 발행
        coord_msg = detect_human_hog(cv_image)
        if coord_msg is not None:
            human_pub.publish(coord_msg)

        rate.sleep()

if __name__ == "__main__":
    # Realsense 카메라 설정
    pipeline = rs.pipeline()
    config = rs.config()
    config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
    pipeline.start(config)

    # ROS 초기화 및 퍼블리셔 설정
    rospy.init_node('hog_node', anonymous=False)
    human_pub = rospy.Publisher('human_coordinates', Point, queue_size=10)
    
    rate = rospy.Rate(10)  # 10Hz

    run(pipeline, human_pub, rate)



# image 파일을 subscribe 로 받을 때 

# #!/usr/bin/env python

# import rospy
# from sensor_msgs.msg import Image
# from geometry_msgs.msg import Point
# from cv_bridge import CvBridge
# import cv2

# #!/usr/bin/env python
# import pyrealsense2 as rs


# def detect_human_hog(cv_image):
#     # HOG 디텍터 생성 및 SVM 학습 모델 로딩
#     hog = cv2.HOGDescriptor()
#     hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())

#     # # 이미지에서 사람 검출
#     (rects, weights) = hog.detectMultiScale(cv_image, winStride=(4, 4), padding=(8, 8), scale=1.05)

#     # 최고 신뢰도를 가진 사각형의 인덱스를 찾음
#     highest_confidence_index = weights.argmax()

#     coord_msg = Point(x=0, y=0, z=0)
#     if len(rects) > 0:
#         # 최고 신뢰도를 가진 사각형만 사각형으로 표시
#         x, y, w, h = rects[highest_confidence_index]
#         cv2.rectangle(cv_image, (x, y), (x + w, y + h), (0, 255, 0), 2)
#         height, width = cv_image.shape[:2]


        
#         #박스의 센터점확인
#         cx = x + (w/2)
#         # 확인필요
#         # cy = y - (h/2)

#         cy = y + (h/2)



#         # 전체 images에서 절반을 0,0 이라고 했을 때 위치 확인
#         cx = cx - (width/2)
#         cy = cy - (height/2)

#         coord_msg = Point(x=cx, y=cy, z=0)

#     return coord_msg

# def image_callback(msg, human_pub):
#     try:
#         # ROS 메시지를 OpenCV 이미지로 변환
#         cv_image = bridge.imgmsg_to_cv2(msg, "bgr8")

#         # HOG 기반 사람 감지 수행
#         coord_msg = detect_human_hog(cv_image)

#         #publish coordinates
#         human_pub.publish(coord_msg)


#     except Exception as e:
#         rospy.logerr("Error while processing the image: {}".format(e))

# if __name__ == '__main__':
#     rospy.init_node('hog_node', anonymous=True)
#     human_pub = rospy.Publisher('human_coordinates', Point, queue_size=10)
#     bridge = CvBridge()

#     # 이미지를 받아올 토픽 설정
#     image_sub = rospy.Subscriber('image_topic', Image, image_callback, callback_args=human_pub)

#     rospy.spin()


