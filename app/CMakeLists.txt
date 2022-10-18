add_executable(myApp main.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

link_directories (${CMAKE_BINARY_DIR}/src)

# target_include_directories(shell-app ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(myApp myLib)