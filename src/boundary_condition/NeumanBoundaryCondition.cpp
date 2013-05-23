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
    int duPointNum = (pointNum == numOfPoints ? numOfPoints+2 : numOfPoints+1);

    utils::MatrixElement elem = utils::MatrixElement(
        pointNum,
        duPointNum,
        1
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        duPointNum,
        duPointNum,
        1
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        -1,
        duPointNum,
        getValue()*func->a
    );
    matrix.push_back(elem);

    return matrix;
};
