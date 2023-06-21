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
    draw_t foodS;
    draw_t linemateS;
    draw_t deraumereS;
    draw_t siburS;
    draw_t mendianeS;
    draw_t phirasS;
    draw_t thystameS;
    playerT playerS;

    initAll(foodS, linemateS, deraumereS, siburS, mendianeS, phirasS, thystameS, playerS);

    sf::RenderWindow window(sf::VideoMode(1600, 900), "Camera Test");
    IsometricMap map(500.f);
    Camera camera(window, 50.f, 1.1f);
    bool loadMap = false;

    if (!foodS.textRessources.loadFromFile("assets/food.png")) {
        return;
    }
    if (!linemateS.textRessources.loadFromFile("assets/linemate.png")) {
       return;
    }
    if (!deraumereS.textRessources.loadFromFile("assets/deraumere.png")) {
       return;
    }
    if (!siburS.textRessources.loadFromFile("assets/sibur.png")) {
       return;
    }
    sf::Texture cubeTexture;
    if (!cubeTexture.loadFromFile("assets/Map.png")) {
        return;
    }
    if (!mendianeS.textRessources.loadFromFile("assets/mendiane.png")) {
       return;
    }
    if (!phirasS.textRessources.loadFromFile("assets/phiras.png")) {
       return;
    }
    if (!thystameS.textRessources.loadFromFile("assets/thystame.png")) {
       return;
    }

    foodS.spriteRessources.setTexture(foodS.textRessources);
    linemateS.spriteRessources.setTexture(linemateS.textRessources);
    deraumereS.spriteRessources.setTexture(deraumereS.textRessources);
    siburS.spriteRessources.setTexture(siburS.textRessources);
    mendianeS.spriteRessources.setTexture(mendianeS.textRessources);
    phirasS.spriteRessources.setTexture(phirasS.textRessources);
    thystameS.spriteRessources.setTexture(thystameS.textRessources);

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
            map.setSize(_mapSize.first, _mapSize.second);
            for (int x = 0; x < _mapSize.first; ++x) {
                for (int y = 0; y < _mapSize.second; ++y) {
                    map.getCube(x, y)->setTexture(cubeTexture);
                }
            }
            loadMap = true;
        }
        window.clear();
        map.draw(window);
        
        for (const auto& tile : _map) {
            int x = tile.first.first;
            int y = tile.first.second;
            const ressourcesS& tileContent = tile.second;
            if (tileContent.food > 0) {
                foodS.spriteRessources.setPosition((x - y) * 500 * 0.50f,(x + y) * 500 * 0.25f);
                window.draw(foodS.spriteRessources);
            }
            if (tileContent.linemate > 0) {
                linemateS.spriteRessources.setPosition((x - y) * 500 * 0.50f,(x + y) * 500 * 0.25f);
                window.draw(linemateS.spriteRessources);
            }
            if (tileContent.deraumere > 0) {
                deraumereS.spriteRessources.setPosition((x - y) * 500 * 0.50f,(x + y) * 500 * 0.25f);
                window.draw(deraumereS.spriteRessources);
            }
            if (tileContent.sibur > 0) {
                siburS.spriteRessources.setPosition((x - y) * 500 * 0.50f,(x + y) * 500 * 0.25f);
                window.draw(siburS.spriteRessources);
            }
            if (tileContent.mendiane > 0) {
                mendianeS.spriteRessources.setPosition((x - y) * 500 * 0.50f,(x + y) * 500 * 0.25f);
                window.draw(mendianeS.spriteRessources);
            }
            if (tileContent.phiras > 0) {
                phirasS.spriteRessources.setPosition((x - y) * 500 * 0.50f,(x + y) * 500 * 0.25f);
                window.draw(phirasS.spriteRessources);
            }
            if (tileContent.thystame > 0) {
                thystameS.spriteRessources.setPosition((x - y) * 500 * 0.50f,(x + y) * 500 * 0.25f);
                window.draw(thystameS.spriteRessources);
            }
        for (auto& mobTile : _player) {
                size_t id = mobTile.first;
                playerT& player = mobTile.second;

                player.spritePlayer.setPosition((player.x - player.y) * 500 * 0.50f,(player.x + player.y) * 500 * 0.25f);
                if (mobTile.second.id > 0) {
                    IDText.setPosition((player.x - (player.y - 1) ) * 500 * 0.50f, (player.x + (player.y - 1)) * 500 * 0.25f);
                    IDText.setString(std::to_string(id));
                    window.draw(IDText);
                }
                window.draw(player.spritePlayer);
            }
        }
        window.draw(messageText);
        camera.update(window);
        window.display();
    }
}

void printUsage() {
    std::cout << "USAGE: ./zappy_gui -p port -h machine\n"
              << "port is the port number\n"
              << "machine is the name of the machine; localhost by default\n";
}

void GameWindow::initAll(draw_t food, draw_t linemate, draw_t deraumere, draw_t sibur, draw_t mendiane, draw_t phiras, draw_t thystame, playerT player)
{
    food.spriteRessources = sf::Sprite();
    food.textRessources = sf::Texture();

    linemate.spriteRessources = sf::Sprite();
    linemate.textRessources = sf::Texture();

    deraumere.spriteRessources = sf::Sprite();
    deraumere.textRessources = sf::Texture();

    sibur.spriteRessources = sf::Sprite();
    sibur.textRessources = sf::Texture();

    mendiane.spriteRessources = sf::Sprite();
    mendiane.textRessources = sf::Texture();

    phiras.spriteRessources = sf::Sprite();
    phiras.textRessources = sf::Texture();

    thystame.spriteRessources = sf::Sprite();
    thystame.textRessources = sf::Texture();

    if (!bullText.loadFromFile("assets/Bulle.png")) {
       return;
    }
    if (!font.loadFromFile("assets/arial.ttf")) {
        return;
    }

    messageText.setFont(font);
    messageText.setCharacterSize(150);
    messageText.setFillColor(sf::Color::White);
    IDText.setFont(font);
    IDText.setCharacterSize(50);
    IDText.setFillColor(sf::Color::White);
}

int main(int ac, char **av)
{
    size_t port = 0;
    std::string name;
    std::string machine;
    if (ac != 5 || std::string(av[1]) == "-help") {
        printUsage();
        return 84;
    }
    for (int i = 1; i < ac; i += 2) {
        std::string flag = av[i];
        if (flag.size() != 2 || flag[0] != '-') {
            printUsage();
            return 84;
        }
        switch (flag[1]) {
            case ('p'):
                port = std::atoi(av[i + 1]);
                break;
            case ('h'):
                machine = av[i + 1];
                break;
            default:
                std::cout << "Invalid argument: " << flag << std::endl;
                printUsage();
                return 84;
        }
    }

    GameWindow display(1600, 900, "Zappy", port, machine);
    display.run();
    return 0;
}
