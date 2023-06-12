//
// Created by emonnier on 6/11/23.
//

#include "IsometricMap.hpp"

IsometricMap::IsometricMap(float size, int i, int j) : cubeSize(size)
{
    // Initialize the map with cubes
    for (int x = 0; x < MAP_SIZE; ++x) {
        for (int y = 0; y < MAP_SIZE; ++y) {
            float posX = (x - y) * cubeSize * 0.50f;
            float posY = (x + y) * cubeSize * 0.25f;

            map[x][y] = new Cube(posX, posY, cubeSize); // Use dynamic allocation with 'new'
        }
    }
}

IsometricMap::~IsometricMap() {
    // Deallocate the memory for cubes
    for (int x = 0; x < MAP_SIZE; ++x) {
        for (int y = 0; y < MAP_SIZE; ++y) {
            delete map[x][y];
        }
    }
}

void IsometricMap::draw(sf::RenderWindow& window) {
    // Draw all cubes
    for (int x = 0; x < MAP_SIZE; ++x) {
        for (int y = 0; y < MAP_SIZE; ++y) {
            map[x][y]->draw(window);
        }
    }
}

Cube* IsometricMap::getCube(int x, int y) const {
    if (x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE)
        return map[x][y];
    else
        return nullptr;
}