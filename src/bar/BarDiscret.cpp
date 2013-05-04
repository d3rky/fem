#include "../../include/BarDiscret.h"
#include "../../include/FiniteElementFactory.h"

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */

BarDiscret::BarDiscret(
    const float width, 
    const int elemNum,
    fe::FiniteType type
) : _elemNum(elemNum) {
    float elemLen = width/elemNum;
    fe::FiniteElementFactory* elemFactory = new fe::FiniteElementFactory();

    for(int i=0; i<elemNum; i++) {
        _finiteElements.push_back(
            elemFactory->createFiniteElement(
                type,
                elemLen,
                i,
                i+1
            )
        );
    }
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
