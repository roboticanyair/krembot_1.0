#Krembot

## Installation

### particle-cli
curl -sL https://deb.nodesource.com/setup_6.x | sudo -E bash -
sudo apt-get install -y nodejs
sudo apt-get install npm
sudo npm install -g particle-cli

particle login
? Please enter your email address: robotican.photon@gmail.com
? Please enter your password: 123123rR

### particle-dev
https://github.com/spark/particle-dev

## Compiling code for Krembot

## Flashing a single Krembot

## Flashing multiple Krembots
1. gcd flash
2. ./flash_multi.sh <group file> <bin file>
e.g.
./flash_multi.sh group1.txt photon_0.6.2_firmware_1499256083785.bin
