#include <iostream>
#include <iomanip>

#include "../../include/Utils.h"

using namespace utils;

/*
 * Matrix class
 */
////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
Matrix::Matrix(const int width, const int height): _width(width), _height(height) {
    _matrix = new float*[height];
    _b = new float[height];

    for(int i=0; i<height; i++) {
        _matrix[i] = new float[width];
    }

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            _matrix[i][j] = 0.0;
        }
        _b[i] = 0.0;
    }
};

Matrix::~Matrix() {
    delete[] _b;

    for(int i=0; i<_height; i++) {
        delete[] _matrix[i];
    }

    delete[] _matrix;
}

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
void Matrix::add(MatrixElement elem) {
    if(elem.i == -1) {
        _b[elem.j] += elem.value;
    } else {
        _matrix[elem.i][elem.j] += elem.value;
    }
};

void Matrix::add(std::vector<MatrixElement> vec_elem) {
    std::vector<MatrixElement>::iterator it = vec_elem.begin();

    for(; it != vec_elem.end(); ++it) {
        add((*it));
    }
};

void Matrix::clearRow(const int rowNum) {
    for(int j=0; j<_width; j++) {
        _matrix[rowNum][j] = 0.0;
    }

    _b[rowNum] = 0.0;
};

float** Matrix::getMatrix() const {
    return _matrix;
};

float* Matrix::getB() const {
    return _b;
};

int Matrix::getWidth() const {
    return _width;
};

int Matrix::getHeight() const {
    return _height;
};

void Matrix::print(std::ostream& stream) {
    stream<<std::fixed<<std::setprecision(3);

    for(int i=0; i<_height; i++) {
        for(int j=0; j<_width; j++) {
            stream<<_matrix[i][j]<<"\t";
        }

        stream<<_b[i]<<std::endl;
    }

    stream<<std::endl;
};
