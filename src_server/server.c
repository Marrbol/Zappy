/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myftp-jean-vincent.amalfitano
** File description:
** server
*/

#include "server.h"

void check_send_connexion(client_manager_t *c)
{
    for (size_t i = 0; i < NB_CLIENTS; i++) {
        if (c->client_infos[i].client_socket != 0 &&
        c->client_infos[i].new_connection) {
            c->client_infos[i].new_connection = false;
            write(c->client_infos[i].client_socket, "WELCOME\n", 8);
        }
    }
}

void check_inc_co(server_t *s, client_manager_t *c)
{
    int tmp_socket = 0;

    if (FD_ISSET(s->server_socket, &c->read_fds) == 1) {
        tmp_socket = accept(s->server_socket, (struct sockaddr *)&s->servAd,
        (socklen_t *)&s->addrlen);
    }
    for (size_t i = 0; i < NB_CLIENTS; i++) {
        if (c->client_infos[i].client_socket == 0) {
            c->client_infos[i].client_socket = tmp_socket;
            break;
        }
    }
    check_send_connexion(c);
}

void manage_clients(client_manager_t *c)
{
    char buff[1024];

    memset(buff, 0, sizeof(buff));
    for (size_t i = 0; i < NB_CLIENTS; i++) {
        if (c->client_infos[i].exec_func)
            manage_clock_client(c, i, NULL); //corriger le NULL
        manage_clock_food(c, i);
        if (FD_ISSET(c->client_infos[i].client_socket, &c->read_fds) == 1) {
            read(c->client_infos[i].client_socket, buff, sizeof(buff));
            //bufferisation here
            exec_cmd(c, i, buff); //remove here
            //bufferisation
            FD_CLR(c->client_infos[i].client_socket, &c->read_fds);
        }
        //put exec_cmd here replace buff by first element of chained list
    }
}

void loop_server(server_t *s, client_manager_t *c)
{
    c->maxsd = 0;

    listen(s->server_socket, NB_CLIENTS);
    struct timeval tv;
    tv.tv_sec = c->freq;
    tv.tv_usec = 0;
    while (1) {
        manage_clock_comet(c);
        set_readfds(s, c);
        if (select(c->maxsd + 1, &c->read_fds, NULL, NULL, &tv) == -1)
            perror("select()\n");
        check_inc_co(s, c);
        manage_clients(c);
    }
}

int server(int ac, char **argv)
{
    server_t *s = malloc(sizeof(server_t));
    client_manager_t *c = malloc(sizeof(client_manager_t));
    time_t t;

    signal(SIGPIPE, SIG_IGN);
    srand((unsigned) time(&t));
    create_socket_server(s, argv[2]);
    set_clients(c);
    set_teams(c, ac, argv);
    set_coord(c, argv);
    set_map(c);
    init_clock_server(c, c->freq);
    loop_server(s, c);
    destroy(s, c);
    return 0;
}
