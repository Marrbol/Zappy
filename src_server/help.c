/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-enzo.monnier
** File description:
** help
*/

#include "server.h"

void help(client_manager_t *c, int nbClient, __attribute__((unused)) char *buff)
{
    FILE *f;
    char *line = NULL;
    size_t len = 0;

    f = fopen(HELP_DIS, "r");
    while (getline(&line, &len, f) != -1) {
        write(c->client_infos[nbClient].client_socket, line, len);
    }
    fclose(f);
}
