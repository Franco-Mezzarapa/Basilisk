#include "networking_server.hpp"

void packet_dispatcher(server_interface* server_interface){
    // Wait for an event (e.g., connection, packet, or disconnection)
    while (enet_host_service(server_interface -> server, &server_interface -> event, 1000) > 0) {
        switch (server_interface -> event.type) {
            case ENET_EVENT_TYPE_CONNECT:
            std::cout << "A client connected from "
                      << server_interface -> event.peer->address.host << ":" 
                      << server_interface -> event.peer->address.port << std::endl;
            break;

            case ENET_EVENT_TYPE_RECEIVE:
                // Process the received packet
                std::cout << "Received a packet from client: " << std::endl;
                std::cout << "Packet data: " << (char*)server_interface -> event.packet->data << std::endl;
                std::cout << "Packet length: " << server_interface -> event.packet-> dataLength << std::endl;

                // Clean up the packet
                enet_packet_destroy(server_interface -> event.packet);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                std::cout << "A client disconnected." << std::endl;
                break;

            default:
                break;
        }
    }
}


