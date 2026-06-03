#include <iostream>
#include <vector>
#include "src/myfunctions.hpp"

int main(int, char**) {
    std::cout << "Sigmoid of -100 is: " << sigmoid(-100.f) << std::endl;
    std::cout << "Sigmoid of 0 is: " << sigmoid(0.f) << std::endl;
    std::cout << "Sigmoid of 100 is: " << sigmoid(100.f) << std::endl;

    std::vector<int> vecOdd {9, 4, 1, 11, 20, -1, 2};
    std::cout << "The middle value of the vector is: " << find_middle(vecOdd) << std::endl;
    std::vector<int> vecEven {9, 4, 11, 20, -1, 2};
    std::cout << "The middle value of the vector is: " << find_middle(vecEven) << std::endl;

    return 0;
}