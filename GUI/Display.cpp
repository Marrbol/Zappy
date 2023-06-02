/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** Display
*/

#include "Display.hpp"



int main(int ac, char **av)
{
    Display Display(atoi(av[1]), av[2]);
    Display.communicateWithServer();
    return 0;
}