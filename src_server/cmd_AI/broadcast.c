/*
** EPITECH PROJECT, 2023
** temp
** File description:
** broadcast
*/

#include "server.h"

size_t len_txt(char *buff)
{
    size_t i = (strlen(BRDTXT) + 1);
    size_t res = 0;

    while (buff[i] != '\n' && buff[i] != '\0') {
        i++;
        res++;
    }
    return res;
}

char *tile(client_manager_t *c, int from, int to)
{
    int x = c->client_infos[from].coord->x;
    int y = c->client_infos[from].coord->y;
    double angle = 0.0;
    int dir = 0;

    if (check_same(c, from, to))
        return "0";
    x -= c->client_infos[to].coord->x;
    y -= c->client_infos[to].coord->y;
    angle = atan2((double)x, (double)y);
    dir = (int)round(((4.0 * angle) / (PI + 4.5)));
    dir = ((dir % 8) + 1);
    dir = ((((int)c->client_infos[to].d + dir - 1) % 8) + 1);
    return my_atoi(dir);
}

char *do_txt(client_manager_t *c, int from, int to, char *mess)
{
    char *base = "message ";
    char *buff = cat(cat(cat(base, tile(c, from, to)), ", "), mess);

    return buff;
}

void send_all(client_manager_t *c, int nbClient, char *tmp)
{
    char *message = "";

    for (int i = 0; i < (c->nb_clients * c->nb_teams); i++) {
        if (c->client_infos[i].isauth && !c->client_infos[i].isdead
        && i != nbClient && c->client_infos[i].type != GUI) {
            message = cat(do_txt(c, nbClient, i, tmp), "\n");
            write(c->client_infos[i].client_socket, message, strlen(message));
        }
    }
}

void broadcast(client_manager_t *c, int nbClient, __attribute__((unused)) char *buff)
{
    int len = len_txt(c->client_infos[nbClient].buffer);
    char *tmp = malloc(sizeof(char) * (len + 1));
    size_t index = 0;

    memset(tmp, 0, (len + 1));
    for (size_t i = (strlen(BRDTXT) + 1);
    i < (strlen(c->client_infos[nbClient].buffer) - 1); i++) {
        tmp[index] = c->client_infos[nbClient].buffer[i];
        index++;
    }
    send_all(c, nbClient, tmp);
    write(c->client_infos[nbClient].client_socket, "ok\n", 3);
    pbc(c, get_gui_id(c), cat(cat(my_atoi(nbClient), " "),
    c->client_infos[nbClient].buffer));
}
