#include <stdio.h>
#include <stdlib.h>

void fn()
{
    //int* x = malloc(10*sizeof(int));
    int* x = (int*)malloc(10*sizeof(int)); // Need to explicit cast
    printf("%d", *x); // Memory uninitialized to 0 (reserved but the value is not insured)
    x[10] = 0; // Access out of reserved memory (undefined-behavior). Hard to detect!!
} // Reserved memory is not freed!! Memory leaks!!

int main()
{
    fn();
    return 0;
}