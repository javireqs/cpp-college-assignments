//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file Node.h 
    Listing 4-1 */
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node
   Node<ItemType>* prev; // Pointer to prev node (or to NULL for first node in list)
   
public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(Node<ItemType>* nextNodePtr);
   void setPrev(Node<ItemType>* prevNodePtr);      // setPrev()
   ItemType getItem() const ;
   Node<ItemType>* getNext() const ;
   Node<ItemType>* getPrev() const;       // getPrev()
}; // end Node

#endif