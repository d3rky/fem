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

utils::Matrix* BarDiscret::getMatrix(Function* func) {
    utils::Matrix* matrix = new utils::Matrix(_elemNum+3, _elemNum+3);

    std::vector<utils::MatrixElement> finiteElem;

    std::vector<fe::AbstractFiniteElement*>::iterator iter = _finiteElements.begin();

    for(; iter != _finiteElements.end(); iter++) {
        finiteElem = (*iter)->getMatrixElement(func);

        matrix->add(finiteElem);
    }

    return matrix;
};
