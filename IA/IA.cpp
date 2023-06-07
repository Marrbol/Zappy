/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** IA
*/

#include "IA.hpp"

IA::IA()
{
}

IA::~IA()
{
}

void IA::calculeMateriauxPoids()
{
    size_t _poidFood = (_inventaire.getFood() - _inventaire.getFood()) / FOODRARETY;
    size_t _poidLinemate = (_rituels[_level].getLinemate() - _inventaire.getLinemate()) / LINEMATERARETY;
    size_t _poidDeraumere = (_rituels[_level].getDeraumere() - _inventaire.getDeraumere()) / DERAUMERERARETY;
    size_t _poidSibur = (_rituels[_level].getSibur() - _inventaire.getSibur()) / SIBURRARETY;
    size_t _poidMendiane = (_rituels[_level].getMendiane() - _inventaire.getMendiane()) / MENDIANERARETY;
    size_t _poidPhiras = (_rituels[_level].getPhiras() - _inventaire.getPhiras()) / PHIRASRARETY;
    size_t _poidThystame = (_rituels[_level].getThystame() - _inventaire.getThystame()) / THYSTAMERARETY;

    _poidMateriaux.setDeraumere(_poidDeraumere);
    _poidMateriaux.setFood(_poidFood);
    _poidMateriaux.setLinemate(_poidLinemate);
    _poidMateriaux.setMendiane(_poidMendiane);
    _poidMateriaux.setPhiras(_poidPhiras);
    _poidMateriaux.setSibur(_poidSibur);
    _poidMateriaux.setThystame(_poidThystame);
    // std::cout << "poid food = " << _poidFood << std::endl;
    // std::cout << "poid linemate = " << _poidLinemate << std::endl;
    // std::cout << "poid deraumere = " << _poidDeraumere << std::endl;
    // std::cout << "poid sibur = " << _poidSibur << std::endl;
    // std::cout << "poid mendiane = " << _poidMendiane << std::endl;
    // std::cout << "poid phiras = " << _poidPhiras << std::endl;
    // std::cout << "poid thystame = " << _poidThystame << std::endl;
}

void IA::calculeTilesPoids()
{
    for (size_t i = 0; i < caseMaxViewLevel(_level); i++) {
        size_t poidTmp = 0;
        if (_view[i].find("food") != std::string::npos)
            poidTmp += _poidMateriaux.getFood();
        if (_view[i].find("linemate") != std::string::npos)
            poidTmp += _poidMateriaux.getLinemate();
        if (_view[i].find("deraumere") != std::string::npos)
            poidTmp += _poidMateriaux.getDeraumere();
        if (_view[i].find("sibur") != std::string::npos)
            poidTmp += _poidMateriaux.getSibur();
        if (_view[i].find("mendiane") != std::string::npos)
            poidTmp += _poidMateriaux.getMendiane();
        if (_view[i].find("phiras") != std::string::npos)
            poidTmp += _poidMateriaux.getPhiras();
        if (_view[i].find("thystame") != std::string::npos)
            poidTmp += _poidMateriaux.getThystame();
        _tilesPoid[i] = poidTmp;
        // std::cout << " poid de case " << i << " = " << _tilesPoid[i] << std::endl;
    }
}

size_t IA::caseMaxViewLevel(size_t level)
{
    if (level == 1)
        return 3;
    if (level == 2)
        return 8;
    if (level == 3)
        return 15;
    if (level == 4)
        return 24;
    if (level == 5)
        return 35;
    if (level == 6)
        return 48;
    if (level == 7)
        return 63;
    if (level == 8)
        return 80;
    return 0;
}

// trouver un moyen de savoir quelles ressources sont sur quelles cases et de stocker ça

// int main()
// {
//     IA ia;
//     ia.look();
//     std::cout << std::endl;
//     ia.calculeMateriauxPoids();
//     std::cout << std::endl;
//     ia.calculeTilesPoids();
//     std::cout << "fini" <<std::endl;
//     return 0;
// }
