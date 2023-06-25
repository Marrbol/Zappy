/*
** EPITECH PROJECT, 2023
** temp
** File description:
** right
*/

#include "server.h"
void set_right(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff) {
    c->client_infos[nbClient].time = 7;
    c->client_infos[nbClient].fct = right;
    c->client_infos[nbClient].action_clock = clock();
    c->client_infos[nbClient].exec_func = true;
}


void right(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff)
{
    c->client_infos[nbClient].d++;
    if (c->client_infos[nbClient].d == NONE2)
        c->client_infos[nbClient].d = NORTH;
    write(c->client_infos[nbClient].client_socket, "ok\n", 3);
}