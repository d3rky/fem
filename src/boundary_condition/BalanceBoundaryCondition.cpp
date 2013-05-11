#include "../../include/BalanceBoundaryCondition.h"
#include "../../include/Utils.h"

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
BalanceBoundaryCondition::BalanceBoundaryCondition()
: AbstractBoundaryCondition(0.0, true) {
    ;  
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
std::vector<utils::MatrixElement> BalanceBoundaryCondition::getMatrix(
    const int pointNum,
    const int numOfPoints,
    Function* func
) {
    std::vector<utils::MatrixElement> matrix;

    return matrix;
};
