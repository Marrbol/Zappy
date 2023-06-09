/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** Display
*/

#include "Display.hpp"

GameWindow::GameWindow(int width, int height, const std::string& title) {
    window.create(sf::VideoMode(width, height), title);
}

void GameWindow::run() {
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

int main()
{
    GameWindow game(800, 600, "SFML Window");
    game.run();

    return 0;
}