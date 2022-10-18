#ifndef INCLUDE_IDENTIFIER_H_
#define INCLUDE_IDENTIFIER_H_

#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

using cv::Mat;
using cv::dnn::Net;

/**
 * @brief this class helps in identifying humans in a given frame
 * 
 */
class Identifier{
    public:
        /**
         * @brief Construct a new Identifier object
         * 
         */
        Identifier();

        /**
         * @brief this function extracts the details for drawing a bounding box
         * 
         */
        void unwrapPrediction();

        /**
         * @brief this method draws the identifier on the frame
         * 
         * @return std::vector<Mat> the modified frame
         */
        int drawIdentifier(Mat &input_image, std::vector<Mat> &outputs, std::vector<std::string> &class_name);
        
        std::vector<Mat> predicted_out;
        const float CONFIDENCE_THRESHOLD = 0.45;
        const float SCORE_THRESHOLD = 0.5;

    private:
        std::vector<int> class_ids;
        std::vector<double> class_confidence;
        std::vector<cv::Rect> bounding_box;
};


#endif // INCLUDE_IDENTIFIER_H_
