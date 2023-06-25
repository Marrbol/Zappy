/*
** EPITECH PROJECT, 2023
** temp
** File description:
** pdr
*/

#include "server.h"

void pdr(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff) {
    char *msg = "pdr ";

    msg = cat(msg, buff);
    write(c->client_infos[nbClient].client_socket, msg, strlen(msg));
}
