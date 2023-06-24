#pragma once
#include"SFML/Graphics/CircleShape.hpp"
#include "Figure.h"

class Circle : public Figure{
public:
    Circle(const Circle& circle);
    Circle(sf::CircleShape* shape, int scale, sf::Color color, sf::Vector2f coords);

    void resize() override;
};
