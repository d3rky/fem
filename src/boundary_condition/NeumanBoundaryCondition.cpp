#include "../../include/NeumanBoundaryCondition.h"
#include "../../include/Utils.h"

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
NeumanBoundaryCondition::NeumanBoundaryCondition(const float value)
: AbstractBoundaryCondition(value, false) {
    ;  
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
std::vector<utils::MatrixElement> NeumanBoundaryCondition::getMatrix(
    const int pointNum,
    const int numOfPoints,
    Function* func
) {
    std::vector<utils::MatrixElement> matrix;

    return matrix;
};
