#ifndef COMPLEX_H
#define COMPLEX_H


class Complex
{
    public:
        Complex();
        Complex(const Complex &other);
        virtual ~Complex();
        void Complex_set(float x, float y);
        void Plus(Complex *x);
        void Multiply(Complex *x);
        void Minus(Complex *x);
        void Divide(Complex *x);
        void print();

    private:
        float re;
        float im;
};

#endif // COMPLEX_H
