include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
add_library(detector_lib yoloDetect.cpp  ${CMAKE_SOURCE_DIR}/include/yoloDetect.h)
# target_include_directories(detector_lib PUBLIC ../include)