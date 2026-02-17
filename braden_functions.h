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

void generateEvaluation(int n1, int n2, int n3, char op1, char op2);


#endif //BRADEN_FUNCTIONS_H_
