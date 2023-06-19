/*
** EPITECH PROJECT, 2023
** temp
** File description:
** msz
*/

#include "server.h"

void msz(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff) {
    char *message = cat(cat(cat(cat("msz ", my_atoi(c->coord->x)), " "),
    my_atoi(c->coord->y)), "\n");

    write(c->client_infos[nbClient].client_socket, message, strlen(message));
}
