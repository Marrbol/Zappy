/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myftp-jean-vincent.amalfitano
** File description:
** coms
*/

#include "server.h"

bool check_req(client_manager_t *c, int nbClient, char *buff)
{
    if (c->client_infos[nbClient].isauth == false) {
        return com_login(c, nbClient, buff);
    } else {
        return true;
    }
}

void exec_client(client_manager_t *c, int nbClient, char *buff)
{
    bool exec = false;

    for (size_t i = 0; i < NB_COM_AI; i++) {
        if (strncmp(buff, allcoms_AI[i].name,
        strlen(allcoms_AI[i].name)) == 0) {
            allcoms_AI[i].findcoms(c, nbClient, buff);
            exec = true;
        }
    }
    if (c->client_infos[nbClient].first_connection) {
        c->client_infos[nbClient].first_connection = false;
        return;
    }
    if (!exec)
        write(c->client_infos[nbClient].client_socket, "ko\n", 3);
}

void exec_gui(client_manager_t *c, int nbClient, char *buff)
{
    bool exec = false;

    for (size_t i = 0; i < NB_COM_GUI; i++) {
        if (strncmp(buff, allcoms_GUI[i].name,
        strlen(allcoms_GUI[i].name)) == 0) {
            allcoms_GUI[i].findcoms(c, nbClient, buff);
            exec = true;
            printf("GUI: %s\n", buff);
        }
    }
    if (c->client_infos[nbClient].first_connection) {
        c->client_infos[nbClient].first_connection = false;
        msz(c, nbClient, NULL);
        sgt(c, nbClient, NULL);
        mct(c, nbClient, NULL);
        tna(c, nbClient, NULL);
        return;
    }
    if (!exec)
        write(c->client_infos[nbClient].client_socket, "ko\n", 3);
}

void exec_cmd(client_manager_t *c, int nbClient, char *buff)
{
    if (!check_req(c, nbClient, buff)) {
        return;
    }
    //BUFFFERIZED put the command in chained list
    if (c->client_infos[nbClient].exec_func)
        return;
    if (c->client_infos[nbClient].type == GUI)
        exec_gui(c, nbClient, buff);
    else
        exec_client(c, nbClient, buff);

}
