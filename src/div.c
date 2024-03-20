#include "div.h"
#include <stdio.h>

/**
 * @brief Performs a two integer division.
 * @param a Dividend
 * @param b Divisor
 * @return a / b, 0 if b equals 0 (avoids division by 0)
 * @warning No error is thrown for zero division
 * */
int div(int a, int b)
{
    if (b == 0)
    {
        fprintf(stderr, "division by 0\n");
        return 0;
    }

    return a / b;
}

