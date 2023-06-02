/*
** EPITECH PROJECT, 2023
** temp
** File description:
** inventory
*/

#include "inventory.h"

void set_inventory(size_t *inv)
{
    inv = malloc(sizeof(size_t) * LENINV);

    for (size_t i = food; i < none; i++)
        inv[i] = 0;
}
