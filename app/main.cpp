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
#include "../include/identifier.h"
#include "../include/yoloDetect.h"
#include "../include/pixelToWorld.h"

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
  Identifier identify;
  PixelToWorld world;

  // load the network
  net = cv::dnn::readNetFromONNX("../yolov5s/yolov5s.onnx");

  Mat blob;
  // Pre-Process the image.
  blob = yolo.preProcess(frame);
  std::vector<Mat> predictions;

  // get detections
  predictions = yolo.detect(blob, net);
  std::vector<double> pixels =  identify.drawIdentifier(frame, predictions, class_list);
  std::cout << "Number of humans: " << pixels.size()/2.0<<"\n";
  MatrixXf TM(3,4);
  TM = world.transformationMat();
  std::cout << "TM"<<TM<<"\n";
  std::vector<double> RW = world.worldPoints(TM, pixels);
  std::cout<<"size 27?"<< RW.size();
  
}
