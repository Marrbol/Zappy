/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-guillaume.papineau
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include "INetwork.hpp"

class Network : public INetwork {
    public:
        Network();
        ~Network();
        void sendMessage(int fd, std::string message);
        std::string receiveMessage(int fd);
        int connectSocketClient(std::string ip, int port);
        int connectSocketServer(int port);
        int selectSocket(int fd, fd_set *readfds);
        int acceptSocket(int fd, struct sockaddr_in address);
        int selectClient(int client_socket, fd_set *readfds, int socket_descriptor);
        bool fdReady(int fd, fd_set *readfds);

    protected:
    private:
};

#endif /* !NETWORK_HPP_ */