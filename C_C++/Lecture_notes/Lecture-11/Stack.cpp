#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

template <typename T>
class Stack
{
    struct Item
    {
        T val;
        Item *next;
        Item(T v) : val(v), next(0) {}
    };
    Item *head;
    // forbid users being able to copy stacks
    Stack(const Stack &s) {}            // private
    Stack &operator=(const Stack &s) {} // private

public:
    Stack() : head(0) {}
    // ~Stack(); // should generally be virtual
    T pop();
    void push(T val);
    void append(T val);
};

template <typename T>
void Stack<T>::append(T val)
{
    Item **pp = &head;
    while (*pp)
    {
        pp = &((*pp)->next);
    }
    *pp = new Item(val);
};

template <typename T>
void Stack<T>::push(T val)
{
    if (head)
    {
        Item *pp = new Item(val);
        pp->next = head;
        head = pp;
    }
    else
    {
        head = new Item(val);
    }
};

struct StackError
{
    string message;
    StackError(string i) : message(i){};
};

template <typename T>
T Stack<T>::pop()
{
    if (head)
    {
        T res = head->val;
        head = head->next;
        return res;
    }
    else
    {
        throw StackError("No items to pop");
    }
};

int main()
{
    Stack<char> s;
}