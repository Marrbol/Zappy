/*
** EPITECH PROJECT, 2023
** temp
** File description:
** broadcast
*/

#include "server.h"

size_t len_txt(char *buff)
{
    size_t i = (strlen(BRDTXT) + 1);
    size_t res = 0;

    while (buff[i] != '\n' && buff[i] != '\0') {
        i++;
        res++;
    }
    return res;
}

char *tile(client_manager_t *c, int nbClient)
{
    //TODO find client dir sound
}

char *do_txt(client_manager_t *c, int nbClient, char *message)
{
    size_t len = strlen("message ") + 1 + strlen(", ") + strlen(message);
    char *txt = malloc(sizeof(char) * (len + 1));

    memset(txt, 0, (len + 1));
    strcat(txt, "message ");
    strcat(txt, tile(c, nbClient));
    strcat(txt, ", ");
    strcat(txt, message);
    return txt;
}

void send_all(client_manager_t *c, int nbClient, char *buff)
{
    char *txt = do_txt(c, nbClient, buff);

    for (size_t i = 0; i < (c->nb_clients * c->nb_teams); i++) {
        if (i != nbClient)
            write(c->client_infos[i].client_socket, txt, strlen(txt));
    }   
}

void broadcast(client_manager_t *c, int nbClient, char *buff)
{
    int len = len_txt(buff);
    char *tmp = malloc(sizeof(char) * (len + 1));
    size_t index = 0;

    memset(tmp, 0, (len + 1));
    for (size_t i = (strlen(BRDTXT) + 1); i < (strlen(buff) - 1); i++) {
        tmp[index] = buff[i];
        index++;
    }
    send_all(c, nbClient, buff);
    write(c->client_infos[nbClient].client_socket, "ok\n", 3);
}
