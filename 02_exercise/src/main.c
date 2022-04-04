#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    int i = 1;
    while (n>1)
    {
        i = i*n;
        //  Here, we are creating a new local variable that hides previous n.
        // int n = n-1;
        n = n-1;
    }
    return i;
}

int main()
{
    int fac4 = factorial(4);
    int fac5 = factorial(5);

    printf("4! = %d, 5! = %d\n", fac4, fac5);
    return 0;
}
