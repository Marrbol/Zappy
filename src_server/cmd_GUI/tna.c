/*
** EPITECH PROJECT, 2023
** temp
** File description:
** tna
*/

#include "server.h"

void tna(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff) {
    char *message = "tna ";

    for (int i = 0; i < c->nb_teams; i++) {
        message = cat(cat(message, c->teams[i].name),"\n");
        write(c->client_infos[nbClient].client_socket, message,
        strlen(message));
        message = "tna ";
    }
}
