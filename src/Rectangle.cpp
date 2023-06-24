
#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(sf::RectangleShape *shape, int scale, sf::Color color, sf::Vector2f coords) : Figure(scale, color,coords,shape) {}

Rectangle::Rectangle(const Rectangle &rect) : Figure(rect) {
    this->shape = new sf::RectangleShape(sf::Vector2f (10*scale, 8*scale));
    this->shape->setFillColor(rect.color);
    this->shape->setPosition(rect.position);
}


void Rectangle::resize() {
    shape = new sf::RectangleShape(sf::Vector2f (scale * 10, scale * 8));
    shape->setFillColor(color);
    shape->setPosition(position);
    std::cout << "Circle is resized" << std::endl;

}
