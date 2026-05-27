#include <iostream>
#include <Eigen/Dense>

using Matrix = Eigen::MatrixXd;

int main(int, char**){
    Matrix A(2, 2);
    A(0, 0) = 2.;
    A(0, 1) = 3.;
    A(1, 0) = -2.;
    A(1, 1) = 1.;

    Matrix B(2, 3);
    B(0, 0) = 1.;
    B(0, 1) = 2.;
    B(0, 2) = -1.;
    B(1, 0) = 1.;
    B(1, 1) = 2.;
    B(1, 2) = 1.;

    auto C = A * B;

    std::cout << "A:" << std::endl << A << std::endl;
    std::cout << "B:" << std::endl << B << std::endl;
    std::cout << "C:" << std::endl << C << std::endl << std::endl;

    auto D = B.cwiseProduct(C);
    std::cout << "Coefficient-wise multiplication of B & C is:" << std::endl << D << std::endl;

    return 0;
}