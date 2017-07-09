# Krembot

? Please enter your email address: krembot1@gmail.com
? Please enter your password: 123123rR

## Installation

These instructions are compatible with an Ubuntu 14.04.

### particle-cli
```
curl -sL https://deb.nodesource.com/setup_6.x | sudo -E bash -
sudo apt-get install -y nodejs
sudo apt-get install npm
sudo npm install -g particle-cli
particle login
```

### particle-dev
https://github.com/spark/particle-dev

### Clone repository
```
cd ~
git clone https://github.com/robotican/krembot.git
```

Launch Atom and login with your account, see: https://docs.particle.io/guide/tools-and-features/dev/#logging-in

Open the ~/krembot project folder:

File -> Add Project Folder -> ~/krembot


## Compiling ang flashing code for Krembot
Use the particle-dev to select required Krembot and compile and flash using the cloud.

See:

https://docs.particle.io/guide/tools-and-features/dev/#compiling-code

https://docs.particle.io/guide/tools-and-features/dev/#flashing-device

## Flashing multiple Krembots
Compile your code in particle-dev (without flashing). This step will create a compiled bin file.
```
cd ~/krembot/flash
./flash_multi.sh <group file path> <bin file path>
```
for example:
```
./flash_multi.sh group1.txt ../krembot/photon_0.6.2_firmware_1499256083785.bin
```

