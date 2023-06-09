/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** getMessages
*/

#include "Display.hpp"

GameWindow::GameWindow(int port, std::string machine) : _machine(machine)
{
    _network = Network();
    _socket = _network.connectSocketClient(machine, port);
}

GameWindow::~GameWindow()
{
}

void GameWindow::askMapSize()
{
    _network.sendMessage(_socket, "msz\n");
}

void GameWindow::askTileContent(size_t x, size_t y)
{
    std::string message = "bct " + std::to_string(x) + " " + std::to_string(y) + "\n";
    _network.sendMessage(_socket, message);
}

void GameWindow::askAllTileContent()
{
    _network.sendMessage(_socket, "mct\n");
}

void GameWindow::askTeamsNames()
{
    _network.sendMessage(_socket, "tna\n");
}

void GameWindow::askPlayerPosition(size_t id)
{
    std::string message = "ppo " + std::to_string(id) + "\n";
    _network.sendMessage(_socket, message);
}

void GameWindow::askPlayerLevel(size_t id)
{
    std::string message = "plv " + std::to_string(id) + "\n";
    _network.sendMessage(_socket, message);
}

void GameWindow::askPlayerInventory(size_t id)
{
    std::string message = "pin " + std::to_string(id) + "\n";
    _network.sendMessage(_socket, message);
}

void GameWindow::askTimeUnit()
{
    _network.sendMessage(_socket, "sgt\n");
}

void GameWindow::askTimeUnitModification(size_t time)
{
    std::string message = "sst " + std::to_string(time) + "\n";
    _network.sendMessage(_socket, message);
}

void GameWindow::communicateWithServer()
{
    if (_network.selectSocket(_socket, &_readfds) == -1)
        throw std::runtime_error("Error: select failed");
    if (_network.fdReady(_socket, &_readfds)) {
        _commande = _network.receiveMessage(_socket);
        if (!parseCommande())
            std::cout << "Unknown command" << std::endl;
    }
}

bool GameWindow::parseCommande()
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

void GameWindow::connection()
{
    _network.sendMessage(_socket, "GRAPHIC\n");
    std::cout << "Connection to server" << std::endl;
}

//message = X Y food linemate deraumere sibur mendiane phiras thystame
void GameWindow::tileContent()
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

void GameWindow::mapSize()
{
    size_t x = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t y = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    _mapSize = std::pair<size_t, size_t>(x, y);
}

void GameWindow::TeamName()
{
    std::string name = _line.substr(0, _line.find(" "));
    _line.erase(0, _line.find(" ") + 1);
    for (size_t x = 0; x < _teamName.size(); x++)
        if (_teamName[x] == name)
            return;
    _teamName.push_back(name);
}

void GameWindow::newPlayer()
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

void GameWindow::playerPosition()
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

void GameWindow::playerLevel()
{
    size_t id = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t level = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    _player[id].level = level;
}

void GameWindow::playerInventory()
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

void GameWindow::broadcast()
{
    size_t id = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    _messageBroadcast = std::pair<size_t, std::string>(id, _line);
}

void GameWindow::startIncantation()
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

void GameWindow::endIncantation()
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

void GameWindow::startLaying()
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

void GameWindow::eggLaid()
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

void GameWindow::playerConnectionEgg()
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

void GameWindow::deathEgg()
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

void GameWindow::expulsion()
{
    size_t idPlayer = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
}

void GameWindow::ressourceDropping()
{
    size_t idPlayer = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t ressource = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);

    modifInventory(idPlayer, ressource, -1);
    switch (ressource)
    {
        case 0:
             _map[std::pair<size_t, size_t>(_player[idPlayer].x, _player[idPlayer].y)].food += 1;
            break;
        case 1:
             _map[std::pair<size_t, size_t>(_player[idPlayer].x, _player[idPlayer].y)].linemate += 1;
            break;

        case 2:
             _map[std::pair<size_t, size_t>(_player[idPlayer].x, _player[idPlayer].y)].deraumere += 1;
            break;
        case 3:
             _map[std::pair<size_t, size_t>(_player[idPlayer].x, _player[idPlayer].y)].sibur += 1;
            break;

        case 4:
             _map[std::pair<size_t, size_t>(_player[idPlayer].x, _player[idPlayer].y)].mendiane += 1;
            break;

        case 5:
             _map[std::pair<size_t, size_t>(_player[idPlayer].x, _player[idPlayer].y)].phiras += 1;
            break;
        default:
        break;
    }
}

void GameWindow::ressourceTaking()
{
    size_t idPlayer = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);
    size_t ressource = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);

    modifInventory(idPlayer, ressource, 1);
}

void GameWindow::modifInventory(size_t idPlayer, size_t ressource, int value)
{
    switch (ressource)
    {
        case 0:
            _player[idPlayer].inventory.food += value;
            break;
        case 1:
            _player[idPlayer].inventory.linemate += value;
            break;

        case 2:
            _player[idPlayer].inventory.deraumere += value;
            break;
        case 3:
            _player[idPlayer].inventory.sibur += value;
            break;

        case 4:
            _player[idPlayer].inventory.mendiane += value;
            break;

        case 5:
            _player[idPlayer].inventory.phiras += value;
            break;
        default:
        break;
    }
}

void GameWindow::playerDeath()
{
    size_t idPlayer = std::stoi(_line.substr(0, _line.find(" ")));
    _line.erase(0, _line.find(" ") + 1);

    // _player[idPlayer].
}

void GameWindow::endGame()
{

}

void GameWindow::messageFromServer()
{

}

void GameWindow::unknownCommand()
{

}

void GameWindow::CommandParameter()
{

}

void GameWindow::timeUnit()
{

}

void GameWindow::timeUnitModification()
{

}