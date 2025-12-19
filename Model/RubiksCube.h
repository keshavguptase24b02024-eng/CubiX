#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

/**
 * Base class for all Rubik's Cube models.
 * Each model may have its own internal representation.
 * This class provides common functionality and helpers.
 */
class RubiksCube {
public:
    enum class FACE {
        UP, LEFT, FRONT, RIGHT, BACK, DOWN
    };

    enum class COLOR {
        WHITE, GREEN, RED, BLUE, ORANGE, YELLOW
    };

    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    // Get the color of a cell at (row, col) on a given face
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    // Returns the first letter of a color (e.g., GREEN -> 'G')
    static char getColorLetter(COLOR color);

    // Returns true if cube is solved
    virtual bool isSolved() const = 0;

    // Returns string representation of a move
    static string getMove(MOVE moveIndex);

    /**
     * Print cube in planar format.
     *
     * The cube is laid out as follows:
     *
     *       U
     *    L  F  R  B
     *       D
     *
     * Color wise example:
     *
     *           W W W
     *           W W W
     *           W W W
     *
     *   G G G   R R R   B B B   O O O
     *   G G G   R R R   B B B   O O O
     *   G G G   R R R   B B B   O O O
     *
     *           Y Y Y
     *           Y Y Y
     *           Y Y Y
     *
     */
    void print() const;

    // Randomly shuffle the cube and return the performed moves
    vector<MOVE> randomShuffleCube(unsigned int times);

    // Perform a move
    RubiksCube& move(MOVE moveIndex);

    // Invert a move
    RubiksCube& invert(MOVE moveIndex);

    // Rotational moves
    virtual RubiksCube& f() = 0;
    virtual RubiksCube& fPrime() = 0;
    virtual RubiksCube& f2() = 0;
    virtual RubiksCube& u() = 0;
    virtual RubiksCube& uPrime() = 0;
    virtual RubiksCube& u2() = 0;
    virtual RubiksCube& l() = 0;
    virtual RubiksCube& lPrime() = 0;
    virtual RubiksCube& l2() = 0;
    virtual RubiksCube& r() = 0;
    virtual RubiksCube& rPrime() = 0;
    virtual RubiksCube& r2() = 0;
    virtual RubiksCube& d() = 0;
    virtual RubiksCube& dPrime() = 0;
    virtual RubiksCube& d2() = 0;
    virtual RubiksCube& b() = 0;
    virtual RubiksCube& bPrime() = 0;
    virtual RubiksCube& b2() = 0;

    // Corner helpers
    string getCornerColorString(uint8_t cornerIndex) const;
    uint8_t getCornerIndex(uint8_t cornerIndex) const;
    uint8_t getCornerOrientation(uint8_t cornerIndex) const;
};

#endif // RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
