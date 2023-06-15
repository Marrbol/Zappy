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
    std::cout << "ask Look" << std::endl;
}

void IA::broadcast(std::string message)
{
    _network.sendMessage(_socket, "Broadcast " + message + "\n");
    _ask.push_back("Broadcast");
}

void IA::inventory()
{
    _network.sendMessage(_socket, "Inventory\n");
    _ask.push_back("Inventory");
    std::cout << "ask Inventory" << std::endl;
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
    _ask.push_back("Set");
}

void IA::incantation()
{
    _network.sendMessage(_socket, "Incantation\n");
    _ask.push_back("Incantation");
}


void IA::parseCommande()
{
    while (_commande.find("\n") != std::string::npos) {
        // std::cout << _commande << std::endl;
        _line = _commande.substr(0, _commande.find("\n"));
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
            continue;
        }
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

void IA::ReceiveMessage()
{
    if (_line.substr(0, _line.find(" ")) == "message") {
        _line.erase(0, _line.find(" ") + 1);
        size_t direction = std::stoi(_line.substr(0, _line.find(",")));
        _line.erase(0, _line.find(",") + 1);
        if (_line[0] == ' ')
            _line.erase(0, 1);
        _messageReceived.push_back(std::make_pair(direction, _line));
    }
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
        if (tmp[0] == ' ')
            tmp.erase(0, 1);
        if (tmp.size() == 0) {
            _view[x + 1] = "";
            continue;
        }
        if (tmp[tmp.size() - 1] == ' ')
            tmp.erase(tmp.size() - 1, 1);
        _line.erase(0, _line.find(",") + 1);
        if (_line[0] == ' ')
            _line.erase(0, 1);
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
    std::cout << _ask.front() << std::endl;
    if (_line[0] == '[')
        _line.erase(0, 1);
    if (_line[_line.size() - 1] == ']')
        _line.erase(_line.size() - 1, 1);
    if (_line[0] == ' ')
        _line.erase(0, 1);
    if (_line[_line.size() - 1] == ' ')
        _line.erase(_line.size() - 1, 1);
    std::cout << _line << std::endl;
    for (size_t x = 0; ; x++) {
        std::string tmp = _line.substr(0, _line.find(","));
        if (tmp[0] == ' ')
            tmp.erase(0, 1);
        if (tmp[tmp.size() - 1] == ' ')
            tmp.erase(tmp.size(), 1);
        _line.erase(0, _line.find(",") + 1);
        std::cout << tmp << std::endl;
        std::string material = tmp.substr(0, tmp.find(" "));
        tmp.erase(0, tmp.find(" ") + 1);
        std::cout << "tmp avant " << tmp << std::endl;
        size_t nb = std::stoi(tmp);
        changeTheInventory(material, nb);
        if (_line.find(",") == std::string::npos) {
            std::cout << "line " << _line << std::endl;
            tmp = _line;
            if (tmp[0] == ' ')
                tmp.erase(0, 1);
            std::cout << "tmp" << tmp << std::endl;
            material = tmp.substr(0, tmp.find(" "));
            tmp.erase(0, tmp.find(" ") + 1);
            std::cout << "tmp 2 " << tmp << std::endl;
            nb = std::stoi(tmp);
            std::cout << material << " " << nb << std::endl;
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
    if (object == FOOD)
        _inventaire.setFood(_inventaire.getFood() + 1);
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
    if (_line == "Elevation underway")
        _validate = true;
    _line.clear();
    _ask.pop_front();
}
