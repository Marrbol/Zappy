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

class Display {
    public:
        Display(int port, std::string machine);
        ~Display();
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

    protected:
    private:
        //GUI variable
        std::pair<size_t, size_t> _mapSize; // x, y
        std::vector<std::string> _teamName;
        std::pair<size_t, std::string> _messageBroadcast; // id, message

        using CommandFunction = std::function<void(void)>;

        typedef struct allCmdS {
            std::string cmd;
            CommandFunction func;
        } allCmdT;

        typedef struct ressourcesS {
            size_t food = 0;
            size_t linemate = 0;
            size_t deraumere = 0;
            size_t sibur = 0;
            size_t mendiane = 0;
            size_t phiras = 0;
            size_t thystame = 0;
        } ressourcesT;
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
            {"WELCOME", std::bind(&Display::connection, this)},
            {"pnw", std::bind(&Display::newPlayer, this)},
            {"pex", std::bind(&Display::expulsion, this)},
            {"pbc", std::bind(&Display::broadcast, this)},
            {"pic", std::bind(&Display::startIncantation, this)},
            {"pie", std::bind(&Display::endIncantation, this)},
            {"pfk", std::bind(&Display::startLaying, this)},
            {"pdr", std::bind(&Display::ressourceDropping, this)},
            {"pgt", std::bind(&Display::ressourceTaking, this)},
            {"pdi", std::bind(&Display::playerDeath, this)},
            {"enw", std::bind(&Display::eggLaid, this)},
            {"ebo", std::bind(&Display::playerConnectionEgg, this)},
            {"edi", std::bind(&Display::deathEgg, this)},
            {"seg", std::bind(&Display::endGame, this)},
            {"smg", std::bind(&Display::messageFromServer, this)},
            {"suc", std::bind(&Display::unknownCommand, this)},
            {"sbp", std::bind(&Display::CommandParameter, this)},
            {"msz", std::bind(&Display::mapSize, this)},
            {"bct", std::bind(&Display::tileContent, this)},
            {"tna", std::bind(&Display::TeamName, this)},
            {"ppo", std::bind(&Display::playerPosition, this)},
            {"plv", std::bind(&Display::playerLevel, this)},
            {"pin", std::bind(&Display::playerInventory, this)},
            {"sgt", std::bind(&Display::timeUnit, this)},
            {"sst", std::bind(&Display::timeUnitModification, this)},
            {"NULL", NULL}
        };
};

#endif /* !Display_HPP_ */
