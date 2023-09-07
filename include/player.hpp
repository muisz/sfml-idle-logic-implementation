#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Drawable {
private:
    sf::RectangleShape player;
    sf::Clock clock;

    bool isMovingLeft;
    bool isMovingRight;
    bool isMovingUp;
    bool isMovingDown;

    int idleSize;
    int activeIdleColor;
    sf::Color idleColors[5];

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void updateMovement(sf::Time deltaTime);
    bool checkIsPlayerIdle();
    void handlePlayerIdle();

public:
    Player();
    void update(sf::Time deltaTime);
    void moveLeft(bool isPressed);
    void moveRight(bool isPressed);
    void moveUp(bool isPressed);
    void moveDown(bool isPressed);
};

#endif
