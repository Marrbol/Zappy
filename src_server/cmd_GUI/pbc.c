/*
** EPITECH PROJECT, 2023
** temp
** File description:
** pbc
*/

#include "server.h"

char *do_rebuff(char *buff)
{
    char *delete = "Broadcast ";
    printf("len buff = %ld len delete = %ld\n", strlen(buff), strlen(delete));
    int len = ((strlen(buff) - strlen(delete) + 1));
    printf("len = %d\n", len);
    char *rebuff = malloc(sizeof(char) * len);
    int index = (strlen(delete) + 2);

    memset(rebuff, 0, len);
    for (int i = 0; i < (len - 3); i++) {
        rebuff[i] = buff[index++];
    }
    return rebuff;
}

void pbc(client_manager_t *c, int nbClient, char *buff) {
    char *base = "pbc ";
    char *rebuff = do_rebuff(buff);
    char *message = "";

    message = cat(base, rebuff);
    write(c->client_infos[nbClient].client_socket, message, strlen(message));
}
