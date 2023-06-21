/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-enzo.monnier
** File description:
** Map Utils
*/

#include "server.h"

int find_itemsize(int *ob)
{
    int result = 0;
    for (int i = 0; i < LENINV; i++)
        result += ob[i];
    return result;
}

int count_allitems(int ***map)
{
    int result = 0;

    for (int x = 0; map[x]; x++)
        for (int y = 0; map[x][y]; y++)
           result += find_itemsize(map[x][y]);
    return result;
}

int count_player(client_manager_t *c, int x, int y)
{
    int result = 0;
    coord_t *tmp;

    for (int i = 0; i < c->nb_clients; i++) {
        tmp = c->client_infos[i].coord;
        if (tmp->x == x && tmp->y == y)
            result++;
    }
    return result;
}
