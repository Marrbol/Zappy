/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** comete
*/

#include "server.h"

void put_ressource(client_manager_t *c, inv_t r)
{
    int x = (rand() % c->coord->x);
    int y = (rand() % c->coord->y);
    c->map[x][y].cont[r]++;
}

void comete(client_manager_t *c)
{
    size_t tmp = 0;

    for (inv_t i = food; i < none; i++) {
        tmp = (c->coord->x * c->coord->y * allInv[i].density);
        for (size_t j = 0; j < tmp; j++) {
            put_ressource(c, i);
        }
    }
}