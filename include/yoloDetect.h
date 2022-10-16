#ifndef INCLUDE_YOLO_DETECT_H_
#define INCLUDE_YOLO_DETECT_H_

#include <vector>
// #include <opencv2/dnn.hpp>
#include <opencv2/opencv.hpp>
// #include <opencv2/imgproc.hpp>
// #include <opencv2/highgui.hpp>

using cv::Mat;

/**
 * @brief this class containds methods and attributes for human detection
 * 
 */
class YoloDetect{
    public:
        /**
         * @brief Construct a new Yolo Detect object
         * 
         */
        YoloDetect();
        
        /**
         * @brief this method will detect humans in the given frame
         * 
         * @param frame inout frame
         * @return vector<Mat> frame with humans detected
         */
        std::vector<Mat> detectHuman(std::vector<Mat> frame);

        std::vector<Mat> input_frame;
        

    private:
        /**
         * @brief this method preprocess the input frame such as resize, etc.
         * 
         * @return vector<Mat> preprocessed frame for human detection
         */
        std::vector<Mat> preProcess();
};



#endif // INCLUDE_YOLO_DETECT_H_
