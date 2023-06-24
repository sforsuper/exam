#include <iostream>
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Text.hpp"


std::ostream& operator << (std::ostream& os, const Figure& figure) {
    os << "Scale:" << figure.scale << std::endl;
    os << "Coord-x:" << figure.position.x << std::endl;
    os << "Coord-y:" << figure.position.y << std::endl;
    return os;
}

template<typename T>
class Animation {
public:
    void display(T& a, T& b, T& c, sf::RenderWindow& window) {
        std::cout << a << "+" << b << "=" << c << std::endl;
    }
};


template<>
class Animation<AnimatedObject>{
private:

public:
    void display(AnimatedObject& a, AnimatedObject& b, AnimatedObject& c, sf::RenderWindow& window, sf::Vector2f position) {
        float max_height = std::max(std::max(a.getHeight(), b.getHeight()), c.getHeight());
        
        a.setPosition({position.x, position.y + (max_height - a.getHeight()) / 2 });

        sf::RectangleShape rect1 = sf::RectangleShape({35, 10});
        sf::RectangleShape rect2 = sf::RectangleShape({10, 35});

        rect1.setPosition({a.getPosition().x + a.getWidth() + 10, position.y + (max_height - 10) / 2});
        rect2.setPosition({a.getPosition().x + a.getWidth() + 5 + (rect1.getGlobalBounds().width / 2), position.y + (max_height - 35) / 2});
        rect1.setFillColor(sf::Color::Black);
        rect2.setFillColor(sf::Color::Black);

        b.setPosition({rect1.getPosition().x + rect1.getGlobalBounds().width + 10, position.y + (max_height - b.getHeight()) / 2 });

        sf::RectangleShape rect3 = sf::RectangleShape({40, 10});
        sf::RectangleShape rect4 = sf::RectangleShape({40, 10});

        rect3.setFillColor(sf::Color::Black);
        rect4.setFillColor(sf::Color::Black);

        rect3.setPosition({b.getPosition().x + b.getWidth() + 10, position.y + (max_height) / 2 - 15});
        rect4.setPosition({b.getPosition().x + b.getWidth() + 10, position.y + (max_height) / 2});

        c.setPosition({rect3.getPosition().x + rect3.getGlobalBounds().width + 10, position.y + (max_height - c.getHeight()) / 2 });

        a.display(window);
        b.display(window);
        c.display(window);
        window.draw(rect1);
        window.draw(rect2);
        window.draw(rect3);
        window.draw(rect4);
    }
};


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Figures");
    Animation<AnimatedObject> anim;
    Text text1 = Text("Cat");
    Text text2 = Text(std::string ("Dog"));
    Text text3 = Text(std::string ("DogCat"));

    Figure* circle = Figure::create_figure(ShapeType::Circle, sf::Color::Cyan, 10, sf::Vector2f (0, 50));
    Figure* circle1 = Figure::create_figure(ShapeType::Circle, sf::Color::Cyan, 10, sf::Vector2f (0, 50));
    Figure* circle2 = Figure::create_figure(ShapeType::Circle, sf::Color::Yellow, 10, sf::Vector2f (0, 50));



    *circle2 += *circle;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        anim.display(*circle, *circle1, *circle2, window, {50, 50});
        anim.display(text1, text2, text3, window, {50, 450});
        window.display();
    }
    delete circle;
    delete circle1;
    delete circle2;
}