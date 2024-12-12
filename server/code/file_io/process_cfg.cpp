#include "process_cfg.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // for exit(EXIT_FAILURE)

process_cfg* parse_configuration_file() {
    
    process_cfg* server_configuration_information = new process_cfg();
    std::fstream server_configuration("configurations/server-configuration.cfg");

    if (!server_configuration.is_open()) {
        std::cerr << "Unable to open server configuration file" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::string line;

    // Extract and parse lines
    std::getline(server_configuration, line);
    server_configuration_information->ip_address = line.substr(line.find('=') + 1); // Part after '='

    std::getline(server_configuration, line);
    server_configuration_information->port = std::stoi(line.substr(line.find('=') + 1)); // Take whats after the = and return it. convert to int

    std::getline(server_configuration, line);
    server_configuration_information->max_users = std::stoi(line.substr(line.find('=') + 1)); // Take whats after the = and return it. convert to int

    server_configuration.close();
    return server_configuration_information;
}
