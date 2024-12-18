sudo apt-get install gnupg curl

curl -fsSL https://www.mongodb.org/static/pgp/server-8.0.asc | \
   sudo gpg -o /usr/share/keyrings/mongodb-server-8.0.gpg \
   --dearmor

sudo touch /etc/apt/sources.list.d/mongodb-org-8.0.list
sudo echo "deb [ arch=amd64,arm64 signed-by=/usr/share/keyrings/mongodb-server-8.0.gpg ] https://repo.mongodb.org/apt/ubuntu noble/mongodb-org/8.0 multiverse" | sudo tee /etc/apt/sources.list.d/mongodb-org-8.0.list

sudo apt-get update
sudo apt-get install -y mongodb-org

sudo systemctl daemon-reload
sudo systemctl start mongod

curl -OL https://github.com/mongodb/mongo-cxx-driver/releases/download/r3.10.1/mongo-cxx-driver-r3.10.1.tar.gz
tar -xzf mongo-cxx-driver-r3.10.1.tar.gz
cd mongo-cxx-driver-r3.10.1/build


sudo apt install build-essential libboost-system-dev libboost-thread-dev libboost-program-options-dev libboost-test-dev
sudo apt install libboost-filesystem-dev

cmake ..                                \
    -DCMAKE_BUILD_TYPE=Release          \
    -DMONGOCXX_OVERRIDE_DEFAULT_INSTALL_PREFIX=OFF

cmake ..                                            \
    -DCMAKE_BUILD_TYPE=Release                      \
    -DBSONCXX_POLY_USE_BOOST=1                      \
    -DMONGOCXX_OVERRIDE_DEFAULT_INSTALL_PREFIX=OFF

cmake --build .
sudo cmake --build . --target install




