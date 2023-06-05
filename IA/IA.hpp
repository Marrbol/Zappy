/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** IA
*/

#ifndef IA_HPP_
#define IA_HPP_

#include <string>
#include <functional>
#include "../network/Network.hpp"
#include <vector>
#include <iostream>
#include <error.h>

class IA {
    public:
        IA(int port, std::string machine);
        ~IA();
        void communicateWithServer();
        bool parseCommande();
        void connection();

    protected:
    private:
        fd_set _readfds;
        Network _network;
        int _socket;
        std::string _commande;
        std::string _machine;
        std::string _line;
        size_t x = 0;
        size_t y = 0;

        using CommandFunction = std::function<void(void)>;

        typedef struct allCmdS {
            std::string cmd;
            CommandFunction func;
        } allCmdT;

        std::vector<allCmdT> _cmd = {
            {"WELCOME", std::bind(&IA::connection, this)},
            {"NULL", NULL}
        };

};

#endif /* !IA_HPP_ */
