/*
** EPITECH PROJECT, 2023
** B-NWP-400-REN-4-1-myteams-enzo.monnier
** File description:
** check
*/

#include "server.h"

bool check_port(char **argv)
{
    if (strcmp("-p", argv[1]) != 0)
        return false;
    if (!is_nb(argv[2]))
        return false;
    return true;
}

bool check_coord(char **argv)
{
    if (strcmp("-x", argv[3]) != 0 || strcmp("-y", argv[5]) != 0)
        return false;
    if (!is_nb(argv[4]) || !is_nb(argv[6]))
        return false;
    return true;
}

bool check_name(char **argv, int ac)
{
    if (strcmp("-n", argv[7]) != 0)
        return false;
    if (count_team(argv, ac) == 0)
        return false;
    return true;
}

bool check_other(char **argv, int ac)
{
    if (strcmp(argv[8 + count_team(argv, ac)], "-c") != 0 ||
    strcmp(argv[10 + count_team(argv, ac)], "-f") != 0)
        return false;
    if (!is_nb(argv[9 + count_team(argv, ac)]) ||
    !is_nb(argv[11 + count_team(argv, ac)]))
        return false;
    if (atoi((argv[11 + count_team(argv, ac)])) < 2)
        return false;
    return true;
}

bool check_param(char **argv, int ac)
{
    if (!check_port(argv) || !check_coord(argv))
        return false;
    if (!check_name(argv, ac))
        return false;
    if (!check_other(argv, ac))
        return false;
    return true;
}