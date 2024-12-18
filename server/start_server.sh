#/bin/bash

# Setting up mongo has to be done more securely than this..
sudo systemctl stop mongod.service
sudo chown -R mongodb:mongodb $PWD/database && sudo chmod -R u+rwX $PWD/database
sudo mongod --dbpath $PWD/database

./server