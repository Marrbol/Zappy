/*
** EPITECH PROJECT, 2023
** temp
** File description:
** invent
*/

#include "server.h"

void write_to(client_manager_t *c, int nbClient, size_t i)
{
    write(c->client_infos[nbClient].client_socket, ", ", 2);
    write(c->client_infos[nbClient].client_socket, allInv[i].name,
    strlen(allInv[i].name));
    write(c->client_infos[nbClient].client_socket, " ", 1);
    write(c->client_infos[nbClient].client_socket,
    my_atoi(c->client_infos[nbClient].inv[i]),
    strlen(my_atoi(c->client_infos[nbClient].inv[i])));
}

void set_invent(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff)
{
    c->client_infos[nbClient].time = 1;
    c->client_infos[nbClient].fct = invent;
    c->client_infos[nbClient].action_clock = clock();
    c->client_infos[nbClient].exec_func = true;
}

void invent(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff)
{
    size_t i = 0;

    write(c->client_infos[nbClient].client_socket, "[ ", 2);
    write(c->client_infos[nbClient].client_socket, allInv[i].name,
    strlen(allInv[i].name));
    write(c->client_infos[nbClient].client_socket, " ", 1);
    write(c->client_infos[nbClient].client_socket,
    my_atoi(c->client_infos[nbClient].inv[i]),
    strlen(my_atoi(c->client_infos[nbClient].inv[i])));
    i++;
    while (i < (LENINV - 1)) {
        write_to(c, nbClient, i);
        i++;
    }
    write(c->client_infos[nbClient].client_socket, " ]\n", 3);
}
