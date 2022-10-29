/**
 * @file yoloDetect.cpp
 * @author Madhu Narra Chittibabu (madhunc117@gmail.com) (driver @ phase 1)
 *         Sharmitha Ganesan (sharmithaganesan08@gmail.com) (driver @ phase 2)
 * @brief Implementation of yoloDetect class
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/yoloDetect.h"

using std::vector;

std::vector<int> YoloDetect::input_size = {640, 640};
/**
 * @brief Converts input frame into blob
 *
 * @param input_frame
 * @return Mat
 */
Mat YoloDetect::preProcess(cv::Mat &input_frame) {
  // Convert to blob.
  Mat blob;
  // convert input frame to blob
  cv::dnn::blobFromImage(input_frame, blob, 1. / 255.,
                         cv::Size(input_size.at(0), input_size.at(1)),
                         cv::Scalar(), true, false);
  return blob;
}
/**
 * @brief returns the predicted weights
 *
 * @param blob
 * @param net
 * @return std::vector<Mat>
 */
std::vector<Mat> YoloDetect::detect(Mat blob, Net &net) {
  net.setInput(blob);
  std::vector<Mat> predictions;
  // Run the forward pass to get predicted weights of the output layers.
  net.forward(predictions, net.getUnconnectedOutLayersNames());
  return predictions;
}
