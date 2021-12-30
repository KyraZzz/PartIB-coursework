#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node
{
    bool flag;
    int size;
    Node **children;
};

Node *
node(int n, Node **children)
{
    Node *nd = malloc(sizeof(Node));
    nd->flag = false;
    nd->size = n;
    nd->children = children;
    return nd;
}

Node *example(void)
{
    Node *node1 = node(1, malloc(1 * sizeof(Node *)));
    Node *node2 = node(2, malloc(2 * sizeof(Node *)));
    node1->children[0] = node2;
    node2->children[0] = node2;
    node2->children[1] = node1;
    printf("%p\n", node1);
    printf("%p\n", node2);
    printf("%p\n", (node1->children)[0]);
    printf("%p\n", node1->children);
    printf("%p\n", node2->children);
    printf("%p\n", *(node2->children));
    printf("%p\n", (*(node2->children)) + 1);
    printf("%p\n", node2->children[0]);
    printf("%p\n", node2->children[1]);
    printf("%p\n", *((node2->children) + 1));
    return node1;
}

int main()
{
    example();
}