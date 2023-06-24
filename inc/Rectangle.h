#pragma once
#include"SFML/Graphics/RectangleShape.hpp"
#include "Figure.h"

class Rectangle : public Figure{
public:
    Rectangle(sf::RectangleShape* shape, int scale, sf::Color color, sf::Vector2f coords);
    Rectangle(const Rectangle& rect);

    void resize() override;
};
