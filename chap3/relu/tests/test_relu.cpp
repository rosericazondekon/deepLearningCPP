#include <gtest/gtest.h>
#include "../src/helpers.hpp"

TEST(CheckRelu, NegativeInput){
    EXPECT_FLOAT_EQ(relu(-5.f), 0.f) << "ReLU should return 0 for negative inputs.";
}

TEST(CheckRelu, ZeroInput){
    EXPECT_FLOAT_EQ(relu(0.f), 0.f) << "ReLU should return 0 for zero input.";
}

TEST(CheckRelu, PositiveInput){
    EXPECT_FLOAT_EQ(relu(5.f), 5.f) << "ReLU should return the input value for positive inputs.";
}