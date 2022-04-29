#include <stdio.h>
template <typename T>
void swap(T *a, T *b, int length)
{
    for (int i = 0; i < length; i++)
    {
        T temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
};

int main()
{
    int arra[3] = {-1, -2, -3};
    int arrb[4] = {-9, -8, -7};
    int *ai = &arra[0];
    int *bi = arrb;
    swap(ai, bi, 3);
    for (int i = 0; i < 3; i++)
    {
        printf("ai[%d]: %d\n", i, ai[i]);
        printf("bi[%d]: %d\n", i, bi[i]);
    }
}