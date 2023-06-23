/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** CommuncateWithServer
*/

#include "IA.hpp"


void IA::forward()
{
    _network.sendMessage(_socket, "Forward\n");
    _ask.push_back("Forward");
}

void IA::turnLeft()
{
    _network.sendMessage(_socket, "Left\n");
    _ask.push_back("Left");
}

void IA::turnRight()
{
    _network.sendMessage(_socket, "Right\n");
    _ask.push_back("Right");
}

void IA::look()
{
    _network.sendMessage(_socket, "Look\n");
    _ask.push_back("Look");
    _view.clear();
}

void IA::broadcast(std::string message)
{
    _network.sendMessage(_socket, "Broadcast " + message + "\n");
    _ask.push_back("Broadcast");
    std::cout << _clientName << " Broadcast " + message + "\n" << std::endl;
}

void IA::inventory()
{
    _network.sendMessage(_socket, "Inventory\n");
    _ask.push_back("Inventory");
}

void IA::connectNbr()
{
    _network.sendMessage(_socket, "Connect_nbr\n");
    _ask.push_back("Connect_nbr");
}

void IA::forkIA()
{
    _network.sendMessage(_socket, "Fork\n");
    _ask.push_back("Fork");
}

void IA::eject()
{
    _network.sendMessage(_socket, "Eject\n");
    _ask.push_back("Eject");
}

void IA::take(std::string object)
{
    _network.sendMessage(_socket, "Take " + object + "\n");
    _ask.push_back("Take");
}

void IA::set(std::string object)
{
    _network.sendMessage(_socket, "Set " + object + "\n");
    std::cout << _clientName << " Set " + object << std::endl;
    _ask.push_back("Set");
}

void IA::incantation()
{
    if (_inventaire.getFood() < 5)
        return;
    _ritualAfter = false;
    bool end = false;
    if (_level == 1) {
        set(LINEMATE);
        end = true;
    } else if (_role == "leader") {
        while (_ask.size() < 9) {
            if (_rituelsLeader[_level].getLinemate() > 0) {
                _rituelsLeader[_level].setLinemate(_rituelsLeader[_level].getLinemate() - 1);
                set(LINEMATE);
                _inventaire.setLinemate(_inventaire.getLinemate() - 1);
                continue;
            }
            if (_rituelsLeader[_level].getDeraumere() > 0) {
                _rituelsLeader[_level].setDeraumere(_rituelsLeader[_level].getDeraumere() - 1);
                set(DERAUMERE);
                _inventaire.setDeraumere(_inventaire.getDeraumere() - 1);
                continue;
            }
            if (_rituelsLeader[_level].getSibur() > 0) {
                _rituelsLeader[_level].setSibur(_rituelsLeader[_level].getSibur() - 1);
                set(SIBUR);
                _inventaire.setSibur(_inventaire.getSibur() - 1);
                continue;
            }
            if (_rituelsLeader[_level].getMendiane() > 0) {
                _rituelsLeader[_level].setMendiane(_rituelsLeader[_level].getMendiane() - 1);
                set(MENDIANE);
                _inventaire.setMendiane(_inventaire.getMendiane() - 1);
                continue;
            }
            if (_rituelsLeader[_level].getPhiras() > 0) {
                _rituelsLeader[_level].setPhiras(_rituelsLeader[_level].getPhiras() - 1);
                set(PHIRAS);
                _inventaire.setPhiras(_inventaire.getPhiras() - 1);
                continue;
            }
            if (_rituelsLeader[_level].getThystame() > 0) {
                _rituelsLeader[_level].setThystame(_rituelsLeader[_level].getThystame() - 1);
                set(THYSTAME);
                _inventaire.setThystame(_inventaire.getThystame() - 1);
                continue;
            }
            _rituelsLeader = _cpRituelsLeader;
            _setEverythingRitual = false;
            end = true;
        }
    }
    if ((_role == "leader" && !end) || !_leaderRitual)
        return;
    _network.sendMessage(_socket, "Incantation\n");
    _ask.push_back("Incantation");
    _ritualAsked = true;
    std::cout << _clientName << " Incantation to level " << _level << std::endl;
}

