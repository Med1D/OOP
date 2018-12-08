#include <SFML/Graphics.hpp>
//#include <SFML/Audio/Music.hpp>
#include <iostream>
#include <sstream>
#include <ctime>
#include <windows.h>
#include "Life.h"

int main()
{
    int SCRWIDTH=600,SCRHEIGHT=600;
    int sizeCell=3;
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(SCRWIDTH, SCRHEIGHT), "Life");
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);
    //MUSIC
/*    sf::Music music;
    if(!music.openFromFile("music.ogg"))
    {
        std::cout << "MUSIC ERROR";
    }
    else
    {
    music.setPosition(0, 1, 10); // change its 3D position
    //music.setPitch(2);           // increase the pitch
    music.setVolume(20);         // reduce the volume
    music.setLoop(true);
    music.play();
    }
*/
    //MUSIC
    //TEXT
    sf::Font font;
    font.loadFromFile("Calibri.ttf");
    sf::Text text("",font,15);
    text.setColor(sf::Color::White);
    text.setPosition(10,10);

    sf::Text startText("Press SPACE to start",font,25);
    startText.setPosition(sf::Vector2f(SCRWIDTH/2.9f,SCRHEIGHT/2.2f));

    sf::Text loadingText("Loading",font,25);
    loadingText.setPosition(sf::Vector2f(SCRWIDTH/2.4f,SCRHEIGHT/2.2f));

    int gen = 0;
    std::ostringstream genString;
    genString << gen;


    //TEXT

    window.draw(loadingText);
    window.display();
    Life game(SCRHEIGHT,sizeCell);
    game.randomLife();
    window.clear();
    window.draw(startText);
    window.display();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
        text.setString("Generation: " + genString.str());
        window.clear();
        game.actionUniverse();
        game.showUniverse(window);
        window.draw(text);
        window.display();
        gen++;
        genString.str("");
        genString.clear();
        genString<<gen;
        //Sleep(100);
        }
        if(gen!=0 && (window.getSize().x!=SCRWIDTH || window.getSize().y != SCRHEIGHT))
        {
            std::cout << "RESIZED";
            SCRWIDTH=window.getSize().x;
            SCRHEIGHT=window.getSize().y;
            window.clear();
            window.draw(text);
            window.display();
        }
        else if(gen==0 && (window.getSize().x!=SCRWIDTH || window.getSize().y != SCRHEIGHT))
        {
            std::cout << "RESIZED";
            SCRWIDTH=window.getSize().x;
            SCRHEIGHT=window.getSize().y;
            window.clear();
            window.draw(startText);
            window.display();
        }
    }
    return 0;
}
