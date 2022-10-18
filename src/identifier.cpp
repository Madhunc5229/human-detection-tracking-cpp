#include "../include/identifier.h"


using std::vector;
std::vector<int> Identifier::input_size = {640, 640};

int Identifier::drawIdentifier(Mat &input_image, std::vector<Mat> &outputs, std::vector<std::string> &class_name){

    // Initialize vectors to hold respective outputs while unwrapping detections.
    vector<int> class_ids;
    vector<float> confidences;
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
        if (confidence >= Identifier::CONFIDENCE_THRESHOLD)
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