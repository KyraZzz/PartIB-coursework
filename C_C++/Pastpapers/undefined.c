#include <string.h>
#include <stdio.h>
int main(void)
{
    char s[] = "abcde";
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        s[i] += 1;
    return printf("'%s' is %lu characters long\n", s + 1, strlen(s + 1));
}