#include "div.h"
#include <stdio.h>

int div(int a, int b)
{
    if (b == 0)
    {
        fprintf(stderr, "division by 0\n");
        return 0;
    }

    return a / b;
}
