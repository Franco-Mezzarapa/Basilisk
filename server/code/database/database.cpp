#include "database.hpp"

mongocxx::database connect_to_database(process_cfg *server_configuration){
 try {
        std::string string_uri = "mongodb://" + server_configuration->db_ip_address + ":" + server_configuration->db_port + "/";
        mongocxx::uri uri(string_uri);
        mongocxx::client client(uri);
        
        // Perform a simple operation to verify the connection
        std::cout << "Connection to MongoDB was successful." << std::endl;
        auto db = client["server_database"];
        return db;
    } catch (const mongocxx::exception& e) {
        // Handle connection errors
        std::cerr << "Failed to connect to MongoDB: " << e.what() << std::endl;
    }


}

// Reads and prints a single account by account_name
void get_account(mongocxx::database db, const std::string& account_name) {
    auto accounts = db["accounts"];
    bsoncxx::document::view filter;
    filter.find("account_names");
    auto doc = accounts.find_one(filter);
    if (doc) {
        std::cout << "Account found:\n" << bsoncxx::to_json(*doc) << "\n";
    } else {
        std::cout << "No account found with name: " << account_name << "\n";
    }
}