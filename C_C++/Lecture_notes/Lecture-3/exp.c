#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct exp Exp;

struct exp
{
    enum tag
    {
        Var = 1,
        Neg = 2,
        Divide = 3
    } t;
    union
    {
        struct exp *arg1;
        char *var_name;
    };
    struct exp *arg2;
};

bool isEqual(Exp *a, Exp *b)
{
    if (a == b)
        return true;
    if (a->t != b->t)
        return false;
    if (a->t == 1 && (strcmp(a->var_name, b->var_name) == 0))
        return true;
    if (a->t == 2 && isEqual(a->arg1, b->arg1))
        return true;
    if (a->t == 3 && isEqual(a->arg1, b->arg1) && isEqual(a->arg2, b->arg2))
        return true;
    return false;
}

int main()
{
    Exp *a = (Exp *)malloc(sizeof(Exp));
    Exp *b = malloc(sizeof(Exp));
    a->t = 2;
    b->t = 2;
    a->arg1 = b;
    b->arg1 = b;
    printf("%d", isEqual(a, a));
}
