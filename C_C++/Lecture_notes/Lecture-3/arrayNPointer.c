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
}