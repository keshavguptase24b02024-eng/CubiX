//
//

#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"
#include "DFSSolver.h"

#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H

template<typename T, typename H>
class IDDFSSolver {

private:
    int max_search_depth;
    vector<RubiksCube::MOVE> moves;

public:
    T rubiksCube;

    IDDFSSolver(T _rubiksCube, int _max_search_depth = 7) {
        rubiksCube = _rubiksCube;
        max_search_depth = _max_search_depth;
    }

    // Uses DFSSolver with increasing depth limit
    vector<RubiksCube::MOVE> solve() {
        for (int depth = 1; depth <= max_search_depth; ++depth) {
            DFSSolver<T, H> dfsSolver(rubiksCube, depth);
            moves = dfsSolver.solve();

            if (dfsSolver.rubiksCube.isSolved()) {
                rubiksCube = dfsSolver.rubiksCube;
                break;
            }
        }
        return moves;
    }
};

#endif //RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
