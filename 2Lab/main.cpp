#include <iostream>
#include <stdio.h>
#include "COne.h"
#include "CTwo.h"
using namespace std;

int main()
{
    COne object1;
    object1.Set_l(15);
    object1.Set_s("hello!");
    object1.print();

    CTwo object2("Oh, hello there!",object1);
    object2.print();

    object2.Set_s("NEW STRING");
    COne object3(25,"OBJECT3");
    object2.Set_obj(object3);
    object2.print();

    return 0;
}
