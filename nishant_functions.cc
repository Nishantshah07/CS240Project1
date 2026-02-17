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
	char operands[5] = {'+', '-', '*', '/', '%'};
	a = operands[rand() % 5];
	b = operands[rand() % 5];
}

#include "nishant_functions.h"