/**
 * @file yoloDetect.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef INCLUDE_YOLODETECT_H_
#define INCLUDE_YOLODETECT_H_

#include <vector>
#include <opencv2/dnn.hpp>
#include <opencv2/opencv.hpp>


using cv::Mat;
using cv::dnn::Net;

/**
 * @brief this class containds methods and attributes for human detection
 * 
 */
class YoloDetect{
 public:
        
        /**
         * @brief this function forwards the blob to the model and gets the detection
         * 
         * @param blob pre-processed image blob
         * @param net object of opencv Net class
         * @return std::vector<Mat> detections in the given frame
         */
        std::vector<Mat> detectHuman(Mat blob, Net &net);

        /**
         * @brief this function takes input image and converts it to input size blob
         * 
         * @param input_frame input from either files or camera feed
         * @return Mat image blob
         */
        Mat preProcess(Mat &input_frame);

        std::vector<Mat> input_frame;

 private:
        static std::vector<int> input_size;
};

#endif  // INCLUDE_YOLODETECT_H_
