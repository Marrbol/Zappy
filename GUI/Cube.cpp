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

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Camera Test");
    Camera camera(window, 50.f, 1.1f);
    IsometricMap map(500.f, 10, 10);

    sf::Texture cubeTexture;
    if (!cubeTexture.loadFromFile("Map.png")) {
        return EXIT_FAILURE;
    }
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            map.getCube(x, y)->setTexture(cubeTexture);
        }
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            camera.handleInput(event);
        }

        window.clear();
        map.draw(window);
        camera.update(window);
        window.display();
    }

    return 0;
}


