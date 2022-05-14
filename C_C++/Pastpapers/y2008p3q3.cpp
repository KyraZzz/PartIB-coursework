#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <bitset>
using namespace std;
class BitQueueException
{
};

class BitQueue
{
    int valid_bits; // the number of valid bits held in queue
    int queue;      // least significant bit is the most recent bit added
public:
    BitQueue() : valid_bits(0), queue(0) {}
    void push(int val, int bsize);
    int pop(int bsize);
    int size();
    void printQueue()
    {
        cout << bitset<32>(queue).to_string() << endl;
    }
};

void BitQueue::push(int val, int bsize)
{
    if (size() + bsize > 32)
    {
        throw new BitQueueException();
    }
    cout << "push " << val << endl;
    valid_bits += bsize;
    val &= ((1 << bsize) - 1);
    queue <<= bsize;
    queue |= val;
    printQueue();
}

int BitQueue::pop(int bsize)
{
    if (size() < bsize)
    {
        throw new BitQueueException();
    }
    valid_bits -= bsize;
    int result = queue >> valid_bits;
    queue &= ((1 << valid_bits) - 1);
    cout << "pop" << endl;
    printQueue();
    return result;
}

int BitQueue::size()
{
    return valid_bits;
}

void send(char c)
{
    cout << "send start" << endl;
    cout << bitset<8>(c).to_string() << endl;
    cout << "send end" << endl;
}

void sendmsg(const char *msg)
{
    BitQueue *b = new BitQueue();
    while (*msg)
    {
        if (msg[0] == 'a')
            b->push(0, 1);
        else if (msg[0] == 'b')
            b->push(2, 2);
        else if (msg[0] == 'c')
            b->push(12, 4);
        else if (msg[0] == 'd')
            b->push(13, 4);
        msg++;
        if (b->size() >= 8)
            send(b->pop(8));
    }
    b->push(7, 3);
    int padding = 8 - b->size();
    for (int i = 0; i < padding; i++)
    {
        b->push(0, 1);
    }
    send(b->pop(8));
}

int main()
{
    /*
    BitQueue *b = new BitQueue();
    b->push(0, 1);  // push 'a' = 0
    b->push(2, 2);  // push 'b' = 10
    b->push(12, 3); // push 'c' = 1100
    b->push(13, 4); // push 'd' = 1101
    b->pop(3);
    */
    sendmsg("abcd");
}