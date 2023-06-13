//
// Created by emonnier on 6/11/23.
//

#ifndef B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_CAMERA_H
#define B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_CAMERA_H

#include <SFML/Graphics.hpp>

class Camera {
private:
    sf::View view;
    float moveSpeed;
    float zoomAmount;

public:
    Camera(sf::RenderWindow& window, float speed, float zoom);
    ~Camera() {}

    void handleInput(sf::Event& event);
    void update(sf::RenderWindow& window);
};


#endif //B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_CAMERA_H
