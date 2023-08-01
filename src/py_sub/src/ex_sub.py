#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def publisher_node():
    # 노드 초기화
    rospy.init_node('py_sub', anonymous=True)

    # 메시지를 발행할 토픽 설정 (이 예제에서는 "simple_topic" 이라는 이름의 토픽)
    pub = rospy.Publisher('simple_topic', String, queue_size=10)

    rate = rospy.Rate(1)  # 발행 주기 설정 (1 Hz로 설정)

    while not rospy.is_shutdown():
        # 발행할 메시지 생성
        message = "Hello, ROS!"
        rospy.loginfo(message)

        # 메시지를 토픽에 발행
        pub.publish(message)

        rate.sleep()

if __name__ == '__main__':
    try:
        publisher_node()
    except rospy.ROSInterruptException:
        pass
