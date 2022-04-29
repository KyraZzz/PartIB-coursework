#include <stdlib.h>
#include <stdio.h>

typedef struct tree Tree;
struct tree
{
    int value;
    Tree *left;
    Tree *right;
};

typedef struct arena *arena_t;
struct arena
{
    int size;
    int current; // how many in-use
    Tree *elts;
};

arena_t make_arena(int size)
{
    arena_t arena = malloc(sizeof(struct arena));
    arena->size = size;
    arena->current = 0;
    arena->elts = malloc(size * sizeof(Tree));
    return arena;
}

// arena allocation
// 1. initialise current element
// 2. increment current
// 3. return the initialised node

Tree *node(int value, Tree *left, Tree *right, arena_t arena)
{
    if (arena->current < arena->size)
    {
        Tree *t = &((arena->elts)[arena->current]); // access the i^th tree if current is the i
        arena->current += 1;
        t->value = value, t->left = left, t->right = right;
        printf("value: %d\n", (arena->elts + (arena->current) - 2)->value);
        return t;
    }
    else
        return NULL;
}

// arena deallocation
void free_arena(arena_t arena)
{
    free(arena->elts);
    free(arena);
}

int main()
{
    int BIG_NUMBER = 10000;
    arena_t a = make_arena(BIG_NUMBER); // allocate the arena

    // build an arbitrary graph
    Tree *node1 = node(2, NULL, NULL, a);
    Tree *node2 = node(1, node1, node1, a); // a DAG
    // do something with the nodes

    // free the nodes at once in the arena
    free_arena(a);
}