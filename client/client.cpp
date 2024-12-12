#include "client.hpp"
#include <string.h>
int main(){

    std::cout << "Connecting to server..." << std::endl;
    client_interface client_communication = initalize_client("192.168.1.3",7555);

    


    // Clean up resources (unreachable in this example due to infinite loop)
    enet_host_destroy(client_communication.client);
    return EXIT_SUCCESS;
}
