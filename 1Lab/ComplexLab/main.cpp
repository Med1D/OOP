#include <iostream>
#include <stdio.h>
#include "Complex.h"

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");
    float im1,im2,re1,re2;
    printf("������ ����� � ��������� ����������!\n");
    printf("������� ������ ����������� �����: ");
    scanf("%f %f",&re1,&im1);
    Complex *number1 = new Complex;
    number1->Complex_set(re1,im1);

    fflush(stdin);
    printf("������� ������ ����������� �����: ");
    scanf("%f %f",&re2,&im2);
    Complex *number2 = new Complex;
    number2->Complex_set(re2,im2);

    //------------------PLUS
    printf("---------------------------------\n");
    printf("�������� ��������: ");
    number1->Plus(number2);
    number1->print();
    printf("\n---------------------------------\n");
    //------------------

    //------------------MULTIPLY
    printf("---------------------------------\n");
    printf("�������� ���������: ");
    number1->Multiply(number2);
    number1->print();
    printf("\n---------------------------------\n");
    //------------------

    //------------------MINUS
    printf("---------------------------------\n");
    printf("�������� ���������: ");
    number1->Minus(number2);
    number1->print();
    printf("\n---------------------------------\n");
    //------------------

    //------------------DIVIDE
    printf("---------------------------------\n");
    printf("�������� �������: ");
    number1->Divide(number2);
    number1->print();
    printf("\n---------------------------------\n");
    //------------------
number1->~Complex();
number2->~Complex();
    return 0;
}
