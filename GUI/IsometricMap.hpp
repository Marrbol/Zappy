//
// Created by emonnier on 6/11/23.
//

#ifndef B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_ISOMETRICMAP_H
#define B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_ISOMETRICMAP_H

#include "Cube.h"

// Forward declaration of Cube class
class Cube;

// IsometricMap.h
class IsometricMap {
private:
    static const int MAP_SIZE = 10;
    Cube* map[MAP_SIZE][MAP_SIZE];
    float cubeSize;

public:
    IsometricMap(float size, int i, int j);
    ~IsometricMap();
    void draw(sf::RenderWindow& window, int i, int j);
};

#endif //B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_ISOMETRICMAP_H
