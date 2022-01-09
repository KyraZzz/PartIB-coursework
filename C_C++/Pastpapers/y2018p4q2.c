#include <stdio.h>
#include <stdlib.h>
typedef struct snode Node;
struct snode
{
    int data;
    struct snode *tail;
};

Node *cons(int n, Node *tail)
{
    Node *l = malloc(sizeof(Node));
    l->data = n;
    l->tail = tail;
    return l;
}

void free_list(Node *list)
{
    if (list != NULL)
    {
        free_list(list->tail);
        free(list);
    }
}

Node *reverse(Node *list)
{
    Node *prev = NULL;
    while (list != NULL)
    {
        Node *temp = list->tail;
        list->tail = prev;
        prev = list;
        list = temp;
    }
    return prev;
}

int main()
{
    Node *list = NULL;
    for (int i = 0; i < 5; i++)
    {
        list = cons(i, list);
    }
    Node *temp = list;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", temp->data);
        temp = temp->tail;
    }
    Node *revlist = reverse(list);
    temp = revlist;
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", temp->data);
        temp = temp->tail;
    }
}