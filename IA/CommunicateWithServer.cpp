/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** CommuncateWithServer
*/

#include "IA.hpp"


void IA::forward()
{
    _actualCommand = "forward";
    _network.sendMessage(_socket, "Forward\n");
    _ask.push_back("Forward");
}

void IA::turnLeft()
{
    _actualCommand = "left";
    _network.sendMessage(_socket, "Left\n");
    _ask.push_back("Left");
}

void IA::turnRight()
{
    _actualCommand = "right";
    _network.sendMessage(_socket, "Right\n");
    _ask.push_back("Right");
}

void IA::look()
{
    _actualCommand = "look";
    _network.sendMessage(_socket, "Look\n");
    _ask.push_back("Look");
}

void IA::broadcast(std::string message)
{
    _actualCommand = "broadcast";
    _network.sendMessage(_socket, "Broadcast " + message + "\n");
}

void IA::inventory()
{
    _actualCommand = "inventory";
    _network.sendMessage(_socket, "Inventory\n");
}

void IA::connectNbr()
{
    _actualCommand = "connect_nbr";
    _network.sendMessage(_socket, "Connect_nbr\n");
}

void IA::fork()
{
    _actualCommand = "fork";
    _network.sendMessage(_socket, "Fork\n");
}

void IA::eject()
{
    _actualCommand = "eject";
    _network.sendMessage(_socket, "Eject\n");
}

void IA::take(std::string object)
{
    _actualCommand = "take";
    _network.sendMessage(_socket, "Take " + object + "\n");
}

void IA::set(std::string object)
{
    _actualCommand = "set";
    _network.sendMessage(_socket, "Set " + object + "\n");
}

void IA::incantation()
{
    _actualCommand = "incantation";
    _network.sendMessage(_socket, "Incantation\n");
}


void IA::parseCommande()
{
    while (_commande.find("\n") != std::string::npos) {
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
                look();
            }
            continue;
        }
        if (_line == "dead") {
            std::cout << "Dead" << std::endl;
            break;
        }
        if (_line.substr(0, _line.find(" ")) == "Current") {
            _line.erase(0, _line.find(" ") + 1);
            _line.erase(0, _line.find(" ") + 1);
            _level = std::stoi(_line.substr(0, _line.find("\n")));
            continue;
        }
        for (size_t i = 0; _cmd[i].cmd.compare("NULL"); i++) {
            if (_cmd[i].cmd == _actualCommand) {
                _cmd[i].func();
                break;
            }
        }
    }
}

void IA::communicateWithServer()
{
    while (1) {
        if (_network.selectSocket(_socket, &_readfds) == -1)
            throw std::runtime_error("Error: select failed");
        if (_network.fdReady(_socket, &_readfds)) {
            _commande = _network.receiveMessage(_socket);
            parseCommande();
            std::cout << "commande: " << _commande << std::endl;
        }
    }
}

void IA::getForward()
{
    if (_line == "ok")
        _validate = true;
    _actualCommand.clear();
}

void IA::getTurnLeft()
{
    if (_line == "ok")
        _validate = true;
    _actualCommand.clear();
}

void IA::getTurnRight()
{
    if (_line == "ok")
        _validate = true;
    _actualCommand.clear();
}

void IA::getLook()
{
    std::cout << "look: " << _line << std::endl;
    _actualCommand.clear();
}

void IA::getBroadcast()
{
    if (_line == "ok")
        _validate = true;
    _actualCommand.clear();
}

void IA::getInventory()
{
    _actualCommand.clear();
}

void IA::getConnectNbr()
{
    _actualCommand.clear();
}

void IA::getFork()
{
    if (_line == "ok")
        _validate = true;
    _actualCommand.clear();
}

void IA::getEject()
{
    _actualCommand.clear();
}

void IA::getTake()
{
    _actualCommand.clear();
}

void IA::getSet()
{
    _actualCommand.clear();
}

void IA::getIncantation()
{
    _actualCommand.clear();
}

//quand on fait un call on rempli une variable puis pointeur sur fonction apres avoir la réponse
