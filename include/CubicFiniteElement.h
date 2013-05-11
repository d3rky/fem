#ifndef CUBICFINITEELEMENT_H

#define CUBICFINITEELEMENT_H

#include "AbstractFiniteElement.h"

namespace fe {

class CubicFiniteElement: public AbstractFiniteElement {
    
    public:
        /**
         * @constructor
         *
         * @param len длина элемента
         * @param pointNumFrom
         * @param pointNumTo какие точки элемент соединяет
         */
        CubicFiniteElement(
            const float len,
            const int pointNumFrom,
            const int pointNumTo
        );

        /**
         * Возвращаем часть матрицы для данного конечного элемента
         *
         * @param func коэффициенты функций, для которых применяется это уравнение
         *
         * @return часть матрицы
         */
        virtual std::vector<utils::MatrixElement> getMatrixElement(Function* func);

    protected:
        const int dim;

};

}; //fe namespace

#endif
