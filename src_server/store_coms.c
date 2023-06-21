/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myftp-jean-vincent.amalfitano
** File description:
** store_coms
*/

#include "server.h"

void logout(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff)
{
    c->client_infos[nbClient].isauth = false;
}