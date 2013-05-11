#include <iostream>
#include <fstream>

#include "../include/Function.h"

#include "../include/DerichleBoundaryCondition.h"
#include "../include/NeumanBoundaryCondition.h"
#include "../include/BalanceBoundaryCondition.h"

#include "../include/FiniteElementFactory.h"
#include "../include/BarDiscret.h"
#include "../include/Utils.h"
#include "../include/GaussSeidel.h"


void solve(const float width, const int elemNum, const float eps, fe::FiniteType finiteType) {
    char* fileName;

    switch(finiteType) {
        case fe::LINEAR:
            fileName = "build/linear.output";
            break;
        case fe::CUBIC:
            fileName = "build/cubic.output";
            break;
    };

    std::ofstream output(fileName, std::ios::trunc | std::ios::out);

    Solver* solver = new GaussSeidel(eps);

    utils::BoundaryPlace leftCond = utils::BoundaryPlace(
        0,
        new DerichleBoundaryCondition(5.0)
    );
    utils::BoundaryPlace rightCond = utils::BoundaryPlace(
        elemNum*finiteType,
        new DerichleBoundaryCondition(10.0)
    );

    Function* u = new Function(8.0, -3.0, 0.0, 7.0);
    
    BarDiscret* linearBar = new BarDiscret(width, elemNum, finiteType);
    linearBar->addCondition(leftCond);
    linearBar->addCondition(rightCond);

    utils::Matrix* matr = linearBar->getMatrix(u);

    //matr->print();

    float* result = solver->solve(matr);

    std::cout<<"========================================================"<<std::endl;
    float x = 0.0;
    for(int i=0; i<elemNum*finiteType+3; i++) {
        output<<x/finiteType<<"\t"<<result[i]<<std::endl;
        std::cout<<result[i]<<std::endl;

        x+=linearBar->getElemLen();
    }
    std::cout<<"========================================================"<<std::endl;
};

int main(int argc, char** argv) {
    
    const float width = 7.0;
    const int elemNum = 7;
    const float eps = 1E-6;

    //solve linear finite elements
    std::cout<<"////////////////////////////////////////////////////////////////"<<std::endl;
    std::cout<<" LINEAR FINITE ELEMENTS"<<std::endl;
    solve(width, elemNum, eps, fe::LINEAR);
    std::cout<<"////////////////////////////////////////////////////////////////"<<std::endl;

    std::cout<<"////////////////////////////////////////////////////////////////"<<std::endl;
    std::cout<<" CUBIC FINITE ELEMENTS"<<std::endl;
    solve(width, elemNum, eps, fe::CUBIC);
    std::cout<<"////////////////////////////////////////////////////////////////"<<std::endl;

    return 0;  
};
