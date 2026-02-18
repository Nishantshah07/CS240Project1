//
// Created by Braden Guliano on 2/10/26.
//

#ifndef BRADEN_FUNCTIONS_H_
#define BRADEN_FUNCTIONS_H_

#include <string>
using std::string;

void askGameSettings(int &num_rounds, int &time_per_round);

void askPlayerSettings(int &num_players, string player_names[], int player_names_size);

bool expressionIsInOrder(char op1, char op2);

int evaluateExpression(int n1, int n2, int n3, char op1, char op2);

void explainEvaluation(int n1, int n2, int n3, char op1, char op2);

void printExpression(int n1, int n2, int n3, char op1, char op2);

bool checkTime(int current_time, int max_time, int &elapsed_time);

void generateExpression(int &x, int &y, int &z, char &a, char &b);

void displayScoreboard(std::string playerNames[], int scores[], int numPlayers);


#endif //BRADEN_FUNCTIONS_H_
