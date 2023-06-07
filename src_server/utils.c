/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-enzo.monnier
** File description:
** utils
*/

#include "server.h"

size_t count_words(char *buff)
{
    size_t w = 0;

    for (size_t i = 0; i < strlen(buff); i++) {
        if (buff[i] == ' ')
            w++;
    }
    return w;
}

char *cat(char *tmp, char *name)
{
    char *d = malloc(sizeof(char) * (strlen(tmp) + strlen(name) + 1));

    memset(d, 0, (strlen(tmp) + strlen(name) + 1));
    strcat(d, tmp);
    strcat(d, name);
    return d;
}

size_t count_team(char **argv, int ac)
{
    size_t res = 0;
    int index = 8;

    while (strcmp("-c", argv[index]) != 0 && index++ < ac)
        res++;
    if (index == ac)
        res = 0;
    return res;
}

bool is_nb(char *buff)
{
    for (size_t i = 0; i < strlen(buff); i++) {
        if ('0' > buff[i] || buff[i] > '9')
            return false;
    }
    return true;
}

int remain_team(client_manager_t *c, char *team)
{
    int res = 0;

    for (int i = 0; i < (c->nb_clients * c->nb_teams); i++) {
        if (strcmp(team, c->client_infos[i].team) == 0)
            res++;
    }
    return res;
}
