#ifndef INCLUDE_IDENTIFIER_H_
#define INCLUDE_IDENTIFIER_H_

#include <vector>
using cv::Mat;
using cv::Rect;

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
        std::vector<Mat> drawIdentifier();

        std::vector<Mat> predicted_out;
        

    private:
        std::vector<int> class_ids;
        std::vector<double> class_confidence;
        std::vector<Rect> bounding_box;
}


#endif // INCLUDE_IDENTIFIER_H_
