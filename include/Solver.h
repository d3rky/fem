#ifndef SOLVER_H

#define SOLVER_H

#include "Utils.h"

class Solver {
    
    public:
        Solver(const float eps): _eps(eps) {};

        virtual float* solve(utils::Matrix* matrix)=0;

    protected:
        const float _eps; 
};

#endif
