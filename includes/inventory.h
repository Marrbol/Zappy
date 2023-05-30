/*
** EPITECH PROJECT, 2023
** temp
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_
    #include <stdlib.h>

typedef enum inv_s {food, deraumere, sibur, mendiane, phiras, thystame, none} inv_t;

void set_inventory(size_t *inv);

#endif /* !INVENTORY_H_ */
