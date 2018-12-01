#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Life.h"
using namespace std;


int main()
{
    //SetConsoleTextAttribute(hConsole, (WORD) ((Blue << 4) | Blue));

    Life game(28);
    game.randomLife();
    game.showUniverse();
    Sleep(1000);
    system("cls");
    //while(true)
    //{
    game.actionUniverse();
    //game.showUniverse();
    //Sleep(1000);
    //system("cls");
    //}


    //SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
    return 0;
}
