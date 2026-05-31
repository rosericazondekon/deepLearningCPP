#include <cmath>
#include <vector>
#include <stdexcept>

float sigmoid(float z) {
    if(z >= 45.f){
        return 1.f;
    } else if(z <= -45.f){
        return 0.f;
    } else {
        return 1.f / (1.f + exp(-z));
    }
}

int find_middle(const std::vector<int>& arr){
    const size_t size = arr.size();

    auto temp = arr;
    std::sort(temp.begin(), temp.end());

    if(size == 0){
        throw std::invalid_argument("Input array is empty");
    }
    return temp[size / 2];
}