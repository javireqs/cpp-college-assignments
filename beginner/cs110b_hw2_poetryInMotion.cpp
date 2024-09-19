/* 
Javier Hernandez Requena
June 19, 2022
CS 110 B - C++ Programming Fundamentals
Assignement 2 - Poetry in Motion
This program creates a poem through user-input, one line at a time using a user-conrtolled loop
*/

#include <iostream>
#include <string>
using namespace std;

void makePoem()
{
    string userInput;
    string userPoem;
    string exitPoem = "Quit";

    do
    {
        cout << "Enter one line at a time, press Enter to end line.\n";
        cout << "Type Quit to exit: ";
        getline (cin, userInput);
        if (userInput != exitPoem)
        {
            userPoem += userInput + "\n\n";
        }
    }while (userInput != exitPoem);

    cout << "Here is your poem,\n\n" << userPoem << "\n\na true masterpiece!\n\n";
}

int main()
{
    makePoem();
}
