#include <stdio.h>

int main(void)
{
    int x = 1, y = 2;
    int *pi = &x;
    int **ppi = &pi;
    printf("%p %p %d = %d = %d\n", ppi, pi, x, *pi, **ppi);
    pi = &y;
    printf("%p %p %d = %d = %d\n", ppi, pi, y, *pi, **ppi);

    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int *arr_p = arr;      // pointer to the first element of the array
    int **arr_pp = &arr_p; // pointer to pointer to the first element of the array

    printf("arr_p: %d, arr_pp: %ld\n", arr_p[0], arr_pp[1] - arr_pp[0]);

    int **pptr;
    int z = 3;
    int *ptr = &z;
    *ptr = y;
    pptr = &ptr;
    *pptr = &x;
    printf("pptr:%p, *pptr:%p, ptr: %p, *ptr:%d, x:%d, y:%d, z:%d\n", pptr, *pptr, ptr, *ptr, x, y, z);
}