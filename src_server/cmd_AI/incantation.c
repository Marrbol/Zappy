/*
** EPITECH PROJECT, 2023
** temp
** File description:
** incantation
*/

#include "server.h"

void set_incantation(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff)
{

    c->client_infos[nbClient].fct = incantation;
    c->client_infos[nbClient].exec_func = true;
    c->client_infos[nbClient].time = 300;
}

void incantation(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff)
{

    printf("Elevation underway\n");
    switch (c->client_infos[nbClient].lvl)
    {
    case 1:
        elevation_lvltwo(c, nbClient, buff);
        break;
    case 2:
        elevation_lvlthree(c, nbClient, buff);
        break;
    default:
        break;
    }

}
