#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/exception/exception.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include "file_io/process_cfg.hpp"

mongocxx::database connect_to_database(process_cfg *server_configuration);
void get_account(mongocxx::database db, const std::string& account_name);

#endif