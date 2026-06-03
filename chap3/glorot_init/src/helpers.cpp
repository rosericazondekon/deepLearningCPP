#include <cmath>
#include <vector>
#include <iostream>
#include <random>
#include <chrono>
#include <boost/math/distributions/chi_squared.hpp>
#include <boost/math/distributions/students_t.hpp>

using namespace boost::math;

std::vector<float> glorot_initializer(size_t fan_in, size_t fan_out){
    size_t size = fan_in * fan_out;
    float std_dev = sqrt(2. / (fan_in + fan_out));

    size_t seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<float> normal_distro(0.0, std_dev);

    std::vector<float> weights(size);

    std::generate(weights.begin(), weights.end(),
        [&generator, &normal_distro](){
            return normal_distro(generator);
        }
    );

    return weights;
}



bool chi_squared_test(float population_std, float sample_std, size_t sample_size, float confidence){
    float variance_rate = sample_std / population_std;
    variance_rate *= variance_rate;
    float t_stat = (sample_size - 1) * variance_rate;

    chi_squared distro(sample_size - 1);

    float upper_limit = quantile(complement(distro, confidence / 2));
    float lower_limit = quantile(distro, confidence / 2);


    return t_stat > upper_limit && t_stat < lower_limit;
}

bool t_test(float population_mean, float sample_mean, float sample_std, size_t sample_size, float confidence){
    float diff = sample_mean - population_mean;
    float t_stat = diff * sqrt((double)sample_size) / sample_std;

    size_t degrees_of_freedom = sample_size - 1;

    students_t distro(degrees_of_freedom);

    float qt = cdf(complement(distro, fabs(t_stat)));

    float confidence_2 = confidence / 2;

    return qt < confidence_2;
}