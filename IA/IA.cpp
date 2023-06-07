/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** IA
*/

#include "IA.hpp"

IA::IA(int port, std::string name, std::string machine) : _machine(machine), _teamName(name)
{
    _network = Network();
    _socket = _network.connectSocketClient(machine, port);
}

IA::~IA()
{
}


// int main(int ac, char **av)
// {
//     if (ac != 4)
//         return 84;
//     IA IA(atoi(av[1]), av[2], av[3]);
//     IA.communicateWithServer();
//     return 0;
// }
