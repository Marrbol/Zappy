/*
** EPITECH PROJECT, 2023
** temp
** File description:
** bct
*/

#include "server.h"

int get_x(char *buff)
{
    int len = 1;
    char *tmp = strdup(buff);

    tmp = strtok(tmp, "bct");
    while (buff[len] != ' ')
        len++;
    tmp = strtok(tmp, " ");
    if (!is_nb(tmp))
        return -1;    
    return atoi(tmp);
}

int get_y(char *buff)
{
    char *tmp = "";
    char *nb = "";
    int index = 1;
    int begin = 0;
    int end = 0;
    int res = 0;
    int parcour = 0;

    tmp = strtok(buff, "bct");
    while (tmp[index] != ' ')
        index++;
    begin = (index + 1);
    index++;
    while (tmp[index] != '\n')
        index++;
    end = (index - 1);
    res = ((end - begin) + 1);
    nb = malloc(sizeof(char) * res);
    memset(nb, 0, res);
    for (int i = begin; i < end; i++)
        nb[parcour++] = tmp[i];
    if (!is_nb(nb))
        return -1;
    return atoi(nb);
}

void bct(client_manager_t *c, int nbClient, char *buff) {
    char *message = cat("bct ", "");
    char *content = "";
    int x = get_x(buff);
    int y = get_y(buff);

    if (x == -1 || y == -1 || x > c->coord->x || y > c->coord->y) {
        write(c->client_infos[nbClient].client_socket, "ko\n", 3);
        return;
    }
    content = get_content(c, x, y);
    message = cat(cat(cat(cat(message, my_atoi(x)), " "),
    my_atoi(y)), content);
    write(c->client_infos[nbClient].client_socket, message, strlen(message));
}

