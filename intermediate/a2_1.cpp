//
//  Javier Hernandez Requena
//  CS 110B
//  Dave Harden
//  a2_1.cpp
//
//  Created on 9/21/2021
//
//  This program plays a game of Blackjack.
//
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    
    int card1, card2;
    int total = 0;
    char gameChoice = 'y';
    char cardChoice;
   
    while (gameChoice == 'y' || gameChoice == 'Y'){
        card1 = rand() % 10 + 1;
        card2 = rand() % 10 + 1;
        total = card1 + card2;
        
        cout << "Your cards: " << card1 << ", " << card2 << endl;
        cout << "Total: " << total << endl;
        
        cout << "Another card? (y/n)" << endl;
        cin >> cardChoice;
        
        if (cardChoice == 'y' || cardChoice == 'Y'){
            int anotherCard = rand() % 10 + 1;
            cout << "Card: " << anotherCard << endl;
            total += anotherCard;
            cout << "Total: " << total << endl;
            
            if (total == 21){
                cout << "Congratulations!" << endl;
            } else if (total > 21){
                cout << "Bust!" << endl;
            }
            
            while (total < 21){
                cout << "Another card? (y/n)" << endl;
                cin >> cardChoice;
                
                if (cardChoice == 'y' || cardChoice == 'Y'){
                    cout << "Card: " << anotherCard << endl;
                    total += anotherCard;
                    cout << "Total: " << total << endl;
                    
                    if (total == 21){
                        cout << "Congratulations!" << endl;
                    } else if (total > 21){
                        cout << "Bust" << endl;
                    }                }
            }
            
        } else if (cardChoice == 'n' || cardChoice == 'N'){
            cout << "Your total is: " << total << endl;
        } else {
            cout << "Please enter y or n." << endl;
        }
    
        cout << "Do you want to play again? (y/n)" << endl;
        cin >> gameChoice;
        if (gameChoice == 'n' || gameChoice == 'N'){
            cout << "Thanks for playing!" << endl;
        }
    }
    
    
    return 0;
}


/*
 
 Program Output:

 Your cards: 9, 2
 Total: 11
 Another card? (y/n)
 y
 Card: 8
 Total: 19
 Another card? (y/n)
 y
 Card: 8
 Total: 27
 Bust
 Do you want to play again? (y/n)
 y
 Your cards: 8, 3
 Total: 11
 Another card? (y/n)
 y
 Card: 4
 Total: 15
 Another card? (y/n)
 y
 Card: 4
 Total: 19
 Another card? (y/n)
 y
 Card: 4
 Total: 23
 Bust
 Do you want to play again? (y/n)
 y
 Your cards: 8, 4
 Total: 12
 Another card? (y/n)
 y
 Card: 9
 Total: 21
 Congratulations!
 Do you want to play again? (y/n)
 y
 Your cards: 9, 8
 Total: 17
 Another card? (y/n)
 n
 Your total is: 17
 Do you want to play again? (y/n)
 n
 Thanks for playing!
 Program ended with exit code: 0
 
 */
