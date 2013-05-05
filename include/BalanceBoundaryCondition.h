#ifndef BALANCEBOUNDARYCONDITION_H

#define NEUMANBOUNDARYCONDITION_H

#include "AbstractBoundaryCondition.h"

/**
 * @class граничные условия 3-ого рода
 */
class BalanceBoundaryCondition : public AbstractBoundaryCondition {
    
    public:
        NeumanBoundaryCondition();

        virtual std::vector<utils::MatrixElement> getMatrix(
            const int pointNum,
            const int numOfPoints=0
        );

};

#endif
