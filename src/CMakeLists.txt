include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
add_library(myLib yoloDetect.cpp identifier.cpp)
