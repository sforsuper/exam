#include <iostream>
#include "Circle.h"

Circle::Circle(sf::CircleShape *shape, int scale, sf::Color color, sf::Vector2f coords) : Figure(scale, color, coords, shape){

}

Circle::Circle(const Circle& circle) : Figure(circle){
    this->shape = new sf::CircleShape(circle.scale * 10);
    this->shape->setFillColor(circle.color);
    this->shape->setPosition(circle.position);
}

void Circle::resize() {
    shape = new sf::CircleShape(scale * 8);
    shape->setFillColor(color);
    shape->setPosition(position);
    std::cout << "Circle is resized" << std::endl;
}
