#include <math.h>

#include "../../include/GaussSeidel.h"

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
GaussSeidel::GaussSeidel(const float eps): Solver(eps) {
    ;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * private functions
 */
bool GaussSeidel::converge(float* x, float* xp, const int n) {
    for (int i=0; i < n; i++)  {
        if (fabs(x[i] - xp[i]) >= _eps) 
            return false;
    }
    return true;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
float* GaussSeidel::solve(utils::Matrix* matrix) {
    float* result = new float[matrix->getHeight()];
    float* prev_result = new float[matrix->getHeight()];
    float** mat = matrix->getMatrix();
    float* b = matrix->getB();

    for(int i=0; i<matrix->getHeight(); i++) {
        result[i] = 0.0;
        prev_result[i] = 0.0;
    }

    do {

        for(int i=0; i<matrix->getHeight(); i++) {
            float var = 0.0;
        
            for(int j=0; j<matrix->getWidth(); j++) {
                if(j != i) { 
                    var += (mat[i][j] * result[j]);
                }
            }
            prev_result[i] = result[i];
            result[i] = (b[i] - var) / mat[i][i];
        }
    } while(!converge(result, prev_result, matrix->getHeight()));


    return result;
};
