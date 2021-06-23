#include <stdio.h>
#include <string.h>

int main(void)
{
    static char strings[][80] = {
        "University",
        "University of Cambridge",
        "Hello, world",
        " Hello ",
        "University of Cambridge!",
        " University of Cambridge",
        "-$$$!!!-",
        "University-of-Cambridge"};
    for (int i = 0; i < strlen(strings[0]); i++)
    {
        printf("%d %c\n", i, strings[0][i]);
    }
}