/*
** EPITECH PROJECT, 2023
** temp
** File description:
** invent
*/

#include "server.h"

bool check_buff(client_manager_t *c, int nbClient, char *buff)
{
    if (strcmp(buff, allcoms_AI[4].name) != 0) {
        write(c->client_infos[nbClient].client_socket, "KO\n", 3);
        return false;
    }
    return true;
}

void invent(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff)
{
    size_t i = 0;

    if (!check_buff(c, nbClient, buff))
        return;

    write(c->client_infos[nbClient].client_socket, "[", 1);
    write(c->client_infos[nbClient].client_socket, allInv[i].name,
    strlen(allInv[i].name));
    i++;
    while (i < (LENINV - 1)) {
        write(c->client_infos[nbClient].client_socket, ",", 1);
        write(c->client_infos[nbClient].client_socket, allInv[i].name,
        strlen(allInv[i].name));
    }
    write(c->client_infos[nbClient].client_socket, "]\n", 2);
}
