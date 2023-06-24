#pragma once

#include "SFML/Graphics/RenderWindow.hpp"

class AnimatedObject{
protected:
    sf::Vector2f position;
public:
    virtual void display(sf::RenderWindow& window) = 0;
    virtual void setPosition(sf::Vector2f position) = 0;

    virtual sf::Vector2f getPosition() = 0;
    virtual float getWidth() = 0;
    virtual float getHeight() = 0;
};