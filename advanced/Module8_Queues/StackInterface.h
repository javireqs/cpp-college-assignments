/** @file StackInterface.h */
#ifndef STACK_INTERFACE_
#define STACK_INTERFACE_

template<class ItemType>
class StackInterface
{
    public:
        /** Checks whether stack is empty.
         * @return True if the stack is empty, false if not. */
        virtual bool isEmpty() const = 0;

        /** Adds a new entry to top of the stack.
         * @post If successful, newEntry is at the top of the stack.
         * @param newEntry The object to be added as a new entry.
         * @return True if the addition was successful, false if not. */
        virtual bool push(const ItemType& newEntry) = 0;

        /** Removes the top of the stack.
         * @post If successful, the top of the stack has been removed.
         * @return True if the removal was successful, false if not. */
        virtual bool pop() = 0;

        /** Returns a copy of the top of the stack.
         * @pre The stack is not empty.
         * @post A copy of the top of the stack has been returned, and the stack is unchanged.
         * @return A copy of the top of the stack. */
        virtual ItemType peek() const = 0;

        /** Destroys the stack and frees its memory. */
        virtual ~StackInterface() { }
}; // end StackInterface


#endif