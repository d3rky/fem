#ifndef BAR_DISCRET_H

#define BAR_DISCRET_H

#include <vector>

#include "Utils.h"
#include "AbstractFiniteElement.h"
#include "FiniteElementFactory.h"
#include "Function.h"

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
         * @param func коэффициенты уравнения, для которых надо рассчитать
         *
         * @return матрица
         */
        utils::Matrix* getMatrix(Function* func);

        /**
         * Возвратить количество элементов, на которые разбиваем
         *
         * @return
         */
        int getElemNum() const;

        /**
         * Возвратить длину конечного элемента
         *
         * @return
         */
        float getElemLen() const;

    protected:

        /**
         * Граничные условия
         */
        std::vector<utils::BoundaryPlace> _boundaryConditions;

        /**
         * Количество конечных элементов
         */
        const int _elemNum;

        int _elemDim;

        float _elemLen;

        /**
         * Массив конечных элементов
         */
        std::vector<fe::AbstractFiniteElement*> _finiteElements;
};

#endif
