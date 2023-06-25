/*
** EPITECH PROJECT, 2023
** temp
** File description:
** look
*/

#include "server.h"

static void pr(char *res, int id)
{
    if (allInv[id].id == none)
        return;
    strcat(res, allInv[id].name);
    strcat(res, " ");
}

char *get_ob(int *ob, int x, int y, client_manager_t *c) {
    int sp = count_player(c, x, y);
    int size = find_itemsize(ob) + sp;
    char *res;

    if (size == 0) {
        res = calloc(3, sizeof(char));
        strcat(res, " ");
        return res;
    }
    res = calloc(size * 15, sizeof(char));
    for (int i = 0; i < sp; i++) {
        strcat(res, "player ");
    }
    for (int i = 0; i < LENINV; i++)
        for (int j = 0; j < ob[i]; j++) {
            pr(res, i);
        }
    return res;
}

// static char *check_case_look(int ***map, int x, int y, client_manager_t *c)
// {
//     int fx = x;
//     int fy = y;

//     if (x >= c->coord->x)
//         fx = x - c->coord->x;
//     if (x < 0)
//         fx = c->coord->x + x;
//     if (y >= c->coord->y)
//         fy = y - c->coord->y;
//     if (y < 0)
//         fy = c->coord->y + y;
//     if (fx >= 0 && fx < c->coord->x && fy >= 0 && fy < c->coord->y)
//         return get_ob(map[fx][fy], fx, fy, c);
//     else
//         return get_ob(map[0][0], 0, 0, c);
// }

// static char *find_case(client_t *player, int i, int j, client_manager_t *c)
// {

//     char *vo = calloc(3, sizeof(char));
//     strcat(vo, " ");
//     switch (player->d) {
//         case (NORTH):
//             return (check_case_look(c->map,
//                                     player->coord->y - i, player->coord->x + j, c));
//         case (EAST):
//             return (check_case_look(c->map,
//                                     player->coord->y + j, player->coord->x + i, c));
//         case (OUEST):
//             return (check_case_look(c->map,
//                                     player->coord->y + i, player->coord->x - j, c));
//         case (SUD):
//             return (check_case_look(c->map,
//                                     player->coord->y - j, player->coord->x - i, c));
//         default: {
//             return vo;
//         }
//     }
// }

void look(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff)
{
    //int size = count_allitems(c->map, c) + c->nb_clients;
    //char	*items = calloc(size * 15, sizeof (char));
    //client_t *client = &c->client_infos[nbClient];
    //char *tmp;

    //strcat(items, "[ player ");
    //for (int i = 0; i <= client->lvl; i++) {
    //    for (int j = 0; j < (2 * i) + 1; j++) {
    //        tmp = find_case(client, i, j - i, c);
    //        strcat(items, tmp);
    //        strcat(items, ", ");
    //        free(tmp);
    //    }
    //}
    //strcat(items, "]\n\0");
    //write(c->client_infos[nbClient].client_socket, items, strlen(items));
    //free(items);
}
