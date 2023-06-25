//
// Created by emonnier on 6/11/23.
//

#ifndef B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_ISOMETRICMAP_H
#define B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_ISOMETRICMAP_H

#include "Cube.hpp"
#include <map>

// Forward declaration of Cube class
class Cube;

// IsometricMap.h
class IsometricMap {
private:
    std::map <std::pair<int, int>, Cube*> map;
    float cubeSize;
    int _i;
    int _j;

public:
    IsometricMap(float size);
    ~IsometricMap();
    void setSize(float x, float y);

    Cube* getCube(int x, int y) const;
    void draw(sf::RenderWindow& window);
};


#endif //B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_ISOMETRICMAP_H
