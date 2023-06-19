#!/bin/sh

set -o errexit

# rm -rf .bulid
mkdir .bulid -p
cd .bulid

#Genrate bulid folder
cmake ../.
#make, execute compile command
make

mv ./main ..
cd ..
#run
./main

set +o errexit
