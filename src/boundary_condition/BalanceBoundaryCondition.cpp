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
    const int numOfPoints
) {
    std::vector<utils::MatrixElement> matrix;
    int realPointNum = (pointNum == numOfPoints-1 ? numOfPoints+1 : numOfPoints);

    utils::MatrixElement elem = utils::MatrixElement(
        pointNum,
        realPointNum,
        1
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        realPointNum,
        realPointNum,
        1
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        -1,
        realPointNum,
        getValue()
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        pointNum,
        pointNum,
        1
    );
    matrix.push_back(elem);

    return matrix;
};
