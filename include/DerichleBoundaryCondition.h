#ifndef DERICHLEBONDARYCONDITION_H

#define DERICHLEBOUNDARYCONDITION_H

#include "AbstractBoundaryCondition.h"

/**
 * @class граничные условия 1-ого рода
 */
class DerichleBoundaryCondition : public AbstractBoundaryCondition {
    
    public:
        DerichleBoundaryCondition(const float value);

        virtual std::vector<utils::MatrixElement> getMatrix(const int pointNum);

};

#endif