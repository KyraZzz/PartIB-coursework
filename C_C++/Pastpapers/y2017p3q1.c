#include <string.h>
#include <stdlib.h>

char *reverse(char *input)
{
    int len = strlen(input);
    char output[len + 1];
    for (int i = 0; i < len; i++)
    {
        output[len - i - 1] = input[i];
    }
    output[len] = '\0';
    return &(output[0]);
}