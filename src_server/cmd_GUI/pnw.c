/*
** EPITECH PROJECT, 2023
** temp
** File description:
** pnw
*/

#include "server.h"

void pnw(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff) {
    char *message = cat("pnw ", buff);

    write(c->client_infos[nbClient].client_socket, message, strlen(message));
}
