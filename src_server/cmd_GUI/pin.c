/*
** EPITECH PROJECT, 2023
** temp
** File description:
** pin
*/

#include "server.h"

void pin(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff) {
    char *base = "pin ";
    char *rebuff = strtok(buff, base);
    int id = atoi(rebuff);
    char *message = "";

    message = cat(cat(cat(cat(cat(cat(base, " "), my_atoi(id)), " "), my_atoi(c->client_infos[id].coord->x)), " "), my_atoi(c->client_infos[id].coord->y));
    for (inv_t i = food; i < none; i++) {
        message = cat(cat(message, " "), my_atoi((int)c->client_infos[id].inv[i]));
    }
    message = cat(message, "\n");
    write(c->client_infos[nbClient].client_socket, message, strlen(message));
}
