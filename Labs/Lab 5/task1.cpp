// Assume you are developing a program to simulate a game where players take turns
// to guess a number between 1 and 100. The program generates a random number between
// 1 and 100 at the start of the game, and the player who guesses the correct number wins
// the game. If a player guesses incorrectly, the program tells them whether their guess was
// too high or too low, and the turn passes to the next player. Solve it using Direct
// Recursion?
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void guess(int number, int player){
    cout<<"Player No."<<player<<" Turn"<<endl;

    int g;
    cout<<"Enter you guess: ";
    cin>>g;

    if(g == number){
        cout<<number<<" is the correct guess\nPlayer No."<<player<<" wins"<<endl;
        return;
    }else if(g < number){
        cout<<"Your guess is too low"<<endl;
    }else{
        cout<<"Your guess is too high"<<endl;
    }

    guess(number, ((player==1)?2:1));
}

int main(){
    srand(time(NULL));

    guess(rand()%200, 1);
}