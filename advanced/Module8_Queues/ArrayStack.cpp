/** @file ArrayStack.cpp */

#include <cassert>
#include "ArrayStack.h"

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
} // end default constructor

// copy constructor and destructor are provided by the compiler

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
    return top < 0;
} // end isEmpty

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
    bool result = false;
    if (top < MAX - 1)  // Does stack have room for newEntry?
    {
        top++;
        items[top] = newEntry;
        result = true;
    } // end if

    return result;
} // end push

template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
    bool result = false;
    if (!isEmpty())
    {
        top--;
        result = true;
    } // end if

    return result;
} // end pop

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
    if(isEmpty())
        throw PrecondViolatedExcept("peek() called with empty stack");
    else // Stack is not empty; return top
        return items[top];
} // end peek
// end of implementation file