/*
** EPITECH PROJECT, 2023
** temp
** File description:
** right
*/

#include "server.h"

void right(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff)
{
    c->client_infos[nbClient].d++;
    if (c->client_infos[nbClient].d == NONE2)
        c->client_infos[nbClient].d = NORTH;
    write(c->client_infos[nbClient].client_socket, "ok\n", 3);
}