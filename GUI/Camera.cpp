//
// Created by emonnier on 6/11/23.
//

#include "Camera.hpp"

Camera::Camera(sf::RenderWindow& window, float speed, float zoom) : moveSpeed(speed), zoomAmount(zoom)
{
    view = window.getDefaultView();
    view.zoom(5.f / zoomAmount);
}

void Camera::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed) {
        sf::Vector2f movement(0.f, 0.f);

        if (event.key.code == sf::Keyboard::Up)
            movement.y -= moveSpeed;
        else if (event.key.code == sf::Keyboard::Down)
            movement.y += moveSpeed;
        else if (event.key.code == sf::Keyboard::Left)
            movement.x -= moveSpeed;
        else if (event.key.code == sf::Keyboard::Right)
            movement.x += moveSpeed;

        view.move(movement);
    }
    else if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0)
            view.zoom(1.f / zoomAmount);
        else if (event.mouseWheelScroll.delta < 0)
            view.zoom(zoomAmount);
    }
}

void Camera::update(sf::RenderWindow& window)
{
    window.setView(view);
}