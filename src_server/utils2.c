/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-enzo.monnier
** File description:
** utils2
*/

#include "server.h"

char *my_atoi(int nb)
{
    int len = snprintf(NULL, 0, "%d", nb);
    char *buff = malloc(sizeof(char) * (len + 1));

    snprintf(buff, (len + 1), "%d", nb);
    return buff;
}

inv_t search_type(char *tmp)
{
    for (inv_t i = food; i < none; i++)
        if (strncmp(allInv[i].name, tmp, strlen(allInv[i].name)) == 0) {
            return allInv[i].id;
        }
    return none;
}

char *get_content(client_manager_t *c, int x, int y)
{
    char *content = "";
    inv_t i = food;

    while (i < none)
        content = cat(content, cat(" ", my_atoi(c->map[x][y][i++])));
    content = cat(content, "\n");
    return content;
}

int get_gui_id(client_manager_t *c)
{
    int i = 0;

    while (i < (c->nb_clients * c->nb_teams)) {
        if (c->client_infos[i].type == GUI)
            return i;
        i++;
    }
    return 0;
}
