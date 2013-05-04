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
         * @param width {const int} длина стержня
         * @param elemNum {const int} количество конечныъ элементов
         * @param type {fe::FiniteType} тип конечного элемента
         */
        BarDiscret(const int width, const int elemNum, fe::FiniteType type);

        /**
         * Добавить граничное условие
         *
         * @param {utils::BoundaryPlace} граничное условие с привязкой к месту
         */
        void addCondition(utils::BoundaryPlace bound);

        /**
         * Рассчитать матрицу конечных элементов
         *
         * @return {utils::Matrix*} матрица
         */
        utils::Matrix* getMatrix();

        /**
         * Возвратить количество элементов, на которые разбиваем
         *
         * @return {int}
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
        std::vector<fe::AbstractFiniteElement*> finiteElements;
};

#endif
