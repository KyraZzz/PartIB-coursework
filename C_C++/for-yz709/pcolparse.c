#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pcolparse.h"

#if HAVE_BYTESWAP_H
#include <byteswap.h>
#else
#define bswap_16(value) \
    ((((value)&0xff) << 8) | ((value) >> 8))

#define bswap_32(value)                                       \
    (((uint32_t)bswap_16((uint16_t)((value)&0xffff)) << 16) | \
     (uint32_t)bswap_16((uint16_t)((value) >> 16)))

#endif

#define IPHSIZE 20
#define TCPHSIZE 28
#define BUFSIZE 1024

Packet *parse_packet(char *filename)
{
    FILE *fp;
    if ((fp = fopen(filename, "rb")) == 0)
    {
        perror("Cannot find file to serve");
        return NULL;
    }
    Packet *previous = NULL;
    Packet *header = NULL;
    while (!feof(fp)) // not end of file
    {
        Packet *current = malloc(sizeof(Packet));
        current->next = NULL;
        unsigned char bytes[BUFSIZE];
        size_t r;
        // read the IP header
        if ((r = fread(bytes, sizeof(char), IPHSIZE, fp) > 0))
        {
            // only need the last 4 bits of the first byte
            current->IHL = (uint8_t)bytes[0] & 0x0F;
            // read bytes[2] + bytes[3] for tot_len, need to reverse the order because of little endian
            memcpy(&(current->tot_len), &(bytes[2]), 2);
            current->tot_len = bswap_16(current->tot_len);
            // read bytes[12] ~ bytes[15] for source, need to reverse the order because of little endian
            memcpy(&(current->source), &(bytes[12]), 4);
            current->source = bswap_32(current->source);
            // read bytes[16] ~ bytes[19] for destination, need to reverse the order because of little endian
            memcpy(&(current->destination), &(bytes[16]), 4);
            current->destination = bswap_32(current->destination);
        }
        else
        {
            break;
        }
        if ((r = fread(bytes, sizeof(char), TCPHSIZE, fp) > 0))
        {
            // read the first 4 bits of bytes[12] for data_offset,
            // need to shift right by 4 bits
            current->data_offset = (uint8_t)(bytes[12] & 0xF0) >> 4;
        }
        else
        {
            break;
        }
        if (previous != NULL)
        {
            previous->next = current;
        }
        else
        {
            header = current;
        }
        // set the file pointer to skip the packet data
        fseek(fp, current->tot_len - IPHSIZE - TCPHSIZE, SEEK_CUR);
        previous = current;
    }
    fclose(fp);
    return header;
}

void free_packet(Packet *header)
{
    if (header == NULL)
        return;
    free_packet(header->next);
    free(header);
}
