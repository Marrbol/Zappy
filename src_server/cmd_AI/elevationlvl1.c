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
        printf("Current lvl %ld\n", c->client_infos[nbClient].lvl);
    } else {
        printf("/ko\n");
    }
}

void elevation_lvlthree(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff)
{
    int x_player = c->client_infos[nbClient].coord->x;
    int y_player = c->client_infos[nbClient].coord->y;
    char *team_name = c->client_infos[nbClient].team;

    if (c->client_infos[nbClient].inv[linemate] >= 1 &&
        c->client_infos[nbClient].inv[deraumere] >= 1 &&
        c->client_infos[nbClient].inv[mendiane] >= 1) {
        for (int i = 0; i < c->nb_clients; i++) {
            if (strcmp(c->client_infos[i].team, team_name) == 0 && 
                c->client_infos[i].coord->x == x_player &&
                c->client_infos[i].coord->y == y_player) {
                if (c->client_infos[i].inv[linemate] >= 1 &&
                    c->client_infos[i].inv[deraumere] >= 1 &&
                    c->client_infos[i].inv[mendiane] >= 1) {
                    c->client_infos[nbClient].inv[linemate]--;
                    c->client_infos[nbClient].inv[deraumere]--;
                    c->client_infos[nbClient].inv[mendiane]--;
                    c->client_infos[i].inv[linemate]--;
                    c->client_infos[i].inv[deraumere]--;
                    c->client_infos[i].inv[mendiane]--;
                    c->map[x_player][y_player][linemate]++;
                    c->map[x_player][y_player][deraumere]++;
                    c->map[x_player][y_player][mendiane]++;
                    c->client_infos[nbClient].lvl++;
                    c->client_infos[i].lvl++;
                }
            }
        }
        printf("Current lvl %ld\n", c->client_infos[nbClient].lvl);
    } else {
        printf("/ko\n");
    }
}
