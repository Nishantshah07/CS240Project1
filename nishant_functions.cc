//
// Created by Nishant Shah on 2/10/26.
//
#include "nishant_functions.h"
#include <iostream>
#include<cstdlib>
using std::cout;
using std::endl;
using std::cin;


void generateExpression(int &x, int &y, int &z, char &a, char &b) {//generates a random expression with 3 numbers and 2 operators, ensuring that the expression is valid 
	x = rand() % (10);
	y = rand() % (10);
	z = rand() % (10);
	char operands[6] = {'+', '-', '*', '/', '%', '^'};
	a = operands[rand() % 6];
	b = operands[rand() % 6];
    if(a=='/' || a=='%'){
        if(y==0)
            y = 1;
        if(y > x && x != 0)
            y = x;

    while(y > 1 && x % y != 0){
        y--;
        }
    }
    if(b=='/' || b=='%'){
        if(z==0 && y != 0)
            z = 1;
        if(z > y)
            z = y;

    while(z > 1 && y % z != 0){
        z--;
        }
    }

    if(a == '^' && b == '^'){
        b = '+';
    }

    if(a == '^' && y>3){
        y = 3;
    }

    if(b == '^' && z>3){
        z = 3;
    }
}

void displayScoreboard(std::string playerNames[], int scores[], int numPlayers){//displays the scoreboard and announces the winner

    if(numPlayers <= 0){
        cout << "No players." << endl;
        return;
    }

    int maxScore = scores[0];

    // Print each player's score and find max
    for(int i = 0; i < numPlayers; i++){
        cout << playerNames[i] 
             << ": " << scores[i] << endl;

        if(scores[i] > maxScore){
            maxScore = scores[i];
        }
    }

    // Count how many players have max score
    int winnerCount = 0;
    for(int i = 0; i < numPlayers; i++){
        if(scores[i] == maxScore){
            winnerCount++;
        }
    }

    // Announce winner(s)
    if(winnerCount == 1){
        for(int i = 0; i < numPlayers; i++){
            if(scores[i] == maxScore){
                cout << "Winner: " 
                     << playerNames[i]
                     << " with " 
                     << maxScore 
                     << " points." 
                     << endl;
            }
        }
    }
    else{
        cout << "Tie between: ";
        for(int i = 0; i < numPlayers; i++){
            if(scores[i] == maxScore){
                cout << playerNames[i] << " ";
            }
        }
        cout << "with " 
             << maxScore 
             << " points." 
             << endl;
    }
}
