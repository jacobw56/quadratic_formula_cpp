/**
 * Copyright (c) 2022 Walter Jacob
 *
 * SPDX-License-Identifier: MIT
 *
 */

/**
 * @addtogroup  Quad Quardatic root library
 * @defgroup    QuadLib
 * @ingroup     Quad
 * @{
 *
 * @file    quadratic.c
 * @author  Walter Jacob
 * @date    2022
 *
 * @brief Quadratic root finder library
 *
 * @details Definitely overkill, but this file contains the functions that are used by
 * the quadratic root finder program. They are refactored into this library
 * to give an example of a program that uses external headers/source files.
 */

#ifndef __QUADRATIC_H
#define __QUADRATIC_H

#include <cmath>
#include <cstddef>
#include <cstdio>

/**
 * @class QuadPoly quadratic.hh "include/quadratic.hh"
 * @brief Quadratic Polynomial class
 *
 * @details Unlike in the C OOP version of this same program, the constructor
 * does all the work here, with the idea that we don't need to regenerate roots
 * down the line, although that would be easy to add.
 */
class QuadPoly
{
public:
    /**
     * @brief Construct a new Quad Poly object
     *
     * @details The default constructor gives A=1, B=0, C=0
     */
    QuadPoly() = default;

    /**
     * @brief Construct a new Quad Poly object
     *
     * @param a     Quadratic coefficient
     * @param b     Linear coefficient
     * @param c     Constant coefficient
     */
    QuadPoly(double a, double b, double c);

    /**
     * @brief Print the roots to the screen
     */
    void printRoots();

private:
    double a = 1.0;
    double b = 0.0;
    double c = 0.0;
    double roots[2] = {0.0};
    unsigned int number_of_roots = 0;
};

#endif // __QUADRATIC_H

/** @} */