/** @file Stack.cpp */

#include "Stack.h"

template <class ItemType>
Stack<ItemType>::Stack()
{
}


template <class ItemType>
Stack<ItemType>::~Stack()
{
}


template <class ItemType>
bool Stack<ItemType>::isEmpty() const
{
  return list.isEmpty();
}


template <class ItemType>
bool Stack<ItemType>::push(const ItemType& newEntry)
{
  return list.insert(1, newEntry);
}


template <class ItemType>
bool Stack<ItemType>::pop()
{
  return list.remove(1);
}


template <class ItemType>
ItemType Stack<ItemType>::peek() const
{
  return list.getEntry(1);
}
