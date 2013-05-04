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
std::vector<utils::MatrixElement> LinearFiniteElement::getMatrixElement() {
    std::vector<utils::MatrixElement> matrix;

    return matrix;  
};
