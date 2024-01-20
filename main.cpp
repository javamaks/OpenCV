#include <opencv2/opencv.hpp>

int main() {
    
    cv::VideoCapture cap(0); 

    
    if (!cap.isOpened()) {
        std::cout << "������ �������� ������" << std::endl;
        return -1;
    }

   
    cv::namedWindow("Camera", cv::WINDOW_NORMAL);

    while (true) {
        cv::Mat frame;
        
        cap >> frame;

        
        if (frame.empty()) {
            std::cout << "������ ����" << std::endl;
            break;
        }

        
        cv::imshow("Camera", frame);

        
        char key = cv::waitKey(1);
        if (key == 27)
            break;
    }

    
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