void IA::parseCommande()
{
    while (_commande.find("\n") != std::string::npos) {
        _line = _commande.substr(0, _commande.find("\n"));
        // std::cout << _clientName << " Message received: " << _line << std::endl;
        if (_line == "ko") {
            std::cout << _clientName << " KO " << _ask.front() << " " << _ask.size() << std::endl;
        }
        _commande.erase(0, _commande.find("\n") + 1);
        if (_line == "WELCOME") {
            _start = true;
            _network.sendMessage(_socket, _teamName + "\n");
            continue;
        }
        if (_start) {
            if (!_name) {
                _name = true;
                _clientName = std::stoi(_line);
            } else {
                _start = false;
                size_t x = std::stoi(_line.substr(0, _line.find(" ")));
                _line.erase(0, _line.find(" ") + 1);
                size_t y = std::stoi(_line.substr(0, _line.find(" ")));
                _mapSize = std::make_pair(x, y);
                _line.erase(0, _line.find(" ") + 1);
                broadcast(_teamName + " Hello " + std::to_string(_clientName));
            }
            continue;
        }
        if (_line == "dead") {
            std::cout << "Dead" << std::endl;
            _isDead = true;
            break;
        }
        if (_line.substr(0, _line.find(" ")) == "Current") {
            _line.erase(0, _line.find(" ") + 1);
            _line.erase(0, _line.find(" ") + 1);
            _level = std::stoi(_line.substr(0, _line.find("\n")));
            everyoneHere = false;
            _ritualAsked = false;
            _ritualAfter = false;
            goToRitual = false;
            nbPlayerHere = 0;
            _saidHere = false;
            _readyIncantation = false;
            std::cout << "Level: " << _level << " currentname = " << _clientName << std::endl;
            removeMaterialForIncanation();
            continue;
        }
        if (_line.substr(0, _line.find(" ")) == "message")
            _ask.push_front("message");
        for (size_t i = 0; _cmd[i].cmd.compare("NULL"); i++) {
            if (_cmd[i].cmd == _ask.front()) {
                _cmd[i].func();
                break;
            }
        }
    }
}

void IA::communicateWithServer()
{
    if (_network.selectSocket(_socket, &_readfds) == -1)
        throw std::runtime_error("Error: select failed");
    if (_network.fdReady(_socket, &_readfds)) {
        _commande = _network.receiveMessage(_socket);
        parseCommande();
    }
}

void IA::reduceForRitual(std::string materiaux)
{
    size_t level = _level;
    if (_line.find(" ") != std::string::npos) {
        _line.erase(0, _line.find(" ") + 1);
        level = std::stoi(_line.substr(0, _line.find(" ")));
    }
    switch (materiaux[0])
    {
    case '1':
        if (_rituels[level].getLinemate() > 0)
            _rituels[level].setLinemate(_rituels[level].getLinemate() - 1);
        break;
    case '2':
        if (_rituels[level].getDeraumere() > 0)
            _rituels[level].setDeraumere(_rituels[level].getDeraumere() - 1);
        break;
    case '3':
        if (_rituels[level].getSibur() > 0)
            _rituels[level].setSibur(_rituels[level].getSibur() - 1);
        break;
    case '4':
        if (_rituels[level].getMendiane() > 0)
            _rituels[level].setMendiane(_rituels[level].getMendiane() - 1);
        break;
    case '5':
        if (_rituels[level].getPhiras() > 0)
            _rituels[level].setPhiras(_rituels[level].getPhiras() - 1);
        break;
    case '6':
        if (_rituels[level].getThystame() > 0)
            _rituels[level].setThystame(_rituels[level].getThystame() - 1);
        break;
    default:
        break;
    }
}

bool IA::setRitual()
{
    while (_ask.size() < 9) {
        if (_inventaire.getLinemate() > 0 && _cpRituels[_level].getLinemate() > 0) {
            _cpRituels[_level].setLinemate(_cpRituels[_level].getLinemate() - 1);
            set(LINEMATE);
            _inventaire.setLinemate(_inventaire.getLinemate() - 1);
            continue;
        }
        if (_inventaire.getDeraumere() > 0 && _cpRituels[_level].getDeraumere() > 0) {
            _cpRituels[_level].setDeraumere(_cpRituels[_level].getDeraumere() - 1);
            set(DERAUMERE);
            _inventaire.setDeraumere(_inventaire.getDeraumere() - 1);
            continue;
        }
        if (_inventaire.getSibur() > 0 && _cpRituels[_level].getSibur() > 0) {
            _cpRituels[_level].setSibur(_cpRituels[_level].getSibur() - 1);
            set(SIBUR);
            _inventaire.setSibur(_inventaire.getSibur() - 1);
            continue;
        }
        if (_inventaire.getMendiane() > 0 && _cpRituels[_level].getMendiane() > 0) {
            _cpRituels[_level].setMendiane(_cpRituels[_level].getMendiane() - 1);
            set(MENDIANE);
            _inventaire.setMendiane(_inventaire.getMendiane() - 1);
            continue;
        }
        if (_inventaire.getPhiras() > 0 && _cpRituels[_level].getPhiras() > 0) {
            _cpRituels[_level].setPhiras(_cpRituels[_level].getPhiras() - 1);
            set(PHIRAS);
            _inventaire.setPhiras(_inventaire.getPhiras() - 1);
            continue;
        }
        if (_inventaire.getThystame() > 0 && _cpRituels[_level].getThystame() > 0) {
            _cpRituels[_level].setThystame(_cpRituels[_level].getThystame() - 1);
            set(THYSTAME);
            _inventaire.setThystame(_inventaire.getThystame() - 1);
            continue;
        }
        return true;
    }
    return false;
}

