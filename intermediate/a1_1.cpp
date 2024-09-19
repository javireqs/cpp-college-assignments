//
//  a1_1.cpp
//  CS 110B w/ David Harden
//
//  Created by Javier Hernandez Requena
//  9/6/2021
//
//  This program allows the user to input a date and returns
//  whether the date is "magic" or not.
//


#include <iostream>
using namespace std;

int main()
{
    int month;
    int day;
    int year;
    char tempChar;
    
    cout << "Enter a date in the format month/day/2-digit year: ";
    cin >> month >> tempChar >> day >> tempChar >> year;
    
    if (month * day == year) {
        cout << "That's a magic date!\n";
    } else {
        cout << "That's a normal date.\n";
    }
    
    return 0;
}

/*
 (sample code output)
 Enter a date in the format month/day/2-digit year: 6/10/60
 That's a normal date.
 Program ended with exit code: 0
 (if statement not working properly)
 */
