/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myftp-jean-vincent.amalfitano
** File description:
** coms
*/

#include "server.h"

bool com_login(client_manager_t *c, int nbClient, char *buff)
{
    for (int i = 0; i < c->nb_teams; i++) {
        if (strncmp(buff, c->teamsp[i], strlen(c->teamsp[i])) == 0) {
            c->client_infos[nbClient].isauth = true;
            c->client_infos[nbClient].team = buff;
            write(c->client_infos[nbClient].client_socket,
            my_atoi(remain_team(c, buff)),
            strlen(my_atoi(remain_team(c, buff))));
            write(c->client_infos[nbClient].client_socket, c->coord->coord,
            strlen(c->coord->coord));
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
