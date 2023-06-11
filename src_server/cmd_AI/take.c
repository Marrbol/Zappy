/*
** EPITECH PROJECT, 2023
** temp
** File description:
** take
*/

#include "server.h"

size_t len_obj(char *buff)
{
    size_t i = (strlen(TKO) + 1);
    size_t res = 0;

    while (buff[i] != '\n' && buff[i] != '\0') {
        i++;
        res++;
    }
    return res;
}

inv_t search_type(char *tmp)
{
    for (inv_t i = food; i < none; i++)
        if (strcmp(allInv[i].name, tmp) == 0) {
            printf("search find %s\n", tmp);
            return allInv[i].id;
        }
    return none;
}

void take(client_manager_t *c, int nbClient, char *buff)
{
    int len = len_obj(buff);
    char *tmp = malloc(sizeof(char) * (len + 1));
    size_t index = 0;
    size_t x = c->client_infos[nbClient].coord->x;
    size_t y = c->client_infos[nbClient].coord->y;
    inv_t i = none;

    memset(tmp, 0, (len + 1));
    for (size_t i = (strlen(TKO) + 1); i < (strlen(buff) - 1); i++) {
        tmp[index] = buff[i];
        index++;
    }
    i = search_type(tmp);
    if (c->map[x][y].cont[i] != 0) {
        c->map[x][y].cont[i]--;
        c->client_infos[nbClient].inv[i]++;
        write(c->client_infos[nbClient].client_socket, "ok\n", 3);
    } else
        write(c->client_infos[nbClient].client_socket, "ko\n", 3);
}
