/*
** EPITECH PROJECT, 2023
** temp
** File description:
** look
*/

#include "server.h"

static map_t check_case_look(map_t **map, int x, int y)
{
    return map[x][y];
}

static map_t find_case(client_t *player, int i, int j, map_t **map)
{
    switch (player->d) {
        case (NORTH):
            return (check_case_look(map,
                                    player->coord->y - i, player->coord->x + j));
        case (EAST):
            return (check_case_look(map,
                                    player->coord->y + j, player->coord->x + i));
        case (OUEST):
            return (check_case_look(map,
                                    player->coord->y + i, player->coord->x - j));
        case (SUD):
            return (check_case_look(map,
                                    player->coord->y - j, player->coord->x - i));
        default: {
            map_t de;
            int raw[1];

            raw[0] = none;
            de.cont = raw;
            return de;
        }
    }
}

char *get_ob(map_t ob)
{
    int size = 0;
    for (int i = 0; ob.cont[i]; i++)
        size++;
    char *res = calloc(size * 10, sizeof(char));
    for (int i = 0; ob.cont[i]; i++)
        res += sprintf(res, "%s, ", allInv[ob.cont[i]].name);
    return res;
}

void look(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff)
{
    char	*items = calloc(1000, sizeof (char));
    client_t *client = &c->client_infos[nbClient];
    map_t data;

    items += sprintf(items, "[ ");
    for (int i = 0; i <= client->lvl; i++) {
        for (int j = 0; j < (2 * i) + 1; j++) {
            data = find_case(client, i, j - i, c->map);
            items += sprintf(items, "%s, ", get_ob(data));
        }
    }
    items += sprintf(items, "]\n");
    write(c->client_infos[nbClient].client_socket, items, strlen(items));
}
