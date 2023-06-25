//
// Created by emonnier on 6/6/23.
//

#include "Cube.hpp"

Cube::Cube(float x, float y, float cubeSize) : position(x, y), size(cubeSize)
{
    face[5].setPointCount(4);

    face[5].setPoint(0, sf::Vector2f(x, y - cubeSize / 2.f));
    face[5].setPoint(1, sf::Vector2f(x + cubeSize, y));
    face[5].setPoint(2, sf::Vector2f(x, y + cubeSize / 2.f));
    face[5].setPoint(3, sf::Vector2f(x - cubeSize, y));

    face[5].setFillColor(sf::Color::Cyan);
}

void Cube::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}

void Cube::setTexture(const sf::Texture& texture)
{
    sprite.setTexture(texture);
}

void Cube::draw(sf::RenderWindow& window)
{
    sprite.setPosition(position);
    window.draw(sprite);
}
