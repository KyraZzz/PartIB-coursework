#ifdef __cplusplus
extern "C"
{
#endif
    typedef struct Packet Packet;
    struct Packet
    {
        // header length (IHL): 4 bits
        uint8_t IHL;
        // total length: 16 bits
        uint16_t tot_len;
        // source address: 32 bits
        uint32_t source;
        // destination address: 32 bits
        uint32_t destination;
        // data offset in TCP header: 4 bits
        uint8_t data_offset;
        // data length
        int data_length;
        // packet data
        char *data;
        Packet *next;
    };

    /* parse a file to find information about packets */
    Packet *parse_packet(char *filename);

    /* free the packet linked list */
    void free_packet(Packet *header);
#ifdef __cplusplus
}
#endif
