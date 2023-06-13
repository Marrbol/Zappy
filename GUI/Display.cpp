/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** Display
*/

#include "Display.hpp"

GameWindow::GameWindow(int width, int height, const std::string& title, int port, std::string machine) : _machine(machine)
{
    _network = Network();
    _socket = _network.connectSocketClient(machine, port);
}

void GameWindow::run()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Camera Test");
    IsometricMap map(500.f);
    Camera camera(window, 50.f, 1.1f);
    bool loadMap = false;

    sf::Texture cubeTexture;
    if (!cubeTexture.loadFromFile("Map.png")) {
        return;
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            camera.handleInput(event);
        }
        communicateWithServer();
        if (_mapSize.first == 0 && _mapSize.second == 0)
            continue;
        if (!loadMap) {
            std::cout << "Map size: " << _mapSize.first << " " << _mapSize.second << std::endl;
            map.setSize(_mapSize.first, _mapSize.second);
            for (int x = 0; x < 10; ++x) {
                for (int y = 0; y < 10; ++y) {
                    map.getCube(x, y)->setTexture(cubeTexture);
                }
            }
            loadMap = true;
        }
        window.clear();
        map.draw(window);
        camera.update(window);
        window.display();
    }
}


int main()
{
    GameWindow display(1600, 900, "Zappy", 35000, "127.0.0.1");
    display.run();
    return 0;
}
