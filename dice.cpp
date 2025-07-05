#include <iostream>
#include <ctime>
#include <random>
#include "dice.h"
using namespace std;

void playDice()
{
    srand(time(0));
    int num, bet, bet_no, win_amount = 0, total_winnings = 0;
    char choice;

    cout << "Welcome to Game Mainia!" << endl;

    do {
        num = (rand() % 6) + 1; 
        cout << "Place your bet on a number (1 to 6): ";
        cin >> bet_no;

        if (bet_no < 1 || bet_no > 6) {
            cout << "Invalid bet number. Please enter a number between 1 and 6." << endl;
            continue;
        }

        cout << "Enter your bet amount: ";
        cin >> bet;

        if (bet_no == num) {
            win_amount = 2 * bet;
            total_winnings += win_amount;
            cout << "Congratulations! You win!" << endl;
            cout << "You won: " << win_amount << endl;
        } else {
            cout << "You lose!" << endl;
            cout << "Your bet number was: " << bet_no << "\tDice number is: " << num << endl;
        }

        cout << "Your total winnings: " << total_winnings << endl;
        cout << "Do you want to cashout your winnings? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "You have cashed out " << total_winnings << "!" << endl;
            total_winnings = 0;
            break;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for playing Luck Mania!" << endl;
    cout << "Your final winnings: " << total_winnings << endl;
}
