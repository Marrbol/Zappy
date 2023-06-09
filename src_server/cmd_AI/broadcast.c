/*
** EPITECH PROJECT, 2023
** temp
** File description:
** broadcast
*/

#include "server.h"

void broadcast(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient,
__attribute__((unused)) char *buff)
{
    int len = (strlen(buff) - strlen(BRDTXT) + 1);
    char *tmp = malloc(sizeof(char) * len);
    size_t index = 0;
    memset(tmp, 0, len);
    for (size_t i = (strlen(BRDTXT) + 1); i < (strlen(buff) - 1); i++) {
        tmp[index++] = buff[i];
    }
    printf("len = %d\n", len);
    printf("tmp = |%s|\n", tmp);
}
