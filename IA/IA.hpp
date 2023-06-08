/*
** EPITECH PROJECT, 2023
** B-YEP-400-REN-4-1-zappy-martin.boucault
** File description:
** IA
*/

#ifndef IA_HPP_
    #define IA_HPP_

#include <iostream>
#include <map>
#include <vector>
#include "../Materiaux/Materiaux.hpp"
#include <string>
#include <list>
#include <functional>
#include "../network/Network.hpp"
#include <iostream>
#include <error.h>
#define FOODRARETY 0.5
#define LINEMATERARETY 0.3
#define DERAUMERERARETY 0.15
#define SIBURRARETY 0.1
#define MENDIANERARETY 0.1
#define PHIRASRARETY 0.08
#define THYSTAMERARETY 0.05
#define MAXLEVEL 8
#define FOOD "food"
#define LINEMATE "linemate"
#define DERAUMERE "deraumere"
#define SIBUR "sibur"
#define MENDIANE "mendiane"
#define PHIRAS "phiras"
#define THYSTAME "thystame"

class IA {
    public:
        ~IA();
        void calculeMateriauxPoids();
        void calculeTilesPoids();

        IA(int port, std::string name, std::string machine);
        void communicateWithServer();
        void parseCommande();
        void loopIA();

        //send command
        void forward();
        void turnLeft();
        void turnRight();
        void look();
        void broadcast(std::string message);
        void inventory();
        void connectNbr();
        void fork();
        void eject();
        void take(std::string object);
        void set(std::string object);
        void incantation();

        //get command
        void getForward();
        void getTurnLeft();
        void getTurnRight();
        void getLook();
        void getBroadcast();
        void getInventory();
        void getConnectNbr();
        void getFork();
        void getEject();
        void getTake();
        void getSet();
        void getIncantation();
        size_t countSubStr(std::string str, std::string subStr);

    private:
        std::string _commande;
        std::string _machine;
        std::string _line;
        std::pair<size_t, size_t> _mapSize;
        size_t _level = 3;
        std::string _teamName;
        size_t _clientName;
        std::string _actualCommand;
        bool _isDead = false;

        bool _validate = false;
        bool _start = false;
        bool _name = false;
        fd_set _readfds;
        Network _network;
        int _socket;
        std::list<std::string> _responce;
        std::list<std::string> _ask;

        using CommandFunction = std::function<void(void)>;

        typedef struct allCmdS {
            std::string cmd;
            CommandFunction func;
        } allCmdT;

         std::vector<allCmdT> _cmd = {
            {"forward", std::bind(&IA::getForward, this)},
            {"right", std::bind(&IA::getTurnRight, this)},
            {"left", std::bind(&IA::getTurnLeft, this)},
            {"look", std::bind(&IA::getLook, this)},
            {"broadcast", std::bind(&IA::getBroadcast, this)},
            {"inventory", std::bind(&IA::getInventory, this)},
            {"connect_nbr", std::bind(&IA::getConnectNbr, this)},
            {"fork", std::bind(&IA::getFork, this)},
            {"eject", std::bind(&IA::getEject, this)},
            {"take", std::bind(&IA::getTake, this)},
            {"set", std::bind(&IA::getSet, this)},
            {"incantation", std::bind(&IA::getIncantation, this)},
        };
        size_t _food;
        std::map<size_t, Materiaux> _rituels = {
            {1, Materiaux(1,0,0,0,0,0)},
            {2, Materiaux(1,1,1,0,0,0)},
            {3, Materiaux(2,0,1,0,2,0)},
            {4, Materiaux(1,1,2,0,1,0)},
            {5, Materiaux(1,2,1,3,0,0)},
            {6, Materiaux(1,2,3,0,1,0)},
            {7, Materiaux(2,2,2,2,2,1)}
        };
        std::map<size_t, size_t> _maxCaseViewLevel = {
            {1, 3},
            {2, 8},
            {3, 15},
            {4, 24},
            {5, 35},
            {6, 48},
            {7, 63},
            {8, 80}
        };
        Materiaux _inventaire = Materiaux(0,0,0,0,0,0);
        std::map<size_t, std::string> _materiauxPriority;
        std::map<std::string, size_t> _tilesPriority; // index de la case et poid de la case
        std::map<size_t, std::string> _view;
        Materiaux _poidMateriaux;
        std::map<size_t, size_t> _tilesPoid;
        std::map<size_t, size_t> _tilesDistance = { // index de la case et distance de la case
            {0,0},
            {1,2},
            {2,1},
            {3,2},
            {4,4},
            {5,3},
            {6,2},
            {7,3},
            {8,4},
            {9,6},
            {10,5},
            {11,4},
            {12,3},
            {13,4},
            {14,5},
            {15,6},
            {16,8},
            {17,7},
            {18,6},
            {19,5},
            {20,4},
            {21,5},
            {22,6},
            {23,7},
            {24,8},
            {25,10},
            {26,9},
            {27,8},
            {28,7},
            {29,6},
            {30,5},
            {31,6},
            {32,7},
            {33,8},
            {34,9},
            {35,10},
            {36,12},
            {37,11},
            {37,11},
            {38,10},
            {39,9},
            {40,8},
            {41,7},
            {42,6},
            {43,7},
            {44,8},
            {45,9},
            {46,10},
            {47,11},
            {48,12},
            {49,14},
            {50,13},
            {51,12},
            {52,11},
            {53,10},
            {54,9},
            {55,8},
            {56,7},
            {57,8},
            {58,9},
            {59,10},
            {60,11},
            {61,12},
            {62,13},
            {63,14},
            {64,16},
            {65,15},
            {66,14},
            {67,13},
            {68,12},
            {69,11},
            {70,10},
            {71,9},
            {72,8},
            {73,9},
            {74,10},
            {75,11},
            {76,12},
            {77,13},
            {78,14},
            {79,15},
            {80,16},
        };
};

// classe materiaux pour l'inventaire et les rituels (map <size_t(niveau), materiaux>)
// faire des opérateurs pour les materiaux (-=, ==, >=)
//l'inventaire sera une classe materiaux
//faire look je recois une map <size_t ntile, sting content>
// savoir quel materiaux m'interesse le plus


//boucler sur ça
//je calcule le poids de chaque materiaux
    //boucle sur cette merde
    // je look
    // je calcule le poid des cases (poid de tous les materiaux - distance)
    // je prend la case avec le plus de poid
    // je calcule le chemin le plus court pour y aller
    // je me deplace
    // je break dès que je me retrouve sur la bonne case.
// je prend le materiaux
// je regarde si j'ai assez de materiaux pour un rituel
// si oui je fais le rituel
// si non je recommence


// faire une liste de priorité pour les materiaux avec des poids (metreriaux les plus importants et plus lourd)
//recalculer le poids de la liste de priorité a chaque fois que je recois un look
//calculer le chemin le plus court pour aller chercher le materiaux le plus important

#endif /* !IA_HPP_ */
