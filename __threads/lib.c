#include <stdio.h>
#include <stdlib.h>     // rand

#include "lib.h"

void test()
{
    printf("%s\n", "test");
}

int randint(int min, int max)
{
    double val = (double) rand() / RAND_MAX;
    val *= (max-min);
    val += min;
    return (int) (val-.5);
}