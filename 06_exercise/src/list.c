#include <list.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct node_t {
    void* data;
    struct node_t* next;
};

struct list_t {
    struct node_t* first;
    size_t data_size;
    size_t size;
};

struct node_t* list_create_node(void* data, struct node_t* next) {
    struct node_t* n = (struct node_t*)malloc(sizeof(struct node_t));
    if (!n) return NULL;
    n->data = data; n->next = next;
    return n;
}

struct list_t* list_new(size_t data_size) {
    struct list_t* l = (struct list_t*) malloc(sizeof(struct list_t));
    l->data_size = data_size; l->first = NULL; l->size = 0;
    return l;
}

void list_free_node_recursively(struct node_t* n) {
    if (!n)
        return;
    list_free_node_recursively(n->next);
    free(n->data);free(n);
}
void list_free(struct list_t* l) {
    list_free_node_recursively(l->first);
    free(l);
}

void list_insert_(struct node_t** n, size_t pos, void* data) {
    if (!n) {
        printf("ERROR list_insert_(NULL,) NULL ptr\n"); exit(1);
    }
    //if (!(*n)) printf("WARN list_insert_(*NULL,) contains NULL\n");

    if (pos == -1) *n = list_create_node(data, *n);                     // CASE FIRST NODE CHANGED
    else if (pos == 0) (*n)->next = list_create_node(data, (*n)->next); // INSERT BETWEEN
    else               list_insert_(&(*n)->next, pos-1, data);          // RECURSIVE CASE
}

void* list_insert(struct list_t* l, size_t pos) {
    if (!l) {
        printf("ERROR list_insert(NULL,)\n"); exit(1);
    }

    void* data = malloc(l->data_size);
    list_insert_(&l->first, pos-1, data);
    ++l->size;
    return data;
}

void list_remove_(struct node_t** n, size_t pos) {
    if (!n) {
        printf("ERROR list_remove_(NULL,) NULL ptr\n"); exit(1);
    }
    //if (!(*n)) printf("WARN list_insert_(*NULL,) contains NULL\n");
    struct node_t* n_free = NULL;
    if (pos == -1) // CASE FIRST NODE CHANGED
    {
        n_free = *n;
        *n = n_free->next;
    }                     
    else if (pos == 0) {
        n_free = (*n)->next; // INSERT BETWEEN
        (*n)->next = n_free->next;
    }
    else
        return list_remove_(&(*n)->next, pos-1);          // RECURSIVE CASE
    
    free(n_free->data);
    free(n_free);
}

void list_remove(struct list_t* l, size_t pos)
{
    if (!l) {
        printf("ERROR list_remove(NULL,)\n");
        exit(1);
    }

    list_remove_(&l->first, pos-1);
    --l->size;
}

void list_print_(struct node_t* n) {
    if (!n) return;

    if (n->data)
        printf("%d ", *(int*)(n->data));
    list_print_(n->next);
}

void list_print(struct list_t* l) {
    list_print_(l->first);
}

void list_iterate_(struct node_t* n, list_iterate_function f) {
    if (!n) return;    
    if (f(n->data)) return;
    list_iterate_(n->next, f);
}

void list_iterate(struct list_t* l, list_iterate_function f) {
    list_iterate_(l->first, f);
}

size_t list_size(struct list_t* l) {
    return l->size;
}
