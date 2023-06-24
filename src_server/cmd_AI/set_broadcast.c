/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** set_broadcast
*/

#include "server.h"

void set_broadcast(client_manager_t *c, int nbClient, char *buff)
{
    c->client_infos[nbClient].time = 7;
    c->client_infos[nbClient].fct = broadcast;
    c->client_infos[nbClient].buffer = strdup(buff);
    c->client_infos[nbClient].action_clock = clock();
    c->client_infos[nbClient].exec_func = true;
}