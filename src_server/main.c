/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myftp-jean-vincent.amalfitano
** File description:
** main
*/

#include "server.h"
#include "print_usage.h"

int main(int ac, char **argv)
{
    if (ac == 2 && strcmp(argv[1], "-help") == 0) {
        print_usage();
        return 0;
    } else if (!check_param(argv, ac)) {
        return 84;
    } else {
        server(ac, argv);
        return 0;
    }
}
