#include <iostream>
#include "COne.h"
#include "CTwo.h"
#include "CThree.h"
#include "CFour.h"
using namespace std;

void printAll(CTwo *p[],int n)
{
    for(int i=0;i<n;i++)
    {
    p[i]->print();
    }
}


int main()
{
    COne object1(15,"OBJECT1");
    CTwo object2("OBJECT2",object1);
    CThree object3("OBJECT3",object1,25);
    CFour object4("OBJECT4",object1,35,1);
    int n=3;
    CTwo *p[n];
    p[0]=&object2;
    p[1]=&object3;
    p[2]=&object4;
    printAll(p,n);


/*  CTwo *pointer = new CTwo;
    pointer = &object2;
    pointer->print();

    pointer = &object3;
    pointer->print();

    pointer = &object4;
    pointer->print();
*/

    return 0;
}
