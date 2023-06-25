/*
** EPITECH PROJECT, 2023
** temp
** File description:
** sgt
*/

#include "server.h"

void sgt(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff) {
    char *message = cat(cat("sgt ", my_atoi(c->freq)), "\n");

    write(c->client_infos[nbClient].client_socket, message, strlen(message));
}
