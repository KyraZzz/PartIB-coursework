#include <stdio.h>
#include "example1.h"

int main(void)
{
    char s[] = "Reverse me";
    reverse(s);
    printf("%s\n", s);
    return 0;
}