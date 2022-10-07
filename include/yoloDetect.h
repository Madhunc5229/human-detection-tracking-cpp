#ifndef INCLUDE_YOLO_DETECT_H_
#define INCLUDE_YOLO_DETECT_H_

#include <vector>
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
        vector<Mat> detectHuman(vector<Mat> frame);

        std::vector<Mat> input_frame;
        

    private:
        /**
         * @brief this method preprocess the input frame such as resize, etc.
         * 
         * @return vector<Mat> preprocessed frame for human detection
         */
        vector<Mat> preProcess();
}



#endif // INCLUDE_YOLO_DETECT_H_
