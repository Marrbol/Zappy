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
    _view.clear();
}

IA::~IA()
{
}

void IA::calculeMateriauxPoids()
{
    size_t _poidFood =  (1 / FOODRARETY);
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
    std::cout << "poid food = " << _poidFood << std::endl;
    std::cout << "poid linemate = " << _poidLinemate << std::endl;
    std::cout << "poid deraumere = " << _poidDeraumere << std::endl;
    std::cout << "poid sibur = " << _poidSibur << std::endl;
    std::cout << "poid mendiane = " << _poidMendiane << std::endl;
    std::cout << "poid phiras = " << _poidPhiras << std::endl;
    std::cout << "poid thystame = " << _poidThystame << std::endl;
    std::cout << std::endl;
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
    calculeMateriauxPoids();
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
        std::cout << "case " << i << " have a poid of " << poidTmp << std::endl;
    }
    for (size_t i = 0; i < _maxCaseViewLevel[_level]; i++)
        if (_tilesPoid[i] > _tilesPoid[_numTilesPriority])
            _numTilesPriority = i;
}

bool IA::GetAllRessourcesTile()
{
    std::string tile =_view[_numTilesPriority];
    size_t nbCommandLeft = 10 - _ask.size();
    size_t nbFood = countSubStr(tile, FOOD);
    size_t nbLinemate = countSubStr(tile, LINEMATE);
    size_t nbDeraumere = countSubStr(tile, DERAUMERE);
    size_t nbSibur = countSubStr(tile, SIBUR);
    size_t nbMendiane = countSubStr(tile, MENDIANE);
    size_t nbPhiras = countSubStr(tile, PHIRAS);
    size_t nbThystame = countSubStr(tile, THYSTAME);
    size_t nbMaterials = nbFood + nbLinemate + nbDeraumere + nbSibur + nbMendiane + nbPhiras + nbThystame;
    std::cout << "nbMaterials = " << nbMaterials << std::endl;


    for (; nbCommandLeft > 0 && nbMaterials > 0; nbCommandLeft--) {
        if (nbFood > 0) {
            take(FOOD);
            nbFood--;
            nbMaterials--;
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(FOOD), 4);
            continue;
        }
        if (nbLinemate > 0) {
            take(LINEMATE);
            nbLinemate--;
            nbMaterials--;
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(LINEMATE), 8);
            continue;
        }
        if (nbDeraumere > 0) {
            take(DERAUMERE);
            nbDeraumere--;
            nbMaterials--;
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(DERAUMERE), 9);
            continue;
        }
        if (nbSibur > 0) {
            take(SIBUR);
            nbSibur--;
            nbMaterials--;
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(SIBUR), 5);
            continue;
        }
        if (nbMendiane > 0) {
            take(MENDIANE);
            nbMendiane--;
            nbMaterials--;
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(MENDIANE), 8);
            continue;
        }
        if (nbPhiras > 0) {
            take(PHIRAS);
            nbPhiras--;
            nbMaterials--;
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(PHIRAS), 6);
            continue;
        }
        if (nbThystame > 0) {
            take(THYSTAME);
            nbThystame--;
            nbMaterials--;
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(THYSTAME), 8);
            continue;
        }
    }
    if (nbMaterials == 0)
        return !false;
    return !true;
}

bool IA::moveTheIAToTheBestCase()
{
    size_t nbCommandLeft = 10 - _ask.size();

    while (nbCommandLeft > 0 && _coordBestCase.second > 0) {
        forward();
        std::cout << "I avance\n";
        _coordBestCase.second--;
        nbCommandLeft--;
    }
    if (!!!isTurned) {
        if (_coordBestCase.first > 0)
            turnRight();
        if (_coordBestCase.first < 0) {
            turnLeft();
            _coordBestCase.first *= -1;
        }
        isTurned = true;
    }
    while (nbCommandLeft > 0 && _coordBestCase.first > 0) {
        forward();
        std::cout << "I avance\n";
        _coordBestCase.first--;
        nbCommandLeft--;
    }
    if (_coordBestCase.first == 0 && _coordBestCase.second == 0)
        return !false;
    return !true;
}

void IA::loopIA()
{
    bool sendlook = false;
    bool calculated = false;
    while (1) {
        do {
            IA::communicateWithServer();
        } while (_name == false);
        std::cout << "c'est le print de avant le if et apres le while pour voir si le do while se fait\n";
        std::cout << "ask size = " << _ask.size() << " and send look = " << sendlook << std::endl;
        if (_ask.size() > 0)
            std::cout << "ask i = " << _ask.front() << std::endl;
        if (_isDead)
            break;
        if (!_view.empty()) {
            std::cout << "estc e qu'il rentre dans le if\n";
            if (!calculated) {
                IA::calculateCoordBestCase();
                calculated = true;
                if (_tilesPoid[_numTilesPriority] == 0) {
                    _view.clear();
                    sendlook = false;
                    forward();
                }
            }
            std::cout << "avant le move\n";
            bool here = moveTheIAToTheBestCase();
            std::cout << "cest pour que ca marche\n";
            std::cout << _ask.size() << std::endl;
            if (here) {
                if (GetAllRessourcesTile()) {
                    std::cout << _inventaire.getFood() << std::endl;
                    std::cout << _inventaire.getDeraumere() << std::endl;
                    std::cout << _inventaire.getLinemate() << std::endl;
                    std::cout << _inventaire.getMendiane() << std::endl;
                    std::cout << _inventaire.getPhiras() << std::endl;
                    std::cout << _inventaire.getSibur() << std::endl;
                    std::cout << _inventaire.getThystame() << std::endl;
                    _view.clear();
                    sendlook = false;
                    std::cout << "je suis dans le if\n";
                } else {
                    std::cout << "je suis dans le else\n";
                }
            }
        } else {
            if (!sendlook && _ask.size() < 10) {
                IA::look();
                sendlook = true;
                _numTilesPriority = 0;
                calculated = false;
                std::cout << "il est là?\n";
            }
        }
    }
}

void IA::calculateCoordBestCase()
{
    IA::calculeTilesPoids();
    for (size_t i = 1; i <= MAXLEVEL; i++) {
        if ((_numTilesPriority >= i * i) && (_numTilesPriority <= ((i + 1) * (i + 1) - 1) )) {
            _coordBestCase.second = i;
            size_t middleCase = _coordBestCase.second * (_coordBestCase.second + 1);
            _coordBestCase.first = abs(int(middleCase - _numTilesPriority));
            if (middleCase > _numTilesPriority)
                _coordBestCase.first *= -1;
        }
    }
    std::cout << "the case and the coord for the best case are " << _numTilesPriority << " and the coord are " <<_coordBestCase.second << " and " << _coordBestCase.first << std::endl;
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
