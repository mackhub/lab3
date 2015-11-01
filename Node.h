/** @file Node.h */
#ifndef _NODE
#define _NODE

template <class ItemType>

class Node
{
    
private :
    ItemType item; // A data item
    Node<ItemType>* next; // Pointer to next node
    Node<ItemType>* prev; // Pointer to prev node

public :
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    void setPrev(Node<ItemType>* prevNodePtr);
    ItemType getItem() const ;
    Node<ItemType>* getNext() const ;
    Node<ItemType>* getPrev() const ;
    
}
; // end Node
#include "Node.cpp"
#endif

