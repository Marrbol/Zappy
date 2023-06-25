/*
** EPITECH PROJECT, 2023
** bootstrap plazza
** File description:
** Process
*/

#ifndef PROCESS_HPP_
#define PROCESS_HPP_

#include "IProcess.hpp"
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <iostream>

class Process : public IProcess{
    public:
        Process();
        ~Process();
        int forkProcess();
        void exitProcess(int status);
        void waitProcess();
};

#endif /* !PROCESS_HPP_ */
