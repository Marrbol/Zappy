//
// Created by emonnier on 6/2/23.
//

#include "Display.hpp"

GameWindow::GameWindow(int width, int height, const std::string& title)
{
    window.create(sf::VideoMode(width, height), title);
}

void GameWindow::run()
{
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.display();
    }
}
