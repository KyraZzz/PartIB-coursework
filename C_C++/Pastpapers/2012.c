#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(void *a, void *b, int length)
{
    void *temp = malloc(length);
    memcpy(temp, a, length);
    memcpy(a, b, length);
    memcpy(b, temp, length);
    free(temp);
    return;
};
int main()
{
    int arra[3] = {1, 2, 3};
    int arrb[4] = {9, 8, 7};
    int *ai = &arra[0];
    int *bi = arrb;
    swap(ai, bi, 3);
    for (int i = 0; i < 3; i++)
    {
        printf("ai[%d]: %d\n", i, ai[i]);
        printf("bi[%d]: %d\n", i, bi[i]);
    }

    char arrc[4] = {'a', 'b', 'c', 'd'};
    char arrd[4] = {'z', 'y', 'x', 'w'};
    char *cc = &arrc[0];
    char *dc = arrd;
    swap(cc, dc, 4);
    for (int i = 0; i < 3; i++)
    {
        printf("cc[%i]: %c\n", i, cc[i]);
        printf("dc[%i]: %c\n", i, dc[i]);
    }
}