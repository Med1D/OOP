#include <iostream>
#include <stdio.h>
#include "COne.h"
#include "CTwo.h"
#include "CThree.h"
using namespace std;

int main()
{
    COne object1;
    object1.Set_l(33);
    object1.Set_s("CLASS COne");

    CTwo object2;
    object2.Set_obj(object1);
    object2.Set_s("CLASS CTwo");

    CThree object3_0;
    object3_0.print();
    std::cout << std::endl;
    CThree object3("STROKA",object1,23);
    object3.print();
    std::cout << std::endl;
    CThree object3_1(object3);
    object3_1.print();

    return 0;
}
