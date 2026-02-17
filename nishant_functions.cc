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

#include "nishant_functions.h"