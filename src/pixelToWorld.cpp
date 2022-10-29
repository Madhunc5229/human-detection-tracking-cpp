/**
 * @file pixelToWorld.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../include/pixelToWorld.h"
using Eigen::Matrix3f;
using Eigen::MatrixXf;
using Eigen::Vector3f;
using Eigen::Vector4f;

double PixelToWorld::focalLength = 27.0;
MatrixXf PixelToWorld::transformationMat() {
Matrix3f intrinsic;
intrinsic << focalLength, 0, 0, 0, focalLength, 0, 0, 0, 1;
MatrixXf extrinsic(3, 4);
extrinsic << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1;
MatrixXf T(3,4);
T = intrinsic * extrinsic;
return T;
}

std::vector<double> PixelToWorld:: worldPoints(MatrixXf T, std::vector<double> pixelValues) {
std::vector<double> real_world;
MatrixXf pseudo_T(4,3);
pseudo_T= T.completeOrthogonalDecomposition().pseudoInverse();
for (long unsigned int i = 0; i<pixelValues.size(); i=i+2) {
double u = pixelValues.at(i);
double v = pixelValues.at(i+1);
Vector3f pixel_coord;
pixel_coord << u,v,1;
Vector4f world_coord;
world_coord = pseudo_T * pixel_coord;
double x = world_coord[0]/world_coord[3];
double y = world_coord[1]/world_coord[3];
double z = world_coord[2]/world_coord[3];

real_world.push_back(x);
real_world.push_back(y);
real_world.push_back(z);

}
return real_world;
}
