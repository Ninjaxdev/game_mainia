// Rock-Paper-Scissors

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "rsp.h"
using namespace std;

char getComputerMove()
{
    int move;
    // generating random number between 0 - 2
    srand(time(NULL));
    move = rand() % 3;

    if (move == 0) {
        return 'p';
    }
    else if (move == 1) {
        return 's';
    }
    return 'r';
}

int getResults(char playerMove, char computerMove)
{
    if (playerMove == computerMove) 
          return 0;
    
    if (playerMove == 's' && computerMove == 'p') 
         return 1;
   
    if (playerMove == 's' && computerMove == 'r') 
        return -1;
    
    if (playerMove == 'p' && computerMove == 'r') 
        return 1;
    
    if (playerMove == 'p' && computerMove == 's') 
        return -1;
    
    if (playerMove == 'r' && computerMove == 'p') 
        return -1;
    
    if (playerMove == 'r' && computerMove == 's') 
        return 1;
    
    
    return 0;
}

void playrsp()
{
   int choice;
   do
   {char playerMove;
    cout <<"Welcome to Stone Paper Scissor Game"<<endl;
    cout << "Enter r for ROCK, p for PAPER & s for SCISSOR"<<endl;

    while(1) {
        cin >> playerMove;
        if (playerMove == 'p' || playerMove == 'r' || playerMove == 's') 
             break;
        else 
            cout << "Invalid Move"<< endl;
              }
   char computerMove = getComputerMove();
   int result = getResults(playerMove, computerMove);
   if (result == 0) 
   {
        cout << "Game Draw!\n";
    }
    else if (result == 1) {
        cout <<"Congratulations! you win "<<endl;
    }
    else {
        cout << "Computer win"<<endl;
    }
    cout << "your Move: " << playerMove << endl;
    cout << "Computer's Move: " << computerMove << endl;
    cout<<"\nWanna play again?? press->1 to continue or press 0->exit:";
    cin>>choice;
    }while(choice==1);
}
