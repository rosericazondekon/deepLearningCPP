#include <gtest/gtest.h>
#include <numeric>
#include <algorithm>
#include "../src/helpers.hpp"

TEST(CheckGlorotInitializer, StatCases){
    size_t fan_in = 6;
    size_t fan_out = 5;

    auto weights = glorot_initializer(fan_in, fan_out);

    const size_t sample_size = weights.size();

    EXPECT_EQ(sample_size, fan_in * fan_out);

    float sum = std::accumulate(weights.begin(), weights.end(), .0);
    float sample_mean = sum / sample_size;

    float acc = 0.0;

    auto differ = [&acc, &sample_mean](const float x){
        const float diff = x - sample_mean;
        acc += diff * diff;
    };

    std::for_each(weights.begin(), weights.end(), differ);
    float sample_std = sqrt(acc / (sample_size - 1));

    float population_std = sqrt(2. / (fan_in + fan_out));

    bool std_rejected = chi_squared_test(population_std, sample_std, sample_size, 0.05);

    if(std_rejected){
        FAIL() << "The weights standard deviation does not match the expected value from the Glorot initializer.";
    }

    bool mean_rejected = t_test(0.0, sample_mean, sample_std, sample_size, 0.05);
    if(mean_rejected){
        FAIL() << "The weights mean does not match the expected value from the Glorot initializer.";
    }
}