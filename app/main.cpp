/**
* @file main.cpp
* @author Madhu Narra Chittibabu (madhunc117@gmail.com)
* @brief 
* @version 0.1
* @date 2022-10-06
* 
* @copyright Copyright (c) 2022
* 
*/
#include <iostream>
#include "yoloDetect.h"

/**
* @brief starting point for the program
* 
* @return int 
*/
int main() {
    Mat frame;
    //read the test image
    frame = cv::imread("data/test_image.jpg");
    Net net;
    YoloDetect yolo;

    //load the network
    net = cv::dnn::readNet("YOLOv5s.onnx");

    Mat blob;
    // Pre-Process the image.
    blob = yolo.preProcess(frame);

    std::vector<Mat> detections; 

    //get detections 
    detections = yolo.detectHuman(blob, net);

}
