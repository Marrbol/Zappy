/*
** EPITECH PROJECT, 2023
** temp
** File description:
** connect_to
*/

#include "server.h"

void connect_to(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff)
{
    printf("id %d\n", nbClient);  //FIX
    int res = remain_team(c, c->client_infos[nbClient].team);

    write(c->client_infos[nbClient].client_socket, my_atoi(res),
    strlen(my_atoi(res)));
    write(c->client_infos[nbClient].client_socket, "\n", 1);
}
