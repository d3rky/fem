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

        std::vector<utils::MatrixElement>::iterator matIter = finiteElem.begin();

        std::cout<<"============================================================"<<std::endl<<std::endl;
        for(; matIter != finiteElem.end(); matIter++) {
            std::cout<<"////////////////////////////////////////////////////////"<<std::endl;
            std::cout<<" - i "<<(*matIter).i<<std::endl;
            std::cout<<" - j "<<(*matIter).j<<std::endl;
            std::cout<<" - value "<<(*matIter).value<<std::endl;
            std::cout<<"////////////////////////////////////////////////////////"<<std::endl;
        }
        std::cout<<"============================================================"<<std::endl<<std::endl;

        matrix->add(finiteElem);
    }

    std::vector<utils::BoundaryPlace>::iterator condIter = _boundaryConditions.begin();

    for(; condIter != _boundaryConditions.end(); condIter++) {
        std::vector<utils::MatrixElement> condMatr = (*condIter).cond->getMatrix((*condIter).pointNum, _elemNum+1);

        if((*condIter).cond->clearRow()) {
            matrix->clearRow((*condIter).pointNum);
        }

        std::vector<utils::MatrixElement>::iterator matrIter = condMatr.begin();

        matrix->add(condMatr);
    }

    return matrix;
};
