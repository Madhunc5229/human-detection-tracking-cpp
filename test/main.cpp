/**
 * @brief Main function for running test cases
 * @version 0.1
 * @date 2022-10-19
 * 
 * @copyright Copyright (c) 2022
 */
#include <gtest/gtest.h>
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
