#include <stdio.h>
#include <stdlib.h>
#include <list.h>

// FUNCTION TO ITERATE LIST
int print_int(void* d) {
    printf("%d ", *(int*)d);
    return 0;
}

int main()
{
    // List that holds int type
    struct list_t* l = list_new(sizeof(int));

    int* d0;

    // Insert elements to position i and assign i
    for (size_t i=0 ; i<11 ; ++i)
        { d0 = (int*)list_insert(l, i); *d0 = i;}
    
    d0 = (int*)list_insert(l, list_size(l)); *d0 = 44; // Insert at the end
    d0 = (int*)list_insert(l, list_size(l)/2); *d0 = 99; // Insert in middle

    // Iterate over list with fn pointer
    list_iterate(l, print_int); printf("\n");

    // Remove middle element of the list
    list_remove(l, list_size(l)/2);

    // Iterate over list with fn pointer
    list_iterate(l, print_int); printf("\n");

    // Free list
    list_free(l);

    return 0;
}