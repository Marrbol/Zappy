/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myftp-jean-vincent.amalfitano
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include "inventory.h"
    #include <sys/time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <errno.h>
    #include <string.h>
    #include <uuid/uuid.h>
    #include <dirent.h>
    #include <signal.h>
    #include "utils.h"
    #include "protocol.h"
    #define _GNU_SOURCE
    #define BUFFER_LEN (200)
    #define NB_CLIENTS (30)
    #define LENLOG (4)
    #define LENREQFILEOK (4)
    #define LENCMDNOTIMP (4)
    #define LENCMDBADPARAM (4)
    #define LEN_USE (3)
    #define STATE_TEAM (0)
    #define STATE_CHANNEL (1)
    #define STATE_THREAD (2)
    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512
    #define GUID ("GRAPHIC")

typedef enum type_s {NONE, AI, GUI} type_t;

typedef enum dir_s {NONE1, NORTH, EAST, SUD, OUEST, NONE2} dir_t;

typedef struct coord_s {
    int x;
    int y;
    char *coord;
} coord_t;

typedef struct server_s {
    int server_socket;
    socklen_t addrlen;
    struct sockaddr_in servAd;
} server_t;

typedef struct client_s {
    type_t type;
    dir_t d;
    coord_t *coord;
    int client_socket;
    bool isauth;
    bool new_connection;
    char *team;
    int *inv;
    size_t lvl;
} client_t;

typedef struct team_s {
    char *name;
    size_t nb;
} team_t;

typedef struct egg_s {
    int x;
    int y;
    int time;
    char *team;
    struct egg_s *next;
} egg_t;

typedef struct client_manager_s {
    fd_set read_fds;
    client_t *client_infos;
    coord_t *coord;
    int ***map;
    team_t *teams;
    int nb_teams;
    int nb_clients;
    int maxsd;
    int freq;
    egg_t *egg;
} client_manager_t;

bool is_nb(char *buff);
char *my_atoi(int nb);
int protocode(char *buff);
inv_t search_type(char *tmp);
int server(int ac, char **argv);
void comete(client_manager_t *c);
char *cat(char *tmp, char *name);
void set_client_coord(coord_t *c);
void set_map(client_manager_t *c);
bool issearch(char *name, char *uid);
void set_clients(client_manager_t *c);
bool check_param(char **argv, int ac);
size_t count_team(char **argv, int ac);
void set_coord(client_manager_t *c, char **argv);
void destroy(server_t *s, client_manager_t *c);
int remain_team(client_manager_t *c, char *team);
void add_to_team(client_manager_t *c, char *team);
void create_socket_server(server_t *s, char *port);
void set_readfds(server_t *s, client_manager_t *c);
char *get_content(client_manager_t *c, int x, int y);
size_t nb_state_def(client_manager_t *c, int nbClient);
void set_teams(client_manager_t *c, int ac, char **argv);
void exec_cmd(client_manager_t *c, int nbClient, char *buff);
bool com_login(client_manager_t *c, int nbClient, char *buff);
void create_team(char *buff, client_manager_t *c, int nbClient);
void list_folder(char *where, client_manager_t *c, int nbClient);

void forward(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff);
void right(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff);
void left(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff);
void look(client_manager_t *c, int nbClient, char *buff);
void invent(client_manager_t *c, int nbClient, char *buff);
void broadcast(client_manager_t *c, int nbClient, char *buff);
void connect_to(client_manager_t *c, int nbClient,
__attribute__((unused)) char *buff);
void forks(client_manager_t *c, int nbClient, char *buff);
void eject(client_manager_t *c, int nbClient, char *buff);
void take(client_manager_t *c, int nbClient, char *buff);
void set(client_manager_t *c, int nbClient, char *buff);
void incantation(client_manager_t *c, int nbClient, char *buff);

void msz(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void bct(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void mct(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void tna(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void pnw(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void ppo(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void plv(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void pin(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void pex(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void pbc(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void pic(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void pie(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void pfk(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void pdr(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void pgt(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void pdi(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void enw(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void ebo(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void edi(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void sgt(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void sst(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void seg(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void smg(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void suc(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);
void sbp(__attribute__((unused)) client_manager_t *c,
__attribute__((unused)) int nbClient, __attribute__((unused)) char *buff);

typedef struct coms_s {
    char *name;
    void (*findcoms)(client_manager_t *c, int nbClient, char *buff);
} coms_t;

static const coms_t allcoms_AI[NB_COM_AI] = {
    {
        .name = FWRD,
        .findcoms = &forward
    },
    {
        .name = RGHT,
        .findcoms = &right
    },
    {
        .name = LFT,
        .findcoms = &left
    },
    {
        .name = LK,
        .findcoms = &look
    },
    {
        .name = INVT,
        .findcoms = &invent
    },
    {
        .name = BRDTXT,
        .findcoms = &broadcast
    },
    {
        .name = CNCTNB,
        .findcoms = &connect_to
    },
    {
        .name = FRK,
        .findcoms = &forks
    },
    {
        .name = EJCT,
        .findcoms = &eject
    },
    {
        .name = TKO,
        .findcoms = &take
    },
    {
        .name = STO,
        .findcoms = &set
    },
    {
        .name = INC,
        .findcoms = &incantation
    }
};

static const coms_t allcoms_GUI[NB_COM_GUI] = {
    {
        .name = MSZ,
        .findcoms = &msz
    },
    {
        .name = BCT,
        .findcoms = &bct
    },
    {
        .name = MCT,
        .findcoms = &mct
    },
    {
        .name = TNA,
        .findcoms = &tna
    },
    {
        .name = PNW,
        .findcoms = &pnw
    },
    {
        .name = PPO,
        .findcoms = &ppo
    },
    {
        .name = PLV,
        .findcoms = &plv
    },
    {
        .name = PIN,
        .findcoms = &pin
    },
    {
        .name = PEX,
        .findcoms = &pex
    },
    {
        .name = PBC,
        .findcoms = &pbc
    },
    {
        .name = PIC,
        .findcoms = &pic
    },
    {
        .name = PIE,
        .findcoms = &pie
    },
    {
        .name = PFK,
        .findcoms = &pfk
    },
    {
        .name = PDR,
        .findcoms = &pdr
    },
    {
        .name = PGT,
        .findcoms = &pgt
    },
    {
        .name = PDI,
        .findcoms = &pdi
    },
    {
        .name = ENW,
        .findcoms = &enw
    },
    {
        .name = EBO,
        .findcoms = &ebo
    },
    {
        .name = EDI,
        .findcoms = &edi
    },
    {
        .name = SGT,
        .findcoms = &sgt
    },
    {
        .name = SST,
        .findcoms = &sst
    },
    {
        .name = SEG,
        .findcoms = &seg
    },
    {
        .name = SMG,
        .findcoms = &smg
    },
    {
        .name = SUC,
        .findcoms = &suc
    },
    {
        .name = SBP,
        .findcoms = &sbp
    }
};

#endif /* !SERVER_H_ */
