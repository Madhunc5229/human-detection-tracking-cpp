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

std::vector<Mat> YoloDetect::detectHuman(Mat blob, Net &net) {
  net.setInput(blob);
  std::vector<Mat> outputs;
  // Run the forward pass to get output of the output layers.
  net.forward(outputs, net.getUnconnectedOutLayersNames());
  return outputs;
}


int YoloDetect::process(Mat &input_image, std::vector<Mat> &outputs, std::vector<std::string> &class_name){

    // Initialize vectors to hold respective outputs while unwrapping     detections.
    vector<int> class_ids;
    vector<float> confidences;
    // vector<cv::Rect> boxes;
    // Resizing factor.
    int count =0;
    float x_factor = input_image.cols / input_size.at(0);
    float y_factor = input_image.rows / input_size.at(1);
    float *data = (float *)outputs[0].data;
    const int dimensions = 85;
    // 25200 for default size 640.
    const int rows = 25200;
    // Iterate through 25200 detections.
    for (int i = 0; i < rows; ++i)
    {
        float confidence = data[4];
        // Discard bad detections and continue.
        if (confidence >= YoloDetect::CONFIDENCE_THRESHOLD)
        {
            float * classes_scores = data + 5;
            // Create a 1x85 Mat and store class scores of 80 classes.
            Mat scores(1, class_name.size(), CV_32FC1, classes_scores);
            // Perform minMaxLoc and acquire the index of best class  score.
            cv::Point class_id;
            double max_class_score;
            cv::minMaxLoc(scores, 0, &max_class_score, 0, &class_id);

            if (class_id.x ==1){
              count ++;
            }
            
        }
        // Jump to the next row.
        data += 85;
    }
    return count;
}
