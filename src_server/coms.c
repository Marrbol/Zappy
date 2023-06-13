/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myftp-jean-vincent.amalfitano
** File description:
** coms
*/

#include "server.h"

void client_base(client_manager_t *c, int nbClient, char *buff)
{
    c->client_infos[nbClient].isauth = true;
    c->client_infos[nbClient].team = buff;
    write(c->client_infos[nbClient].client_socket,
    my_atoi(remain_team(c, buff)),
    strlen(my_atoi(remain_team(c, buff))));
    write(c->client_infos[nbClient].client_socket, "\n", 1);
    write(c->client_infos[nbClient].client_socket, c->coord->coord,
    strlen(c->coord->coord));
    c->client_infos[nbClient].type = AI;
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
        if (strncmp(buff, c->teamsp[i], strlen(c->teamsp[i])) == 0) {
            client_base(c, nbClient, buff);
            return true;
        } else if (strncmp(buff, GUID, strlen(GUID)) == 0) {
            client_gui(c, nbClient, buff);
            return true;
        }
    }
    return false;
}

bool check_req(client_manager_t *c, int nbClient, char *buff)
{
    if (c->client_infos[nbClient].isauth == false) {
        return com_login(c, nbClient, buff);
    } else {
        return true;
    }
}

void exec_cmd(client_manager_t *c, int nbClient, char *buff)
{
    if (!check_req(c, nbClient, buff)) {
        //TODO ==> SEND COMMAND FALSE
        return;
    }
    //BUFFFERIZED
    for (size_t i = 0; i < NB_COM_AI; i++) {
        if (strncmp(buff, allcoms_AI[i].name, strlen(allcoms_AI[i].name)) == 0)
            allcoms_AI[i].findcoms(c, nbClient, buff);
    }
}
