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

| Day | Problem                                                        | Solution           | Stars |
| --- | -------------------------------------------------------------- | ------------------ | ----- |
| 01  | [Historian Hysteria](https://adventofcode.com/2024/day/1)      | [Solution](day01/) | ⭐⭐  |
| 02  | [Red-Nosed Reports](https://adventofcode.com/2024/day/2)       | [Solution](day02/) | ⭐⭐  |
| 03  | [Mull It Over](https://adventofcode.com/2024/day/3)            | [Solution](day03/) | ⭐⭐  |
| 04  | [Ceres Search](https://adventofcode.com/2024/day/4)            | [Solution](day04/) | ⭐⭐  |
| 05  | [Print Queue](https://adventofcode.com/2024/day/5)             | [Solution](day05/) | ⭐⭐  |
| 06  | [Guard Gallivant](https://adventofcode.com/2024/day/6)         | [Solution](day06/) | ⭐⭐  |
| 07  | [Bridge Repair](https://adventofcode.com/2024/day/7)           | [Solution](day07/) | ⭐⭐  |
| 08  | [Resonant Collinearity](https://adventofcode.com/2024/day/8)   | [Solution](day08/) | ⭐⭐  |
| 09  | [Disk Defragmentation](https://adventofcode.com/2024/day/9)    | [Solution](day09/) | ⭐⭐  |
| 10  | [Hoof It](https://adventofcode.com/2024/day/10)                | [Solution](day10/) | ⭐⭐  |
| 11  | [Plutonian Pebbles](https://adventofcode.com/2024/day/11)      | [Solution](day11/) | ⭐⭐  |
| 12  | [Garden Groups](https://adventofcode.com/2024/day/12)          | [Solution](day12/) | ⭐⭐  |
| 13  | [Claw Contraption](https://adventofcode.com/2024/day/13)       | [Solution](day13/) | ⭐⭐  |
| 14  | [Restroom Redoubt](https://adventofcode.com/2024/day/14)       | [Solution](day14/) | ⭐⭐  |
| 15  | [Warehouse Woes](https://adventofcode.com/2024/day/15)         | [Solution](day15/) | ⭐⭐  |
| 16  | [Reindeer Maze](https://adventofcode.com/2024/day/16)          | [Solution](day16/) | ⭐⭐  |
| 17  | [Chronospatial Computer](https://adventofcode.com/2024/day/17) | [Solution](day17/) | ⭐⭐  |
| 18  | [RAM Run](https://adventofcode.com/2024/day/18)                | [Solution](day18/) | ⭐⭐  |
| 19  | [Linen Layout](https://adventofcode.com/2024/day/19)           | [Solution](day19/) | ⭐⭐  |
| 20  | [Race Condition](https://adventofcode.com/2024/day/20)         | [Solution](day20/) | ⭐⭐  |
| 21  | [Step Counter](https://adventofcode.com/2024/day/21)           | [Solution](day21/) | ⭐⭐  |
| 22  | [Monkey Market](https://adventofcode.com/2024/day/22)          | [Solution](day22/) | ⭐⭐  |
| 23  | [LAN Party](https://adventofcode.com/2024/day/23)              | [Solution](day23/) | ⭐⭐  |
| 24  | [Circuit Circus](https://adventofcode.com/2024/day/24)         | [Solution](day24/) | ⭐⭐  |
| 25  | [Code Chronicle](https://adventofcode.com/2024/day/25)         | [Solution](day25/) | ⭐⭐  |

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

### Day 12

- Implemented flood fill algorithm for finding connected garden plot regions
- Used efficient boundary counting with state tracking
- Optimized memory usage with set-based data structures
- Handled both perimeter counting (Part 1) and distinct sides counting (Part 2)
- Improved performance by avoiding redundant boundary checks

### Day 13

- Implemented linear equation solver for button combination puzzle
- Used Cramer's rule for solving 2x2 linear systems efficiently
- Added high-precision floating point calculations for Part 2
- Handled edge cases with parallel lines and non-integer solutions
- Optimized solution by avoiding unnecessary matrix operations

### Day 14

- Implemented robot movement simulation with modular arithmetic for position wrapping
- Used floating-point arithmetic for precise position tracking
- Part 1 focused on quadrant-based robot counting after fixed time
- Part 2 required finding first time when horizontal adjacencies exceed threshold
- Optimized position lookup using set data structure
- Handled negative coordinates with proper modulo arithmetic

### Day 15

- Implemented grid-based box pushing simulation with robot movement
- Used lambda functions for direction handling to reduce code duplication
- Part 1 focused on single box movement with simple collision detection
- Part 2 added complexity with chained box movements and expanded grid
- Optimized box chain detection using set data structure
- Handled edge cases with wall collisions and multi-box interactions
- Implemented efficient grid state management for box movements
- Special thanks to [zebalu](https://github.com/zebalu) for their [amazing Java solution that I used as a reference](https://github.com/zebalu/advent-of-code-2024/blob/master/solution/src/main/java/io/github/zebalu/aoc2024/Day15.java)!

### Day 16

- Implemented Dijkstra's algorithm for finding optimal paths through reindeer maze
- Used state-based approach to track both position and direction in maze navigation
- Part 1 focused on finding shortest path with rotation costs
- Part 2 added complexity with path reconstruction and optimal tile counting
- Optimized memory usage with map-based distance tracking
- Handled rotation costs efficiently with modular arithmetic
- Implemented backtracking for finding all optimal paths in Part 2
- Used set data structure for tracking unique visited tiles

### Day 17

- Implemented virtual machine for chronospatial computer simulation
- Used switch-case for efficient opcode handling with bit manipulation operations
- Part 1 focused on executing programs with register-based computation
- Part 2 added complexity with reverse engineering program outputs
- Optimized memory usage with vector-based instruction storage
- Handled various instruction types including arithmetic and control flow
- Special thanks to [TrueNorthIT](https://github.com/TrueNorthIT) for their insightful approach to handling register operations!

### Day 18

- Implemented BFS-based pathfinding in a dynamic grid environment
- Used vector of vectors for efficient grid representation and updates
- Part 1 focused on finding shortest path avoiding first 1024 corrupted cells
- Part 2 required finding critical point that blocks all possible paths
- Optimized memory usage with boolean grid for corruption tracking
- Handled coordinate system with proper bounds checking
- Used structured bindings for cleaner queue element access
- Resolved signed/unsigned comparison warnings using size_t
- Implemented efficient path existence checking for part 2
- Used min<size_t> for safe comparison between different integer types
- Used freopen for input file reading as an alternative to ios::sync_with_stdio approach

### Day 19

- Implemented recursive pattern matching for linen design validation
- Used dynamic programming with memoization to optimize repeated subproblems
- Part 1 focused on determining if designs could be made from given patterns
- Part 2 extended to counting all possible pattern combinations
- Optimized string operations with substr for pattern matching
- Handled large numbers using long long for combination counting
- Used unordered_map for efficient memoization of subproblems
- Implemented efficient input parsing with stringstream

### Day 20

- Implemented path optimization algorithm for race track navigation
- Used BFS for initial path finding with position tracking
- Part 1 focused on finding optimal skips in straight-line segments
- Part 2 extended to include diagonal movements and longer skip distances
- Optimized skip calculation with efficient distance metrics
- Used map for tracking frequency of different skip lengths
- Implemented position struct for clean coordinate handling
- Special thanks to [piman51277](https://github.com/piman51277) for their elegant approach to handling path optimizations!

### Day 21

- Attempted to implement complex path optimization for robot movement patterns
- Challenge involved calculating optimal button press sequences
- Required understanding of multi-dimensional path finding and state management
- Found the mathematical complexity and optimization requirements beyond current skill level
- Learned valuable lessons about problem difficulty assessment and knowing when to step back
- Plan to revisit this challenge after building stronger foundations in advanced algorithms

### Day 22

- Implemented pseudorandom number generation for simulating buyer behavior
- Used nested loops to explore all possible price change sequences
- Part 1 focused on calculating the sum of the 2000th secret number for each buyer
- Part 2 required finding the optimal sequence of four price changes to maximize banana yield
- Optimized solution by precomputing prices and changes for each buyer
- Added progress indicator with estimated time remaining for long-running calculations
- Used modulo arithmetic and bitwise XOR for efficient mixing and pruning operations

### Day 23

- Implemented graph analysis algorithms for network connectivity
- Part 1 focused on finding triangles (3-cliques) containing specific nodes
- Part 2 required finding the maximum clique in the network
- Used adjacency lists with unordered_sets for efficient connection lookups
- Optimized clique finding with incremental group expansion
- Implemented efficient connectivity validation using count operations
- Used sorting for consistent group comparison and password generation
- Handled large datasets with proper iteration and group management

### Day 24

- Implemented circuit simulation with logical gate operations
- Used maps to store wire values and gate definitions
- Part 1 focused on simulating the circuit and converting the output to decimal
- Part 2 required identifying four pairs of swapped gate outputs
- Analyzed circuit structure to identify binary adder components
- Used pattern matching to find XOR-AND gate pairs and carry chains
- Handled wire dependencies and operation tracking efficiently
- Implemented sorting for consistent wire name output

### Day 25

- Implemented virtual lock and key matching system for office security
- Used grid-based height calculation for lock pins and key shapes
- Optimized matching algorithm by measuring heights from appropriate directions
- Handled overlapping detection with efficient boundary checking
- Added support for processing multiple lock/key schematics in batch

## Acknowledgments

- Thanks to [Eric Wastl](http://was.tl/), the creator of Advent of Code
- The amazing AoC community for their support and discussions

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

⚠️ **Note**: If you're working on Advent of Code yourself, I encourage you to solve the problems on your own before looking at any solutions. The journey of problem-solving is the most valuable part of the experience!
