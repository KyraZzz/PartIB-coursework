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

int main()
{
    Exp e1, e2, e3, e4, e5;
}