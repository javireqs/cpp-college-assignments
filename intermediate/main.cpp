//
//  main.cpp
//  numberGame
//
//  Created by r94 on 10/12/21.
//

#include <iostream>

using namespace std;

void playOneGame();
void getUserResponseToGuess();
int getMidpoint();


const int UPPER_BOUND = 100; // global variable for upper bound
const int LOWER_BOUND = 1;  // global variable for lower bound


int main() {
    char response;
    
    cout << "Ready to play (y/n)? ";
    cin >> response;
    while (response == 'y') {
        playOneGame();
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
}

void playOneGame() {
    
    getUserResponseToGuess();
    getMidpoint();
}



void getUserResponseToGuess(int guess, char result) {
    
    char result;
    char lower = 'l';
    char higher = 'h';
    char correct = 'c';
    int guess = 50;
    
    cout << "My guess is " << guess << ". Enter 'l', if your number is lower, 'h' if it is higher, 'c' if it is correct.";
    
    cin >> result;                                  
    
    if (result == lower){
        
    }
    else if (result == higher){
        
    }
    else if (result == correct){
        
    }
    else{
        
    }
}



void getMidpoint(int low, int high) {
    
    
    
    
}
