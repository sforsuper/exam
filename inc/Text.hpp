#include "AnimatedObject.hpp"
#include "SFML/Graphics.hpp"
#pragma once
class Text : public AnimatedObject{
private:
    std::string m_string;
    sf::Text text;
    sf::Font font;
public:
    Text(std::string str);
    void setPosition(sf::Vector2f pos) override;
    sf::Vector2f getPosition() override;
    float getWidth() override;
    float getHeight() override;
    void display(sf::RenderWindow& window) override;
};