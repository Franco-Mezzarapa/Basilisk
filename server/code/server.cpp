#include "server.hpp"
#include <openssl/evp.h>

int main(){

    std::cout << "Loading Server.." << std::endl;

    //parse the CFG file for configuration information.
    process_cfg* server_configuration = parse_configuration_file();
    server_interface server = initialize_server(server_configuration -> ip_address, 
                                                server_configuration -> port, 
                                                server_configuration -> max_users);
    //connect to database.
    mongocxx::database db = connect_to_database(server_configuration); //I might need to return the mongoDB client
    get_account(db,"Account1");
    
    delete(server_configuration);
    server_configuration = NULL;

    
    //receive event
    //ACTION - INFORMATION - -> STRING.


    // Clean up the server
    enet_host_destroy(server.server);
    return EXIT_SUCCESS;
}