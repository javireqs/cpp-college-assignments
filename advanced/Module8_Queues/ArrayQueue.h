/** ADT queue: Circular array-based implementation
 * @file ArrayQueue.h */

#ifndef ARRAY_QUEUE_
#define ARRAY_QUEUE_

#include "QueueInterface.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class ArrayQueue : public QueueInterface<ItemType>
{
    private:
        static const int DEFAULT_CAPACITY = 50;
        ItemType items[DEFAULT_CAPACITY];   // Array of queue items
        int front;  // Index to the front of the queue
        int back;   // Index to the back of the queue
        int count;  // Number of items currently in the queue

    public:
        ArrayQueue();
        // Copy constructor supplied by complier; destructor is inherited
        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();

        /** @throw  PrecondViolatedExcept if queue is empty. */
        ItemType peekFront() const throw(PrecondViolatedExcept);
};  // end ArrayQueue

#include "ArrayQueue.cpp"
#endif