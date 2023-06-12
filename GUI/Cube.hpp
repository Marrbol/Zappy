//
// Created by emonnier on 6/6/23.
//

#ifndef B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_CUBE_H
#define B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_CUBE_H

#include "Camera.h"
#include "IsometricMap.h"
#include "Display.hpp"
#include <SFML/Graphics.hpp>

class Cube {
private:
    sf::ConvexShape face[6];
    sf::Vector2f position;
    float size;

public:
    Cube(float x, float y, float cubeSize);
    void setPosition(float x, float y);
    void draw(sf::RenderWindow& window);
};

#endif //B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_CUBE_H