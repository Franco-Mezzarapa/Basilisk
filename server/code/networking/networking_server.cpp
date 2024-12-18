#include "networking_server.hpp"

server_interface initialize_server(const std::string& ip_address, enet_uint16 port, int number_of_connections) {
    std::cout << "Initializing Server..." << std::endl;
    atexit(enet_deinitialize);

    // Initialize ENet
    if (enet_initialize() != 0) {
        std::cerr << "ENet failed to initialize." << std::endl;
        exit(EXIT_FAILURE); // Exit the program on failure
    } else {
        std::cout << "ENet initialized successfully." << std::endl;
    }

    server_interface networking_information;

    // Set port
    networking_information.addressing.port = port;

    // Convert the IP address into a format ENet can use
    if (enet_address_set_host(&networking_information.addressing, ip_address.c_str()) != 0) {
        std::cerr << "Failed to set IP address: " << ip_address << std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::cout << "--------Configuration File Setup----------" << std::endl;
    std::cout << "IP Address: " << networking_information.addressing.host << std::endl;
    std::cout << "Port: " << networking_information.addressing.port << std::endl;
    std::cout << "Max Users: " << number_of_connections << std::endl;
    std::cout << "------------------------------------------" << std::endl;


    // Create the server
    networking_information.server = enet_host_create(
        &networking_information.addressing,  // Addressing information
        number_of_connections,               // Number of concurrent connections
        2,                                   // Number of channels
        0,                                   // Incoming bandwidth (0 = unlimited)
        0                                    // Outgoing bandwidth (0 = unlimited)
    );

    if (networking_information.server == nullptr) {
        std::cerr << "Failed to create ENet server." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Server created successfully on " << ip_address << ":" << port << std::endl;

    return networking_information;
}
