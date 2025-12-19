//
//

#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"

#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

// T: RubiksCube representation (3D, 1D, Bitboard)
// H: Hash function for unordered_map (if needed)

template<typename T, typename H>
class DFSSolver {
private:
    vector<RubiksCube::MOVE> solutionMoves;
    int depthLimit;

    // Recursive helper function for DFS
    bool searchDFS(int currentDepth) {
        if (cubeInstance.isSolved()) return true;
        if (currentDepth > depthLimit) return false;

        for (int m = 0; m < 18; ++m) {
            auto move = RubiksCube::MOVE(m);
            cubeInstance.move(move);
            solutionMoves.push_back(move);

            if (searchDFS(currentDepth + 1)) return true;

            solutionMoves.pop_back();
            cubeInstance.invert(move);
        }
        return false;
    }

public:
    T cubeInstance;

    DFSSolver(T initialCube, int maxDepth = 8)
        : cubeInstance(std::move(initialCube)), depthLimit(maxDepth) {}

    vector<RubiksCube::MOVE> solve() {
        searchDFS(1);
        return solutionMoves;
    }
};

#endif //RUBIKS_CUBE_SOLVER_DFSSOLVER_H
