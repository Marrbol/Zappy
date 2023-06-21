/*
** EPITECH PROJECT, 2023
** temp
** File description:
** pdi
*/

#include "server.h"

void pdi(client_manager_t *c, int nbClient, char *buff) {
    char *base = "pdi ";
    char *message = cat(base, buff);

    write(c->client_infos[nbClient].client_socket, message, strlen(message));
}
