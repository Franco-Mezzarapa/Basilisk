#ifndef PROCESS_CFG_H
#define PROCESS_CFG_H

#include <iostream>
#include  <fstream>

struct process_cfg
{
    std::string ip_address;
    int port;
    int max_users;
};

process_cfg* parse_configuration_file();

#endif