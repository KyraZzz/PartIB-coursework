int main(void)
{
    int i = 42, j = 28;
    const int *pc = &i; // cannot change content of pc but can reassign to other memory chunk
    // *pc = 41; // compiler error
    pc = &j; // allow reassignment

    int *const cp = &i; // can change the content of pc but not reassign it to some other memory chunk
    *cp = 41;           // can change content
    // cp = &j;         // compiler error

    const int *const cpc = &i;
    // *cpc = 41; // compiler error
    // cpc = &j;  // compiler error
}