#include "greetings.h"
#include "substraction.h"
#include "sum.h"
#include <stdio.h>

/**
 * @brief main function for testing configuration.
 * @param argc: number of arguments
 * @param argv: array of arguments
 * @return 1 if succes, 0 if failure
 * @see greetings sum resta
 * */
int main(int argc, char* argv[])
{
    greetings();
    printf("sum: %i, substraction: %i \n", sum(10, 5), substraction(10, 5));
    return 0;
}

