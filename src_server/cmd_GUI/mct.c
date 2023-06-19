/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** mct
*/

#include "server.h"

void mct(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff) {
    char *message = "bct ";
    char *content = "";
    char *coord = "";

    for (int x = 0; x < c->coord->x; x++) {
        for (int y = 0; y < c->coord->y; y++) {
            coord = cat(cat(my_atoi(x), " "), my_atoi(y));
            content = get_content(c, x, y);
            message = cat(cat(message, coord), content);
            write(c->client_infos[nbClient].client_socket, message,
            strlen(message));
            message = "bct ";
            coord = "";
            content = "";
        }
    }
}
