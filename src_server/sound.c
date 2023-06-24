/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** sound
*/

#include "server.h"

bool check_same(client_manager_t *c, int from, int to)
{
    if (c->client_infos[from].coord->x == c->client_infos[to].coord->x &&
    c->client_infos[from].coord->y == c->client_infos[to].coord->y)
        return true;
    return false;
}