void IA::ReceiveMessage()
{
    _ask.pop_front();
    _line.erase(0, _line.find(" ") + 1);
    size_t direction = std::stoi(_line.substr(0, _line.find(",")));
    _line.erase(0, _line.find(",") + 1);
    if (_line[0] == ' ')
        _line.erase(0, 1);
    // _messageReceived.push_back(std::make_pair(direction, _line));
    if (_line.substr(0, _line.find(" ")) == _teamName) {
        _line.erase(0, _line.find(" ") + 1);
        std::string cmd = _line.substr(0, _line.find(" "));
        if (cmd == "Hello") {
            if (_role == "")
                _role = "leader";
            if (_role == "leader") {
                _line.erase(0, _line.find(" ") + 1);
                int numberWorker = std::stoi(_line.substr(_line.find(" ") + 1, _line.size()));
                broadcast(_teamName + " Hola worker ");
            }
        }
        if (cmd == "Hola" && _role == "")
            _role = "worker";
        if (cmd == "start") {
            _canIncantation = true;
            removeMaterialForIncanation();
        }
        if (cmd == "f")
            reduceForRitual(_line.substr(_line.find(" ") + 1, _line.size()));
        if (cmd == "incantation") {
            if (_saidHere) {
                _ritualDirection = 0;
                return;
            }
            if (_inventaire.getFood() < 30)
                return;
            if (direction == 0 && !_readyIncantation) {
                _readyIncantation = true;
                _saidHere = false;
            }
            goToRitual = true;
            _ritualDirection = direction;
        }
        if (cmd == "startRitual") {
            _line.erase(0, _line.find(" ") + 1);
            size_t number = stoi(_line);
            if (number == _clientName) {
                incantation();
                goToRitual = false;
            }
        }
        if (cmd == "come") {
            _line.erase(0, _line.find(" ") + 1);
            size_t number = stoi(_line.substr(0, _line.find(" ")));
            _line.erase(0, _line.find(" ") + 1);
            size_t number2 = stoi(_line);
            if (number == _clientName || number2 == _clientName) {
                goToRitual = true;
                _ritualDirection = direction;
                _ritualAfter = true;
                std::cout << _clientName << " come" << std::endl;
                _readyIncantation = false;
            }
        }
        if (cmd == "here") {
            if (_role == "leader") {
                nbPlayerHere++;
                look();
                if (nbPlayerHere == _clientName)
                    everyoneHere = true;
            }
        }
    } else if (_role == "leader")
        broadcast(_line);
    _line.clear();
}

void IA::getForward()
{
    if (_line == OK)
        _validate = true;
    _line.clear();
    _ask.pop_front();
}

void IA::getTurnLeft()
{
    if (_line == OK)
        _validate = true;
    _line.clear();
    _ask.pop_front();
}

void IA::getTurnRight()
{
    if (_line == OK)
        _validate = true;
    _line.clear();
    _ask.pop_front();
}

void IA::getLook()
{
    if (_line[0] == '[')
        _line.erase(0, 1);
    if (_line[_line.size() - 1] == ']')
        _line.erase(_line.size() - 1, 1);
    if (_line[0] == ' ')
        _line.erase(0, 1);
    if (_line[_line.size() - 1] == ' ')
        _line.erase(_line.size() - 1, 1);
    for (size_t x = 0; x <= _maxCaseViewLevel[_level] ; x++) {
        std::string tmp = _line.substr(0, _line.find(","));
        if (x == 0 && tmp.substr(0, _line.find(" ")) != "player"){
            // _ask.pop_front();
            // _ask.pop_front();
            // _ask.push_front("Look");
            // _ask.push_front("Inventory");
            return getInventory();
        }
        _line.erase(0, _line.find(",") + 1);
        if (_line[0] == ' ')
            _line.erase(0, 1);
        if (tmp[0] == ' ')
            tmp.erase(0, 1);
        if (tmp.size() == 0) {
            _view[x] = "";
            continue;
        }
        if (tmp[tmp.size() - 1] == ' ')
            tmp.erase(tmp.size() - 1, 1);
        _view[x] = tmp;
        if (_line.find(",") == std::string::npos) {
            _view[x + 1] = _line;
            break;
        }
    }
    _validate = true;
    _line.clear();
    _ask.pop_front();
}

