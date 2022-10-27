/**
 * @file identifier.cpp
 * @author Madhu Narra Chittibabu (madhunc117@gmail.com) (driver @ phase 1)
 *         Sharmitha Ganesan (sharmithaganesan08@gmail.com) (driver @ phase 2)
 * @brief Implementation od identifier class
 * @version 0.1
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../include/identifier.h"


using std::vector;

std::vector<float> Identifier::input_size = {640.0, 640.0};

/**
 * @brief In Sprint 1, this method returns the number of detected humans before non-max suppression
 * 
 * @param input_image 
 * @param outputs 
 * @param class_name 
 * @return int 
 */
void Identifier::drawIdentifier(const cv::Mat &input_image, std::vector<Mat> &predictions, std::vector<std::string> &class_name) {
    // Initialize vectors to hold outputs while unwrapping detections.
    vector<int> class_ids;
    vector<float> confidences;
    vector<cv::Rect> boxes;

    struct Detection {
    int class_id;
    float confidence;
    cv::Rect box;
    };
    // Resizing factor.
    int count = 0;
    float x_factor = input_image.cols / input_size.at(0);
    float y_factor = input_image.rows / input_size.at(1);
    float* data = (float* )predictions[0].data;  // NOLINT
    // const int dimensions = 85;
    // 25200 for default size 640.
    const int rows = 25200;
    // Iterate through 25200 detections.
    for (int i = 0; i < rows; ++i) {
        float confidence = data[4];
        // Discard bad detections and continue.
        if (confidence >= Identifier::CONFIDENCE_THRESHOLD) {
            float * classes_scores = data + 5;
            // Create a 1x85 Mat and store class scores of 80 classes.
            Mat scores(1, class_name.size(), CV_32FC1, classes_scores);
            // Perform minMaxLoc and acquire the index of best class  score.
            cv::Point class_id;
            double max_class_score;
            cv::minMaxLoc(scores, 0, &max_class_score, 0, &class_id);

            if (class_id.x == 0) {
            if (max_class_score > SCORE_THRESHOLD) {
              count  ++;  // NOLINT
              confidences.push_back(confidence);
              class_ids.push_back(class_id.x);
              float x = data[0];
              float y = data[1];
              float w = data[2];
              float h = data[3];
              int left = int((x - 0.5 * w) * x_factor);
              int top = int((y - 0.5 * h) * y_factor);
              int width = int(w * x_factor);
              int height = int(h * y_factor);
              boxes.push_back(cv::Rect(left, top, width, height));
            }}
        }
        // Jump to the next row.
        data += 85;
    }
    std::vector<int> nms_result;
    std::vector<Detection> output;
    cv::dnn::NMSBoxes(boxes, confidences, SCORE_THRESHOLD, NMS_THRESHOLD, nms_result);
    for (int i = 0; i < static_cast<int>(nms_result.size()); i++) {
        int idx = nms_result[i];
        Detection result;
        result.class_id = class_ids[idx];
        result.confidence = confidences[idx];
        result.box = boxes[idx];
        output.push_back(result);}
    int no_detections = output.size();
    std::cout<<"detections "<<no_detections<<"\n";
    const std::vector<cv::Scalar> colors = {cv::Scalar(255, 255, 0), cv::Scalar(0, 255, 0), cv::Scalar(0, 255, 255), cv::Scalar(255, 0, 0)};
        for (int i = 0; i < no_detections; ++i) {
            auto detection = output[i];
            auto box = detection.box;
            auto classId = detection.class_id;
            const auto color = colors[classId % colors.size()];
            cv::rectangle(input_image, box, (color), 3);
            cv::rectangle(input_image, cv::Point(box.x, box.y - 20), cv::Point(box.x + box.width, box.y), color, cv::FILLED);
            cv::putText(input_image, (class_name[classId].c_str()+ std::to_string(i+1)), cv::Point(box.x, box.y - 5), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
        }
    cv::imshow("output",input_image);
    cv::waitKey(0);
    
    
}
