#include <iostream>
#include <cstdlib>
#include "rsp.h"
#include "guess_the_number.h"
#include "guess_the_word.h"
#include "dice.h"
using namespace std;

void showMenu() {
    cout << "\n================ GAME MAINIA ================\n";
    cout << "1. Rock Paper Scissors\n";
    cout << "2. Guess the Number\n";
    cout << "3. Guess the Word\n";
    cout << "4. Bet the Dice\n";
    cout << "5. Exit\n";
    cout << "===========================================\n";
    cout << "Choose a game (1-5): ";
}

int main() 
{
    int choice;
    cout<<"enter your choice :";
    while (1)
     {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
            case 1: playrsp();
            break;
            case 2: playGuessTheNumber();
            break;
            case 3: playGuessTheWord();
            break;
            case 4: playDice();
            break;
            case 5: cout << "Thanks for playing Game Mania!\n";
            return 0;
            default: cout << "Invalid choice. Try again.\n"; 
            break;
        }
    }
    return 0;
}
