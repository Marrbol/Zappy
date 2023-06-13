/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** Display
*/

#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include <string>
#include <functional>
#include "../network/Network.hpp"
#include <vector>
#include <iostream>
#include <error.h>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Camera.hpp"
#include "IsometricMap.hpp"

class GameWindow {
    private:
        typedef struct ressourcesS {
            size_t food = 0;
            size_t linemate = 0;
            size_t deraumere = 0;
            size_t sibur = 0;
            size_t mendiane = 0;
            size_t phiras = 0;
            size_t thystame = 0;
        } ressourcesT;
    public:
        GameWindow(int width, int height, const std::string& title, int port, std::string machine);
        ~GameWindow();
        void run();

        //send to server
        void askMapSize();
        void askTileContent(size_t x, size_t y);
        void askAllTileContent();
        void askTeamsNames();
        void askPlayerPosition(size_t id);
        void askPlayerLevel(size_t id);
        void askPlayerInventory(size_t id);
        void askTimeUnit();
        void askTimeUnitModification(size_t time);

        //Receive from server
        void communicateWithServer();
        bool parseCommande();
        void connection();
        void newPlayer();
        void expulsion();
        void broadcast();
        void startIncantation();
        void endIncantation();
        void startLaying();
        void ressourceDropping();
        void ressourceTaking();
        void playerDeath();
        void eggLaid();
        void playerConnectionEgg();
        void deathEgg();
        void endGame();
        void messageFromServer();
        void unknownCommand();
        void CommandParameter();
        void mapSize();
        void tileContent();
        void TeamName();
        void playerPosition();
        void playerLevel();
        void playerInventory();
        void timeUnit();
        void timeUnitModification();
        void modifInventory(size_t id_player, size_t id_ressource, int nb);

    protected:
    private:
        sf::RenderWindow window;
        //GUI variable
        std::pair<size_t, size_t> _mapSize; // x, y
        std::vector<std::string> _teamName;
        std::pair<size_t, std::string> _messageBroadcast; // id, message

        using CommandFunction = std::function<void(void)>;

        typedef struct allCmdS {
            std::string cmd;
            CommandFunction func;
        } allCmdT;

        std::map<std::pair<size_t, size_t>, ressourcesT> _map; // x, y -> ressources

        typedef struct playerS {
            size_t id = 0;
            size_t x = 0;
            size_t y = 0;
            size_t orientation = 0;
            size_t level = 0;
            std::string team = "";
            ressourcesT inventory;
            bool laying = false;
        } playerT;
        std::map<size_t, playerT> _player;  // id -> player

        typedef struct incantationS {
            size_t x = 0;
            size_t y = 0;
            size_t level = 0;
            std::vector<playerT *> players;
        } incantationT;
        std::map<size_t, incantationT> _incantation;

        typedef struct eggS {
            size_t id = 0;
            size_t x = 0;
            size_t y = 0;
        } eggT;
        std::vector<eggT> _egg;

        //communication
        fd_set _readfds;
        Network _network;
        int _socket;
        std::string _commande;
        std::string _machine;
        std::string _line;

        std::map<size_t, std::string> _ressourcesByID = {
            {0, "food"},
            {1, "linemate"},
            {2, "deraumere"},
            {3, "sibur"},
            {4, "mendiane"},
            {5, "phiras"},
            {6, "thystame"}
        };

        std::vector<allCmdT> _cmd = {
            {"WELCOME", std::bind(&GameWindow::connection, this)},
            {"pnw", std::bind(&GameWindow::newPlayer, this)},
            {"pex", std::bind(&GameWindow::expulsion, this)},
            {"pbc", std::bind(&GameWindow::broadcast, this)},
            {"pic", std::bind(&GameWindow::startIncantation, this)},
            {"pie", std::bind(&GameWindow::endIncantation, this)},
            {"pfk", std::bind(&GameWindow::startLaying, this)},
            {"pdr", std::bind(&GameWindow::ressourceDropping, this)},
            {"pgt", std::bind(&GameWindow::ressourceTaking, this)},
            {"pdi", std::bind(&GameWindow::playerDeath, this)},
            {"enw", std::bind(&GameWindow::eggLaid, this)},
            {"ebo", std::bind(&GameWindow::playerConnectionEgg, this)},
            {"edi", std::bind(&GameWindow::deathEgg, this)},
            {"seg", std::bind(&GameWindow::endGame, this)},
            {"smg", std::bind(&GameWindow::messageFromServer, this)},
            {"suc", std::bind(&GameWindow::unknownCommand, this)},
            {"sbp", std::bind(&GameWindow::CommandParameter, this)},
            {"msz", std::bind(&GameWindow::mapSize, this)},
            {"bct", std::bind(&GameWindow::tileContent, this)},
            {"tna", std::bind(&GameWindow::TeamName, this)},
            {"ppo", std::bind(&GameWindow::playerPosition, this)},
            {"plv", std::bind(&GameWindow::playerLevel, this)},
            {"pin", std::bind(&GameWindow::playerInventory, this)},
            {"sgt", std::bind(&GameWindow::timeUnit, this)},
            {"sst", std::bind(&GameWindow::timeUnitModification, this)},
            {"NULL", NULL}
        };
};

#endif //B_YEP_400_REN_4_1_ZAPPY_MARTIN_BOUCAULT_DISPLAY_H
