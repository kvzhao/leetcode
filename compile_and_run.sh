#!/bin/bash

echo "Run task: $1" 
g++ -std=c++17 -Wall -O2 src/$1.cc
./a.out < tests/$1.txt