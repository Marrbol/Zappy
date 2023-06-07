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

void IA::loopIA()
{
    IA::communicateWithServer();
    while (1) {
    }
}

void printUsage() {
    std::cout << "USAGE: ./zappy_ai -p port -n name -h machine\n"
              << "port is the port number\n"
              << "name is the name of the team\n"
              << "machine is the name of the machine; localhost by default\n";
}

int main(int ac, char **av)
{
    size_t port = 0;
    std::string name;
    std::string machine;
    if (ac != 7 || std::string(av[1]) == "-help") {
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
            case ('n'):
                name = av[i + 1];
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
    try {
        IA IA(port, name, machine);
        IA.loopIA();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
