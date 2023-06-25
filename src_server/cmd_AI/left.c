/*
** EPITECH PROJECT, 2023
** temp
** File description:
** left
*/

#include "server.h"

void set_left(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff)
{
    c->client_infos[nbClient].time = 7;
    c->client_infos[nbClient].fct = left;
    c->client_infos[nbClient].action_clock = clock();
    c->client_infos[nbClient].exec_func = true;
}

void left(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff)
{
    c->client_infos[nbClient].d--;
    if (c->client_infos[nbClient].d == NONE1)
        c->client_infos[nbClient].d = OUEST;
    write(c->client_infos[nbClient].client_socket, "ok\n", 3);
}
