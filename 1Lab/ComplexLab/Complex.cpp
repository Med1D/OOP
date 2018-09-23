#include "Complex.h"
#include <stdio.h>
Complex::Complex()
{

}

Complex::~Complex()
{

}
void Complex::Complex_set(float x, float y)
{
    Complex::re=x;
    Complex::im=y;
}

void Complex::Plus(Complex *x)
{
    this->re+=x->re;
    this->im+=x->im;
}

void Complex::Multiply(Complex *x)
{
    float result_re=this->re*x->re-(this->im*x->im);
    float result_im=this->re*x->im+this->im*x->re;
    this->re=result_re;
    this->im=result_im;
}

void Complex::Minus(Complex *x)
{
    this->re-=x->re;
    this->im-=x->im;
}

void Complex::Divide(Complex *x)
{
    float re_chisl=this->re*x->re+this->im*x->im;
    float im_chisl=this->re*(-x->im)+this->im*x->re;
    this->re=re_chisl/((x->re*x->re)+(x->im*x->im));
    this->im=im_chisl/((x->re*x->re)+(x->im*x->im));
}





void Complex::print()
{
    printf("%0.1f%+0.1fi",this->re,this->im);
}
