#ifndef FINITEELEMENTFACTORY_H

#define FINITEELEMENTFACTORY_H

#include "AbstractFiniteElement.h"

namespace fe {
 
/**
 * @enum тип конечного элемента
 */ 
enum FiniteType {
    LINEAR,
    CUBIC
};

/**
 * @class Фабрика конечных элементов
 */
class FiniteElementFactory {
    
    public:

        /**
         * @constructor
         */
        FiniteElementFactory();

        /**
         * Создать конечный элемент определенного типа
         *
         * @param type тип конечного элемента
         * @param len длина конечного элемента
         * @param pointFrom точка
         * @param pointTo точка
         *
         * @return конечный элемент
         */
        AbstractFiniteElement* createFinititeElement(
            FiniteType type,
            const float len, 
            const int pointFrom,
            const int pointTo
        );

};

}; //finite elements workspace

#endif