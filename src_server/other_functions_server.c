/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myftp-jean-vincent.amalfitano
** File description:
** other_functions_server
*/

#include "server.h"

void create_socket_server(server_t *s, char *port)
{
    int check = 0;

    check = socket(AF_INET, SOCK_STREAM, 0);
    if (check == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    memset(&s->servAd, 0, sizeof(struct sockaddr_in));
    s->server_socket = check;
    s->servAd.sin_family = AF_INET;
    s->servAd.sin_addr.s_addr = INADDR_ANY;
    s->servAd.sin_port = htons(atoi(port));
    check = 0;
    check = bind(s->server_socket,  (struct sockaddr *)&s->servAd,
    sizeof(s->servAd));
    if (check < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    s->addrlen = sizeof(struct sockaddr_in);
}

void set_clients(client_manager_t *c)
{
    c->client_infos = malloc(sizeof(client_t) * NB_CLIENTS);

    for (size_t i = 0; i < NB_CLIENTS; i++) {
        c->client_infos[i].type = NONE;
        c->client_infos[i].client_socket = 0;
        c->client_infos[i].isauth = false;
        c->client_infos[i].new_connection = true;
        c->client_infos[i].team = NULL;
        set_inventory(c->client_infos[i].inv);
    };
    c->maxsd = 0;
}

void set_readfds(server_t *s, client_manager_t *c)
{
    int sd = 0;
    c->maxsd = s->server_socket;

    FD_ZERO(&c->read_fds);
    FD_SET(s->server_socket, &c->read_fds);
    for (size_t i = 0; i < NB_CLIENTS; i++) {
        sd = c->client_infos[i].client_socket;
        if (sd > 0)
            FD_SET(sd, &c->read_fds);
        if (sd > c->maxsd)
            c->maxsd = sd;
    }
}

void set_teams(client_manager_t *c, int ac, char **argv)
{
    size_t i = 8;
    int index = 0;

    c->nb_teams = count_team(argv, ac);
    c->teamsp = malloc(sizeof(char *) * c->nb_teams + 1);
    while (index < c->nb_teams) {
        c->teamsp[index++] = argv[i];
        i++;
    }
    c->teamsp[i] = NULL;
    c->nb_clients = atoi(argv[9 + c->nb_teams]);
    c->freq = atoi(argv[11 + count_team(argv, ac)]);
}

void set_coord(client_manager_t *c, char **argv)
{
    c->coord = malloc(sizeof(coord_t));
    c->coord->coord = malloc(sizeof(char) * (strlen(argv[3]) +
    strlen(argv[5]) + 3));

    memset(c->coord->coord, 0, (strlen(argv[3]) + strlen(argv[5]) + 3));
    strcat(c->coord->coord, argv[4]);
    strcat(c->coord->coord, " ");
    strcat(c->coord->coord, argv[6]);
    strcat(c->coord->coord, "\n");
    c->coord->x = atoi(argv[3]);
    c->coord->y = atoi(argv[5]);
}
