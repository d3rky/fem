#ifndef UTILS_H

#define UTILS_H

#include <vector>
#include <iostream>

class AbstractBoundaryCondition;

namespace utils {

////////////////////////////////////////////////////////////////////////////////
/**
 * @enum Направление вектора вдоль оси
 */
enum Direction {
    POSITIVE=1,
    NEGATIVE=-1
};


////////////////////////////////////////////////////////////////////////////////
/**
 * @struct Структура для составляющей части матрицы 
 */
struct MatrixElement {
    int i;
    int j;
    float value;
    MatrixElement(int i, int j, float value) : i(i), j(j), value(value) {};
};


////////////////////////////////////////////////////////////////////////////////
/**
 * @class Матрица
 */
class Matrix {

    public:

        /**
         * @constructor
         *
         * @param width {const int}
         * @param height {const int}
         */
        Matrix(const int width, const int height);

        ~Matrix();

        /**
         * Добавить элемент в матрицу
         *
         * @param {MatrixElement}
         */
        void add(MatrixElement);
        /**
         * Добавить несколько элементов в матрицу
         *
         * @param {vector<MatrixElement>}
         */
        void add(std::vector<MatrixElement>);

        /**
         * Очистить строчку
         *
         * @param rowNum номер строки(нумерация с 0)
         */
        void clearRow(const int rowNum);

        /**
         * @return {float**}
         */
        float** getMatrix() const;
        /**
         * @return {float*}
         */
        float* getB() const;

        /**
         * @return {int}
         */
        int getWidth() const;
        /**
         * @return {int}
         */
        int getHeight() const;

        /**
         */
        void print(std::ostream& stream=std::cout);

    private:
        /**
         * Матрица элементов
         */
        float** _matrix;
        /**
         * Матрица правых частей
         */
        float* _b;

        /**
         * Размерность матрицы
         */
        const int _width;
        const int _height;
};

////////////////////////////////////////////////////////////////////////////////

/**
 * @struct связываем точку и привязанную к ней граничное условие
 */
struct BoundaryPlace {
    int pointNum;
    AbstractBoundaryCondition* cond;

    BoundaryPlace(int pointNum, AbstractBoundaryCondition* cond) 
    : pointNum(pointNum), cond(cond) {
        ;
    };
};


}; //end namespace utils

#endif
