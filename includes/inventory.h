/*
** EPITECH PROJECT, 2023
** temp
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include <stdlib.h>
    #define LENINV (8)

typedef enum inv_s {food, deraumere, linemate, sibur, mendiane, phiras, thystame, none} inv_t;

typedef struct inventory_s {
    char *name;
    int id;
    float density;
} inventory_t;

static const inventory_t allInv[LENINV] = {
    {
        .id = food,
        .name = "food",
        .density = 0.5
    },
    {
        .id = linemate,
        .name = "linemate",
        .density = 0.3
    },
    {
        .id = deraumere,
        .name = "deraumere",
        .density = 0.15

    },
    {
        .id = sibur,
        .name = "sibur",
        .density = 0.1

    },
    {
        .id = mendiane,
        .name = "mendiane",
        .density = 0.1

    },
    {
        .id = phiras,
        .name = "phiras",
        .density = 0.08

    },
    {
        .id = thystame,
        .name = "thystame",
        .density = 0.05

    },
    {
        .id = none,
        .name = "none",
        .density = 0.0
    }
};

void set_inventory(int *inv);

#endif /* !INVENTORY_H_ */
