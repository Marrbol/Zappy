/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** map
*/

#include "server.h"

void set_map(client_manager_t *c)
{
    c->map = malloc(sizeof(int **) * (c->coord->x + 1));
    memset(c->map, 0, (sizeof(int **) * c->coord->x + 1));

    for (int i = 0; i < c->coord->x; i++) {
        c->map[i] = malloc(sizeof(int *) * (c->coord->y + 1));
        memset(c->map[i], 0, (sizeof(int *) * (c->coord->y + 1)));
        for (int j = 0; j < c->coord->y; j++) {
            c->map[i][j] = malloc(sizeof(int) * none);
            memset(c->map[i][j], 0, (sizeof(int) * none));
        }
    }
}
