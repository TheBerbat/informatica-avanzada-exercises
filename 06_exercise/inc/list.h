#ifndef LIST_H
#define LIST_H
#include <stddef.h>

// INTERNAL STRUCTS
struct node_t;
struct list_t;

// ITERATE FUNCTION
typedef int (*list_iterate_function)(void* data);

struct list_t* list_new(size_t data_size);
void           list_free(struct list_t* l);
void*          list_insert(struct list_t* l, size_t pos);
void           list_remove(struct list_t* l, size_t pos);
size_t         list_size(struct list_t* l);

void           list_iterate(struct list_t* l, list_iterate_function f);

#endif // LIST_H