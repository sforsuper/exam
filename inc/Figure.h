#pragma once
#include"SFML/Graphics/Shape.hpp"
#include"SFML/Graphics/RenderWindow.hpp"
#include "AnimatedObject.hpp"

enum class ShapeType {
    Circle,
    Rectangle
};

class Figure : public AnimatedObject{
protected:
    sf::Shape* shape;
    sf::Color color;
    int scale;
public:
    Figure(int scale, sf::Color color, sf::Vector2f coords,  sf::Shape* shape);
    Figure(const Figure& figure);
    virtual ~Figure();
    Figure& operator += (const Figure& figure);
    Figure* operator + (const Figure& figure1);
    Figure& operator = (const Figure& other);

    void display(sf::RenderWindow& window) override;
    void setPosition(sf::Vector2f position) override;
    sf::Vector2f getPosition()override;
    float getWidth() override;
    float getHeight() override;
    static Figure* create_figure(ShapeType type, sf::Color color, int scale, sf::Vector2f position);

    friend std::ostream& operator<<(std::ostream& out, const Figure& figure);

    virtual void resize() = 0;
};
