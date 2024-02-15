#pragma once
#include <vector>
#include <stdexcept>

class Matrix {
private:
    std::vector<std::vector<double>> data;
    size_t rows, cols;

public:
    // Constructor for the matrix with the given number of rows and columns
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, std::vector<double>(cols, 0.0)) {}

    // Access elements
    double& at(size_t row, size_t col) {
        return data.at(row).at(col);
    }

    const double& at(size_t row, size_t col) const {
        return data.at(row).at(col);
    }

    // Getters for rows and cols
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    // Matrix multiplication
    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Matrix dimensions are incompatible for multiplication.");
        }

        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.at(i, j) += this->at(i, k) * other.at(k, j);
                }
            }
        }

        return result;
    }
};