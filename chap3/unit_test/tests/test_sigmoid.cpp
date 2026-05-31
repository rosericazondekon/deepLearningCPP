#include <gtest/gtest.h>
#include "../src/myfunctions.hpp"

TEST(SigmoidTest, BaseCases) {
    float actual = sigmoid(-100.f);
    float expected = 0.f;
    EXPECT_NEAR(actual, expected, 1e-7f) << "Sigmoid lower bound test failed";
    EXPECT_NEAR(sigmoid(100.f), 1.f, 1e-7f) << "Sigmoid upper bound test failed";
    EXPECT_NEAR(sigmoid(0.f), 0.5f, 1e-7f) << "Sigmoid midpoint test failed";
}

