#ifndef NEUMANBONDARYCONDITION_H

#define NEUMANBOUNDARYCONDITION_H

#include "AbstractBoundaryCondition.h"

/**
 * @class граничные условия 1-ого рода
 */
class NeumanBoundaryCondition : public AbstractBoundaryCondition {
    
    public:
        NeumanBoundaryCondition(const float value);

        virtual std::vector<utils::MatrixElement> getMatrix(
            const int pointNum,
            const int numOfPoints=0
        );

};

#endif
