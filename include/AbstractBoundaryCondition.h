#ifndef ABSTRACTBOUNDARYCONDITION_H

#define ABSTRACTBOUNDARYCONDITION_H

#include <vector>

#include "Utils.h"

/**
 * @class Абстрактный класс для граничных условий
 */
class AbstractBoundaryCondition {
    
    public:
        AbstractBoundaryCondition(const float value) : _value(value) {};

        float getValue() const { return _value; };

        virtual std::vector<utils::MatrixElement> getMatrix(const int pointNum)=0;

    protected:

        const float _value;
};

#endif
