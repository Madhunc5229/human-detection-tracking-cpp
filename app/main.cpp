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

#include "../include/identifier.h"
#include "../include/pixelToWorld.h"
#include "../include/yoloDetect.h"
#include <iostream>

/**
 * @brief starting point for the program
 *
 * @return int
 */
int main() {
  std::vector<std::string> class_list;
  class_list.push_back("person");
  // cv::VideoCapture cap("../data/pixel5a_video.mp4");
  cv::VideoCapture cap(0);
  while (cap.isOpened()) {
    Mat frame;
    cap.read(frame);
    // read the test image
    // frame = cv::imread("../data/test_image.jpg");
    Net net;
    YoloDetect yolo;
    Identifier identify;
    PixelToWorld to_world;

    // load the network
    net = cv::dnn::readNetFromONNX("../yolov5s/yolov5s.onnx");

    Mat blob;
    // Pre-Process the image.
    blob = yolo.preProcess(frame);
    std::vector<Mat> predictions;

    // get detections
    predictions = yolo.detect(blob, net);
    std::vector<double> pixels =
        identify.drawIdentifier(frame, predictions, class_list);
    std::cout << "Number of humans: " << pixels.size() / 2.0 << "\n";
    MatrixXf TM(3, 4);

    TM = to_world.transformationMat();
    std::cout << TM << "\n";
    
    std::vector<double> real_world = to_world.worldPoints(TM, pixels);
    // int count = 1;
    // for (long unsigned int i = 0; i < 2; i = i + 3) {
    //   std::cout << "Person " << count
    //             << " world coordinates :" << real_world.at(i) << ", "
    //             << real_world.at(i + 1) << ", " << real_world.at(i + 2) << "\n";
    //   count++;
    // }
    std::cout << "Pixel Co-ordinates: " << pixels.at(0) << pixels.at(1) << "\n"; 
    std::cout << "Real World Co-ordinates: " << real_world.at(0) << real_world.at(1)<< real_world.at(2)  << "\n"; 
    cv::imshow("Detections: ", frame);
    if (cv::waitKey(1) == 27) {
            break;
        }
    
    // cv::waitKey(100);
  }
}