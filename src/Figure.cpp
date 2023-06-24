#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"

Figure::Figure(int scale, sf::Color color, sf::Vector2f coords,  sf::Shape* shape) {
    this->shape = shape;
    this->shape->setFillColor(color);
    this->shape->setPosition(coords);
    this->color = color;
    this->scale = scale;
    this->position = coords;
}

Figure::Figure(const Figure &figure) {
    this->color = figure.color;
    this->scale = figure.scale;
    this->position = figure.position;
}

Figure* Figure::create_figure(ShapeType type, sf::Color color, int scale, sf::Vector2f position) {
    Figure* p;
    switch (type) {
        case ShapeType::Rectangle:
            p = new Rectangle(new sf::RectangleShape(sf::Vector2f(scale * 10, scale * 10)), scale, color, position);
            break;
        case ShapeType::Circle:
            p = new Circle(new sf::CircleShape(scale * 10), scale, color, position);
            break;
    }
    return p;
}

Figure::~Figure() {
    delete shape;
}

void Figure::display(sf::RenderWindow& window) {
    window.draw(*shape);
}

Figure& Figure::operator+=(const Figure &figure) {
    scale += figure.scale;
    std::cout << "Figure";
    resize();
    return *this;
}


Figure* Figure::operator+(const Figure& figure1) {
    Figure* a = this;
    *a += figure1;
    return a;
}

void Figure::resize() {
    std::cout << "Figure is resized" << std::endl;
}


Figure &Figure::operator=(const Figure &other) {
    *this->shape = *other.shape;
    this->color = other.color;
    this->position = other.position;
    this->scale = other.scale;
    return *this;
}

float Figure::getWidth() {
    return shape->getGlobalBounds().width;
}

void Figure::setPosition(sf::Vector2f position) {
    this->position = position;
    shape->setPosition(position);
}

sf::Vector2f Figure::getPosition() {
    return position;
}

float Figure::getHeight() {
    return shape->getGlobalBounds().height;
}




