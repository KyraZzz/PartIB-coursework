#include <string.h>
#include "example1.h"

void reverse(char s[])
{
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        char c = s[i];
        s[i] = s[j], s[j] = c;
    }
}