#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "player.hpp"

class Game {
private:
    sf::RenderWindow window;
    sf::Time TimePerFrame;

    Player player;

    void processEvents();
    void update(sf::Time deltaTime);
    void render();

public:
    Game();
    void run();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
};

#endif