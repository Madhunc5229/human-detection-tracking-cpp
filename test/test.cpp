/**
 * @file test.cpp
 * @author Madhu Narra Chittibabu (madhunc117@gmail.com), Sharmitha Ganesan
 * (sharmithaganesan08@gmail.com)
 * @brief Test cases to check methods YoloDetect::preProcess(),
 * YoloDetect::detect()
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <gtest/gtest.h>

#include <iostream>
#include <string>

#include "../include/identifier.h"
#include "../include/pixelToWorld.h"
#include "../include/yoloDetect.h"

using Eigen::Matrix3f;
using Eigen::MatrixXf;

// read the test image
Mat test_frame = cv::imread("../data/test_image.jpg");
// read the network
Net test_net = cv::dnn::readNetFromONNX("../yolov5s/yolov5s.onnx");

YoloDetect test;
Identifier test_identifier;
PixelToWorld to_world;

/**
 * @brief Test 1 checks if the blobs dimension is (1,3,640,640)
 *
 */
TEST(Test1, testPreProcess) {
  Mat test_blob = test.preProcess(test_frame);
  std::cout << "working till here"
            << "\n";
  auto num = test_blob.size;
  int arr[4] = {1, 3, 640, 640};
  for (int i = 0; i < 4; i++) {
    EXPECT_TRUE(arr[i] == (num[i]));
  }
}

/**
 * @brief Test 2 checks if the detections dimension is (1,25200,85)
 *
 */
TEST(Test2, testDetect) {
  Mat test_blob = test.preProcess(test_frame);
  auto detections = test.detect(test_blob, test_net);
  auto num = detections[0].size;
  int arr[3] = {1, 25200, 85};
  for (int i = 0; i < 3; i++) {
    EXPECT_TRUE(arr[i] == (num[i]));
  }
}

/**
 * @brief Test 3 checks the number of detections in an image
 *
 */
TEST(Test3, testNumOfDetections) {
  std::vector<std::string> test_class_list;
  test_class_list.push_back("person");
  Mat test_blob = test.preProcess(test_frame);
  std::vector<Mat> detections;
  detections = test.detect(test_blob, test_net);
  std::vector<double> test_num_of_humans =
      test_identifier.drawIdentifier(test_frame, detections, test_class_list);
  EXPECT_NEAR(9, test_num_of_humans.size() / 2.0, 3);
}

/**
 * @brief Test4 checks the transformation matrix based on a focal length
 *
 */
TEST(Test4, transformationMatTest) {
  MatrixXf transformation_mat(3, 4);
  MatrixXf test_transformation_mat(3, 4);
  double focalLength = 27.0;
  transformation_mat << focalLength, 0, 0, 0, 0, focalLength, 0, 0, 0, 0, 1, 1;
  test_transformation_mat = to_world.transformationMat();
  EXPECT_EQ(transformation_mat, test_transformation_mat);
}

/**
 * @brief Test5 checks the transformation from pixel to world cordinates
 *
 */
TEST(Test5, worldCordinatesTest) {
  std::vector<double> pixels;
  pixels.push_back(5.0);
  pixels.push_back(10.0);
  std::vector<double> real_world;
  real_world.push_back(0.37037);
  real_world.push_back(0.740741);
  real_world.push_back(1);
  MatrixXf transformation_mat(3, 4);
  double focalLength = 27.0;
  transformation_mat << focalLength, 0, 0, 0, 0, focalLength, 0, 0, 0, 0, 1, 1;
  std::vector<double> test_real_world =
      to_world.worldPoints(transformation_mat, pixels);
  EXPECT_NEAR(real_world.at(0), test_real_world.at(0), 1);
  EXPECT_NEAR(real_world.at(1), test_real_world.at(1), 1);
  EXPECT_NEAR(real_world.at(2), test_real_world.at(2), 1);
}