void IA::getBroadcast()
{
    if (_line == OK)
        _validate = true;
    _line.clear();
    _ask.pop_front();
}

void IA::changeTheInventory(std::string material, int nb)
{
    if (material == FOOD)
        _inventaire.setFood(nb);
    if (material == LINEMATE)
        _inventaire.setLinemate(nb);
    if (material == DERAUMERE)
        _inventaire.setDeraumere(nb);
    if (material == SIBUR)
        _inventaire.setSibur(nb);
    if (material == MENDIANE)
        _inventaire.setMendiane(nb);
    if (material == PHIRAS)
        _inventaire.setPhiras(nb);
    if (material == THYSTAME)
        _inventaire.setThystame(nb);
}

void IA::getInventory()
{
    if (_line == "ok" || _line == "ko") {
        _validate = true;
        _line.clear();
        _ask.pop_front();
        return;
    }
    if (_line[0] == '[')
        _line.erase(0, 1);
    if (_line[_line.size() - 1] == ']')
        _line.erase(_line.size() - 1, 1);
    if (_line[0] == ' ')
        _line.erase(0, 1);
    if (_line[_line.size() - 1] == ' ')
        _line.erase(_line.size() - 1, 1);
    for (size_t x = 0; ; x++) {
        std::string tmp = _line.substr(0, _line.find(","));
        if (tmp[0] == ' ')
            tmp.erase(0, 1);
        if (tmp[tmp.size() - 1] == ' ')
            tmp.erase(tmp.size(), 1);
        if (tmp.substr(0, tmp.find(" ")) == "player") {
            // _ask.pop_front();
            // _ask.pop_front();
            // _ask.push_front("Inventory");
            // _ask.push_front("Look");
            return getLook();
        }
        _line.erase(0, _line.find(",") + 1);
        std::string material = tmp.substr(0, tmp.find(" "));
        tmp.erase(0, tmp.find(" ") + 1);
        size_t nb = std::stoi(tmp);
        changeTheInventory(material, nb);
        if (_line.find(",") == std::string::npos) {
            tmp = _line;
            if (tmp[0] == ' ')
                tmp.erase(0, 1);
            material = tmp.substr(0, tmp.find(" "));
            tmp.erase(0, tmp.find(" ") + 1);
            nb = std::stoi(tmp);
            changeTheInventory(material, nb);
            break;
        }
    }
    _validate = true;
    _line.clear();
    _ask.pop_front();
}

void IA::getConnectNbr()
{
    connectNbrLeft = std::stoi(_line);
    _validate = true;
    _line.clear();
    _ask.pop_front();
}

void IA::getFork()
{
    if (_line == OK) {
        _validate = true;
        ForkTheProgram();
    }
    _line.clear();
    _ask.pop_front();
}

void IA::getEject()
{
    if (_line == OK)
        _validate = true;
    else if (_line == KO) {
        _probleme = true;
        _line.clear();
        return;
    }
    _line.clear();
    _ask.pop_front();
}

void IA::getTake()
{
    if (_line == OK)
        _validate = true;
    else if (_line == KO) {
        _probleme = true;
        _line.clear();
        _ask.pop_front();
        return;
    }
    std::string object = _takeObject.front();
    _takeObject.pop_front();
    if (object == FOOD) {
        _inventaire.setFood(_inventaire.getFood() + 1);
    }
    if (object == LINEMATE)
        _inventaire.setLinemate(_inventaire.getLinemate() + 1);
    if (object == DERAUMERE)
        _inventaire.setDeraumere(_inventaire.getDeraumere() + 1);
    if (object == SIBUR)
        _inventaire.setSibur(_inventaire.getSibur() + 1);
    if (object == MENDIANE)
        _inventaire.setMendiane(_inventaire.getMendiane() + 1);
    if (object == PHIRAS)
        _inventaire.setPhiras(_inventaire.getPhiras() + 1);
    if (object == THYSTAME)
        _inventaire.setThystame(_inventaire.getThystame() + 1);
    isItForRitual(object);
    _line.clear();
    _ask.pop_front();
}

void IA::getSet()
{
    if (_line == OK)
        _validate = true;
    else if (_line == KO) {
        _probleme = true;
        _line.clear();
        return;
    }
    _line.clear();
    _ask.pop_front();
}

void IA::getIncantation()
{
    if (_line == "KO")
        _ritualAsked = false;
    if (_line == "Elevation underway")
        _validate = true;
    _line.clear();
    _ask.pop_front();
}
