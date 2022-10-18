/**
 * @file main.cpp
 * @author Madhu Narra Chittibabu (madhunc117@gmail.com)
 * @navigator Sharmitha Ganesan (sharmithaganesan08@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-10-06
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include "../include/yoloDetect.h"

/**
 * @brief starting point for the program
 *
 * @return int
 */
int main() {

  std::vector<std::string> class_list;
  class_list.push_back("person");

  Mat frame;
  // read the test image
  frame = cv::imread("../data/test_image.jpg");
  Net net;
  YoloDetect yolo;

  // load the network
  net = cv::dnn::readNet("../yolov5s/yolov5s.onnx");

  Mat blob;
  // Pre-Process the image.
  blob = yolo.preProcess(frame);

  std::vector<Mat> detections;

  // get detections
  detections = yolo.detectHuman(blob, net);

  Mat frame_copy = frame.clone();

  int count = yolo.process(frame_copy, detections, class_list);

  std::cout << "Number of Humans : " << count << "\n";

}
