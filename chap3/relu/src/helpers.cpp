#include <stdexcept>
#include <vector>
#include <algorithm>

float relu(float x){
    return x > 0.f ? x : 0.f;
}

int find_median(const std::vector<int>& arr){
    const size_t size = arr.size();

    if(size == 0){
        throw std::invalid_argument("Cannot find the median of an empty vector.");
    }

    std::vector<int> sorted = arr;
    std::sort(sorted.begin(), sorted.end());

    if(size % 2 == 0){
        return (sorted[size / 2 - 1] + sorted[size / 2]) / 2;
    } else {
        return sorted[size / 2];
    }
}