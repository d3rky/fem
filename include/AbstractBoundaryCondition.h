#ifndef ABSTRACTBOUNDARYCONDITION_H

#define ABSTRACTBOUNDARYCONDITION_H

#include <vector>

#include "Utils.h"
#include "Function.h"

/**
 * @class Абстрактный класс для граничных условий
 */
class AbstractBoundaryCondition {
    
    public:
        AbstractBoundaryCondition(const float value, const bool mustClear) 
        : _value(value), _mustClear(mustClear) {};

        float getValue() const { return _value; };

        bool clearRow() const {return _mustClear; };

        virtual std::vector<utils::MatrixElement> getMatrix(
            const int pointNum,
            const int numOfPoints=0,
            Function* func=0
        )=0;

    protected:

        const float _value;

        const bool _mustClear;
};

#endif
