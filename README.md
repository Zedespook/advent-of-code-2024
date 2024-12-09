# 🎄 Advent of Code 2024

Welcome to my Advent of Code 2024 solutions repository! This is my first year participating in Advent of Code, and I'm excited to share my journey through the challenges.

## What is Advent of Code?

[Advent of Code](https://adventofcode.com/2024) is an annual set of Christmas-themed programming puzzles that cover a variety of skill sets and skill levels. It consists of 25 days of coding challenges, with each day offering two related puzzles.

## Repository Structure

Each day's solutions are organized in their own directory:

```
advent-of-code-2024/
├── aoc.sh  # Unified build script
├── day01/
│   ├── part1.cpp
│   ├── part2.cpp
│   └── input.txt
├── day02/
└── ...
```

## Solutions

| Day | Problem                                                      | Solution           | Stars |
| --- | ------------------------------------------------------------ | ------------------ | ----- |
| 01  | [Historian Hysteria](https://adventofcode.com/2024/day/1)    | [Solution](day01/) | ⭐⭐  |
| 02  | [Red-Nosed Reports](https://adventofcode.com/2024/day/2)     | [Solution](day02/) | ⭐⭐  |
| 03  | [Mull It Over](https://adventofcode.com/2024/day/3)          | [Solution](day03/) | ⭐⭐  |
| 04  | [Ceres Search](https://adventofcode.com/2024/day/4)          | [Solution](day04/) | ⭐⭐  |
| 05  | [Print Queue](https://adventofcode.com/2024/day/5)           | [Solution](day05/) | ⭐⭐  |
| 06  | [Guard Gallivant](https://adventofcode.com/2024/day/6)       | [Solution](day06/) | ⭐⭐  |
| 07  | [Bridge Repair](https://adventofcode.com/2024/day/7)         | [Solution](day07/) | ⭐⭐  |
| 08  | [Resonant Collinearity](https://adventofcode.com/2024/day/8) | [Solution](day08/) | ⭐⭐  |
| 09  | [Disk Defragmentation](https://adventofcode.com/2024/day/9)  | [Solution](day09/) | ⭐⭐  |
| 10  | [Hoof It](https://adventofcode.com/2024/day/10)              | [Solution](day10/) | ⭐⭐  |
| 11  | [Plutonian Pebbles](https://adventofcode.com/2024/day/11)    | [Solution](day11/) | ⭐    |

## Running the Solutions

Solutions are written in C++23 and compiled with Clang 19. The repository includes a unified build system that makes it easy to compile and run solutions.

### Using the Build Script

The `aoc` script in the repository root provides a streamlined way to compile and run solutions:

```bash
# Make the script executable (first time only)
chmod +x aoc

# Run all available solutions
./aoc

# Run both parts of a day
./aoc <day>

# Run a specific part of a day
./aoc <day> <part>

# Examples:
./aoc       # Run all solutions
./aoc 1     # Run both parts of Day 1
./aoc 2 1   # Run only Part 1 of Day 2
```

### Build System Features

- Unified compilation settings across all solutions
- C++23 standard with -O2 optimization
- AddressSanitizer enabled for runtime error detection
- Colored output for better readability
- Automatic input file handling
- Comprehensive error reporting

### Compilation Details

All solutions are compiled with the following flags:

- `-std=c++23`: Latest C++ standard
- `-O2`: Level 2 optimization
- `-fsanitize=address`: AddressSanitizer for memory error detection
- `-Wall -Wextra -Wpedantic`: Comprehensive warning flags

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

### Day 4

- Developed grid search algorithm for word pattern matching
- Implemented efficient X-MAS pattern detection using coordinate transformations
- Optimized intersection point detection for crossed patterns
- Handled both forward and reverse pattern matching

### Day 5

- Implemented topological sort for printer queue ordering
- Used adjacency lists for efficient graph representation
- Added verification for cyclical dependencies
- Optimized middle element finding for ordered sequences

### Day 6

- Developed grid-based path simulation for guard movement patterns
- Implemented direction vectors for efficient movement tracking
- Used state detection for identifying cyclic patrol routes
- Optimized loop detection with position-direction state tracking

### Day 7

- Implemented operator evaluation for bridge repair calibration equations
- Used bit manipulation for efficient operator combination testing in Part 1
- Extended solution with base-3 number system for three operators in Part 2
- Handled string concatenation operations while maintaining left-to-right evaluation
- Optimized number parsing and validation for large test values

### Day 8

- Implemented grid-based antenna frequency analysis for signal interference patterns
- Developed efficient algorithms for calculating antinode positions based on antenna pairs
- Used cross product calculations to determine collinear points in Part 2
- Optimized position tracking with set-based data structures to ensure unique antinode counts
- Handled both distance-based and collinearity-based resonance calculations

### Day 9

- Implemented disk defragmentation algorithms for optimizing file storage
- Used vector-based approach for tracking file positions and gaps
- Part 1 focused on simple left-to-right defragmentation
- Part 2 added complexity with optimal file placement strategies
- Handled file position tracking and checksum calculations efficiently

### Day 10

- Implemented path-finding algorithms for hiking trail analysis
- Used DFS with backtracking for exploring valid height-increasing paths
- Part 1 focused on counting unique reachable endpoints
- Part 2 required tracking complete unique paths using string encoding
- Optimized memory usage with visited array reuse in backtracking
- Handled large path counts with appropriate data types

### Day 11

- Implemented stone evolution simulation with multiple transformation rules
- Used map to track stone counts instead of individual stones for efficiency
- Handled large numbers with \_\_int128_t for final count
- Optimized memory usage by avoiding storage of duplicate stones
- Implemented string-based number splitting for even-digit numbers
- Used structured bindings for cleaner map iteration

## Acknowledgments

- Thanks to [Eric Wastl](http://was.tl/), the creator of Advent of Code
- The amazing AoC community for their support and discussions

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

⚠️ **Note**: If you're working on Advent of Code yourself, I encourage you to solve the problems on your own before looking at any solutions. The journey of problem-solving is the most valuable part of the experience!
