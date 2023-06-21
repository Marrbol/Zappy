/*
** EPITECH PROJECT, 2023
** temp
** File description:
** coms_AI
*/

#ifndef COMS_AI_H_
#define COMS_AI_H_


static const coms_t allcoms_AI[NB_COM_AI] = {
    {
        .name = FWRD,
        .findcoms = &logout
    },
    {
        .name = RGHT,
        .findcoms = &users
    },
    {
        .name = LFT,
        .findcoms = &use
    },
    {
        .name = LK,
        .findcoms = &create
    },
    {
        .name = INVT,
        .findcoms = &list
    },
    {
        .name = BRDTXT,
        .findcoms = &info
    },
    {
        .name = CNCTNB;
        .findcoms = &help
    },
    {
        .name = FRK,
        .findcoms = &sendcmd
    },
    {
        .name = EJCT,
        .findcoms = &
    },
    {
        .name = TKO,
        .findcoms = &
    },
    {
        .name = STO,
        .findcoms = &
    },
    {
        .name = INC,
        .findcoms = &
    }
};

#endif /* !COMS_AI_H_ */
