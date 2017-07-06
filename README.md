# Krembot

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
1. Compile your code in particle-dev (without flashing). This step will create a compiled bin file.
2. cd flash
3. ./flash_multi.sh <group file path> <bin file path>
e.g.
./flash_multi.sh group1.txt ../krembot/photon_0.6.2_firmware_1499256083785.bin

