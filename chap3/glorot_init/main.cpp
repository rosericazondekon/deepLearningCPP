#include "src/helpers.hpp"
#include <iostream>
#include <numeric>

int main(){
    std::cout << "Glorot Initializer Example" << std::endl;
    auto weights = glorot_initializer(16, 9);
    for(const auto& weight : weights){
        std::cout << weight << " ";
    }
    std::cout << std::endl << std::endl;

    size_t N = weights.size();
    float acc = 0.0;
    float sum = std::accumulate(weights.begin(), weights.end(), .0);
    float weight_mean = sum / N;

    auto differ = [&acc, &weight_mean](const float x){
        const float diff = x - weight_mean;
        acc += diff * diff;
    };

    std::for_each(weights.begin(), weights.end(), differ);

    float weight_std = sqrt(acc / (N - 1));
    std::cout << "Weight mean: " << weight_mean << std::endl;
    std::cout << "Weight std: " << weight_std << std::endl << std::endl;

    float expected_std = sqrt(2. / (6 + 5));
    std::cout << "Expected mean from Glorot initializer: 0.0" << std::endl;
    std::cout << "Expected std from Glorot initializer: " 
              << expected_std << std::endl << std::endl;

    std::cout << "Std rejected: " 
            //   << std::boolalpha 
              << (chi_squared_test(expected_std, weight_std, N, 0.05) ? "Yes" : "No")
              << std::endl;

    std::cout << "Mean rejected: " 
              << (t_test(0.0, weight_mean, weight_std, N, 0.05) ? "Yes" : "No")
              << std::endl;
    
    return 0;
}