#include "Life.h"


Life::Life():universe_size(0),generation(0)
{
    //ctor
}

Life::Life(int n):universe_size(n),generation(0)
{
    for(int i=0;i<n;i++)
    {
        universe[i] = new char[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            universe[i][j]='0';
        }
    }
    for(int i=0;i<n;i++)
    {
        buffer[i] = new char[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            buffer[i][j]='0';
        }
    }
}

Life::~Life()
{
    delete []universe;
}

void Life::createUniverse(int n)
{
    this->generation = 0;
    this->universe_size = n;
    for(int i=0;i<n;i++)
    {
        universe[i] = new char[n];
    }
    for(int i=0;i<universe_size;i++)
    {
        for(int j=0;j<universe_size;j++)
        {
            universe[i][j]='0';
        }
    }
        for(int i=0;i<n;i++)
    {
        buffer[i] = new char[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            buffer[i][j]='0';
        }
    }
}

void Life::randomLife()
{
    srand(time(0));
    int n = universe_size*2;
    while(n!=0)
    {
        universe[rand()%universe_size][rand()%universe_size]='1';
        n--;
    }
    generation++;
}

void Life::actionUniverse()
{
    while(true)
    //SetConsoleTextAttribute(hConsole, (WORD) ((Green << 4) | Blue));
    {
    for(int i=0;i<universe_size;i++)
    {
        for(int j=0;j<universe_size;j++)
        {
            if(i!=0 && j!=0 && i!=universe_size-1 && j!=universe_size-1)
            {
                if(universe[i][j]=='1')
                {
                    int counter=0;
                    if(universe[i-1][j-1]=='1') {counter++;}
                    if(universe[i-1][j]=='1') {counter++;}
                    if(universe[i-1][j+1]=='1') {counter++;}
                    if(universe[i][j-1]=='1') {counter++;}
                    if(universe[i][j+1]=='1') {counter++;}
                    if(universe[i+1][j-1]=='1') {counter++;}
                    if(universe[i+1][j]=='1') {counter++;}
                    if(universe[i+1][j+1]=='1') {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j]='0';}
                    else {buffer[i][j]='1';}
                }
                else
                {
                    int counter=0;
                    if(universe[i-1][j-1]=='1') {counter++;}
                    if(universe[i-1][j]=='1') {counter++;}
                    if(universe[i-1][j+1]=='1') {counter++;}
                    if(universe[i][j-1]=='1') {counter++;}
                    if(universe[i][j+1]=='1') {counter++;}
                    if(universe[i+1][j-1]=='1') {counter++;}
                    if(universe[i+1][j]=='1') {counter++;}
                    if(universe[i+1][j+1]=='1') {counter++;}
                    if(counter==3) {buffer[i][j]='1';}
                    else {buffer[i][j]='0';}
                }
            }
            else if(i==0 && j==0)
            {
                if(universe[i][j]=='1')
                {
                    int counter=0;
                    if(universe[i][j+1]=='1') {counter++;}
                    if(universe[i+1][j]=='1') {counter++;}
                    if(universe[i+1][j+1]=='1') {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j]='0';}
                    else {buffer[i][j]='1';}
                }
                else
                {
                    int counter=0;
                    if(universe[i][j+1]=='1') {counter++;}
                    if(universe[i+1][j]=='1') {counter++;}
                    if(universe[i+1][j+1]=='1') {counter++;}
                    if(counter==3) {buffer[i][j]='1';}
                    else {buffer[i][j]='0';}
                }
                }
            else if(i==0 && j==universe_size-1)
            {
            if(universe[i][j]=='1')
                {
                    int counter=0;
                    if(universe[i][j-1]=='1') {counter++;}
                    if(universe[i+1][j]=='1') {counter++;}
                    if(universe[i+1][j-1]=='1') {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j]='0';}
                    else {buffer[i][j]='1';}
                }
                else
                {
                    int counter=0;
                    if(universe[i][j-1]=='1') {counter++;}
                    if(universe[i+1][j]=='1') {counter++;}
                    if(universe[i+1][j-1]=='1') {counter++;}
                    if(counter==3) {buffer[i][j]='1';}
                    else {buffer[i][j]='0';}
                }
            }
            else if(i==universe_size-1 && j==0)
            {
                if(universe[i][j]=='1')
                {
                    int counter=0;
                    if(universe[i][j+1]=='1') {counter++;}
                    if(universe[i-1][j]=='1') {counter++;}
                    if(universe[i-1][j+1]=='1') {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j]='0';}
                    else {buffer[i][j]='1';}
                }
                else
                {
                    int counter=0;
                    if(universe[i][j+1]=='1') {counter++;}
                    if(universe[i-1][j]=='1') {counter++;}
                    if(universe[i-1][j+1]=='1') {counter++;}
                    if(counter==3) {buffer[i][j]='1';}
                    else {buffer[i][j]='0';}
                }
            }
            else if(i==universe_size-1 && j==universe_size-1)
            {
                if(universe[i][j]=='1')
                {
                    int counter=0;
                    if(universe[i][j-1]=='1') {counter++;}
                    if(universe[i-1][j]=='1') {counter++;}
                    if(universe[i-1][j-1]=='1') {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j]='0';}
                    else {buffer[i][j]='1';}
                }
                else
                {
                    int counter=0;
                    if(universe[i][j-1]=='1') {counter++;}
                    if(universe[i-1][j]=='1') {counter++;}
                    if(universe[i-1][j-1]=='1') {counter++;}
                    if(counter==3) {buffer[i][j]='1';}
                    else {buffer[i][j]='0';}
                }
            }
            else if(i==0)
            {
                if(universe[i][j]=='1')
                {
                    int counter = 0;
                    if(universe[i][j-1]=='1') {counter++;}
                    if(universe[i+1][j-1]=='1') {counter++;}
                    if(universe[i+1][j]=='1') {counter++;}
                    if(universe[i+1][j+1]=='1') {counter++;}
                    if(universe[i][j+1]=='1') {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j]='0';}
                    else {buffer[i][j]='1';}
                }
                else
                {
                    int counter = 0;
                    if(universe[i][j-1]=='1') {counter++;}
                    if(universe[i+1][j-1]=='1') {counter++;}
                    if(universe[i+1][j]=='1') {counter++;}
                    if(universe[i+1][j+1]=='1') {counter++;}
                    if(universe[i][j+1]=='1') {counter++;}
                    if(counter==3) {buffer[i][j]='1';}
                    else {buffer[i][j]='0';}
                }
            }
            else if (i==universe_size-1)
            {
                if(universe[i][j]=='1')
                {
                    int counter = 0;
                    if(universe[i][j-1]=='1') {counter++;}
                    if(universe[i-1][j-1]=='1') {counter++;}
                    if(universe[i-1][j]=='1') {counter++;}
                    if(universe[i-1][j+1]=='1') {counter++;}
                    if(universe[i][j+1]=='1') {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j]='0';}
                    else {buffer[i][j]='1';}
                }
                else
                {
                    int counter = 0;
                    if(universe[i][j-1]=='1') {counter++;}
                    if(universe[i-1][j-1]=='1') {counter++;}
                    if(universe[i-1][j]=='1') {counter++;}
                    if(universe[i-1][j+1]=='1') {counter++;}
                    if(universe[i][j+1]=='1') {counter++;}
                    if(counter==3) {buffer[i][j]='1';}
                    else {buffer[i][j]='0';}
                }
            }
            else if(j==0)
            {
                if(universe[i][j]=='1')
                {
                    int counter = 0;
                    if(universe[i-1][j]=='1') {counter++;}
                    if(universe[i-1][j+1]=='1') {counter++;}
                    if(universe[i][j+1]=='1') {counter++;}
                    if(universe[i+1][j+1]=='1') {counter++;}
                    if(universe[i+1][j]=='1') {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j]='0';}
                    else {buffer[i][j]='1';}
                }
                else
                {
                    int counter = 0;
                    if(universe[i-1][j]=='1') {counter++;}
                    if(universe[i-1][j+1]=='1') {counter++;}
                    if(universe[i][j+1]=='1') {counter++;}
                    if(universe[i+1][j+1]=='1') {counter++;}
                    if(universe[i+1][j]=='1') {counter++;}
                    if(counter==3) {buffer[i][j]='1';}
                    else {buffer[i][j]='0';}
                }
            }
            else if(j==universe_size-1)
            {
                if(universe[i][j]=='1')
                {
                    int counter = 0;
                    if(universe[i-1][j]=='1') {counter++;}
                    if(universe[i-1][j-1]=='1') {counter++;}
                    if(universe[i][j-1]=='1') {counter++;}
                    if(universe[i+1][j-1]=='1') {counter++;}
                    if(universe[i+1][j]=='1') {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j]='0';}
                    else {buffer[i][j]='1';}
                }
                else
                {
                    int counter = 0;
                    if(universe[i-1][j]=='1') {counter++;}
                    if(universe[i-1][j-1]=='1') {counter++;}
                    if(universe[i][j-1]=='1') {counter++;}
                    if(universe[i+1][j-1]=='1') {counter++;}
                    if(universe[i+1][j]=='1') {counter++;}
                    if(counter==3) {buffer[i][j]='1';}
                    else {buffer[i][j]='0';}
                }
            }
        }
    }
                    for(int i=0;i<universe_size;i++)
                    {
                        for(int j=0;j<universe_size;j++)
                        {
                            universe[i][j]=buffer[i][j];
                        }
                    }
                    generation++;
                    this->showUniverse();
                    Sleep(1000);
                    system("cls");
                    int endSum=0;
                    for(int i=0;i<universe_size;i++)
                    {
                        for(int j=0;j<universe_size;j++)
                        {
                            if(universe[i][j]=='1')
                            {
                                endSum++;
                            }
                        }
                    }
                    if(endSum==0)
                    {
                        std::cout << "Last generation: " << generation-1;
                        break;
                    }
    }
    }
char** Life::getPtr()
{
    return universe;
}

void Life::showUniverse()
{
    SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | LightGray));
    std::cout << "Generation: " << generation << std::endl;
    for(int i=0;i<universe_size;i++)
    {
        for(int j=0;j<universe_size;j++)
        {
            if(universe[i][j]=='0')
            {
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | DarkGray));
                std::cout << universe[i][j];
            }
            if(universe[i][j]=='1')
            {
                SetConsoleTextAttribute(hConsole, (WORD) ((Black << 4) | White));
            std::cout << universe[i][j];
            }

        }
        std::cout << "\n";
    }
}
