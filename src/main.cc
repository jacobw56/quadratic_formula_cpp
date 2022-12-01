/**
 * Copyright (c) 2022 Walter Jacob
 *
 * SPDX-License-Identifier: MIT
 *
 */

/**
 * @addtogroup  Quad Quadratic root finder
 * @defgroup    Main Quadratic root finder main application
 * @ingroup     Quad
 * @{
 *
 * @file    main.c
 * @author  Walter Jacob
 * @date    2022
 *
 * @brief Quadratic root finder
 *
 * Provide the real solution(s), as double precision values, if they exist,
 * of a quadratic equation of the form
 *
 * 	Ax^2 + Bx + C = 0
 *
 * where A, B, and C are real, double precision, numbers. The values are
 * passed to the program as options.
 *
 * Example:
 *
 * 	quadratic_formula -A=1 -B=0 -C=-4
 *
 * This has an expected return value of 2, -2.
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "quadratic.hh"

// #define LOG_DBG

/* Notice that I didn't change the printf calls to cout. You could, but printf
 * works just fine and I don't need any overloading here.
 */
static void help_msg(void)
{
    printf("\nQuadratic root finder\n\n");
    printf("Provide the real solution(s), as double precision values, if they exist,\n");
    printf("of a quadratic equation of the form\n\n\tAx^2 + Bx + C = 0\n\n");
    printf("where A, B, and C are real, double precision, numbers. The values are\n");
    printf("passed to the program as options.\n\n");
    printf("Example:\n\n\tquadratic_formula -A=1 -B=0 -C=-4\n\n");
    printf("This has expected return value of 2, -2\n\n");
    printf("Options:\n\n");
    printf("\t--help  \tDisplay this help menu.\n\n");
    printf("\t-A=value\tAssign a value to coefficient A as in the example above.\n");
    printf("\t        \tThis value defaults to 1.\n\n");
    printf("\t-B=value\n");
    printf("\t-C=value\tAssign a value to coefficient B, or C as in the example above.\n");
    printf("\t        \tThis value defaults to 0.\n\n");
}

int main(int argc, char *argv[])
{
    if (argc > 4)
    {
        printf("\nOh teh noes! Too many arguments! Try running with --help for valid options.\n");
        return -1;
    }

    if ((argc == 2) && (strncmp(argv[1], "--help", 6) == 0))
    {
        help_msg();

        return 0;
    }

    double a = 1.0, b = 0.0, c = 0.0;

    /* Assign our coefficients from user input */
    for (int i = 1; i < argc; i++)
    {
        if (strncmp(argv[i], "-A=", 3) == 0)
        {
            a = strtod(argv[i] + 3, NULL);
            if (a == 0.0)
            {
                printf("\nThis is a line, not a parabola! The A coefficient cannot be zero!\n\n");
                return -1;
            }
        }
        else if (strncmp(argv[i], "-B=", 3) == 0)
        {
            b = strtod(argv[i] + 3, NULL);
        }
        else if (strncmp(argv[i], "-C=", 3) == 0)
        {
            c = strtod(argv[i] + 3, NULL);
        }
    }

#ifdef LOG_DBG
    printf("Values: %f, %f, %f\n", a, b, c);
#endif

    QuadPoly qp(a, b, c);

    qp.printRoots();

    return 0;
}

/**
 * @}
 */
