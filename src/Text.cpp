#include "Text.hpp"
#include "SFML/Graphics.hpp"

Text::Text(std::string str) : m_string(str) {
    font.loadFromFile("res/arial.ttf");
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(64);
    text.setOrigin({0, 17.5});
    text.setFillColor(sf::Color::Black);
}

void Text::setPosition(sf::Vector2f pos) {
    text.setPosition(pos);
    position = pos;
}

sf::Vector2f Text::getPosition() {
    return position;
}

float Text::getWidth() {
    return text.getGlobalBounds().width;}

void Text::display(sf::RenderWindow &window) {
    window.draw(text);
}

float Text::getHeight() {
    return text.getGlobalBounds().height;
}
