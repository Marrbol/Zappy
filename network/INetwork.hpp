/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-guillaume.papineau
** File description:
** INetwork
*/

#ifndef INETWORK_HPP_
#define INETWORK_HPP_

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>

class INetwork {
    public:
        INetwork() = default;
        ~INetwork() = default;
        virtual void sendMessage(int fd, std::string message) = 0;
        virtual std::string receiveMessage(int fd) = 0;
        virtual int connectSocketClient(std::string IP, int PORT) = 0;
        virtual int selectSocket(int fd, fd_set *readfds) = 0;
        virtual bool fdReady(int fd, fd_set *readfds) = 0;
};

#endif /* !INETWORK_HPP_ */