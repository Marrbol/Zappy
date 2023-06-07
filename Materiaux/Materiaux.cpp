/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** Materiaux
*/

#include "Materiaux.hpp"

Materiaux::Materiaux(size_t linemate, size_t deraumere, size_t sibur, size_t mendiane, size_t phiras, size_t thystame)
{
    _linemate = linemate;
    _deraumere = deraumere;
    _sibur = sibur;
    _mendiane = mendiane;
    _phiras = phiras;
    _thystame = thystame;
}

Materiaux::~Materiaux()
{
}

Materiaux::Materiaux()
{
    _linemate = 0;
    _deraumere = 0;
    _sibur = 0;
    _mendiane = 0;
    _phiras = 0;
    _thystame = 0;
}

bool Materiaux::operator==(const Materiaux &materiaux)
{
    if (_linemate == materiaux._linemate && _deraumere == materiaux._deraumere && _sibur == materiaux._sibur && _mendiane == materiaux._mendiane && _phiras == materiaux._phiras && _thystame == materiaux._thystame)
        return true;
    return false;
}

bool Materiaux::operator>=(const Materiaux &materiaux)
{
    if (_linemate >= materiaux._linemate && _deraumere >= materiaux._deraumere && _sibur >= materiaux._sibur && _mendiane >= materiaux._mendiane && _phiras >= materiaux._phiras && _thystame >= materiaux._thystame)
        return true;
    return false;
}

void Materiaux::operator-=(const Materiaux &materiaux)
{
    _linemate -= materiaux._linemate;
    _deraumere -= materiaux._deraumere;
    _sibur -= materiaux._sibur;
    _mendiane -= materiaux._mendiane;
    _phiras -= materiaux._phiras;
    _thystame -= materiaux._thystame;
}