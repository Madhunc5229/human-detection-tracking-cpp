#include "../include/yoloDetect.h"

using std::vector;

std::vector<int> YoloDetect::input_size = {640, 640};

Mat YoloDetect::preProcess(cv::Mat &input_frame) {

  // Convert to blob.
  Mat blob;
  // convert input frame to blob
  cv::dnn::blobFromImage(input_frame, blob, 1. / 255.,
                         cv::Size(input_size.at(0), input_size.at(1)),
                         cv::Scalar(), true, false);
  return blob;
}

std::vector<Mat> YoloDetect::detect(Mat blob, Net &net) {
  net.setInput(blob);
  std::vector<Mat> outputs;
  // Run the forward pass to get output of the output layers.
  net.forward(outputs, net.getUnconnectedOutLayersNames());
  return outputs;
}
