/**
 * @file pixelToWorld.h
 * @author Madhu Narra Chittibabu (madhunc117@gmail.com) (driver @ phase 1)
 *         Sharmitha Ganesan (sharmithaganesan08@gmail.com) (driver @ phase 2)
 * @brief Declaration of pixelToWorld class
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef INCLUDE_PIXELTOWORLD_H_
#define INCLUDE_PIXELTOWORLD_H_
#include <Eigen/Dense>
#include <vector>
#include <opencv2/opencv.hpp>


using Eigen::MatrixXf;

using cv::Mat;

/**
 * @brief This class converts the pixel cordinates from camera to robot's frame
 * of reference
 *
 */
class PixelToWorld {
 public:
  PixelToWorld() {}
  std::vector<double> pixelValues;
  /**
   * @brief computes the projection matrix to compute XYZ
   *
   * @return vector<Mat> return the projection matrix
   */
  MatrixXf transformationMat();

  /**
   * @brief calculate the world co-ordinates
   *
   * @param tramsformaMatrix projection matrix
   * @return vector<Mat> XYZ co-ordinates
   */
  std::vector<double> worldPoints(MatrixXf T, std::vector<double> pixelValues);

 private:
  static double focalLength;
};
#endif  // INCLUDE_PIXELTOWORLD_H_
