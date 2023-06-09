/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** Materiaux
*/

#ifndef MATERIAUX_HPP_
#define MATERIAUX_HPP_
#include <iostream>
//linemate, deraumere, sibur, mendiane, phiras, thystame
class Materiaux {
    public:
        Materiaux(size_t food, size_t linemate, size_t deraumere, size_t sibur, size_t mendiane, size_t phiras, size_t thystame);
        ~Materiaux();
        Materiaux();
        bool operator==(const Materiaux &materiaux);
        bool operator>=(const Materiaux &materiaux);
        void operator-=(const Materiaux &materiaux);
        size_t getLinemate() const {return _linemate;};
        size_t getDeraumere() const {return _deraumere;};
        size_t getSibur() const {return _sibur;};
        size_t getMendiane() const {return _mendiane;};
        size_t getPhiras() const {return _phiras;};
        size_t getThystame() const {return _thystame;};
        size_t getFood() const {return _food;};
        void setLinemate(size_t linemate) {_linemate = linemate;};
        void setDeraumere(size_t deraumere) {_deraumere = deraumere;};
        void setSibur(size_t sibur) {_sibur = sibur;};
        void setMendiane(size_t mendiane) {_mendiane = mendiane;};
        void setPhiras(size_t phiras) {_phiras = phiras;};
        void setThystame(size_t thystame) {_thystame = thystame;};
        void setFood(size_t food) {_food = food;};

    private:
        size_t _linemate;
        size_t _deraumere;
        size_t _sibur;
        size_t _mendiane;
        size_t _phiras;
        size_t _thystame;
        size_t _food;
};

#endif /* !MATERIAUX_HPP_ */

// poid = nb de ce qui me manque pour le prochain rituel, rareté de l'objet