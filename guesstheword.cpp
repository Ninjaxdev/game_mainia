#include <iostream>
#include <ctime>
#include <string>
#include "guess_the_word.h"
using namespace std;

const int MAX_TRIES = 5;

int letterFill(char guess, string secretword, string& guessword)
{
    int matches = 0;
    for (size_t i = 0; i < secretword.length(); i++) {
        if (guess == guessword[i])
            return 0;
        if (guess == secretword[i]) {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}

void playGuessTheWord() {
    string yes_or_no;

    do {
        string hint, word;
        string words[] = {
            "mexico", "france", "italy", "southafrica", "japan",
            "australia", "egypt", "singapore", "china", "turkey"
        };

        srand(time(NULL));
        int n = rand() % 10;
        word = words[n];

        switch (n) {
            case 0: hint = "Hint: This country shares a border with the USA";
            break;
            case 1: hint = "Hint: This country has the Eiffel tower"; 
            break;
            case 2: hint = "Hint: This country has the city called Rome";
             break;
            case 3: hint = "Hint: The country where Nelson Mandela was born";
             break;
            case 4: hint = "Hint: The country where anime was created"; 
            break;
            case 5: hint = "Hint: This country has kangaroos"; 
            break;
            case 6: hint = "Hint: This country has giant pyramids"; 
            break;
            case 7: hint = "Hint: This country has Changi Airport"; 
            break;
            case 8: hint = "Hint: This country has Beijing"; 
            break;
            case 9: hint = "Hint: This country has Istanbul";
             break;
        }

        string unknown(word.length(), '_');
        int num_of_wrong_guesses = 0;
        char letter;

        cout << "\n\n Welcome to Guess the Country!\n";
        cout << "Each letter is represented by an underscore.\n";
        cout << "You have " << MAX_TRIES << " tries.\n";

        while (num_of_wrong_guesses < MAX_TRIES) {
            cout << "\n" << hint << endl;
            cout << "\nCurrent Word: " << unknown << endl;
            cout << "Guess a letter: ";
            cin >> letter;

            if (letterFill(letter, word, unknown) == 0) {
                cout << "That letter isn't in there!\n";
                num_of_wrong_guesses++;
            } else {
                cout << " You found a letter!\n";
            }

            cout << "Tries left: " << MAX_TRIES - num_of_wrong_guesses << endl;

            if (word == unknown) {
                cout << "\n You got it! The word was: " << word << endl;
                break;
            }
        }

        if (word != unknown) {
            cout << "\n You lost. The word was: " << word << endl;
        }

        cout << "\n Would you like to play again? (yes/no): ";
        cin >> yes_or_no;

    } while (yes_or_no == "yes");
}
