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
#include "../Process/Process.hpp"
#include <csignal>
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
#define OK "ok"
#define KO "ko"


class IA {
    public:
        ~IA();
        void calculeMateriauxPoids();
        void calculeTilesPoids();
        bool moveTheIAToTheBestCase();

        IA(int port, std::string name, std::string machine);
        void communicateWithServer();
        void parseCommande();
        void loopIA();
        void calculateCoordBestCase();
        bool GetAllRessourcesTile();
        void ForkTheProgram();
        void isItForRitual(std::string materiaux);
        void reduceForRitual(std::string materiaux);

        //send command
        void forward();
        void turnLeft();
        void turnRight();
        void look();
        void broadcast(std::string message);
        void inventory();
        void connectNbr();
        void forkIA();
        void eject();
        void take(std::string object);
        void set(std::string object);
        void incantation();
        static void signal_handler(int signal);

        //get command
        void getForward();
        void getTurnLeft();
        void getTurnRight();
        void getLook();
        void getBroadcast();
        void getInventory();
        void changeTheInventory(std::string str, int nb);
        void getConnectNbr();
        void getFork();
        void getEject();
        void getTake();
        void getSet();
        void getIncantation();
        void ReceiveMessage();
        size_t countSubStr(std::string str, std::string subStr);

    private:
        std::string _commande;
        std::string _machine;
        std::string _line;
        std::pair<size_t, size_t> _mapSize;
        size_t _level = 1;
        std::string _teamName;
        size_t _clientName;
        std::list<std::string> _actualCommand;
        bool _isDead = false;
        size_t connectNbrLeft = 0;
        std::list<std::pair<size_t, std::string>> _messageReceived; //first = direction, second = message
        bool _validate = false;
        bool _probleme = false;
        bool _start = false;
        bool _name = false;
        fd_set _readfds = {0};
        Network _network;
        int _socket = 0;
        std::list<std::string> _ask;
        Process _process;
        int _pid;
        int _port;
        std::string _role = "";
        bool forked = false;
        bool _canIncantation = false;

        using CommandFunction = std::function<void(void)>;

        typedef struct allCmdS {
            std::string cmd;
            CommandFunction func;
        } allCmdT;

         std::vector<allCmdT> _cmd = {
            {"Forward", std::bind(&IA::getForward, this)},
            {"Right", std::bind(&IA::getTurnRight, this)},
            {"Left", std::bind(&IA::getTurnLeft, this)},
            {"Look", std::bind(&IA::getLook, this)},
            {"Broadcast", std::bind(&IA::getBroadcast, this)},
            {"Inventory", std::bind(&IA::getInventory, this)},
            {"Connect_nbr", std::bind(&IA::getConnectNbr, this)},
            {"Fork", std::bind(&IA::getFork, this)},
            {"Eject", std::bind(&IA::getEject, this)},
            {"Take", std::bind(&IA::getTake, this)},
            {"Set", std::bind(&IA::getSet, this)},
            {"Incantation", std::bind(&IA::getIncantation, this)},
            {"message", std::bind(&IA::ReceiveMessage, this)},
            {"NULL", NULL},
        };
        std::map<size_t, Materiaux> _rituels = {
            {1, Materiaux(0,1,0,0,0,0,0)},
            {2, Materiaux(0,1,1,1,0,0,0)},
            {3, Materiaux(0,2,0,1,0,2,0)},
            {4, Materiaux(0,1,1,2,0,1,0)},
            {5, Materiaux(0,1,2,1,3,0,0)},
            {6, Materiaux(0,1,2,3,0,1,0)},
            {7, Materiaux(0,2,2,2,2,2,1)}
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
        Materiaux _inventaire = Materiaux(0,0,0,0,0,0,0);
        std::map<size_t, std::string> _materiauxPriority;
        size_t _numTilesPriority = 0;
        std::map<size_t, std::string> _view;
        std::list<std::string> _takeObject;
        Materiaux _poidMateriaux;
        bool isTurned = false;
        std::pair<int, size_t> _coordBestCase;
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
