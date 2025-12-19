//
//

#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_BFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_BFSSOLVER_H

// T -> Rubik's Cube representation (3D, 1D, Bitboard)
// H -> Corresponding hash function for unordered_map

template<typename T, typename H>
class BFSSolver {
private:
    vector<RubiksCube::MOVE> solutionMoves;
    unordered_map<T, bool, H> visitedStates;
    unordered_map<T, RubiksCube::MOVE, H> backtrackMove;

// BFS search implementation
    T performBFS() {
        queue<T> bfsQueue;
        bfsQueue.push(cubeInstance);
        visitedStates[cubeInstance] = true;

        while (!bfsQueue.empty()) {
            T current = bfsQueue.front();
            bfsQueue.pop();

            if (current.isSolved()) {
                return current;
            }

            for (int m = 0; m < 18; ++m) {
                auto move = RubiksCube::MOVE(m);
                current.move(move);

                if (!visitedStates[current]) {
                    visitedStates[current] = true;
                    backtrackMove[current] = move;
                    bfsQueue.push(current);
                }

                current.invert(move);
            }
        }

        return cubeInstance;
    }

public:
    T cubeInstance;

    explicit BFSSolver(T initialCube) : cubeInstance(std::move(initialCube)) {}

    // Returns sequence of moves to solve the cube
    vector<RubiksCube::MOVE> solve() {
        T solvedCube = performBFS();
        assert(solvedCube.isSolved());

        T traceCube = solvedCube;
        while (!(traceCube == cubeInstance)) {
            RubiksCube::MOVE lastMove = backtrackMove[traceCube];
            solutionMoves.push_back(lastMove);
            traceCube.invert(lastMove);
        }

        cubeInstance = solvedCube;
        std::reverse(solutionMoves.begin(), solutionMoves.end());
        return solutionMoves;
    }
};

#endif //RUBIKS_CUBE_SOLVER_BFSSOLVER_H
