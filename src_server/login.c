/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** login
*/

#include "server.h"

void c_pnw(client_manager_t *c, int nbCLient)
{
    char *info = "";

    info = cat(cat(cat(cat(cat(cat(cat(cat(cat(cat(my_atoi(nbCLient), " "),
    my_atoi(c->client_infos[nbCLient].coord->x)), " "),
    my_atoi(c->client_infos[nbCLient].coord->y)), " "),
    my_atoi((int)c->client_infos[nbCLient].d)), " "),
    my_atoi((int)c->client_infos[nbCLient].lvl)), " "),
    c->client_infos[nbCLient].team);
    pnw(c, get_gui_id(c), info);
}

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
    c->client_infos[nbClient].first_connection = true;
    c_pnw(c, nbClient);
    return true;
}

void client_gui(client_manager_t *c, int nbClient, char *buff)
{
    c->client_infos[nbClient].isauth = true;
    c->client_infos[nbClient].team = buff;
    c->client_infos[nbClient].type = GUI;
    c->client_infos[nbClient].first_connection = true;
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
