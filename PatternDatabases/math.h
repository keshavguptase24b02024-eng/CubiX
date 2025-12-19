//
//

#ifndef RUBIKS_CUBE_SOLVER_MATH_H
#define RUBIKS_CUBE_SOLVER_MATH_H

#include <cstdint>

// Computes factorial of n: n!
uint32_t factorial(uint32_t n);

// Computes permutation: nPk = n! / (n - k)!
uint32_t pick(uint32_t n, uint32_t k);

// Computes combination: nCk = n! / ((n - k)! * k!)
uint32_t choose(uint32_t n, uint32_t k);

#endif //RUBIKS_CUBE_SOLVER_MATH_H
