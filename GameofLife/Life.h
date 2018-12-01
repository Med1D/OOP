#ifndef LIFE_H
#define LIFE_H
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>
class Life
{
    public:
        Life();
        Life(int n);
        virtual ~Life();
        void createUniverse(int n);
        void randomLife();
        void actionUniverse();
        char **getPtr();
        void showUniverse();
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
    };



    protected:

    private:
        int universe_size;
        int generation = 0;
        char **universe = new char*[universe_size];
        char **buffer = new char*[universe_size];
};

#endif // LIFE_H
