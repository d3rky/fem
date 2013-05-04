#ifndef ABSTRACTFINITEELEMENT_H

#define ABSTRACTFINITEELEMENT_H

#include <vector>

#include "Utils.h"
#include "AbstractBoundaryCondition.h"

class BarDiscret;

namespace fe {

/**
 * @class Абстрактный класс для конечных элементов
 */
class AbstractFiniteElement {
    
    protected:

        /**
         * длина конечного элемента
         */
        const float _len;

        /**
         * Номера точек, между которыми находится конечный элемент
         */
        const int _pointNumFrom;
        const int _pointNumTo;

        /**
         * номер элемента
         */
        int _num;


    public:

        /**
         * @constructor
         *
         * @param len длина элемента
         * @param pointNumFrom 
         * @param pointNumTo какие номера точек связывает
         */
        AbstractFiniteElement(
            const float len, 
            const int pointNumFrom, 
            const int pointNumTo
        );

        virtual std::vector<utils::MatrixElement> getMatrixElement()=0;
};

}; //fe namespace

#endif
