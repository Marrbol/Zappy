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
        if (strcmp(allInv[i].name, tmp) == 0) {
            return allInv[i].id;
        }
    return none;
}

char *get_content(client_manager_t *c, int x, int y)
{
    char *content = "";
    inv_t i = food;

    printf("first = %s\n", my_atoi(c->map[x][y][i++]));
    while (i < none) {
        content = cat(content, cat(" ", my_atoi(c->map[x][y][i++])));
    }
    printf("content %s\n", content);
    return content;
}
