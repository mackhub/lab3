/** @file Stack.h */
#ifndef _STACK
#define _STACK

#include "LinkedList.h"

template <class ItemType> class Stack
{
private:

    LinkedList<ItemType> list;

public:

    Stack();
    ~Stack();

    // methods from stack interface                                                         
    bool isEmpty() const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const;

}; // end Stack

#include "Stack.cpp"

#endif
