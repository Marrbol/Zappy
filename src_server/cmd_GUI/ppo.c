/*
** EPITECH PROJECT, 2023
** temp
** File description:
** ppo
*/

#include "server.h"

void ppo(client_manager_t *c, int nbClient, char *buff) {
    char *base = "ppo ";
    char *rebuff = strtok(buff, base);
    int id = atoi(rebuff);
    char *message = "";

    message = cat(cat(cat(cat(cat(cat(cat(cat(base, my_atoi(id)), " "),
    my_atoi(c->client_infos[id].coord->x)), " "),
    my_atoi(c->client_infos[id].coord->y)), " "),
    my_atoi((size_t)c->client_infos[id].d)), "\n");
    write(c->client_infos[nbClient].client_socket, message, strlen(message));
}
