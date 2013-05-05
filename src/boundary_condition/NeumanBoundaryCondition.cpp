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

    return matrix;
};
