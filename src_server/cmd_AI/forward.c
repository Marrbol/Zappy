/*
** EPITECH PROJECT, 2023
** temp
** File description:
** forward
*/

#include "server.h"

void verif_coord(client_manager_t *c, int nbClient)
{
    if (c->client_infos[nbClient].coord->x > c->coord->x)
        c->client_infos[nbClient].coord->x = 0;
    if (c->client_infos[nbClient].coord->x < 0)
        c->client_infos[nbClient].coord->x = c->coord->x;
    if (c->client_infos[nbClient].coord->y > c->coord->y)
        c->client_infos[nbClient].coord->y = 0;
    if (c->client_infos[nbClient].coord->y < 0)
        c->client_infos[nbClient].coord->y = c->coord->y;
    //update char *coord
}

void forward(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff)
{
    switch (c->client_infos[nbClient].d) {
        case NORTH:
            c->client_infos[nbClient].coord->x++;
            break;
        case SUD:
            c->client_infos[nbClient].coord->x--;
            break;
        case OUEST:
            c->client_infos[nbClient].coord->y--;
            break;
        default:
            c->client_infos[nbClient].coord->y++;
            break;
    }
    verif_coord(c, nbClient);
    write(c->client_infos[nbClient].client_socket, "ok\n", 3);
}