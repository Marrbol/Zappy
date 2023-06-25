/*
** EPITECH PROJECT, 2023
** temp
** File description:
** Buff Utils
*/

#include "server.h"

static buff_t *create_buff(char *str, bool dup)
{
    buff_t *tmp = calloc(1, sizeof(buff_t));

    if (dup) {
        tmp->buff = strdup(str);
        tmp->isdup = true;
    } else {
        tmp->buff = str;
        tmp->isdup = false;
    }
    tmp->next = NULL;
    if (tmp->buff[strlen(tmp->buff) - 1] == '\n')
        tmp->isfull = true;
    else
        tmp->isfull = false;
    return tmp;
}

static buff_t *find_buff(buff_t *buff) {
    buff_t *tmp = buff;
    int i = 1;

    while (tmp->next != NULL && i <= 10) {
        tmp = tmp->next;
        i++;
    }
    if (i == 10 && tmp->isfull)
        return NULL;
    return tmp;
}

static void complet_buff(buff_t *buff, char *str)
{
    char *tmp = calloc(strlen(buff->buff) + strlen(str) + 1, sizeof(char));

    sprintf(tmp, "%s%s", buff->buff, str);
    if (buff->isdup)
        free(buff->buff);
    buff->buff = tmp;
    if (buff->buff[strlen(buff->buff) - 1] == '\n')
        buff->isfull = true;
}

void addcmd_buff(client_manager_t *c, char *str, int client)
{
    buff_t *tmp;
    if(c->client_infos[client].buff == NULL) {
        c->client_infos[client].buff = create_buff(str,c->client_infos[client].isauth);
        return;
    }
    tmp = find_buff(c->client_infos[client].buff);
    if (tmp == NULL)
        return;
    if (!tmp->isfull)
        complet_buff(tmp, str);
    else
        tmp->next = create_buff(str, c->client_infos[client].isauth);
}

buff_t *read_buff(client_manager_t *c, int client)
{
    buff_t *tmp = c->client_infos[client].buff;

    if (tmp == NULL)
        return NULL;
    if (!tmp->isfull)
        return NULL;
    c->client_infos[client].buff = tmp->next;
    return tmp;
}
