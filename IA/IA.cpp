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
    _port = port;
}

IA::~IA()
{
}

void IA::calculeMateriauxPoids()
{
    size_t _poidFood =  (1 / FOODRARETY);
    if (_inventaire.getFood() < 10)
        _poidFood *= 10;
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
    // std::cout << std::endl;
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

void IA::signal_handler(int signal)
{
    Process process;
    if (signal == SIGINT) {
        process.exitProcess(0);
    }
}

void IA::calculeTilesPoids()
{
    calculeMateriauxPoids();
    for (size_t i = 0; i <= _maxCaseViewLevel[_level]; i++) {
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
        // std::cout << "poid de la case " << i << " = " << _tilesPoid[i] << std::endl;
    }
    for (size_t i = 1; i <= _maxCaseViewLevel[_level]; i++)
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

    for (; nbCommandLeft > 0 && nbMaterials > 0; nbCommandLeft--) {
        if (nbFood > 0) {
            take(FOOD);
            nbFood--;
            nbMaterials--;
            _takeObject.push_back(FOOD);
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(FOOD), 4);
            continue;
        }
        if (nbLinemate > 0) {
            take(LINEMATE);
            nbLinemate--;
            nbMaterials--;
            _takeObject.push_back(LINEMATE);
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(LINEMATE), 8);
            continue;
        }
        if (nbDeraumere > 0) {
            take(DERAUMERE);
            nbDeraumere--;
            nbMaterials--;
            _takeObject.push_back(DERAUMERE);
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(DERAUMERE), 9);
            continue;
        }
        if (nbSibur > 0) {
            take(SIBUR);
            nbSibur--;
            nbMaterials--;
            _takeObject.push_back(SIBUR);
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(SIBUR), 5);
            continue;
        }
        if (nbMendiane > 0) {
            take(MENDIANE);
            nbMendiane--;
            nbMaterials--;
            _takeObject.push_back(MENDIANE);
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(MENDIANE), 8);
            continue;
        }
        if (nbPhiras > 0) {
            take(PHIRAS);
            nbPhiras--;
            nbMaterials--;
            _takeObject.push_back(PHIRAS);
            _view[_numTilesPriority].erase(_view[_numTilesPriority].find(PHIRAS), 6);
            continue;
        }
        if (nbThystame > 0) {
            take(THYSTAME);
            nbThystame--;
            nbMaterials--;
            _takeObject.push_back(THYSTAME);
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
        _coordBestCase.first--;
        nbCommandLeft--;
    }
    if (_coordBestCase.first == 0 && _coordBestCase.second == 0) {
        isTurned = false;
        return !false;
    }
    return !true;
}

void IA::ForkTheProgram()
{
    _pid = _process.forkProcess();
    if (_pid == 0) {
        IA newIA(_port, _teamName, _machine);
        newIA.loopIA();
        _process.exitProcess(0);
    }
}

void IA::isItForRitual(std::string materiaux)
{
    if (!_canIncantation)
        return;
    if (materiaux == LINEMATE && _rituels[_level].getLinemate() > 0) {
        _rituels[_level].setLinemate(_rituels[_level].getLinemate() - 1);
        std::cout << "Linemate left for ritual = " << _rituels[_level].getLinemate() << std::endl;
        if (_level > 1)
            broadcast(_teamName + " f 1");
    }
    if (materiaux == DERAUMERE && _rituels[_level].getDeraumere() > 0) {
        _rituels[_level].setDeraumere(_rituels[_level].getDeraumere() - 1);
        broadcast(_teamName + " f 2");
    }
    if (materiaux == SIBUR && _rituels[_level].getSibur() > 0) {
        _rituels[_level].setSibur(_rituels[_level].getSibur() - 1);
        broadcast(_teamName + " f 3");
    }
    if (materiaux == MENDIANE && _rituels[_level].getMendiane() > 0) {
        _rituels[_level].setMendiane(_rituels[_level].getMendiane() - 1);
        broadcast(_teamName + " f 4");
    }
    if (materiaux == PHIRAS && _rituels[_level].getPhiras() > 0) {
        _rituels[_level].setPhiras(_rituels[_level].getPhiras() - 1);
        broadcast(_teamName + " f 5");
    }
    if (materiaux == THYSTAME && _rituels[_level].getThystame() > 0) {
        _rituels[_level].setThystame(_rituels[_level].getThystame() - 1);
        broadcast(_teamName + " f 6");
    }
}

void IA::assembleAllAI()
{
    if (everyoneHere) {
        broadcast(_teamName + " startRitual");
        incantation();
        return;
    }
    if (_rituels[_level].getLinemate() == 0 && _rituels[_level].getDeraumere() == 0 && _rituels[_level].getSibur() == 0 && _rituels[_level].getMendiane() == 0 && _rituels[_level].getPhiras() == 0 && _rituels[_level].getThystame() == 0) {
        broadcast(_teamName + " incantation");
        return;
    }
}

