import cv2
import numpy as np
import pyrealsense2 as rs

def main():
    # Realsense 카메라 초기화
    print("test \n")

    pipeline = rs.pipeline()
    print("test2 \n")

    config = rs.config()
    config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)

    # 카메라 시작
    pipeline.start(config)

    try:
        while True:
            # 프레임 가져오기
            frames = pipeline.wait_for_frames()
            color_frame = frames.get_color_frame()

            # 카메라에서 가져온 이미지를 numpy 배열로 변환
            if not color_frame:
                continue

            color_image = np.asanyarray(color_frame.get_data())

            # 이미지 표시
            cv2.imshow('Realsense Camera', color_image)

            # 'q' 키를 누르면 종료
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break

    finally:
        # 종료 시 리소스 해제
        pipeline.stop()
        cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
