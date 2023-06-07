/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** IA
*/

#ifndef IA_HPP_
#define IA_HPP_

#include <thread>
#include <string>
#include <list>
#include <functional>
#include "../network/Network.hpp"
#include <vector>
#include <iostream>
#include <error.h>
#include <mutex>

class IA {
    public:
        IA(int port, std::string name, std::string machine);
        ~IA();
        void communicateWithServer();
        void parseCommande();

        //send command
        void forward();
        void turnLeft();
        void turnRight();
        void look();
        void broadcast(std::string message);
        void inventory();
        void connectNbr();
        void fork();
        void eject();
        void take(std::string object);
        void set(std::string object);
        void incantation();

        //get command
        void getForward();
        void getTurnLeft();
        void getTurnRight();
        void getLook();
        void getBroadcast();
        void getInventory();
        void getConnectNbr();
        void getFork();
        void getEject();
        void getTake();
        void getSet();
        void getIncantation();

    protected:
    private:
        std::string _commande;
        std::string _machine;
        std::string _line;
        std::pair<size_t, size_t> _mapSize;
        size_t _level = 1;
        std::string _teamName;
        size_t _clientName;
        std::string _actualCommand;
        bool _isDead = false;

        bool _validate = false;
        std::mutex _mutex;
        bool _start = false;
        bool _name = false;
        fd_set _readfds;
        Network _network;
        int _socket;
        std::list<std::string> _responce;
        std::list<std::string> _ask;

        using CommandFunction = std::function<void(void)>;

        typedef struct allCmdS {
            std::string cmd;
            CommandFunction func;
        } allCmdT;

         std::vector<allCmdT> _cmd = {
            {"forward", std::bind(&IA::getForward, this)},
            {"right", std::bind(&IA::getTurnRight, this)},
            {"left", std::bind(&IA::getTurnLeft, this)},
            {"look", std::bind(&IA::getLook, this)},
            {"broadcast", std::bind(&IA::getBroadcast, this)},
            {"inventory", std::bind(&IA::getInventory, this)},
            {"connect_nbr", std::bind(&IA::getConnectNbr, this)},
            {"fork", std::bind(&IA::getFork, this)},
            {"eject", std::bind(&IA::getEject, this)},
            {"take", std::bind(&IA::getTake, this)},
            {"set", std::bind(&IA::getSet, this)},
            {"incantation", std::bind(&IA::getIncantation, this)},
        };

};

#endif /* !IA_HPP_ */
