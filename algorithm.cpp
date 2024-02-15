#include "algorithm.h"
#include "matrix.h"

void Algorithm::execute()
{
    Matrix A(2, 3); // 2 rows, 3 columns
    Matrix B(3, 2); // 3 rows, 2 columns

    // Fill matrix A
    A.at(0, 0) = 1; A.at(0, 1) = 2; A.at(0, 2) = 3;
    A.at(1, 0) = 4; A.at(1, 1) = 5; A.at(1, 2) = 6;

    // Fill matrix B
    B.at(0, 0) = 7; B.at(0, 1) = 8;
    B.at(1, 0) = 9; B.at(1, 1) = 10;
    B.at(2, 0) = 11; B.at(2, 1) = 12;

    // Perform matrix multiplication
    Matrix C = A.multiply(B);
}