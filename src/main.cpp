#include <iostream>

#include "../include/Function.h"
#include "../include/DerichleBoundaryCondition.h"
#include "../include/FiniteElementFactory.h"
#include "../include/BarDiscret.h"

int main(int argc, char** argv) {
    
    const float width = 7.0;
    const int elemNum = 20;

    DerichleBoundaryCondition* leftCond = new DerichleBoundaryCondition(5.0);
    DerichleBoundaryCondition* rightCond = new DerichleBoundaryCondition(10.0);

    Function* u = new Function(8.0, -7.0, 0.0, 7.0);
    
    BarDiscret* linearBar = new BarDiscret(width, elemNum, fe::LINEAR);

    return 0;  
};
