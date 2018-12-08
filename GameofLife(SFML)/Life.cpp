#include "Life.h"

Life::Life():universe_size(0),cell_size(0)
{
    //ctor
}

Life::Life(int n, int CellSize):universe_size(n),cell_size(CellSize)
{
    for(int i=0;i<n/CellSize;i++)
    {
        universe[i] = new sf::Sprite[n];
    }
    for(int i=0;i<n/CellSize;i++)
    {
        for(int j=0;j<n/CellSize;j++)
        {
            universe[i][j].setTexture(texture);
            universe[i][j].setColor(sf::Color(0,0,0));
            universe[i][j].setTextureRect(sf::IntRect(0,0,CellSize,CellSize));
            std::cout << i << " " << j << " ";
        }
    }
    std::cout << "END";
    for(int i=0;i<n/CellSize;i++)
    {
        buffer[i] = new sf::Sprite[n];
    }
    for(int i=0;i<n/CellSize;i++)
    {
        for(int j=0;j<n/CellSize;j++)
        {
            buffer[i][j].setTexture(texture);
            buffer[i][j].setColor(sf::Color(0,0,0));
            buffer[i][j].setTextureRect(sf::IntRect(0,0,CellSize,CellSize));
        }
    }
    std::cout << "END2";
}

Life::~Life()
{
    delete []universe;
    delete []buffer;
}

void Life::randomLife()
{
    srand(time(0));
    int n = universe_size*50;
    while(n!=0)
    {
        universe[rand()%universe_size/cell_size][rand()%universe_size/cell_size].setColor(sf::Color(50,205,50));
        n--;
    }
    std::cout << "RANDOM";
}

void Life::actionUniverse()
{
    for(int i=0;i<universe_size/cell_size;i++)
    {
        for(int j=0;j<universe_size/cell_size;j++)
        {
            if(i!=0 && j!=0 && i!=universe_size/cell_size-1 && j!=universe_size/cell_size-1)
            {
                if(universe[i][j].getColor()==sf::Color(50,205,50))
                {
                    int counter=0;
                    if(universe[i-1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j].setColor(sf::Color(0,100,0));}
                    else {buffer[i][j].setColor(sf::Color(50,205,50));}
                }
                else
                {
                    int counter=0;
                    if(universe[i-1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter==3) {buffer[i][j].setColor(sf::Color(50,205,50));}
                    else {buffer[i][j].setColor(sf::Color(0,100,0));}
                }
            }
            else if(i==0 && j==0)
            {
                if(universe[i][j].getColor()==sf::Color(50,205,50))
                {
                    int counter=0;
                    if(universe[i][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j].setColor(sf::Color(0,100,0));}
                    else {buffer[i][j].setColor(sf::Color(50,205,50));}
                }
                else
                {
                    int counter=0;
                    if(universe[i][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter==3) {buffer[i][j].setColor(sf::Color(50,205,50));}
                    else {buffer[i][j].setColor(sf::Color(0,100,0));}
                }
                }
            else if(i==0 && j==universe_size/cell_size-1)
            {
            if(universe[i][j].getColor()==sf::Color(50,205,50))
                {
                    int counter=0;
                    if(universe[i][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j].setColor(sf::Color(0,100,0));}
                    else {buffer[i][j].setColor(sf::Color(50,205,50));}
                }
                else
                {
                    int counter=0;
                    if(universe[i][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter==3) {buffer[i][j].setColor(sf::Color(50,205,50));}
                    else {buffer[i][j].setColor(sf::Color(0,100,0));}
                }
            }
            else if(i==universe_size/cell_size-1 && j==0)
            {
                if(universe[i][j].getColor()==sf::Color(50,205,50))
                {
                    int counter=0;
                    if(universe[i][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j].setColor(sf::Color(50,205,50));}
                    else {buffer[i][j].setColor(sf::Color(50,205,50));}
                }
                else
                {
                    int counter=0;
                    if(universe[i][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter==3) {buffer[i][j].setColor(sf::Color(50,205,50));}
                    else {buffer[i][j].setColor(sf::Color(0,100,0));}
                }
            }
            else if(i==universe_size/cell_size-1 && j==universe_size/cell_size-1)
            {
                if(universe[i][j].getColor()==sf::Color(50,205,50))
                {
                    int counter=0;
                    if(universe[i][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j].setColor(sf::Color(0,100,0));}
                    else {buffer[i][j].setColor(sf::Color(50,205,50));}
                }
                else
                {
                    int counter=0;
                    if(universe[i][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter==3) {buffer[i][j].setColor(sf::Color(50,205,50));}
                    else {buffer[i][j].setColor(sf::Color(0,100,0));}
                }
            }
            else if(i==0)
            {
                if(universe[i][j].getColor()==sf::Color(50,205,50))
                {
                    int counter = 0;
                    if(universe[i][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j].setColor(sf::Color(0,100,0));}
                    else {buffer[i][j].setColor(sf::Color(50,205,50));}
                }
                else
                {
                    int counter = 0;
                    if(universe[i][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter==3) {buffer[i][j].setColor(sf::Color(50,205,50));}
                    else {buffer[i][j].setColor(sf::Color(0,100,0));}
                }
            }
            else if (i==universe_size/cell_size-1)
            {
                if(universe[i][j].getColor()==sf::Color(50,205,50))
                {
                    int counter = 0;
                    if(universe[i][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j].setColor(sf::Color(50,205,50));}
                    else {buffer[i][j].setColor(sf::Color(50,205,50));}
                }
                else
                {
                    int counter = 0;
                    if(universe[i][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter==3) {buffer[i][j].setColor(sf::Color(50,205,50));}
                    else {buffer[i][j].setColor(sf::Color(0,100,0));}
                }
            }
            else if(j==0)
            {
                if(universe[i][j].getColor()==sf::Color(50,205,50))
                {
                    int counter = 0;
                    if(universe[i-1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j].setColor(sf::Color(0,100,0));}
                    else {buffer[i][j].setColor(sf::Color(50,205,50));}
                }
                else
                {
                    int counter = 0;
                    if(universe[i-1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j+1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter==3) {buffer[i][j].setColor(sf::Color(50,205,50));}
                    else {buffer[i][j].setColor(sf::Color(0,100,0));}
                }
            }
            else if(j==universe_size/cell_size-1)
            {
                if(universe[i][j].getColor()==sf::Color(50,205,50))
                {
                    int counter = 0;
                    if(universe[i-1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter!=2 && counter!=3) {buffer[i][j].setColor(sf::Color(0,100,0));}
                    else {buffer[i][j].setColor(sf::Color(50,205,50));}
                }
                else
                {
                    int counter = 0;
                    if(universe[i-1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i-1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j-1].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(universe[i+1][j].getColor()==sf::Color(50,205,50)) {counter++;}
                    if(counter==3) {buffer[i][j].setColor(sf::Color(50,205,50));}
                    else {buffer[i][j].setColor(sf::Color(0,100,0));}
                }
            }
        }
    }
                    for(int i=0;i<universe_size/cell_size;i++)
                    {
                        for(int j=0;j<universe_size/cell_size;j++)
                        {
                            if(universe[i][j].getColor()!=buffer[i][j].getColor())
                            {
                            universe[i][j]=buffer[i][j];
                            }
                        }
                    }
    }

void Life::showUniverse(sf::RenderWindow &window)
{
    for(int i=0;i<universe_size/cell_size;i++)
    {
        for(int j=0;j<universe_size/cell_size;j++)
        {
        universe[i][j].setPosition(j*cell_size,i*cell_size);
        window.draw(universe[i][j]);
        }
    }
}


