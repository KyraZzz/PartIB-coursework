extern "C"
{
#include "pcolparse.h"
}
#include <cstdio>
using namespace std;

int main(int argc, char *argv[])
{
    // argc = 3
    // argv[1] = log file read from
    // argv[2] = file written to
    if (argc != 3)
    {
        puts("Usage: extract <logfile> <filename>");
        return 1;
    }
    FILE *fin;
    FILE *fout;
    fin = fopen(argv[1], "r");
    fout = fopen(argv[2], "w");
    if (!fin)
    {
        puts("Error opening log file, log file does not exist");
        return 2;
    }
    int c;
    Packet *header = parse_packet(argv[1]);
    while (header != NULL)
    {
        for (int i = 0; i < header->data_length; i++)
        {
            fputc(header->data[i], fout);
        }
        header = header->next;
    }
    fclose(fin);
    fclose(fout);
}
