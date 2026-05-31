#include <gtest/gtest.h>
#include "../src/myfunctions.hpp"

TEST(OddCase, BaseCases){
    std::vector<int> vec {9, 4, 1, 11, 20, -1, 2};
    int actual = find_middle(vec);

    EXPECT_EQ(4, actual) << "Test failed for odd number of elements";
}

TEST(EvenCase, BaseCases){
    std::vector<int> vec {9, 4, 11, 20, -1, 2};
    int actual = find_middle(vec);

    EXPECT_EQ(9, actual) << "Test failed for even number of elements";
}

TEST(CheckEmptyVector, BaseCases){

    EXPECT_THROW({
        std::vector<int> vec;
        find_middle(vec);
    }, std::invalid_argument) << "Test failed for empty vector";
}