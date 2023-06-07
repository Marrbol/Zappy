/*
** EPITECH PROJECT, 2023
** temp
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include <stdlib.h>
    #define LENINV (7)

typedef enum inv_s {food, deraumere, sibur, mendiane, phiras, thystame, none} inv_t;

typedef struct inventory_s {
    char *name;
    int id;
} inventory_t;

static const inventory_t allInv[LENINV] = {
    {
        .id = food,
        .name = "food"
    },
    {
        .id = deraumere,
        .name = "deraumere"
    },
    {
        .id = sibur,
        .name = "sibur"
    },
    {
        .id = mendiane,
        .name = "mendiane"
    },
    {
        .id = phiras,
        .name = "phiras"
    },
    {
        .id = thystame,
        .name = "thystame"
    },
    {
        .id = none,
        .name = "none"
    }
};

void set_inventory(int *inv);

#endif /* !INVENTORY_H_ */
