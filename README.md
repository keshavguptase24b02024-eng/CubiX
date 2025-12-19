# Rubiks-cube-solver
Rubik's Cube Solver in C++

A Rubik's Cube solver implemented in C++ that supports multiple cube representations and solving algorithms. It demonstrates search strategies and pattern database heuristics for solving a 3x3x3 cube efficiently.

---

## Features

### Cube Representations
- 3D array
  - 1D array
  - Bitboard

### Solving Algorithms
- Breadth-First Search (BFS)
  - Depth-First Search (DFS)
  - Iterative Deepening DFS (IDDFS)
  - IDA* search using pattern database heuristics

### Pattern Databases
- Corner pattern database
  - Memory-efficient storage using nibble arrays

---

## Getting Started

### Requirements
- C++14 or later
  - CMake 3.20 or later
  - Make or Ninja build system

### Build Instructions
```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```
## Running the Solver
````
./rubiks_cube_solver
````
## Algorithms

- Breadth-First Search (BFS)
Explores all moves level by level. Finds the shortest solution but uses a large amount of memory.

  - Depth-First Search (DFS)
  Explores moves deeply along each branch. Uses less memory but may not find the shortest path.

  - Iterative Deepening DFS (IDDFS)
  Performs DFS with increasing depth limits. Finds optimal solutions while using less memory than BFS.

  - IDA with Pattern Databases*
  Combines depth-limited search with heuristics. Uses a corner pattern database to guide the search and reduce the number of states explored.

## Cube Notation

F, B, U, D, L, R – clockwise face turns

F', B', U', D', L', R' – counter-clockwise turns

F2, B2, U2, D2, L2, R2 – 180-degree turns
