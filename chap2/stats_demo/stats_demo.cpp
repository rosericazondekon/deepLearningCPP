#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <string>

std::random_device rd;

int main(int, char**){
    //Normal Distribution
    //Generate 10000 random numbers from a normal distribution with mean 2 and standard deviation 3, and display the histogram of the generated numbers.
    std::mt19937 random_generator{rd()};
    std::normal_distribution<> normal_distro{2, 3};
    std::map<int, int> histogram;

    //Generate 10000 random numbers and count the frequency of each integer value in the histogram map
    for(int i = 0; i < 10000; ++i){
        int value = std::round(normal_distro(random_generator));
        histogram[value]++;
    }

    //Display the histogram
    std::cout << "Histogram of normal distribution:" << std::endl;
    for(auto [x, y] : histogram){
        std::cout << std::setw(2) << x << "" << std::string(y/20, '*') << std::endl;
    }

    //Uniform Distribution
    std::uniform_real_distribution<> uniform_distro {-10, 13};

    std::cout << std::endl << "Histogram of uniform distribution:" << std::endl;
    histogram.clear();
    for(int i = 0; i < 10000; ++i){
        int value = std::round(uniform_distro(random_generator));
        histogram[value]++;
    }

    for(auto [x, y] : histogram){
        std::cout << std::setw(2) << x << "" << std::string(y/20, '*') << std::endl;
    }

    //Central Limit Theorem
    std::cout << std::endl << "Central Limit Theorem:" << std::endl
              << "Histogram of the average of 5 uniform distributions" << std::endl;
    const unsigned int seed = 1234;//rd();
    std::mt19937 random_gen(seed);

    //Define 5 different uniform distributions with different ranges
    std::uniform_real_distribution<> uniform_dist {-10, 13};
    std::uniform_real_distribution<> uniform_dist2 {-5, 8};
    std::uniform_real_distribution<> uniform_dist3 {3, 9};
    std::uniform_real_distribution<> uniform_dist4 {-8, -1};
    std::uniform_real_distribution<> uniform_dist5 {-10, 10};

    //Clear the histogram map before counting the frequency of the average values
    histogram.clear();

    //Generate 10000 random numbers by averaging 5 different uniform distributions and count the frequency of each integer value in the histogram map
    for(int i = 0; i < 10000; ++i){
        double value = uniform_dist(random_gen) +
                          uniform_dist2(random_gen) +
                          uniform_dist3(random_gen) +
                          uniform_dist4(random_gen) +
                          uniform_dist5(random_gen);
        value /= 5; //Average of the 5 uniform distributions
        histogram[std::round(value)]++;
    }

    for(auto [x, y] : histogram){
        std::cout << std::setw(2) << x << "" << std::string(y/20, '*') << std::endl;
    }

    std::vector<double> data;
    for(int i = 0; i < 500; ++i){
        data.push_back(normal_distro(random_generator));
    }

    auto ksmall = [](const std::vector<double>& data, unsigned int k) {
        std::vector<double> result;
        std::vector<double> temp = data;
        for(unsigned int i = 0; i < k; ++i){
            auto min_it = std::min_element(temp.begin(), temp.end());
            result.push_back(*min_it);
            temp.erase(min_it);
        }
        return result;
    };

    std::cout << std::endl 
              << "The 15 smallest values in the generated normal distribution data are:" 
              << std::endl;

    auto smallest_values = ksmall(data, 15);
    for(const auto& value : smallest_values){
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
