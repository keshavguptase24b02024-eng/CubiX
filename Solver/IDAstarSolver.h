//
//

#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"
//#include "../Model/PatternDatabase/PatternDatabase.h"
#include "../PatternDatabases/CornerPatternDatabase.h"

#ifndef RUBIKS_CUBE_SOLVER_IDASTARSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDASTARSOLVER_H

template<typename T, typename H>
class IDAstarSolver {
private:
    CornerPatternDatabase cornerDB;
    vector<RubiksCube::MOVE> solutionMoves;
    unordered_map<T, RubiksCube::MOVE, H> moveMap;
    unordered_map<T, bool, H> visitedStates;

    struct Node {
        T cubeState;
        int depth;
        int heuristic;

        Node(T cube, int d, int h) : cubeState(cube), depth(d), heuristic(h) {}
    };

    struct CompareNodes {
        bool operator()(const pair<Node, int> &a, const pair<Node, int> &b) const {
            int f1 = a.first.depth + a.first.heuristic;
            int f2 = b.first.depth + b.first.heuristic;
            if (f1 == f2) return a.first.heuristic > b.first.heuristic;
            return f1 > f2;
        }
    };

    void clearState() {
        solutionMoves.clear();
        moveMap.clear();
        visitedStates.clear();
    }

    // returns {cube, bound}: solved or next bound
    pair<T, int> searchIDAstar(int bound) {
        priority_queue<pair<Node, int>, vector<pair<Node, int>>, CompareNodes> pq;
        Node startNode(rubiksCube, 0, cornerDB.getNumMoves(rubiksCube));
        pq.push({startNode, 0});
        int nextBound = 100;

        while (!pq.empty()) {
            auto topPair = pq.top(); pq.pop();
            Node currentNode = topPair.first;

            if (visitedStates[currentNode.cubeState]) continue;
            visitedStates[currentNode.cubeState] = true;
            moveMap[currentNode.cubeState] = RubiksCube::MOVE(topPair.second);

            if (currentNode.cubeState.isSolved()) return {currentNode.cubeState, bound};

            currentNode.depth++;
            for (int m = 0; m < 18; ++m) {
                auto move = RubiksCube::MOVE(m);
                currentNode.cubeState.move(move);

                if (!visitedStates[currentNode.cubeState]) {
                    currentNode.heuristic = cornerDB.getNumMoves(currentNode.cubeState);
                    int f = currentNode.depth + currentNode.heuristic;
                    if (f > bound) {
                        nextBound = min(nextBound, f);
                    } else {
                        pq.push({currentNode, m});
                    }
                }

                currentNode.cubeState.invert(move);
            }
        }

        return {rubiksCube, nextBound};
    }

public:
    T rubiksCube;

    IDAstarSolver(T initialCube, const string &dbFile) : rubiksCube(std::move(initialCube)) {
        cornerDB.fromFile(dbFile);
    }

    vector<RubiksCube::MOVE> solve() {
        int bound = 1;
        auto result = searchIDAstar(bound);

        while (result.second != bound) {
            clearState();
            bound = result.second;
            result = searchIDAstar(bound);
        }

        T solvedCube = result.first;
        assert(solvedCube.isSolved());

        T traceCube = solvedCube;
        while (!(traceCube == rubiksCube)) {
            RubiksCube::MOVE lastMove = moveMap[traceCube];
            solutionMoves.push_back(lastMove);
            traceCube.invert(lastMove);
        }

        rubiksCube = solvedCube;
        std::reverse(solutionMoves.begin(), solutionMoves.end());
        return solutionMoves;
    }
};

#endif //RUBIKS_CUBE_SOLVER_IDASTARSOLVER_H
