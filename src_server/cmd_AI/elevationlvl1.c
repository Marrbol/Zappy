/*
** EPITECH PROJECT, 2023
** elevation.c
** File description:
** elevationlvl1
*/

#include "server.h"

void elevation_lvltwo(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff)
{
    int x_player = c->client_infos[nbClient].coord->x;
    int y_player = c->client_infos[nbClient].coord->y;

    if (c->client_infos[nbClient].inv[linemate] >= 1) {
        c->client_infos[nbClient].lvl++;
        c->client_infos[nbClient].inv[linemate]--;
        c->map[x_player][y_player][linemate]++;
        printf("Current lvl %d\n", c->client_infos[nbClient].lvl);
    } else {
        printf("/ko\n");
    }
}

void elevation_lvlthree(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff)
{
    
}