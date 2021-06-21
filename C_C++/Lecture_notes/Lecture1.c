#include <stdio.h>
#include <string.h>

int a;                 // not initialised - not sure about the exact value
unsigned char b = 'A'; // declared and defined
extern int alpha;      // declared but not defined, tell the compiler it is defined elsewhere

char s[] = "University of Cambridge Computer Laboratory";

int main(void)
{
    extern unsigned char b;           // b already defined so no change
    double a = 3.4;                   // may get warning from compiler: redefined and declared a
    {                                 // scope zoom into block
        extern a;                     // type specifier missing, defaults to 'int'
        printf("%d %d \n", b, a + 1); // 65 1, a refer to global int a
    }                                 // scope zoom out of block

    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) // strlen excludes the end '\0'
    {
        char c;
        c = s[i], s[i] = s[j], s[j] = c; // swap the two chars
    }
    printf("%s\n", s);
    return 0;
}