/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** getMessages
*/

#include "Display.hpp"

Display::Display(int port, std::string machine) : _machine(machine)
{
    _network = Network();
    _socket = _network.connectSocketClient(machine, port);
}

Display::~Display()
{
}

void Display::connection()
{
    _network.sendMessage(_socket, "GRAPHIC\n");
    std::cout << "Connection to server" << std::endl;
}

bool Display::parseCommande()
{
    bool isParsed = false;
    while (_commande.find("\n") != std::string::npos) {
        _line.clear();
        _line = _commande.substr(0, _commande.find("\n"));
        _commande.erase(0, _commande.find("\n") + 1);
        std::string cmd = _line.substr(0, _line.find(" "));
        std::cout << "commande: " << _line << std::endl; // "x y n
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

void Display::communicateWithServer()
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

//message = X Y food linemate deraumere sibur mendiane phiras thystame
void Display::tileContent()
{
    size_t x = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t y = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t food = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t linemate = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t deraumere = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t sibur = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t mendiane = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t phiras = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t thystame = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    _map[std::pair<size_t, size_t>(x, y)] = {food, linemate, deraumere, sibur, mendiane, phiras, thystame};
}

void Display::mapSize()
{
    size_t x = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t y = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    _mapSize = std::pair<size_t, size_t>(x, y);
}

void Display::TeamName()
{
    std::string name = _line.substr(0, _line.find(" "));
    _line.erase(0, _line.find(" ") + 1);
    for (size_t x = 0; x < _teamName.size(); x++)
        if (_teamName[x] == name)
            return;
    _teamName.push_back(name);
}

void Display::newPlayer()
{
    size_t id = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t x = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t y = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t orientation = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t level = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    std::string team = _line.substr(0, _line.find(" "));
    _line.erase(0, _line.find(" ") + 1);
    ressourcesT inventory;
    _player[id] = {id, x, y, orientation, level, team, inventory, false};
}

void Display::playerPosition()
{
    size_t id = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t x = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t y = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t orientation = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    _player[id] = {id, x, y, orientation, _player[id].level, _player[id].team, _player[id].inventory, _player[id].laying};
}

void Display::playerLevel()
{
    size_t id = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t level = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    _player[id].level = level;
}

void Display::playerInventory()
{
    size_t id = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t food = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t linemate = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t deraumere = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t sibur = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t mendiane = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t phiras = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t thystame = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    _player[id] = {id, _player[id].x, _player[id].y, _player[id].orientation, _player[id].level, _player[id].team, {food, linemate, deraumere, sibur, mendiane, phiras, thystame}};
}

void Display::broadcast()
{
    size_t id = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    _messageBroadcast = std::pair<size_t, std::string>(id, _line);
}

void Display::startIncantation()
{
    size_t x = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t y = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    std::vector<playerT *> players;
    size_t level = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    while (_line.find(" ") != std::string::npos) {
        players.push_back(&_player[std::stoi(_line.substr(0, _line.find(" ")))]);
        _line.erase(0, _line.find(" ") + 1);
    }
    _incantation[_incantation.size()] = {x, y, level, players};
}

void Display::endIncantation()
{
    size_t x = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t y = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t result = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    int id;
    for (size_t i = 0; i < _incantation.size(); i++) {
        if (_incantation[i].x == x && _incantation[i].y == y) {
            id = i;
            break;
        }
    }
    if (result == 1)
        for (size_t i = 0; i < _incantation[id].players.size(); i++)
            _incantation[id].players[i]->level++;
    _incantation.erase(id);
}

void Display::startLaying()
{
    size_t id = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t x = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t y = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    std::string team = _line.substr(0, _line.find(" "));
    _line.erase(0, _line.find(" ") + 1);
}

void Display::eggLaid()
{
    size_t idEgg = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t idPlayer = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t x = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t y = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    _player[idPlayer].laying = false;
    _egg.push_back({idEgg, x, y});
}

void Display::playerConnectionEgg()
{
    size_t idEgg = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    for (size_t i = 0; i < _egg.size(); i++) {
        if (_egg[i].id == idEgg) {
            _egg.erase(_egg.begin() + i);
            break;
        }
    }
    //peux etre créer un player ici
}

void Display::deathEgg()
{
    size_t idEgg = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    for (size_t i = 0; i < _egg.size(); i++) {
        if (_egg[i].id == idEgg) {
            _egg.erase(_egg.begin() + i);
            break;
        }
    }
}

void Display::expulsion()
{
    size_t idPlayer = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
}

void Display::ressourceDropping()
{
    size_t idPlayer = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t ressource = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);

    // _player[idPlayer].inventory[ressource]--;
}

void Display::ressourceTaking()
{
    size_t idPlayer = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t ressource = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);

    // _player[idPlayer].inventory[ressource]++;
}

void Display::playerDeath()
{
    size_t idPlayer = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);

    // _player[idPlayer].
}

void Display::endGame()
{

}

void Display::messageFromServer()
{

}

void Display::unknownCommand()
{

}

void Display::CommandParameter()
{

}

void Display::timeUnit()
{

}

void Display::timeUnitModification()
{

}