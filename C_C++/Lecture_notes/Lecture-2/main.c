#define BESTRING(s) #s
#define paster(n) printf("token" #n " = %d", token##n)
#define PERCENT(D) (100 * D)
#define DPRINT(D) printf(#D " = %g\n", D)
#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("%s\n", BESTRING("Hi"));
    int token9 = 9;
    // paster(9);
    DPRINT(PERCENT(0.20 + 0.16));
}