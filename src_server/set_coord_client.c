/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** set_coord_client
*/

#include "server.h"

void set_client_coord(client_manager_t *c, coord_t *coord)
{
    coord->x = (rand() % c->coord->x);
    coord->y = (rand() % c->coord->y);
    coord->coord = cat(cat(my_atoi(coord->x), " "), my_atoi(coord->y));
}
