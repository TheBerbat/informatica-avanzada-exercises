#include <stdio.h>
#include <stdlib.h>
#include <triangular.h>

int main()
{
    unsigned int n, res;

    printf("Introduce an interger number: ");
    if ( fscanf(stdin, "%d", &n) != 1)
    {
        printf("Error introducing the number, please rerun the program\n");
        return EXIT_FAILURE;
    }

    res = triguangular(n);
    printf("The result is: %u\n", res);

    return EXIT_SUCCESS;
}
