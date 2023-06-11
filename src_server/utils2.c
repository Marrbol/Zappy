/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-enzo.monnier
** File description:
** utils2
*/

#include "server.h"

void print_desc(char *dir, char *name, client_manager_t *c, int nbClient)
{
    FILE *f;
    char *line = NULL;
    size_t len = 0;

    f = fopen(cat(dir, name), "r");
    while (getline(&line, &len, f) != -1) {
        write(c->client_infos[nbClient].client_socket, name, strlen(name));
        write(c->client_infos[nbClient].client_socket, line, len);
    }
    fclose(f);
}

void list_folder(char *where, client_manager_t *c, int nbClient)
{
    DIR *dir;
    struct dirent *ent;

    dir = opendir(where);
    if (dir != NULL) {
        while (1) {
            ent = readdir(dir);
            if (ent == NULL)
                break;
            if (!(strcmp(ent->d_name, ".") == 0 ||
            strcmp(ent->d_name, "..") == 0)) {
                print_desc(cat(where, ent->d_name), DESC, c, nbClient);
            }
        }
        closedir(dir);
    }
}

char *my_atoi(int nb)
{
    int len = snprintf(NULL, 0, "%d", nb);
    char *buff = malloc(sizeof(char) * (len + 1));

    snprintf(buff, (len + 1), "%d", nb);
    return buff;
}

inv_t search_type(char *tmp)
{
    for (inv_t i = food; i < none; i++)
        if (strcmp(allInv[i].name, tmp) == 0) {
            return allInv[i].id;
        }
    return none;
}
