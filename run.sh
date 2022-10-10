#!/bin/bash

path=$1
echo "Compile task: $path" 
g++ -std=c++17 -Wall -O2 $path
if [[ $? -ne 0 ]]; then
    exit 1
fi

fn=${path##*/}
test_file=${fn%.cc}.txt

if test -f tests/$test_file; then
    echo "Run task: $test_file"
    ./a.out < tests/$test_file
else
    ./a.out
fi