void IA::removeMaterialForIncanation()
{
    std::cout << "remove material for incantation" << std::endl;
    if (_rituels[_level].getLinemate() > 0 && _inventaire.getLinemate() > 0) {
        int nbLinemate = _rituels[_level].getLinemate() - _inventaire.getLinemate();
        if (nbLinemate < 0)
            _rituels[_level].setLinemate(0);
        else
            _rituels[_level].setLinemate(nbLinemate);
    }
    std::cout << _clientName << "  jui " << _rituels[_level].getLinemate() << std::endl;
    if (_rituels[_level].getDeraumere() > 0 && _inventaire.getDeraumere() > 0) {
        int nbDeraumere = _rituels[_level].getDeraumere() - _inventaire.getDeraumere();
        if (nbDeraumere < 0)
            _rituels[_level].setDeraumere(0);
        else
            _rituels[_level].setDeraumere(nbDeraumere);
    }
    if (_rituels[_level].getSibur() > 0 && _inventaire.getSibur() > 0) {
        int nbSibur = _rituels[_level].getSibur() - _inventaire.getSibur();
        if (nbSibur < 0)
            _rituels[_level].setSibur(0);
        else
            _rituels[_level].setSibur(nbSibur);
    }
    if (_rituels[_level].getMendiane() > 0 && _inventaire.getMendiane() > 0) {
        int nbMendiane = _rituels[_level].getMendiane() - _inventaire.getMendiane();
        if (nbMendiane < 0)
            _rituels[_level].setMendiane(0);
        else
            _rituels[_level].setMendiane(nbMendiane);
    }
    if (_rituels[_level].getPhiras() > 0 && _inventaire.getPhiras() > 0) {
        int nbPhiras = _rituels[_level].getPhiras() - _inventaire.getPhiras();
        if (nbPhiras < 0)
            _rituels[_level].setPhiras(0);
        else
            _rituels[_level].setPhiras(nbPhiras);
    }
    if (_rituels[_level].getThystame() > 0 && _inventaire.getThystame() > 0) {
        int nbThystame = _rituels[_level].getThystame() - _inventaire.getThystame();
        if (nbThystame < 0)
            _rituels[_level].setThystame(0);
        else
            _rituels[_level].setThystame(nbThystame);
    }
}

void IA::loopIA()
{
    bool sendlook = false;
    bool calculated = false;
    std::signal(SIGINT, signal_handler);
    while (!!!!!!!!1) {
        do {
            IA::communicateWithServer();
        } while (_name == false);
        if (_isDead) {
            if (_pid != 0)
                _process.waitProcess();
            break;
        }
        if (!forked) {
            if (this->_clientName > 0) {
                forkIA();
            } else
                broadcast(_teamName + " start");
            forked = true;
        }
        if (_role == "leader" && !_canIncantation)
            continue;
        if (_role == "")
            continue;
        if (_ritualAsked)
            continue;
        if (_level == 1 && _rituels[_level].getLinemate() == 0) {
            incantation();
            std::cout << "oui non incantation" << std::endl;
        }
        if (_canIncantation && _role == "leader" && _level > 1) {
            assembleAllAI();
        }
        if (!_view.empty()) {
            bool here = false;
            if (goToRitual) {
                here = true;
                switch (_ritualDirection)
                {
                case 1:
                    forward();
                    break;
                case 2:
                    forward();
                    turnLeft();
                    forward();
                    break;
                case 3:
                    turnLeft();
                    forward();
                    break;
                case 4:
                    turnLeft();
                    forward();
                    turnLeft();
                    forward();
                    break;
                case 5:
                    turnLeft();
                    turnLeft();
                    forward();
                    break;
                case 6:
                    turnRight();
                    forward();
                    turnRight();
                    forward();
                    break;
                case 7:
                    turnRight();
                    forward();
                    break;
                case 8:
                    forward();
                    turnRight();
                    forward();
                    break;
                case 0:
                    continue;
                default:
                    break;
                }
            }else {
                if (!calculated) {
                    IA::calculateCoordBestCase();
                    calculated = true;
                    if (_tilesPoid[_numTilesPriority] == 0) {
                        _view.clear();
                        sendlook = false;
                        forward();
                    }
                }
                here = moveTheIAToTheBestCase();
            }
            if (here) {
                if (GetAllRessourcesTile()) {
                    inventory();
                    std::cout << _clientName << " linemate : "<< _inventaire.getLinemate() << std::endl;
                    // std::cout << _inventaire.getDeraumere() << std::endl;
                    // std::cout << _inventaire.getLinemate() << std::endl;
                    // std::cout << _inventaire.getMendiane() << std::endl;
                    // std::cout << _inventaire.getPhiras() << std::endl;
                    // std::cout << _inventaire.getSibur() << std::endl;
                    // std::cout << _inventaire.getThystame() << std::endl;
                    if (!goToRitual) {
                        _view.clear();
                        sendlook = false;
                    }
                }
            }
                 // faire une fonction qui check si on a toutes les ressources
        } else {
            if (!sendlook && _ask.size() < 10) {
                IA::look();
                sendlook = true;
                _numTilesPriority = 0;
                calculated = false;
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
    std::cout << "nb: " << _clientName << " the case and the coord for the best case are " << _numTilesPriority << " and the coord are " <<_coordBestCase.second << " and " << _coordBestCase.first << std::endl;
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
