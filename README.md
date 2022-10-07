[![Build Status](https://app.travis-ci.com/Madhunc5229/human-detection-tracking-cpp.svg?branch=main)](https://app.travis-ci.com/Madhunc5229/human-detection-tracking-cpp)  [![Coverage Status](https://coveralls.io/repos/github/Madhunc5229/human-detection-tracking-cpp/badge.svg?branch=main)](https://coveralls.io/github/Madhunc5229/human-detection-tracking-cpp?branch=main)
# human-detection-and-tracking-cpp
This project is designed and programmed to detect and track humans which will provide the location of the humans in a robot's frame of reference.
Agile Iterative Process is used for the development of this project consisting of two sprints.  

## Authors
Sprint 1 -
 - Madhu Narra Chittibabu (Driver)
 - [Sharmitha Ganesan](https://github.com/sharmithag) (Navigator)
 - Koundinya Vinnakota (Design Keeper)

Sprint 2 -
 - Madhu Narra Chittibabu (Navigator)
 - [Sharmitha Ganesan](https://github.com/sharmithag) (Driver)
 - Koundinya Vinnakota (Design Keeper)
 
## Introduction
Human Detection is a branch of Object Detection in Computer Vision. Object Detection is the task of identifying the presence of predefined types of objects in an image. This task involves both identification of the presence of the objects and identification of the rectangular boundary surrounding each object (i.e. Object Localisation). An object detection system which can detect the class “Human” can work as a Human Detection System.  

We aim to design and deliver a robust  robust human detector and tracker using a monocular camera, directly usable in a robot’s reference frame according to the requirement specifications provided to us by ACME robotics's RnD division for integration into a future product.

Our system is built using C++ and will employ the robust YOLOv5 neural network model trained on the COCO dataset for human detection and tracking as it is one of the most accurate real-time object detection algorithms. An image from a monocular camera is pre-processed and passed to the model which outputs the location info in the image frame. It is then converted to the camera frame by using the calibration constants and then transformed into the robot's frame.




## Requirements
 - C++ 14++
 - Cmake min 3.2.1  

Continuous integration is tracked by using Travis CI and code coverage is tracked using coveralls. 


## System Design and Architecture 
The following shows the activity diagram for our proposed design : 

![image](https://user-images.githubusercontent.com/90351952/194469507-a9dfbb5f-3e2f-4e71-a1e3-85f28d3e94c5.png)


