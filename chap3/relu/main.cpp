#include <iostream>
#include <vector>
#include "src/helpers.hpp"

int main(int, char**) {
    std::cout << "ReLu of -100 is: " << relu(-100.f) << std::endl;
    std::cout << "ReLu of 0 is: " << relu(0.f) << std::endl;
    std::cout << "ReLu of 59 is: " << relu(59.f) << std::endl << std::endl;

    std::vector<int> vecOdd {9, 4, 1, 11, 20, -1, 2};
    std::cout << "The median value of the odd vector is: " 
              << find_median(vecOdd) << std::endl;

    std::vector<int> vecEven {9, 4, 11, 20, -1, 2};
    std::cout << "The median value of the even vector is: " 
              << find_median(vecEven) << std::endl;

    return 0;
}