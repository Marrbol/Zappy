/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** IA
*/

#include "IA.hpp"

IA::IA(int port, std::string machine) : _machine(machine)
{
    _network = Network();
    _socket = _network.connectSocketClient(machine, port);
}

IA::~IA()
{
}

void IA::connection()
{
    _network.sendMessage(_socket, "GRAPHIC\n");
    std::cout << "Connection to server" << std::endl;
}

bool IA::parseCommande()
{
    bool isParsed = false;
    while (_commande.find("\n") != std::string::npos) {
        _line = _commande.substr(0, _commande.find("\n"));
        _commande.erase(0, _commande.find("\n") + 1);
        std::string cmd = _line.substr(0, _line.find(" "));
        std::cout << "commande: " << _line << std::endl; // "x y n
        _line.erase(0, _line.find(" ") + 1);
        std::cout << "cmd: " << cmd << std::endl;
        for (size_t i = 0; _cmd[i].cmd.compare("NULL"); i++) {
            if (_cmd[i].cmd == cmd) {
                isParsed = true;
                _cmd[i].func();
                break;
            }
        }
    }
    return isParsed;
}

void IA::communicateWithServer()
{
    while (1) {
        if (_network.selectSocket(_socket, &_readfds) == -1)
            throw std::runtime_error("Error: select failed");
        if (_network.fdReady(_socket, &_readfds)) {
            _commande = _network.receiveMessage(_socket);
            if (!parseCommande())
                std::cout << "Unknown command" << std::endl;
        }
    }
}

int main(int ac, char **av)
{
    IA IA(atoi(av[1]), av[2]);
    IA.communicateWithServer();
    return 0;
}