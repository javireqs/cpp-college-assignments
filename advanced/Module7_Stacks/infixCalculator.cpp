// Javier Hernandez Requena
// CS 110 C - Data Structures & Algorithms in C++
// Max Lutrell
// Module 7 HW - Calculator
// @file - infixCalculator.cpp
// @desc - simple stack calculator which can compute an infix expression

#include <iostream>
#include <string>

using namespace std;

char precedence[5][2] = {{'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

class CharStack
{
    private:
        static const int MAX = 20;
        char items[MAX];
        int top;

    public:
        CharStack();
        bool isEmpty() const;
        bool push(const char& newEntry);
        bool pop();
        char peek() const;
}; // end CharStack

CharStack() : top(-1)
{
} // end default constructor

bool isEmpty() const
{
    return top < 0;
} // end isEmpty

bool push(const char& newEntry)
{
    bool result = false;

    if (top < MAX - 1)
    {
        top++;
        items[top] = newEntry;
        result = true;
    } // end if

    return result;
} // end push

bool pop()
{
    bool result = false;

    if (!isEmpty())
    {
        top--;
        result = true;
    } // end if

    return result;
} // end pop

char peek() const
{
    return items[top];
}

string convert2Postfix (string infix)
{
    string postfixExp = "";
    int i;
    char ch = infix[i];

} // end convert2Postfix

int evalPostfix(string postfix)
{

} // end evalPostfix

int main()
{

}



