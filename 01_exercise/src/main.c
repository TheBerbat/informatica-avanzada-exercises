#include <stdio.h>
#include <stdlib.h>
#include <triangular.h>

int main()
{
    printf("Calculating first 100 triangular numbers:\n  n      Tn\n");
    for (int i=1 ; i <= 100; ++i)
        printf("%3d -> %4u\n", i, triguangular(i));

    return EXIT_SUCCESS;
}
