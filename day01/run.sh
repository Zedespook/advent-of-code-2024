#!/bin/bash

echo "Part 1"
g++ -std=c++17 part1.cpp -o part1
./part1 < input.txt

echo "Part 2"
g++ -std=c++17 part2.cpp -o part2
./part2 < input.txt
