/*
** EPITECH PROJECT, 2023
** temp
** File description:
** pgt
*/

#include "server.h"

void pgt(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff) {
    char *msg = "pgt ";

    msg = cat(msg, buff);
    write(c->client_infos[nbClient].client_socket, msg, strlen(msg));
}
