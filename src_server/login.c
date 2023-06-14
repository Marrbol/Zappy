/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** login
*/

#include "server.h"

bool client_base(client_manager_t *c, int nbClient, char *buff)
{
    if (remain_team(c, buff) == 0)
        return false;
    add_to_team(c, buff);
    c->client_infos[nbClient].isauth = true;
    c->client_infos[nbClient].team = buff;
    write(c->client_infos[nbClient].client_socket,
    my_atoi(remain_team(c, buff)),
    strlen(my_atoi(remain_team(c, buff))));
    write(c->client_infos[nbClient].client_socket, "\n", 1);
    write(c->client_infos[nbClient].client_socket, c->coord->coord,
    strlen(c->coord->coord));
    c->client_infos[nbClient].type = AI;
    return true;
}

void client_gui(client_manager_t *c, int nbClient, char *buff)
{
    c->client_infos[nbClient].isauth = true;
    c->client_infos[nbClient].team = buff;
    write(c->client_infos[nbClient].client_socket,
    my_atoi(remain_team(c, buff)),
    strlen(my_atoi(remain_team(c, buff))));
    write(c->client_infos[nbClient].client_socket, "\n", 1);
    write(c->client_infos[nbClient].client_socket, c->coord->coord,
    strlen(c->coord->coord));
    c->client_infos[nbClient].type = GUI;
}

bool com_login(client_manager_t *c, int nbClient, char *buff)
{
    for (int i = 0; i < c->nb_teams; i++) {
        if (strncmp(buff, c->teams[i].name, strlen(c->teams[i].name)) == 0) {
            return client_base(c, nbClient, buff);
        } else if (strncmp(buff, GUID, strlen(GUID)) == 0) {
            client_gui(c, nbClient, buff);
            return true;
        }
    }
    return false;
}
