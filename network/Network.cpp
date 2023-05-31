/*
** EPITECH PROJECT, 2023
** B-OOP-400-REN-4-1-raytracer-guillaume.papineau
** File description:
** Network
*/

#include "Network.hpp"

Network::Network()
{
}

Network::~Network()
{
}

void Network::sendMessage(int fd, std::string message)
{
    send(fd, message.c_str(), message.size(), 0);
}

std::string Network::receiveMessage(int fd)
{
    char buffer[1024] = {0};
    read(fd, buffer, 1024);
    std::string message = buffer;

    return message;
}

int Network::connectSocketClient(std::string ip, int port)
{
    int socket_descriptor;
    struct sockaddr_in server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip.c_str());
    server_address.sin_port = htons(port);
    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(socket_descriptor, (struct sockaddr *)&server_address,
    sizeof(server_address)) < 0) {
        return -1;
    }
    return socket_descriptor;
}

int Network::selectSocket(int fd, fd_set *readfds)
{
    int max_sd;
    int sd;
    int retval;
    FD_ZERO(readfds);
    FD_SET(fd, readfds);
    FD_SET(STDIN_FILENO, readfds);
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    max_sd = fd;
    sd = fd;
    if (sd > 0)
        FD_SET(sd , readfds);
    if (sd > max_sd)
        max_sd = sd;
    retval = select(max_sd + 1, readfds, NULL, NULL, &tv);
    return retval;
}

bool Network::fdReady(int fd, fd_set *readfds)
{
    if (FD_ISSET(fd, readfds))
        return true;
    return false;
}