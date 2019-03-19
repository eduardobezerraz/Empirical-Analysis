#!/bin/sh

if g++ -Wall -std=c++14 src/main.cpp src/search.cpp -o bin/run
then
./bin/run 5000
fi
