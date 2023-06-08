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
    size_t _poidFood = (_inventaire.getFood() - _inventaire.getFood()) * (1 / FOODRARETY);
    size_t _poidLinemate = (_rituels[_level].getLinemate() - _inventaire.getLinemate()) * (1 / LINEMATERARETY);
    size_t _poidDeraumere = (_rituels[_level].getDeraumere() - _inventaire.getDeraumere()) * (1 / DERAUMERERARETY);
    size_t _poidSibur = (_rituels[_level].getSibur() - _inventaire.getSibur()) * (1 / SIBURRARETY);
    size_t _poidMendiane = (_rituels[_level].getMendiane() - _inventaire.getMendiane()) * (1 / MENDIANERARETY);
    size_t _poidPhiras = (_rituels[_level].getPhiras() - _inventaire.getPhiras()) * (1 / PHIRASRARETY);
    size_t _poidThystame = (_rituels[_level].getThystame() - _inventaire.getThystame()) * (1 / THYSTAMERARETY);

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

size_t IA::countSubStr(std::string str, std::string subStr)
{
    size_t pos = 0;
    size_t count = 0;
    while ((pos = str.find(subStr, pos)) != std::string::npos) {
        count++;
        pos += subStr.length();
    }
    return count;
}

void IA::calculeTilesPoids()
{
    for (size_t i = 0; i < _maxCaseViewLevel[_level]; i++) {
        size_t poidTmp = 0;
        if (_view[i].find(FOOD) != std::string::npos)
            poidTmp += countSubStr(_view[i], FOOD) * _poidMateriaux.getFood();
        if (_view[i].find(LINEMATE) != std::string::npos)
            poidTmp += countSubStr(_view[i], LINEMATE) * _poidMateriaux.getLinemate();
        if (_view[i].find(DERAUMERE) != std::string::npos)
            poidTmp += countSubStr(_view[i], DERAUMERE) * _poidMateriaux.getDeraumere();
        if (_view[i].find(SIBUR) != std::string::npos)
            poidTmp += countSubStr(_view[i], SIBUR) * _poidMateriaux.getSibur();
        if (_view[i].find(MENDIANE) != std::string::npos)
            poidTmp += countSubStr(_view[i], MENDIANE) * _poidMateriaux.getMendiane();
        if (_view[i].find(PHIRAS) != std::string::npos)
            poidTmp += countSubStr(_view[i], PHIRAS) * _poidMateriaux.getPhiras();
        if (_view[i].find(THYSTAME) != std::string::npos)
            poidTmp += countSubStr(_view[i], THYSTAME) * _poidMateriaux.getThystame();
        _tilesPoid[i] = poidTmp;
        // std::cout << " poid de case " << i << " = " << _tilesPoid[i] << std::endl;
    }
}


// int main()
// {
//     IA ia;
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
