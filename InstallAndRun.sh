#!/bin/bash
#
# This script exists to make my own building and deployment on my pi easier
#
# IT IS NOT DESIGNED TO BE A GENERAL PURPOSE SCRIPT
# RUN AT YOUR OWN RISK
echo "Updating git repository"
git pull origin master
echo "Removing Build Directory"
rm -rf build
echo "Remaking Build Directory"
mkdir build
cd build
echo "Running cmake"
cmake ..
echo "Making"
make
echo "Executing baseball-pi with root (sudo) privileges"
echo "This is necessary to access the Linux sysfs (the GPIO ports on the Pi)"
echo "You will be prompted for your password"
sudo ./baseball_pi