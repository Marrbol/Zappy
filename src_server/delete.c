/*
** EPITECH PROJECT, 2023
** temp
** File description:
** delete
*/

#include "server.h"

void destroy(server_t *s, client_manager_t *c)
{
    free(c->client_infos);
    free(c);
    free(s);
}
