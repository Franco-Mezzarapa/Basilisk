#ifndef NETWORKING_CLIENT_HPP
#define NETWORKING_CLIENT_HPP

#include <enet/enet.h>
#include <string>
#include <iostream>

struct client_interface{
    ENetAddress address;
    ENetHost*    client;
    ENetPeer*   server;
    ENetEvent   event;
};

/** Creates a host for communicating to peers.  
    @param ip_address   the address at which other peers may connect to this host.  If NULL, then no peers may connect to the host.
    @param port the maximum number of peers that should be allocated for the host.
    @returns On success returns a object of structure client_interface which contains, host, addressing.
    @remarks This will also establish the connection so that all that needs to be done is send packets.
*/
client_interface initalize_client(const std::string& ip_address, enet_uint16 port);

#endif // NETWORKING_CLIENT_HPP
