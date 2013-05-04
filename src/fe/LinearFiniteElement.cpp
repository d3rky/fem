#include "../../include/LinearFiniteElement.h"

using namespace fe;

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
LinearFiniteElement::LinearFiniteElement(
    const float len,
    const int pointNumFrom,
    const int pointNumTo
) : AbstractFiniteElement(len, pointNumFrom, pointNumTo) {
    ;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
std::vector<utils::MatrixElement> LinearFiniteElement::getMatrixElement(Function* func) {
    std::vector<utils::MatrixElement> matrix;
    utils::MatrixElement elem = utils::MatrixElement(
        _pointNumFrom, 
        _pointNumFrom,
        - func->a/_len - func->b/2.0 + func->c*_len/3.0
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        _pointNumFrom,
        _pointNumTo,
        func->a/_len + func->b/2.0 + func->c*_len/6.0
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        _pointNumTo,
        _pointNumFrom,
        func->a/_len - func->b/2.0 + func->c*_len/6.0
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        _pointNumTo,
        _pointNumTo,
        - func->a/_len + func->b/2.0 + func->c*_len/6.0
    );
    matrix.push_back(elem);

    return matrix;  
};
