#ifndef GAUSS_SEIDEL_H

#define GAUSS_SEIDEL_H

#include "Solver.h"

class GaussSeidel: public Solver {

    public:
        GaussSeidel(const float eps);

        virtual float* solve(utils::Matrix* matrix);
    
    private:
        bool converge(float* x, float* xp, const int n);
};

#endif
