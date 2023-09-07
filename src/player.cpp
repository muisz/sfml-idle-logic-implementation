#include <iostream>
#include "player.hpp"

Player::Player()
: player(sf::Vector2f(50.f, 50.f))
{
    player.setFillColor(sf::Color::Red);
    player.setPosition(sf::Vector2f(10.f, 10.f));

    isMovingLeft = false;
    isMovingRight = false;
    isMovingUp = false;
    isMovingDown = false;

    idleSize = 5;
    activeIdleColor = 0;
    idleColors[0] = sf::Color::Green;
    idleColors[1] = sf::Color::Blue;
    idleColors[2] = sf::Color::Yellow;
    idleColors[3] = sf::Color::Cyan;
    idleColors[4] = sf::Color::Magenta;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(player, states);
}

void Player::update(sf::Time deltaTime) {
    updateMovement(deltaTime);
    if (checkIsPlayerIdle())
        handlePlayerIdle();
    else
        player.setFillColor(sf::Color::Red);
}

void Player::updateMovement(sf::Time deltaTime) {
    sf::Vector2f movement;
    int movementStep = 50;

    if (isMovingLeft)
        movement.x -= movementStep;
    if (isMovingRight)
        movement.x += movementStep;
    if (isMovingUp)
        movement.y -= movementStep;
    if (isMovingDown)
        movement.y += movementStep;
    
    if (isMovingUp || isMovingDown || isMovingLeft || isMovingRight)
        clock.restart();
    
    player.move(movement * deltaTime.asSeconds());
}

void Player::moveLeft(bool isPressed) {
    isMovingLeft = isPressed;
}

void Player::moveRight(bool isPressed) {
    isMovingRight = isPressed;
}

void Player::moveUp(bool isPressed) {
    isMovingUp = isPressed;
}

void Player::moveDown(bool isPressed) {
    isMovingDown = isPressed;
}

bool Player::checkIsPlayerIdle() {
    sf::Time elapsedTime = clock.getElapsedTime();
    return elapsedTime.asSeconds() > 5;
}

void Player::handlePlayerIdle() {
    sf::Color color = idleColors[activeIdleColor];
    player.setFillColor(color);
    if (activeIdleColor < idleSize)
        activeIdleColor++;
    else
        activeIdleColor = 0;
}
