#!/bin/bash

echo "Run task: $1" 
g++ -std=c++17 -Wall -O2 src/$1.cc
if [[ $? -ne 0 ]]; then
    exit 1
fi

if test -f tests/$1.txt; then
    ./a.out < tests/$1.txt
else
    ./a.out
fi