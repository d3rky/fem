#include "../../include/AbstractFiniteElement.h"

using namespace fe;

////////////////////////////////////////////////////////////////////////////////
// constructors

AbstractFiniteElement::AbstractFiniteElement(
    const float len,
    const int pointNumFrom,
    const int pointNumTo
) : _len(len), _pointNumFrom(pointNumFrom), _pointNumTo(pointNumTo) {
    _num = _pointNumFrom;
};
