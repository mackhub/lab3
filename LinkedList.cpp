/** @file LinkedList.cpp */

#include "LinkedList.h"

template<class ItemType> Node<ItemType>*
LinkedList<ItemType>::getNodeAt(int position) const
{
  // TODO: handle cases where position is out of range

  Node<ItemType>* curr = headPtr;
  for (int skip = 1; skip < position; skip++)
    {
      curr = curr->getNext();
    }

  return curr;
}

template <class ItemType> LinkedList <ItemType>::LinkedList() :
  headPtr(nullptr), count(0)
{
}


template <class ItemType> LinkedList <ItemType>::LinkedList(const LinkedList<ItemType>& list)
{
}


template <class ItemType> LinkedList <ItemType>::~LinkedList()
{
  clear();
}


template <class ItemType> bool LinkedList <ItemType>::isEmpty() const
{
  return (count == 0);
}


template <class ItemType> int LinkedList <ItemType>::getLength() const
{
  return count;
}


template <class ItemType> bool LinkedList <ItemType>::insert(int newPosition, const ItemType& newEntry)
{
  // insert a new item to an existing list.  if successful list will have
  // count + 1 items.  New position can be anywhere from 1 to count + 1
  // 1 corresponds to the beginning of the list, count + 1 corresponds to
  // the end of the list, and anything in between will be at the appropriate
  // location in the middle of the list

  bool result;

  if ((newPosition < 1) || (newPosition > (count + 1)))
	{
	  result = false;
	}
  else {

	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

	if (newPosition == 1)
	  {
		// Insert new node at the beginning of chain
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
	  }
	else
	  {
		// Find node that will be before new node
		Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

		// Insert new node after node to which prevPtr points
		newNodePtr->setNext(prevPtr->getNext());
		prevPtr->setNext(newNodePtr);
	  }

	count++;

	result = true;
  }

  return result;
}


template <class ItemType> bool LinkedList <ItemType>::remove(int position)
{
  // remove an item from an existing list.  if successful list will have
  // count - 1 items.  Deleted position can be anywhere from 1 to count
  // 1 corresponds to the beginning of the list, count corresponds to
  // the end of the list, and anything in between will be at the appropriate
  // location in the middle of the list

  bool result;

  if ((position < 1) || (position > count))
	{
	  result = false;
	}
  else {

	Node<ItemType>* curPtr = nullptr;

	if (position == 1)
	  {
		// Remove the first node in the chain
		curPtr = headPtr;
		headPtr = headPtr->getNext();
	  }
	else
	  {
		// Find node that is before the one to delete
		Node<ItemType>* prevPtr = getNodeAt(position - 1);

		// Point to node to delete
		curPtr = prevPtr->getNext();

		// Disconnect indicated node from chain by connecting the
		// prior node with the one after
		prevPtr->setNext(curPtr->getNext());
	  }

	// Return node to system
	curPtr->setNext(nullptr);
	delete curPtr;
	curPtr = nullptr;
	count--;
	result = true;
  }

  return result;
}


template <class ItemType> void LinkedList <ItemType>::clear()
{
  while (!isEmpty())
    {
      remove(1);
    }
  return;
}


template <class ItemType> ItemType LinkedList <ItemType>::getEntry(int position)  const
{
  // TODO: handle cases where position is out of bounds
  Node<ItemType>* nodePtr = getNodeAt(position);
  return nodePtr->getItem();
}


template <class ItemType> void LinkedList <ItemType>::setEntry(int position, const ItemType & newEntry) {

  Node<ItemType>* nodePtr = getNodeAt(position);
  nodePtr->setItem(newEntry);
  return;
}


#ifdef _DEBUG
// For unit test use with integers
template <class ItemType> void LinkedList <ItemType>::print() {

  for (int i = 0; i < count; i++) {
	cout << "Item " << i + 1 << " = " << getNodeAt(i+1)->getItem() << endl;
  }
  cout << endl;
  return;
}
#endif
