#include <stdio.h>

struct test
{
    int i;
};

typedef struct test test_t;

int main(void)
{
    test_t a, b;
    test_t *p[] = {&a, &b};
    p[0]->i = 0;
    p[1]->i = 0;
    test_t *q = p[0];

    printf("%d\n", ++q->i); // equivalent to ++(q->i)
    return 0;
}