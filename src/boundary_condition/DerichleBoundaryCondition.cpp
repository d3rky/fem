#include "../../include/DerichleBoundaryCondition.h"
#include "../../include/Utils.h"

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
DerichleBoundaryCondition::DerichleBoundaryCondition(const float value)
: AbstractBoundaryCondition(value) {
    ;  
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
std::vector<utils::MatrixElement> DerichleBoundaryCondition::getMatrix(const int pointNum) {
    std::vector<utils::MatrixElement> matrix;
    utils::MatrixElement elem = utils::MatrixElement(pointNum, pointNum, 1.0);

    matrix.push_back(elem);

    elem = utils::MatrixElement(-1, pointNum, getValue());
    matrix.push_back(elem);

    return matrix;
};
