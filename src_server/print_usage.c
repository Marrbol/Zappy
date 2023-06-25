/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myftp-jean-vincent.amalfitano
** File description:
** print_usage
*/

#include <stdio.h>

void print_usage(void)
{
    printf("USAGE:  ./zappy_server -p port -x width -y height -n name1 ");
    printf("name2 ... -c clientsNb\n");
    printf("-f freq\n");
    printf("        port        is the port number\n");
    printf("        width       is the width of the world\n");
    printf("        height      is the height of the world\n");
    printf("        nameX       is the name of the team X\n");
    printf("        clientNb    is the number of authorized clients per ");
    printf("team\n");
    printf("        freq        is the reciprocal of time unit for ");
    printf("execution of actions\n");
}
