/*
** EPITECH PROJECT, 2023
** bootstrap plazza
** File description:
** Process
*/

#include "Process.hpp"

Process::Process()
{
}

Process::~Process()
{
}

int Process::forkProcess()
{
    int pid = fork();

    if (pid == -1)
        throw std::runtime_error("Fork failed");
    return pid;
}

void Process::exitProcess(int status)
{
    exit(status);
}

void Process::waitProcess()
{
    wait(NULL);
}
