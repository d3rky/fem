#ifndef BAR_DISCRET_H

#define BAR_DISCRET_H

#include <vector>

#include "Utils.h"
#include "AbstractFiniteElement.h"
#include "FiniteElementFactory.h"

class BarDiscret {
    
    public:

        /**
         * @constructor
         *
         * @param width длина стержня
         * @param elemNum количество конечныъ элементов
         * @param type тип конечного элемента
         */
        BarDiscret(const float width, const int elemNum, fe::FiniteType type);

        /**
         * Добавить граничное условие
         *
         * @param граничное условие с привязкой к месту
         */
        void addCondition(utils::BoundaryPlace bound);

        /**
         * Рассчитать матрицу конечных элементов
         *
         * @return матрица
         */
        utils::Matrix* getMatrix();

        /**
         * Возвратить количество элементов, на которые разбиваем
         *
         * @return
         */
        int getElemNum() const;

    protected:

        /**
         * Граничные условия
         */
        std::vector<utils::BoundaryPlace> _boundaryConditions;

        /**
         * Количество конечных элементов
         */
        const int _elemNum;

        /**
         * Массив конечных элементов
         */
        std::vector<fe::AbstractFiniteElement*> _finiteElements;
};

#endif
