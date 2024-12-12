#ifndef NETWORKING_SERVER_HPP
#define NETWORKING_SERVER_HPP

#include <enet/enet.h>
#include <string>
#include <iostream>

// Declare the server_interface structure
struct server_interface {
    ENetAddress addressing;
    ENetHost* server;
    ENetEvent event;
};

//Networking_Server.cpp files
server_interface initialize_server(const std::string& ip_address, enet_uint16 port, int number_of_connections);

//packet_dispatcher.cpp
void packet_dispatcher(server_interface* server_interface);

#endif // NETWORKING_SERVER_HPP
