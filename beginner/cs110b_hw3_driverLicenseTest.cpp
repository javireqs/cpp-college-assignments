/* 
Javier Hernandez Requena
June 25, 2022
CS 110 B - C++ Programming Fundamentals
Assignement 3 - Driver License Test
This program grades the written portion of the driver license exam using arrays, for-loops, and if-else statement.
*/

#include <iostream>
#include <array>
using namespace std;

#define SIZE 20

char testAnswersCapital[SIZE] = { 'B', 'D', 'A', 'A', 'C', 'A', 'B', 'A', 'C', 'D', 'B', 'C', 'D', 'A', 'D', 'C', 'C', 'B', 'D', 'A' };
char testAnswersLowercase[SIZE] = { 'b', 'd', 'a', 'a', 'c', 'a', 'b', 'a', 'c', 'd', 'b', 'c', 'd', 'a', 'd', 'c', 'c', 'b', 'd', 'a' };
char studentAnswers[SIZE];


void driverTest(char studentAnswers[])
{
    float correctAnswers = 0; //accumulator variable

    for (int i=0; i<SIZE; i++)
    {   
        if (studentAnswers[i] == testAnswersCapital[i] || studentAnswers[i] == testAnswersLowercase[i])
        {
            correctAnswers += 1;
        }   
    }
    if (correctAnswers >= 15)
        {
            cout << "\n\nStudent passed!\n";
        }
    else
    {
        cout << "\n\nStudent did not pass.\n";
    }

    float percentage = (correctAnswers/20) * 100;

    cout << "Student got " << correctAnswers << " out of 20 answers correct, for a total score of " << percentage << " percent.\n";
}


int main()
{
    cout << "\n\nPlease enter the student's answers:\n\n";
    for (int i = 0; i < SIZE; i++)
    {
       cin >> studentAnswers[i];
    }
    driverTest(studentAnswers);
    return 0;
}