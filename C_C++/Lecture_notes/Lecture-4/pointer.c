#include <stdio.h>

struct values
{
    int a;
    int b;
};

int main(void)
{
    struct values test2 = {2, 3};
    struct values test1 = {0, 1};

    int *pi = &(test1.a);
    pi += 1;
    printf("%d\n", *pi);

    pi += 2;
    printf("%d\n", *pi);
}