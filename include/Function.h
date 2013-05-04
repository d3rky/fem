#ifndef FUNCTION_H

#define FUNCTION_H

/**
 * @class Контейнер для хранения коэффициентов уравнения
 */
class Function {
  
    public:
        const float a;
        const float b;
        const float c;
        const float d;

        Function(
            const float a,
            const float b,
            const float c,
            const float d
        ) : a(a), b(b), c(c), d(d) {};

};

#endif