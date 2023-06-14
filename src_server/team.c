/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** team
*/

#include "server.h"

void add_to_team(client_manager_t *c, char *team)
{
    for (int i = 0; i < c->nb_teams; i++) {
        if (strncmp(c->teams[i].name, team, strlen(c->teams[i].name)) == 0) {
            c->teams[i].nb++;
        }
    }
}
