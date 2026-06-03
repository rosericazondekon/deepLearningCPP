#include <gtest/gtest.h>
#include "../src/helpers.hpp"

TEST(CheckFindMedian, EmptyVector){
    std::vector<int> empty_vec;
    EXPECT_THROW(find_median(empty_vec), std::invalid_argument);
}

TEST(CheckFindMedian, OddSizeVector){
    std::vector<int> vec {9, 4, 1, 11, 20, -1, 2};
    EXPECT_EQ(find_median(vec), 4);
}

TEST(CheckFindMedian, EvenSizeVector){
    std::vector<int> vec {9, 4, 1, 11, 20, -1};
    EXPECT_EQ(find_median(vec), 6);
}