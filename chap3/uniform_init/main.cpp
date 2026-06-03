#include "src/helpers.hpp"
#include <iostream>
#include <numeric>

int main(){
    std::cout << "Uniform Initializer Example" << std::endl;
    size_t min = 0, max = 35;
    auto weights = uniform_initializer(1500, min, max);
    for(const auto& weight : weights){
        std::cout << weight << " ";
    }
    std::cout << std::endl << std::endl;

    size_t size = weights.size();
    float acc = 0.0;
    float sum = std::accumulate(weights.begin(), weights.end(), 0.0f);
    float weight_mean = sum / size;

    auto differ = [&acc, &weight_mean](const float x){
        const float diff = x - weight_mean;
        acc += diff * diff;
    };

    std::for_each(weights.begin(), weights.end(), differ);

    float weight_std = sqrt(acc / (size - 1));
    std::cout << "Weight mean: " << weight_mean << std::endl;
    std::cout << "Weight std: " << weight_std << std::endl << std::endl;

    float expected_std = sqrt((pow((max - min), 2)) / 12);
    float expected_mean = (min + max) / 2;
    std::cout << "Expected mean from Uniform initializer: " << expected_mean << std::endl;
    std::cout << "Expected std from Uniform initializer: " 
              << expected_std << std::endl << std::endl;

    std::cout << "Std rejected: " 
            //   << std::boolalpha 
              << (chi_squared_test(expected_std, weight_std, size, 0.05) ? "Yes" : "No")
              << std::endl;

    std::cout << "Mean rejected: " 
              << (t_test(expected_mean, weight_mean, weight_std, size, 0.05) ? "Yes" : "No")
              << std::endl;
    
    return 0;
}