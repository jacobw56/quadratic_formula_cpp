/**
 * Copyright (c) 2022 Walter Jacob
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "quadratic.hh"

static double discriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

void QuadPoly::printRoots()
{
    if (number_of_roots == 0)
    {
        printf("\nNo real solutions.\n\n");
    }

    else if (number_of_roots == 1)
    {
        printf("\nSolution: \t%f\n\n", roots[0]);
    }

    else
    {
        printf("\nSolution: \t%f, %f\n\n", roots[0], roots[1]);
    }
}

QuadPoly::QuadPoly(double a, double b, double c)
{
    double dsc = discriminant(a, b, c);

    /* One (repeated) real solution */
    if (dsc == 0.0)
    {
        roots[0] = -1.0 * b / (2.0 * a);
        number_of_roots = 1;
    }

    /* Two unique (conjugate) real solutions */
    else if (dsc > 0.0)
    {
        double sqrt_dsc = sqrt(dsc);
        roots[0] = (-1.0 * b + sqrt_dsc) / (2.0 * a);
        roots[1] = (-1.0 * b - sqrt_dsc) / (2.0 * a);
        number_of_roots = 2;
    }
}