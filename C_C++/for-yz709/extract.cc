#include <iostream>
#include <fstream>
#include "pcolparse.h"
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
    ifstream fin(argv[1]);
    ofstream fout(argv[2], ios::trunc);
    if (fin.fail())
    {
        puts("Error opening log file, log file does not exist");
        return 2;
    }
    Packet *header = parse_packet(argv[1]);
    while (header != NULL)
    {
        for (int i = 0; i < header->data_length; i++)
        {
            fout << header->data[i];
        }
        header = header->next;
    }
    fin.close();
    fout.close();
}
