#include "../../include/BarDiscret.h"

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */

BarDiscret::BarDiscret(
    const int width, 
    const int elemNum,
    fe::FiniteType type
) : _elemNum(elemNum) {
    ;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */

int BarDiscret::getElemNum() const {
    return _elemNum;
};

void BarDiscret::addCondition(utils::BoundaryPlace bound) {
    _boundaryConditions.push_back(bound);
};

utils::Matrix* BarDiscret::getMatrix() {
    utils::Matrix* matrix = new utils::Matrix(_elemNum+1, _elemNum+1);

    return matrix;
};
