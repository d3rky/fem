#include "../../include/BalanceBoundaryCondition.h"
#include "../../include/Utils.h"

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
BalanceBoundaryCondition::BalanceBoundaryCondition()
: AbstractBoundaryCondition(0.0, false) {
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
    int duPointNum = (pointNum == numOfPoints ? numOfPoints+2 : numOfPoints+1);

    utils::MatrixElement elem = utils::MatrixElement(
        pointNum,
        duPointNum,
        1
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        duPointNum,
        pointNum,
        -1
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        duPointNum,
        duPointNum,
        1
    );
    matrix.push_back(elem);

    return matrix;
};
