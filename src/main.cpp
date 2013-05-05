#include <iostream>

#include "../include/Function.h"
#include "../include/DerichleBoundaryCondition.h"
#include "../include/NeumanBoundaryCondition.h"
#include "../include/FiniteElementFactory.h"
#include "../include/BarDiscret.h"
#include "../include/Utils.h"
#include "../include/GaussSeidel.h"

int main(int argc, char** argv) {
    
    const float width = 7.0;
    const int elemNum = 7;
    const float eps = 1E-6;

    Solver* solver = new GaussSeidel(eps);

    utils::BoundaryPlace leftCond = utils::BoundaryPlace(
        0,
        new DerichleBoundaryCondition(5.0)
    );
    utils::BoundaryPlace rightCond = utils::BoundaryPlace(
        elemNum,
        new DerichleBoundaryCondition(10.0)
    );

    Function* u = new Function(8.0, -7.0, 0.0, 7.0);
    
    BarDiscret* linearBar = new BarDiscret(width, elemNum, fe::LINEAR);
    linearBar->addCondition(leftCond);
    linearBar->addCondition(rightCond);

    utils::Matrix* matr = linearBar->getMatrix(u);

    matr->print();

    float* result = solver->solve(matr);

    std::cout<<"========================================================"<<std::endl;
    for(int i=0; i<elemNum+3; i++) {
        std::cout<<result[i]<<std::endl;
    }
    std::cout<<"========================================================"<<std::endl;

    return 0;  
};
