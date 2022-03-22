short receive_bit(void) {}
int receive_bit()
{
    int count = 0;
    for (int i = 31; i >= 0; i--)
    {
        count += receive_bit() << i;
    }
    return count;
}