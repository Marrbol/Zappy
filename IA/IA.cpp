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

void IA::calculeMateriauxPoids()
{
    size_t _poidFood = (_inventaire.getFood() - _inventaire.getFood()) / FOODRARETY;
    size_t _poidLinemate = (_rituels[_level].getLinemate() - _inventaire.getLinemate()) / LINEMATERARETY;
    size_t _poidDeraumere = (_rituels[_level].getDeraumere() - _inventaire.getDeraumere()) / DERAUMERERARETY;
    size_t _poidSibur = (_rituels[_level].getSibur() - _inventaire.getSibur()) / SIBURRARETY;
    size_t _poidMendiane = (_rituels[_level].getMendiane() - _inventaire.getMendiane()) / MENDIANERARETY;
    size_t _poidPhiras = (_rituels[_level].getPhiras() - _inventaire.getPhiras()) / PHIRASRARETY;
    size_t _poidThystame = (_rituels[_level].getThystame() - _inventaire.getThystame()) / THYSTAMERARETY;

    _poidMateriaux.setDeraumere(_poidDeraumere);
    _poidMateriaux.setFood(_poidFood);
    _poidMateriaux.setLinemate(_poidLinemate);
    _poidMateriaux.setMendiane(_poidMendiane);
    _poidMateriaux.setPhiras(_poidPhiras);
    _poidMateriaux.setSibur(_poidSibur);
    _poidMateriaux.setThystame(_poidThystame);
    // std::cout << "poid food = " << _poidFood << std::endl;
    // std::cout << "poid linemate = " << _poidLinemate << std::endl;
    // std::cout << "poid deraumere = " << _poidDeraumere << std::endl;
    // std::cout << "poid sibur = " << _poidSibur << std::endl;
    // std::cout << "poid mendiane = " << _poidMendiane << std::endl;
    // std::cout << "poid phiras = " << _poidPhiras << std::endl;
    // std::cout << "poid thystame = " << _poidThystame << std::endl;
}

void IA::calculeTilesPoids()
{
    for (size_t i = 0; i < _maxCaseViewLevel[_level]; i++) {
        size_t poidTmp = 0;
        if (_view[i].find("food") != std::string::npos)
            poidTmp += _poidMateriaux.getFood();
        if (_view[i].find("linemate") != std::string::npos)
            poidTmp += _poidMateriaux.getLinemate();
        if (_view[i].find("deraumere") != std::string::npos)
            poidTmp += _poidMateriaux.getDeraumere();
        if (_view[i].find("sibur") != std::string::npos)
            poidTmp += _poidMateriaux.getSibur();
        if (_view[i].find("mendiane") != std::string::npos)
            poidTmp += _poidMateriaux.getMendiane();
        if (_view[i].find("phiras") != std::string::npos)
            poidTmp += _poidMateriaux.getPhiras();
        if (_view[i].find("thystame") != std::string::npos)
            poidTmp += _poidMateriaux.getThystame();
        _tilesPoid[i] = poidTmp;
        // std::cout << " poid de case " << i << " = " << _tilesPoid[i] << std::endl;
    }
}

// trouver un moyen de savoir quelles ressources sont sur quelles cases et de stocker ça

// int main()
// {
//     IA ia;
//     ia.look();
//     std::cout << std::endl;
//     ia.calculeMateriauxPoids();
//     std::cout << std::endl;
//     ia.calculeTilesPoids();
//     std::cout << "fini" <<std::endl;
//     return 0;
// }
void IA::loopIA()
{
    while (1) {
        IA::communicateWithServer();
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
