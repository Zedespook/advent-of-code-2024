# 🎄 Advent of Code 2024

Welcome to my Advent of Code 2024 solutions repository! This is my first year participating in Advent of Code, and I'm excited to share my journey through the challenges.

## What is Advent of Code?

[Advent of Code](https://adventofcode.com/2024) is an annual set of Christmas-themed programming puzzles that cover a variety of skill sets and skill levels. It consists of 25 days of coding challenges, with each day offering two related puzzles.

## Repository Structure

Each day's solutions are organized in their own directory:

```
advent-of-code-2024/
├── day-1/
│   ├── part1.cpp
│   ├── part2.cpp
│   └── input.txt
├── day02/
└── ...
```

## Solutions

| Day | Problem | Solution | Stars |
|-----|----------|----------|--------|
| 01 | [Historian Hysteria](https://adventofcode.com/2024/day/1) | [Solution](day01/) | ⭐⭐ |
| 02 | [Red-Nosed Reports](https://adventofcode.com/2024/day/2) | [Solution](day02/) | ⭐⭐ |
| 03 | [Mull It Over](https://adventofcode.com/2024/day/3) | [Solution](day03/) | ⭐⭐ |

## Running the Solutions

Solutions are written in C++17. There are two ways to run the solutions:

### Using the run script (recommended)

Each day's directory contains a `run.sh` script that will compile and run both parts:

```bash
# Navigate to the day's directory
cd dayXX

# Make the script executable (first time only)
chmod +x run.sh

# Run both solutions
./run.sh
```

### Manual compilation

If you prefer to compile and run solutions manually:

```bash
# Navigate to the day's directory
cd dayXX

# Compile (requires C++17)
g++ -std=c++17 partY.cpp -o solution

# Run with input
./solution < input.txt
```

## Personal Goals

- Learn and improve my problem-solving skills
- Experiment with efficient algorithms and data structures
- Complete all 25 days of challenges
- Document my thought process and learnings

## Learnings and Notes

### Day 1
- Learned about sorting-based approach for minimum distance pairing
- Used hash maps for efficient counting in Part 2
- Handled integer overflow cases using long long

### Day 2
- Implemented solution for analyzing nuclear reactor safety reports
- Used vector operations for efficient sequence checking
- Added support for Problem Dampener feature in Part 2

### Day 3
- Implemented pattern matching for parsing corrupted memory data
- Used state management for conditional instruction processing
- Optimized string parsing with early validation checks
- Handled edge cases in multiplication instruction parsing

## Acknowledgments

- Thanks to [Eric Wastl](http://was.tl/), the creator of Advent of Code
- The amazing AoC community for their support and discussions

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

⚠️ **Note**: If you're working on Advent of Code yourself, I encourage you to solve the problems on your own before looking at any solutions. The journey of problem-solving is the most valuable part of the experience!