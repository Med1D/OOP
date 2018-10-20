#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> obj1;


    for (int i=0;i<5;i++)
    {
        obj1.push(i);
    }
    obj1.printStack();
    cout << endl;
    for( int i=0;i<2;i++)
    {
        obj1.pop();
    }
    cout << endl;
    obj1.printStack();
    return 0;
}
