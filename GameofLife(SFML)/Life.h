#ifndef LIFE_H
#define LIFE_H
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <SFML\Graphics.hpp>

class Life:public sf::Sprite
{
    public:
        Life();
        Life(int n,int CellSize);
        virtual ~Life();
        void randomLife();
        void actionUniverse();
        void showUniverse(sf::RenderWindow &window);

    protected:

    private:
        int universe_size;
        int cell_size;
        sf::Sprite **universe = new sf::Sprite*[universe_size];
        sf::Sprite **buffer = new sf::Sprite*[universe_size];
        sf::Texture texture;
};

#endif // LIFE_H
