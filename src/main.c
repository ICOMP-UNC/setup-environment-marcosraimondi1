#include "greetings.h"
#include "resta.h"
#include "sum.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  greetings();

  printf("suma: %i, resta: %i \n", sum(10, 5), resta(10, 5));
  return 0;
}
