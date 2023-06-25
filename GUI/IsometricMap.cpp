//
// Created by emonnier on 6/11/23.
//

#include "IsometricMap.hpp"

IsometricMap::IsometricMap(float size) : cubeSize(size)
{

}

void IsometricMap::setSize(float i, float j) {
    // Set the size of the map
    for (int x = 0; x < i; ++x) {
        for (int y = 0; y < j; ++y) {
            float posX = (x - y) * cubeSize * 0.50f;
            float posY = (x + y) * cubeSize * 0.25f;
            map[std::pair<size_t, size_t>(x, y)] = new Cube(posX, posY, cubeSize);
        }
    }
    _i = i;
    _j = j;
}

IsometricMap::~IsometricMap() {
    // Deallocate the memory for cubes
    for (int x = 0; x < _i; ++x) {
        for (int y = 0; y < _j; ++y) {
            delete map[std::pair<size_t, size_t>(x, y)];
        }
    }
}

void IsometricMap::draw(sf::RenderWindow& window) {
    // Draw all cubes
    for (int x = 0; x < _i; ++x) {
        for (int y = 0; y < _j; ++y) {
            map[std::pair<size_t, size_t>(x, y)]->draw(window);
        }
    }
}

Cube* IsometricMap::getCube(int x, int y) const {
    if (x >= 0 && x < _i && y >= 0 && y < _j)
        return map.at(std::pair<size_t, size_t>(x, y));
    else
        return nullptr;
}