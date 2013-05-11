#include "../../include/FiniteElementFactory.h"
#include "../../include/LinearFiniteElement.h"
#include "../../include/CubicFiniteElement.h"

using namespace fe;

////////////////////////////////////////////////////////////////////////////////
/**
 * constructors
 */
FiniteElementFactory::FiniteElementFactory() {
    ;
};

////////////////////////////////////////////////////////////////////////////////
/**
 * public functions
 */
AbstractFiniteElement* FiniteElementFactory::createFiniteElement(
    FiniteType type,
    const float len, 
    const int pointFrom,
    const int pointTo
) {
    switch(type) {
        case LINEAR:
            return (new LinearFiniteElement(len, pointFrom, pointTo));
            break;
        case CUBIC:
            return (new CubicFiniteElement(len, pointFrom, pointTo));
            break;
        default:
            throw "Non valid finite element type.";
    }
};
