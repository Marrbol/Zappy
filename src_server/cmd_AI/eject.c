/*
** EPITECH PROJECT, 2023
** temp
** File description:
** eject
*/

#include "server.h"

void set_eject(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff)
{
    c->client_infos[nbClient].fct = eject;
    c->client_infos[nbClient].exec_func = true;
    c->client_infos[nbClient].time = 7;
}

void eject(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff)
{
    comete(c);
}
