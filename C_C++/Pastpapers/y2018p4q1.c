#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int64_t divide(int64_t x, int64_t y)
{
    if ((y == 0) || (x == INT64_MIN && y == -1))
        return 0;
    printf("MAX = %lld\n", INT64_MAX);
    printf("MIN = %lld\n", INT64_MIN);
    return (int64_t)(x / y);
}

size_t strlen2(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

void rotate(int len, int *array, int k)
{
    int *new_arr = malloc(sizeof(int) * len);
    int *new_arr2 = malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++)
    {
        new_arr[(i + k) % len] = array[i];
        new_arr2[(i + k) % len] = array[i] * 100;
    }
    for (int i = 0; i < len; i++)
    {
        array[i] = new_arr[i]; // need to do a deep copy
    }
    printf("new_arr[len + 4]:%d\n", new_arr[len + 4]);
}

void rotate2(int len, int *array, int k)
{
    int new_arr[k];
    for (int i = 0; i < k; i++)
    {
        new_arr[i] = array[len - k + i];
    }
    for (int i = len - k - 1; i >= 0; i--)
    {
        array[i + k] = array[i];
    }
    for (int i = 0; i < k; i++)
    {
        array[i] = new_arr[i];
    }
}

int main()
{
    char *a = "hello";
    printf("%zu\n", strlen2(a));
    printf("%lld\n", divide(-5, 3));
    int len = 6;
    int array[6] = {0, 1, 2, 3, 4, 5};
    rotate(len, array, 3);
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
    rotate2(len, array, 3);
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", array[i]);
    }
}