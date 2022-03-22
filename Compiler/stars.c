#include <stdio.h>
#include <stdlib.h>
/**
 * compile and input n, output a triangle pattern of *s
 */
int main(int argc, char *argv[])
{
    int n = argc == 2 ? atoi(argv[1]) : 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}