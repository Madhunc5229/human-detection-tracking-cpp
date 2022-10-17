add_executable(shell-app main.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

# target_include_directories(shell-app ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(shell-app PUBLIC detector_lib ${OpenCV_LIBS})