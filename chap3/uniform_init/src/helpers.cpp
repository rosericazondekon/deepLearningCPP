#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <cmath>

std::vector<float> uniform_initializer(size_t size, float from, float to){
    size_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<float> uniform_distro(from, to);

    std::vector<float> weights(size);

    std::generate(weights.begin(), weights.end(),
        [&generator, &uniform_distro](){
            return uniform_distro(generator);
        }
    );

    return weights;
}