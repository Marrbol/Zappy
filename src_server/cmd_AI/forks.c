/*
** EPITECH PROJECT, 2023
** temp
** File description:
** forks
*/

#include "server.h"

void set_forks(client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff)
{
    c->client_infos[nbClient].fct = forks;
    c->client_infos[nbClient].exec_func = true;
    c->client_infos[nbClient].time = 42;
}

void forks(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff)
{
    client_t *client = &c->client_infos[nbClient];
    egg_t *egg = calloc(1, sizeof(egg_t));

    egg->x = client->coord->x;
    egg->y = client->coord->y;
    egg->team = client->team;
    egg->time = 600;
    egg->next = c->egg;
    c->egg = egg;
    write(c->client_infos[nbClient].client_socket, "ok\n", 3);
}
