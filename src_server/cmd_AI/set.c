/*
** EPITECH PROJECT, 2023
** temp
** File description:
** set
*/

#include "server.h"

void set_set(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff)
{
    c->client_infos[nbClient].fct = set;
    c->client_infos[nbClient].exec_func = true;
    c->client_infos[nbClient].time = 7;
}

size_t len_objset(char *buff)
{
    size_t i = (strlen(STO) + 1);
    size_t res = 0;

    while (buff[i] != '\n' && buff[i] != '\0') {
        i++;
        res++;
    }
    return res;
}

void set(client_manager_t *c, int nbClient, char *buff)
{
    int len = len_objset(buff);
    char *tmp = malloc(sizeof(char) * (len + 1));
    size_t index = 0;
    int x = c->client_infos[nbClient].coord->x;
    int y = c->client_infos[nbClient].coord->y;
    inv_t i = none;

    memset(tmp, 0, (len + 1));
    for (size_t i = (strlen(STO) + 1); i < (strlen(buff) - 1); i++) {
        tmp[index] = buff[i];
        index++;
    }
    i = search_type(tmp);
    if (c->client_infos[nbClient].inv[i] == 0) {
        write(c->client_infos[nbClient].client_socket, "ko\n", 3);
    } else {
        c->map[x][y][i]++;
        c->client_infos[nbClient].inv[i]--;
        write(c->client_infos[nbClient].client_socket, "ok\n", 3);
    }
}
