#pragma once
#include <vector>
#include <cstddef>

std::vector<float> glorot_initializer(size_t fan_in, size_t fan_out);
bool chi_squared_test(float population_std, float sample_std, size_t sample_size, float confidence);
bool t_test(float population_mean, float sample_mean, float sample_std, size_t sample_size, float confidence);
