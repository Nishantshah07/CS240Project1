//
// Created by Nishant Shah on 2/10/26.
//
#include "nishant_functions.h"
#include <iostream>
#include<cstdlib>
using std::cout;
using std::endl;
using std::cin;


void generateExpression(int &x, int &y, int &z, char &a, char &b) {
	x = rand() % (10);
	y = rand() % (10);
	z = rand() % (10);
	char operands[5] = {'+', '-', '*', '/', '%', '^'};
	a = operands[rand() % 6];
	b = operands[rand() % 6];
    if(a=='/'){
        if(y==0)
            y = 1;
        if(y > x)
            y = x;

    while(y > 1 && x % y != 0){
        y--;
        }
    }
    if(b=='/'){
        if(z==0)
            z = 1;
        if(z > y)
            z = y;

    while(z > 1 && y % z != 0){
        z--;
        }
    }
}

void displayScoreboard(int scores[], int numPlayers){

    if(numPlayers <= 0){
        cout << "No players." << endl;
        return;
    }

    int maxScore = scores[0];

    for(int i = 0; i < numPlayers; i++){
        cout << "Player " << i + 1 
             << ": " << scores[i] << endl;

        if(scores[i] > maxScore){
            maxScore = scores[i];
        }
    }

    int winnerCount = 0;
    for(int i = 0; i < numPlayers; i++){
        if(scores[i] == maxScore){
            winnerCount++;
        }
    }

    if(winnerCount == 1){
        for(int i = 0; i < numPlayers; i++){
            if(scores[i] == maxScore){
                cout << "Winner: Player " << i + 1
                     << " with " << maxScore 
                     << " points." << endl;
            }
        }
    }
    else{
        cout << "Tie between players: ";
        for(int i = 0; i < numPlayers; i++){
            if(scores[i] == maxScore){
                cout << i + 1 << " ";
            }
        }
        cout << "with " << maxScore 
             << " points." << endl;
    }
}

