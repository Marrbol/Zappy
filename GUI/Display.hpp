//
// Created by emonnier on 6/2/23.
//

#ifndef B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_DISPLAY_H
#define B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GameWindow {
public:
    GameWindow(int width, int height, const std::string& title);
    ~GameWindow() {}
    void run();
private:
    sf::RenderWindow window;
};


#endif //B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_DISPLAY_H
