#include <iostream>
#include <Eigen/Dense>

using Matrix = Eigen::MatrixXd;

Matrix flipHorizontal(const Matrix& m);
Matrix flipVertical(const Matrix& m);

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

    //Matrix multiplication
    auto C = A * B;

    std::cout << "A:" << std::endl << A << std::endl;
    std::cout << "B:" << std::endl << B << std::endl;
    std::cout << "C:" << std::endl << C << std::endl << std::endl;

    //Coefficient-wise multiplication
    auto D = B.cwiseProduct(C);
    std::cout << "Coefficient-wise multiplication of B & C is:" << std::endl << D << std::endl;

    std::cout << "The inverse of A is:" << std::endl << A.inverse() << std::endl;
    std::cout << "The determinant of A is:" << std::endl << A.determinant() << std::endl;
    std::cout << "The transpose of B is:" << std::endl << B.transpose() << std::endl << std::endl;

    //Example of unary operation
    std::cout << "Example of unary operation: the square of each coefficient of A is:" << std::endl;
    auto funcXX = [](double x){return x*x;};
    std::cout << A.unaryExpr(funcXX) << std::endl << std::endl;
    
    std::cout << "Example of binary operation: the product of each coefficient of B with the corresponding coefficient of C is:" << std::endl;
    auto funcXY = [](double x, double y){return x*y;};
    std::cout << B.binaryExpr(C, funcXY) << std::endl;

    //Examples of flipping matrices
    std::cout << "Horizontal flip of A:" <<
                std::endl << flipHorizontal(A) << std::endl << std::endl;
    std::cout << "Vertical flip of A:" <<
                std::endl << flipVertical(A) << std::endl << std::endl;
    std::cout << "Matrix B:" <<
                std::endl << B << std::endl << std::endl;
    std::cout << "Horizontal flip of B:" <<
                std::endl << flipHorizontal(B) << std::endl << std::endl;
    std::cout << "Vertical flip of B:" <<
                std::endl << flipVertical(B) << std::endl << std::endl;
    std::cout << "Rotate B by 90 degrees clock-wise:" <<
                std::endl << flipVertical(B.transpose()) << std::endl << std::endl;
    std::cout << "Rotate B by 90 degrees counter clock-wise:" <<
                std::endl << flipHorizontal(B.transpose()) << std::endl << std::endl;

    return 0;
}

Matrix flipVertical(const Matrix& m){
    Matrix J = Matrix::Zero(m.cols(), m.cols());
    for(Eigen::Index i = 0; i < m.cols(); i++){
        for(Eigen::Index j = 0; j < m.cols(); j++){
            J(i, j) = ((i + j) == (m.cols() - 1)) ? 1. : 0.;
        }
    }
    J = m * J;
    return J;
}

Matrix flipHorizontal(const Matrix& m){
    Matrix J = Matrix::Zero(m.rows(), m.rows());
    for(Eigen::Index i = 0; i < m.rows(); i++){
        for(Eigen::Index j = 0; j < m.rows(); j++){
            J(i, j) = ((i + j) == (m.rows() - 1)) ? 1. : 0.;
        }
    }
    J = J * m;
    return J;
}