#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "pcolparse.h"

void print_IP_addr(uint32_t ip)
{
    printf("%d.%d.%d.%d", (ip >> 24), (ip >> 16) & 0xff, (ip >> 8) & 0xff, ip & 0xff);
}

int main(int argc, char *argv[])
{
    // the file contains: IP header, TCP header, Data
    if (argc != 2)
    {
        puts("Usage: parse log file <file>");
        return 1;
    }
    Packet *header = parse_packet(argv[1]);
    if (header == NULL)
        return 2;
    int total_packets = 0;
    Packet *current = header;
    while (current != NULL)
    {
        current = current->next;
        total_packets++;
    }
    print_IP_addr(header->source);
    printf(" ");
    print_IP_addr(header->destination);
    printf(" ");
    printf("%d %d %d %d", header->IHL, header->tot_len, header->data_offset, total_packets);
    free_packet(header);
}
