/*
** EPITECH PROJECT, 2023
** temp
** File description:
** look
*/

#include "server.h"

char *get_ob(int *ob, int x, int y, client_manager_t *c)
{
    int sp = count_player(c, x, y);
    int size = find_itemsize(ob) + sp;
    char *res = calloc(size * 12, sizeof(char));

    for (int i = 0; i < sp; i++)
        res += sprintf(res, "player ");
    for (int i = 0; i < LENINV; i++)
        for (int j = 0; j < ob[j]; j++)
            res += sprintf(res, "%s ", allInv[i].name);
    return res;
}

static char *check_case_look(int ***map, int x, int y, client_manager_t *c)
{
    return get_ob(map[x][y], x, y, c);
}

static char *find_case(client_t *player, int i, int j, client_manager_t *c)
{
    int vo[1] = {none};
    switch (player->d) {
        case (NORTH):
            return (check_case_look(c->map,
                                    player->coord->y - i, player->coord->x + j, c));
        case (EAST):
            return (check_case_look(c->map,
                                    player->coord->y + j, player->coord->x + i, c));
        case (OUEST):
            return (check_case_look(c->map,
                                    player->coord->y + i, player->coord->x - j, c));
        case (SUD):
            return (check_case_look(c->map,
                                    player->coord->y - j, player->coord->x - i, c));
        default: {
            return vo;
        }
    }
}

void look(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff)
{
    int size = count_allitems(c->map) + c->nb_clients;
    char	*items = calloc(size * 15, sizeof (char));
    client_t *client = &c->client_infos[nbClient];
    char *tmp;

    items += sprintf(items, "[ ");
    for (int i = 0; i <= client->lvl; i++) {
        for (int j = 0; j < (2 * i) + 1; j++) {
            tmp = find_case(client, i, j - i, c);
            items += sprintf(items, "%s, ", tmp);
            free(tmp);
        }
    }
    items += sprintf(items, "]\n");
    write(c->client_infos[nbClient].client_socket, items, strlen(items));
    free(items);
}
