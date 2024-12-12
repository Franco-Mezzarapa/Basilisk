#include "networking_client.hpp"

client_interface initalize_client(const std::string& ip_address, enet_uint16 port){
    // Initialize ENet
    if (enet_initialize() != 0) {
        std::cerr << "ENet failed to initialize." << std::endl;
        exit(EXIT_FAILURE);
    }
    atexit(enet_deinitialize);

    // Set up the server address
    ENetAddress address;
    address.port = port;    
    enet_address_set_host(&address, ip_address.c_str()); // Server IP

    // Create the client
    ENetHost* client = enet_host_create(nullptr, 1, 2, 0, 0);
    if (!client) {
        std::cerr << "Failed to create ENet client." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    ENetPeer* peer = enet_host_connect(client, &address, 2, 0);
    if (!peer) {
        std::cerr << "Failed to initiate connection to the server." << std::endl;
        enet_host_destroy(client);
        exit(EXIT_FAILURE);
    }

    // Wait for connection
    ENetEvent event;

    client_interface communication_information;
    communication_information.address = address;
    communication_information.client  = client;
    communication_information.server  = peer;
    communication_information.event   = event;
    
    if (enet_host_service(communication_information.client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
        std::cout << "Connected to the server!" << std::endl;
    } else {
        std::cerr << "Failed to connect to the server." << std::endl;
        enet_peer_reset(communication_information.server);
        enet_host_destroy(communication_information.client);
        exit(EXIT_FAILURE);
    }
    return communication_information;
}