#include <gtest/gtest.h>
#include <numeric>
#include <algorithm>
#include "../src/helpers.hpp"

TEST(CheckUniformInitializer, StatCases){
    size_t size = 1500;

    auto weights = uniform_initializer(size, 0, 35);

    const size_t sample_size = weights.size();

    EXPECT_EQ(sample_size, size) << "The number of weights generated does not match the expected size.";

    float a = *std::max_element(weights.begin(), weights.end());
    float b = *std::min_element(weights.begin(), weights.end());

    float sample_mean = std::accumulate(weights.begin(), weights.end(), 0.0f) / sample_size;

    float acc = 0.0;
    
    auto differ = [&acc, &sample_mean](const float x){
        const float diff = x - sample_mean;
        acc += diff * diff;
    };

    std::for_each(weights.begin(), weights.end(), differ);
    
    float sample_std = sqrt(acc / (sample_size - 1));

    float population_std = sqrt((pow((b - a), 2)) / 12);
    float population_mean = (a + b) / 2;

    bool std_rejected = chi_squared_test(population_std, sample_std, sample_size, 0.05);

    if(std_rejected){
        FAIL() << "The weights standard deviation does not match the expected value from the Uniform initializer.";
    }

    bool mean_rejected = t_test(population_mean, sample_mean, sample_std, sample_size, 0.05);
    if(mean_rejected){
        FAIL() << "The weights mean does not match the expected value from the Uniform initializer.";
    }
}