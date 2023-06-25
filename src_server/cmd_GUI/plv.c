/*
** EPITECH PROJECT, 2023
** temp
** File description:
** plv
*/

#include "server.h"

void plv(client_manager_t *c, int nbClient, char *buff) {
    char *base = "plv ";
    char *rebuff = strtok(buff, base);
    int id = atoi(rebuff);
    char *message = "";

    message = cat(cat(cat(cat(base, my_atoi(id)), " "),
    my_atoi((int)c->client_infos[id].lvl)), "\n");
    write(c->client_infos[nbClient].client_socket, message, strlen(message));
}
