/* 
Javier Hernandez Requena
June 15, 2022
CS 110 B - C++ Programming Fundamentals
Assignement 1 - The Everything Calculator
This program takes in parameters and gives a return statement that performs calculations on any numbers
*/

#include <cmath>
#define _USE_MATH_DEFINES
#include <iostream>
using namespace std;

// function to determine inflation - i.e. how much purchasing power does the presentAmount hold vs a futureAmount after a numberOfYears, given inflationRate? 

// formula: future amount = present amount * (1 + inflation rate) ** number of years
float inflationFutureValue(float presentAmount, float inflationRate, float numberOfYears, float& futureAmount)
{

    return futureAmount = presentAmount * pow(1 + (inflationRate/100), numberOfYears);

}

// Simone Christen's function for pounds-to-kilograms formula
float pounds2kilos(float pounds)
{
    float kg = pounds*0.45359237; // conversion formula to take pounds parameter to convert to kilos
    return kg;
}

// Rong Chen's function for feet-to-meters formula
float calcFeetToMeters(float feet)
{
    float meters;
  
    meters = feet * 0.3048;
    return meters;
}

int main()
{
    // My formula
    float futureAmount = 0;
    cout << "You would need " << inflationFutureValue(100, 8, 2, futureAmount) << " of your currency to have equal purchasing power of your present amount." << endl;
    
    // Simone's formula
    cout << "25 pounds equals " << pounds2kilos(25) << " kilos. Formula function provided by Simone Christen." << endl;

    // Rong's formula
    cout << "100 feet equals " << calcFeetToMeters(100) << " meters. Formula function provided by Rong Chen." << endl;

}



/* 

PROGRAM OUTPUT:

You would need 116.64 of your currency to have equal purchasing power of your present amount.
25 pounds equals 11.3398 kilos. Formula function provided by Simone Christen.
100 feet equals 30.48 meters. Formula function provided by Rong Chen.

*/