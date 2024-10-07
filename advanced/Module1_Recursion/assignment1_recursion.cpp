// Javier Hernandez Requena
// CS 110c - C++ Data Structures & Algorithms
// Max Lutrell
// August 28, 2022
// Program: Recursion
// Desc: Recursive Functions

#include <iostream>
#include <string>
using namespace std;


// Prompt 1 - Write a recursive C++ function that writes the digits of a positive decimal integer in reverse order

// reverseInteger - writes digits of a positive decimal integer in reverse order
// @pre - n > 0
// @post - none
// @param - n is a positive integer
// @return - n reversed
void reverseInteger(int n)
{
    if (n < 10)     // base case
        cout << n;
    else
    {
        cout << (n%10);     // write the digit in the 10th's place
        reverseInteger(n/10);   // recursive call (drop digit in 10th's place)
    }
}


// Prompt 2 - Rewrite both of the functions writeBackward and writeBackward2 in section 2.3.1 of the text (page 61 in both the 6th and 7th edition) as C++ functions
// Make sure you include all of the cout statements in these functions which indicate function entry, function exit, and about to write a character.

// writeBackward
// @pre - s is a string
// @post - none
// @param - s is a string
// @return - s written backwards
void writeBackward(string s)
{
    int length = s.size();      // hold length of string

    cout << "Enter writeBackward with string: " << s << endl;       // function entry
    if (length > 0)     // base case (do nothing)
    {
        cout << "About to write last character of string: " << s << endl;   // about to write a character
        cout << s[length - 1];      // write the LAST character of string
        writeBackward(s.substr(0, length - 1));     // recursive call on string minus the LAST character
    }
    cout << "Leave writeBackward with string: " << s << endl;       // function exit
}

// writeBackward2
// @pre - s is a string
// @post - none
// @param - s is a string
// @return - s written backwards
void writeBackward2(string s)
{
    int length = s.size();      // hold length of string

    cout << "Enter writeBackward2 with string: " << s << endl;       // function entry
    if (length > 0)     // base case (do nothing)
    {
        writeBackward2(s.substr(1, length - 1));     // recursive call on string minus the FIRST character
        cout << "About to write first character of string: " << s << endl;   // about to write a character
        cout << s[0];      // write the FIRST character of string
    }
    cout << "Leave writeBackward2 with string: " << s << endl;       // function exit
}


// Prompt 3 -  Chapter 2, exercise 4: Given two integers, start and end, where end is greater than start, 
// write a recursive C++ function that returns the sum of the integers from start through end, inclusive.
// For example, if start is 3 and end is 6, the function should return 18, because 3+4+5+6 = 18.

// sumOfIntegers
// @pre - start is less than end
// @post - unchanged
// @param - int start, int end
// @return - inclusive sum of integers from start to end
int sumOfIntegers(int start, int end)
{   
    if (start == end)   // base case (once start is equal to end, return end)
    {
        return end;
    } 
    return sumOfIntegers(start + 1, end) + start;   // recursive call 
}


int main()
{
    // Variables to hold inputs
    int n;
    int start;
    int end;
    string s;

    // reverseInteger prompt - asks user for integer to be reversed
    cout << "Enter an integer to be reversed: ";
    cin >> n;
    cout << "Integer Reversed: ";
    reverseInteger(n);
    cout << endl << endl;

    // writeBackward & writeBackward2 prompt - asks user to input a string, ending it with '*' as a delimiter
    cout << "Enter a string to be written backwards (Type '*' & hit 'Enter' to end string): ";
    getline(cin, s, '*');
    cout << "\n\nwriteBackward:\n\n";
    writeBackward(s);
    cout << "\n\nwriteBackward2:\n\n";
    writeBackward2(s);
    cout << endl << endl;

    // sumOfIntegers prompt - asks user for two integers, 'start' & 'end', where 'end' is greater than 'start'
    cout << "Enter two digits, 'start' & 'end', where 'end' is greater than 'start':\n";
    cout << "Start: ";
    cin >> start;
    cout << "End: ";
    cin >> end;
    cout << "\nInclusive Sum of Integers from " << start << " to " << end << ": " << sumOfIntegers(start, end) << endl << endl;

    return 0;
}
