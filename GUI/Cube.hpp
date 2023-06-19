//
// Created by emonnier on 6/6/23.
//

#ifndef B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_CUBE_H
#define B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_CUBE_H

#include "Camera.hpp"
#include "IsometricMap.hpp"
#include "Display.hpp"
#include <SFML/Graphics.hpp>

class Cube {
private:
    sf::ConvexShape face[6];
    sf::Vector2f position;
    float size;
    sf::Sprite sprite;

public:
    Cube(float x, float y, float cubeSize);
    Cube* getCube(int x, int y) const;
    void setTexture(const sf::Texture& texture);
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window);
};

#endif //B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_CUBE_H