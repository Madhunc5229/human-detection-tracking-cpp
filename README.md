
[![Build Status](https://github.com/Madhuc5229/human-detection-tracking-cpp/actions/workflows/build_and_coveralls.yml/badge.svg)](https://github.com/Madhuc5229/human-detection-tracking-cpp/actions/workflows/build_and_coveralls.yml)
[![Coverage Status](https://coveralls.io/repos/github/Madhuc5229/human-detection-tracking-cpp/badge.svg?branch=master)](https://coveralls.io/github/Madhuc5229/human-detection-tracking-cpp/?branch=master) [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
# human-detection-and-tracking-cpp
This project is designed and programmed to detect and track humans which will provide the location of the humans in a robot's frame of reference.
Agile Iterative Process is used for the development of this project consisting of two sprints.  

## Authors
Sprint 1 -
 - [Madhu Narra Chittibabu](https://www.linkedin.com/in/madhunc/) (Driver) (UID: 118206196)
 - [Sharmitha Ganesan](https://github.com/sharmithag) (Navigator) (UID: 117518931)
 - [Koundinya Vinnakota](https://github.com/koundinyavinnakota) (Design Keeper) (UID: 118239811)

Sprint 2 -
 - [Madhu Narra Chittibabu](https://www.linkedin.com/in/madhunc/) (Navigator) (UID: 118206196)
 - [Sharmitha Ganesan](https://github.com/sharmithag) (Driver) (UID: 117518931)
 - [Koundinya Vinnakota](https://github.com/koundinyavinnakota) (Design Keeper) (UID: 118239811)
 
## Overview
Human Detection is a branch of Object Detection in Computer Vision. Object Detection is the task of identifying the presence of predefined types of objects in an image. This task involves both identification of the presence of the objects and identification of the rectangular boundary surrounding each object (i.e. Object Localisation). An object detection system which can detect the class “Human” can work as a Human Detection System.  

## Purpose
We aim to design and deliver a robust  robust human detector and tracker using a monocular camera, directly usable in a robot’s reference frame according to the requirement specifications provided to us by ACME robotics's RnD division for integration into a future product.

Our system is built using C++ and will employ the robust YOLOv5 neural network model trained on the COCO dataset for human detection and tracking as it is one of the most accurate real-time object detection algorithms. An image from a monocular camera is pre-processed and passed to the model which outputs the location info in the image frame. It is then converted to the camera frame by using the calibration constants and then transformed into the robot's frame.


## Requirements
 - C++ 14++
 - Cmake min 3.2.1  
 - Opencv [For installation](http://www.codebind.com/linux-tutorials/how-to-install-opencv-in-ubuntu-20-04-lts-for-c-c/)

Continuous integration is tracked by using Travis CI and code coverage is tracked using coveralls. 

## Build and Running Instructions
```
    git clone https://github.com/Madhunc5229/human-detection-tracking-cpp.git
    mkdir build && cd build
    cmake .. 
    make

    <!-- Run app -->
    ./app/myApp

    <!-- Run tests -->
    ./test/cpp-test
```

## Building for code coverage 
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

## Run and save cpplint and cppcheck
```
cpplint $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/") $( find . -name *.h | grep -vE -e "^./build/" -e "^./vendor/") > cpplint.txt

cppcheck --enable=all --std=c++11 -I include/ --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" ) $( find . -name *.h | grep -vE -e "^./build/" -e "^./vendor/") > cppcheck.txt
```

#### The Quad Chart for the project can be found [here](docs/quad_chart.pdf)

#### The Proposal for the project can be found [here](docs/Proposal.pdf)

#### The video explanation of the phase zero of this project can be found [here](https://youtu.be/ooPpgImk9Js)

