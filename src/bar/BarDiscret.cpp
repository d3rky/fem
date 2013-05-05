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

    std::vector<utils::BoundaryPlace>::iterator condIter = _boundaryConditions.begin();

    for(; condIter != _boundaryConditions.end(); condIter++) {
        std::vector<utils::MatrixElement> condMatr = (*condIter).cond->getMatrix((*condIter).pointNum, _elemNum+1);

        if((*condIter).cond->clearRow()) {
            matrix->clearRow((*condIter).pointNum);
        }

        std::vector<utils::MatrixElement>::iterator matrIter = condMatr.begin();

        for(; matrIter != condMatr.end(); matrIter++) {
            std::cout<<"==================================="<<std::endl;
            std::cout<<" - i "<<(*matrIter).i<<std::endl;
            std::cout<<" - j "<<(*matrIter).j<<std::endl;
            std::cout<<" - value "<<(*matrIter).value<<std::endl;
            std::cout<<"==================================="<<std::endl<<std::endl;
        }

        matrix->add(condMatr);
    }

    return matrix;
};
