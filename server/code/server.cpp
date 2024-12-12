#include "server.hpp"

int main(){

    std::cout << "Loading Server.." << std::endl;

    //parse the CFG file for configuration information.
    process_cfg* server_configuration = parse_configuration_file();
    server_interface server = initialize_server(server_configuration -> ip_address, 
                                                          server_configuration -> port, 
                                                          server_configuration -> max_users);
    // Get rid of the server config structure.
    delete(server_configuration);
    server_configuration = NULL;

    while (true) {
       packet_dispatcher(&server);
    }

    
    //receive event
    //ACTION - INFORMATION - -> STRING.


    // Clean up the server
    enet_host_destroy(server.server);
    return EXIT_SUCCESS;
}