#include "RubiksCube.h"

//
// Return the first letter of a color
//
char RubiksCube::getColorLetter(COLOR color) {
    switch (color) {
        case COLOR::BLUE:   return 'B';
        case COLOR::GREEN:  return 'G';
        case COLOR::RED:    return 'R';
        case COLOR::YELLOW: return 'Y';
        case COLOR::WHITE:  return 'W';
        case COLOR::ORANGE: return 'O';
    }
}

/*
 * Describe a move using a Move index
 */
string RubiksCube::getMove(MOVE moveIndex) {
    switch (moveIndex) {
        case MOVE::L:      return "L";
        case MOVE::LPRIME: return "L'";
        case MOVE::L2:     return "L2";
        case MOVE::R:      return "R";
        case MOVE::RPRIME: return "R'";
        case MOVE::R2:     return "R2";
        case MOVE::U:      return "U";
        case MOVE::UPRIME: return "U'";
        case MOVE::U2:     return "U2";
        case MOVE::D:      return "D";
        case MOVE::DPRIME: return "D'";
        case MOVE::D2:     return "D2";
        case MOVE::F:      return "F";
        case MOVE::FPRIME: return "F'";
        case MOVE::F2:     return "F2";
        case MOVE::B:      return "B";
        case MOVE::BPRIME: return "B'";
        case MOVE::B2:     return "B2";
    }
}

/*
 * Perform a move on the cube
 */
RubiksCube& RubiksCube::move(MOVE moveIndex) {
    switch (moveIndex) {
        case MOVE::L:      return l();
        case MOVE::LPRIME: return lPrime();
        case MOVE::L2:     return l2();
        case MOVE::R:      return r();
        case MOVE::RPRIME: return rPrime();
        case MOVE::R2:     return r2();
        case MOVE::U:      return u();
        case MOVE::UPRIME: return uPrime();
        case MOVE::U2:     return u2();
        case MOVE::D:      return d();
        case MOVE::DPRIME: return dPrime();
        case MOVE::D2:     return d2();
        case MOVE::F:      return f();
        case MOVE::FPRIME: return fPrime();
        case MOVE::F2:     return f2();
        case MOVE::B:      return b();
        case MOVE::BPRIME: return bPrime();
        case MOVE::B2:     return b2();
    }
}

/*
 * Invert a move
 */
RubiksCube& RubiksCube::invert(MOVE moveIndex) {
    switch (moveIndex) {
        case MOVE::L:      return lPrime();
        case MOVE::LPRIME: return l();
        case MOVE::L2:     return l2();
        case MOVE::R:      return rPrime();
        case MOVE::RPRIME: return r();
        case MOVE::R2:     return r2();
        case MOVE::U:      return uPrime();
        case MOVE::UPRIME: return u();
        case MOVE::U2:     return u2();
        case MOVE::D:      return dPrime();
        case MOVE::DPRIME: return d();
        case MOVE::D2:     return d2();
        case MOVE::F:      return fPrime();
        case MOVE::FPRIME: return f();
        case MOVE::F2:     return f2();
        case MOVE::B:      return bPrime();
        case MOVE::BPRIME: return b();
        case MOVE::B2:     return b2();
    }
}

void RubiksCube::print() const {
    cout << "Rubik's Cube:\n\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {

        for (int col = 0; col <= 2; col++) cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";
        cout << " ";

        for (int col = 0; col <= 2; col++) cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";
        cout << " ";

        for (int col = 0; col <= 2; col++) cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";
        cout << " ";

        for (int col = 0; col <= 2; col++) cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";
        cout << "\n";
    }

    cout << "\n";

    for (int row = 0; row <= 2; row++) {
        for (unsigned i = 0; i < 7; i++) cout << " ";
        for (int col = 0; col <= 2; col++) cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
        cout << "\n";
    }

    cout << "\n";
}
