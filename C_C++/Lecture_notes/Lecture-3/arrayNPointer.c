#include <stdio.h>

void swap(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
    printf("%d %p = %d, %p = %d\n", temp, px, *px, py, *py);
    int *pc = &temp;
    *pc = temp;
}

void f(int ROW, int COL, int i[][COL])
{
    for (int j = 0; j < ROW; j++)
    {
        for (int k = 0; k < COL; k++)
        {
            printf("%d ", i[j][k]);
        }
        printf("\n");
    }
}

void sort(int a[], const int len, int (*compare)(int, int))
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if ((*compare)(a[j], a[j + 1]))
            {
                int temp = a[j];
                a[j] = a[j + 1], a[j + 1] = temp;
            }
        }
    }
}

int inc(int a, int b) { return a > b ? 1 : 0; }

int main(void)
{
    int c[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *pc = c;
    printf("%p %p %p\n", pc += 3, &c[3], c + 3);
    printf("%d %d %d\n", *(c + 3), c[3], *pc);

    char str[] = "A string";
    char *ps = str;
    printf("%p %p %p\n", ps += 3, &str[3], str + 3);
    printf("%c %c %c\n", *(str + 3), str[3], *ps);

    int x = 1;
    int *pa = &x;
    int y = 2;
    int *pb = &y;
    printf("%p = %d, %p = %d\n", pa, *pa, pb, *pb);
    swap(pa, pb);
    printf("%p = %d, %p = %d\n", pa, *pa, pb, *pb);

    int matrix[5][5] = {0};
    f(5, 5, matrix);

    int a[] = {1, 2, 3, 4, 5, 6, 7, 3, 2, 1, 4, 9, 8};
    sort(a, sizeof(a) / sizeof(int), &inc);
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        printf("%d ", a[i]);
    }
}