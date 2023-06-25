/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** manage_clock
*/

#include "../includes/server.h"

void init_clock_server(client_manager_t *c, int freq)
{
    c->comet_clock = clock();
}

void init_clock_client(client_manager_t *c, int nbClient)
{
    c->client_infos[nbClient].food_clock = clock();
    c->client_infos[nbClient].action_clock = clock();
}

void manage_clock_comet(client_manager_t *c)
{
    clock_t current_time = clock();
    double time = 0;

    time = (double)(current_time - c->comet_clock) / CLOCKS_PER_SEC;
    if (time >= (20.0 / c->freq)) {
        c->comet_clock = clock();
        comete(c);
    }
}

void manage_clock_client(client_manager_t *c, int nb_client, char *com)
{
    clock_t current_time = clock();
    int time_for_action = c->client_infos[nb_client].time;
    double time = 0;

    time = ((double)(current_time - c->client_infos[nb_client].action_clock) / CLOCKS_PER_SEC);
    if (time >= (time_for_action / c->freq)) {
        c->client_infos[nb_client].action_clock = clock();
        c->client_infos[nb_client].exec_func = false;
        c->client_infos[nb_client].fct(c, nb_client, com);
    }
}

void manage_clock_food(client_manager_t *c, int nb_client)
{
    clock_t current_time = clock();
    double time = 0;

    time = (double)(current_time - c->client_infos[nb_client].food_clock) / CLOCKS_PER_SEC;
    if (time >= (126.0 / c->freq)) {
        c->client_infos[nb_client].food_clock = clock();
        c->client_infos[nb_client].inv[food]--; //faire baisser de l'inventaire
        if (c->client_infos[nb_client].inv[food] == -1) {
            c->client_infos[nb_client].isdead = true;
            dprintf(c->client_infos[nb_client].client_socket, "dead\n", 5);
            pdi(c, get_gui_id(c), my_atoi(nb_client));
        }
    }
}
