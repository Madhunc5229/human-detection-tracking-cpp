/**
 * @file identifier.h
 * @author Madhu Narra Chittibabu (madhunc117@gmail.com)
 * @navigator Sharmitha Ganesan (sharmithaganesan08@gmail.com)
 * @brief declaration of identifier class 
 * @version 0.1
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef INCLUDE_IDENTIFIER_H_
#define INCLUDE_IDENTIFIER_H_

#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

using cv::Mat;
using cv::dnn::Net;

/**
 * @brief this class helps in identifying humans in a given frame
 * 
 */
class Identifier {
 public:
        /**
         * @brief Construct a new Identifier object
         * 
         */

        Identifier() {}
        /**
         * @brief this method draws the identifier on the frame
         * 
         * @return std::vector<Mat> the modified frame
         */
        void drawIdentifier(const cv::Mat &input_image,std::vector<Mat> &predictions, std::vector<std::string> &class_name);  // NOLINT
        std::vector<Mat> predicted_out;
        const float CONFIDENCE_THRESHOLD = 0.45;
        const float SCORE_THRESHOLD = 0.25;
        const float NMS_THRESHOLD = 0.1;

 private:
        std::vector<int> class_ids;
        std::vector<double> class_confidence;
        std::vector<cv::Rect> bounding_box;
        static std::vector<int> input_size;
};
#endif  // INCLUDE_IDENTIFIER_H_
