#include <iostream>
#include<random>
#include<ctime>
#include "guess_the_number.h"
using namespace std;

void playGuessTheNumber()
{
   int choice;
  do{
    int number;
    srand(time(0));
    cout <<"Guess the number between 0 to 100"<<endl;
    int guess = 5;
    cout<<"You have 5 guesses"<<endl;
    int n=1+rand()%100;
    while(guess!=0)
    {
      cout<<"Enter your guess :";
      cin>>number;
    if(n==number)
    {
      cout<<"Congratulations!you won"<<endl;
      break;
    }
    else
    {
      guess--;
      cout<<"you have "<<guess<<" guess left"<<endl;
    }
    }
    cout<<"Press 1 To continue or 0 to stop"<<endl;
    cin>>choice;
  } while(choice==1);
  
}