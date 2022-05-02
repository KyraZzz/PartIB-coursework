#include <stdio.h>
void reverse(int *arr[], int len)
{
    for (int i = 0; i < len / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}
void main()
{
    int *a[] = {1, 2, 3, 4, 5};
    reverse(a, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }
}