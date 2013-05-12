#include "../../include/CubicFiniteElement.h"

using namespace fe;

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
CubicFiniteElement::CubicFiniteElement(
    const float len,
    const int pointNumFrom,
    const int pointNumTo
) : AbstractFiniteElement(len, pointNumFrom, pointNumTo), dim(3) {
    ;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
std::vector<utils::MatrixElement> CubicFiniteElement::getMatrixElement(Function* func) {
    std::vector<utils::MatrixElement> matrix;

    //0 0
    utils::MatrixElement elem = utils::MatrixElement(
        _pointNumFrom*dim, 
        _pointNumFrom*dim,
        func->a*3.7/_len - func->b*(-0.5) - func->c*0.0762*_len
    );
    matrix.push_back(elem);

    //0 1
    elem = utils::MatrixElement(
        _pointNumFrom*dim,
        _pointNumFrom*dim+1,
        func->a*(-4.725)/_len - func->b*0.7125 - func->c*0.0589*_len
    );
    matrix.push_back(elem);

    //0 2
    elem = utils::MatrixElement(
        _pointNumFrom*dim,
        _pointNumFrom*dim+2,
        func->a*1.35/_len - func->b*(-0.3) - func->c*(-0.0214)*_len
    );
    matrix.push_back(elem);

    //0 3
    elem = utils::MatrixElement(
        _pointNumFrom*dim,
        _pointNumTo*dim,
        func->a*(-0.325)/_len - func->b*0.0875 - func->c*0.0113*_len
    );
    matrix.push_back(elem);

    //1 0
    elem = utils::MatrixElement(
        _pointNumFrom*dim+1,
        _pointNumFrom*dim,
        func->a*(-4.725)/_len - func->b*(-0.7125) - func->c*0.0589*_len
    );
    matrix.push_back(elem);

    //1 1
    elem = utils::MatrixElement(
        _pointNumFrom*dim+1,
        _pointNumFrom*dim+1,
        func->a*10.8/_len - func->c*0.386*_len
    );
    matrix.push_back(elem);

    //1 2
    elem = utils::MatrixElement(
        _pointNumFrom*dim+1,
        _pointNumFrom*dim+2,
        func->a*(-7.425)/_len - func->b*1.012 - func->c*(-0.0482)*_len
    );
    matrix.push_back(elem);

    //1 3
    elem = utils::MatrixElement(
        _pointNumFrom*dim+1,
        _pointNumTo*dim,
        func->a*1.35/_len - func->b*(-0.3) - func->c*(-0.0214)*_len
    );
    matrix.push_back(elem);

    //2 0
    elem = utils::MatrixElement(
        _pointNumFrom*dim+2,
        _pointNumFrom*dim,
        func->a*1.35/_len - func->b*0.3 - func->c*(-0.0214)*_len
    );
    matrix.push_back(elem);

    //2 1
    elem = utils::MatrixElement(
        _pointNumFrom*dim+2,
        _pointNumFrom*dim+1,
        func->a*(-7.425)/_len - func->b*(-1.012) - func->c*(-0.0482)*_len
    );
    matrix.push_back(elem);

    //2 2
    elem = utils::MatrixElement(
        _pointNumFrom*dim+2,
        _pointNumFrom*dim+2,
        func->a*10.8/_len - func->c*0.386*_len
    );
    matrix.push_back(elem);

    //2 3
    elem = utils::MatrixElement(
        _pointNumFrom*dim+2,
        _pointNumTo*dim,
        func->a*(-4.725)/_len - func->b*0.7125 - func->c*0.0589*_len
    );
    matrix.push_back(elem);

    //3 0
    elem = utils::MatrixElement(
        _pointNumTo*dim,
        _pointNumFrom*dim,
        func->a*(-0.325)/_len - func->b*(-0.0875) - func->c*0.0113*_len
    );
    matrix.push_back(elem);

    //3 1
    elem = utils::MatrixElement(
        _pointNumTo*dim,
        _pointNumFrom*dim+1,
        func->a*1.35/_len - func->b*0.3 - func->c*(-0.0214)*_len
    );
    matrix.push_back(elem);

    //3 2
    elem = utils::MatrixElement(
        _pointNumTo*dim,
        _pointNumFrom*dim+2,
        func->a*(-4.725)/_len - func->b*(-0.7125) - func->c*(0.0589)*_len
    );
    matrix.push_back(elem);

    //3 3
    elem = utils::MatrixElement(
        _pointNumTo*dim,
        _pointNumTo*dim,
        func->a*3.7/_len - func->b*0.5 - func->c*0.0762*_len
    );
    matrix.push_back(elem);

    //B
    elem = utils::MatrixElement(
        -1,
        _pointNumFrom*dim,
        func->d*0.125*_len
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        -1,
        _pointNumFrom*dim+1,
        func->d*0.375*_len
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        -1,
        _pointNumFrom*dim+2,
        func->d*0.375*_len
    );
    matrix.push_back(elem);

    elem = utils::MatrixElement(
        -1,
        _pointNumTo*dim,
        func->d*0.125*_len
    );
    matrix.push_back(elem);

    return matrix;  
};
