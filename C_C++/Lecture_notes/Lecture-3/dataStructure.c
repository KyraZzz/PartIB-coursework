#include <stdio.h>
struct /* a compiler symbol table */
{
    char *name;
    struct
    {
        unsigned int is_keyword : 1;
        unsigned int is_extern : 1;
        unsigned int is_static : 1;
    } flags;
    int utype;
    union
    {
        int ival; /* accessed as symtab[i].u.ival */
        float fvalue;
        char *sval;
    } u;
} symtab[10]; // NSYM = 10

struct linkedList
{
    int head;
    struct linkedList *tail;
};
typedef struct linkedList linkedList;

int main(void)
{
    linkedList *l1;
    l1->head = 3;
    l1->tail->head = 5;
    while (l1 != NULL)
    {
        printf("%d\n", l1->head);
        l1 = l1->tail;
    }
}
