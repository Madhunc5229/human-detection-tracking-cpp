#ifndef INCLUDE_PIXEL_TO_WORLD_H_
#define INCLUDE_PIXEL_TO_WORLD_H_

#include <vector>
#include <opencv2/opencv.hpp>
using cv::Mat;


class PixelToWorld{
    public:
        
        PixelToWorld();
        
        std::vector<int> pixelValues;
        

    private:
        /**
         * @brief computes the projection matrix to compute XYZ
         * 
         * @return vector<Mat> return the projection matrix
         */
        std::vector<Mat> transformationMat();

        /**
         * @brief calculate the world co-ordinates
         * 
         * @param tramsformaMatrix projection matrix
         * @return vector<Mat> XYZ co-ordinates
         */
        std::vector<Mat> worldPoints(std::vector<Mat> tramsformaMatrix);
        
        double focalLength;
};



#endif // INCLUDE_PIXEL_TO_WORLD_H_
