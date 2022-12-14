/**
 * @file identifier.h
 * @author Madhu Narra Chittibabu (madhunc117@gmail.com) (driver @ phase 1)
 *         Sharmitha Ganesan (sharmithaganesan08@gmail.com) (driver @ phase 2)
 * @brief declaration of identifier class
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef INCLUDE_IDENTIFIER_H_
#define INCLUDE_IDENTIFIER_H_

#include <string>
#include <vector>
#include <opencv2/dnn.hpp>
#include <opencv2/opencv.hpp>


using cv::Mat;

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
  std::vector<double> drawIdentifier(
      const cv::Mat &input_image, const std::vector<Mat> &predictions,
      std::vector<std::string> &class_name);  // NOLINT
  std::vector<Mat> predicted_out;
  const float CONFIDENCE_THRESHOLD = 0.35;
  const float SCORE_THRESHOLD = 0.2;
  const float NMS_THRESHOLD = 0.2;

 private:
  static std::vector<float> input_size;
};
#endif  // INCLUDE_IDENTIFIER_H_
