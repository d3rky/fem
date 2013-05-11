#include <iostream>

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

    _elemLen = width/elemNum;
    _elemDim = type;

    fe::FiniteElementFactory* elemFactory = new fe::FiniteElementFactory();

    for(int i=0; i<elemNum; i++) {
        _finiteElements.push_back(
            elemFactory->createFiniteElement(
                type,
                _elemLen,
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

float BarDiscret::getElemLen() const {
    return _elemLen;
};

void BarDiscret::addCondition(utils::BoundaryPlace bound) {
    _boundaryConditions.push_back(bound);
};

utils::Matrix* BarDiscret::getMatrix(Function* func) {
    utils::Matrix* matrix = new utils::Matrix(_elemNum*_elemDim+3, _elemNum*_elemDim+3);

    std::vector<utils::MatrixElement> finiteElem;

    std::vector<fe::AbstractFiniteElement*>::iterator iter = _finiteElements.begin();

    for(; iter != _finiteElements.end(); iter++) {
        finiteElem = (*iter)->getMatrixElement(func);

        matrix->add(finiteElem);
    }

    std::vector<utils::BoundaryPlace>::iterator condIter = _boundaryConditions.begin();

    for(; condIter != _boundaryConditions.end(); condIter++) {
        std::vector<utils::MatrixElement> condMatr = (*condIter).cond->getMatrix((*condIter).pointNum, _elemNum*_elemDim, func);

        if((*condIter).cond->clearRow()) {
            matrix->clearRow((*condIter).pointNum);
        }

        matrix->add(condMatr);
    }

    return matrix;
};
