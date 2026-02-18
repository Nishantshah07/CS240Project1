//
// Created by Braden Guliano on 2/10/26.
//

#include "helper_functions.h"

#include <iostream>
#include <cmath>
//used for array parsing
#include <algorithm>
#include <iterator>
#include <string>
using std::cout;
using std::endl;
using std::cin;

void askGameSettings(int &num_rounds, int &time_per_round) {//game settings
    cout << "First, let's set up the game." << endl;
    num_rounds = 0;
    time_per_round = 0;

    while (num_rounds <= 0) {
        cout << "Enter the number of rounds: ";
        cin >> num_rounds;
    }

    while (time_per_round <= 0) {
        cout << "Enter the time each player gets per round (secs): ";
        cin >> time_per_round;
    }
}

void askPlayerSettings(int &num_players, string player_names[], const int player_names_size) {
    cout << "\nNext, let's determine the players." << endl;
    num_players = 0;

    while (num_players <= 0 || num_players > player_names_size) {
        cout << "Enter the number of players: ";
        cin >> num_players;

        if (num_players > player_names_size)
            cout << "You cannot have more than " << player_names_size << " players." << endl;
    }

    for (int i = 0; i < num_players; i++) {
        cout << "Enter the name for player " << i + 1 << ": ";
        cin >> player_names[i];
    }
}

int perform_op(int n1, int n2, char op) {//performs the given operation on the two numbers
    switch (op) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        case '%':
            return n1 % n2;
        case '^':
            return static_cast<int>(pow(n1, n2));
        default:
            cout << "Invalid operator entered: " << op << endl;
            return -1;
    }
}

bool expressionIsInOrder(char op1, char op2) {//returns true if op1 takes precedent over op2
    char ops[] = {'+', '-', '*', '/', '%', '^'};
    int precedence[] = {0, 0, 1, 1, 1, 2};

    int op1_idx = std::find(std::begin(ops), std::end(ops), op1) - ops;
    int op2_idx = std::find(std::begin(ops), std::end(ops), op2) - ops;

    return precedence[op1_idx] >= precedence[op2_idx];
}

int evaluateExpression(int n1, int n2, int n3, char op1, char op2) {
    int result;
    if (expressionIsInOrder(op1, op2)) {
        result = perform_op(n1, n2, op1);
        result = perform_op(result, n3, op2);
    } else {
        result = perform_op(n2, n3, op2);
        result = perform_op(n1, result, op1);
    }

    return result;
}

void explainEvaluation(int n1, int n2, int n3, char op1,
                       char op2) {//explains how the expression is evaluated step by step
    int result = evaluateExpression(n1, n2, n3, op1, op2);

    if (expressionIsInOrder(op1, op2)) {
        // example: 1 * 2 + 3
        // * comes before +, therefore the expression becomes (1 * 2) + 3
        cout << op1 << " comes before " << op2 << ", therefore the expression becomes ("
                << n1 << " " << op1 << " " << n2 << ") " << op2 << " " << n3 << endl;

        // (1 * 2) + 3 = 2 + 3
        int ls = perform_op(n1, n2, op1);
        cout << "(" << n1 << " " << op1 << " " << n2 << ") " << op2 << " " << n3 << " = "
                << ls << " " << op2 << " " << n3 << endl;

        // finally, 2 + 3 = 5
        cout << "Finally, " << ls << " " << op2 << " " << n3 << " = " << result << endl;
    } else {
        // example: 1 + 2 * 3
        // * comes before +, therefore the expression becomes 1 + (2 * 3)
        cout << op2 << " comes before " << op1 << ", therefore the expression becomes "
                << n1 << " " << op1 << " (" << n2 << " " << op2 << " " << n3 << ")" << endl;

        // 1 + (2 * 3) = 1 + 6
        int rs = perform_op(n2, n3, op2);
        cout << n1 << " " << op1 << " (" << n2 << " " << op2 << " " << n3 << ")" << " = "
                << n1 << " " << op1 << " " << rs << endl;

        // finally, 1 + 6 = 7
        cout << "Finally, " << n1 << " " << op1 << " " << rs << " = " << result << endl;
    }
}

void printExpression(int n1, int n2, int n3, char op1, char op2) {
    cout << n1 << " " << op1 << " " << n2 << " " << op2 << " " << n3;
}

bool checkTime(int current_time, int max_time, int &elapsed_time) {
    elapsed_time = time(0) - current_time;
    return elapsed_time < max_time;
}

void
generateExpression(int &x, int &y, int &z, char &a,
                   char &
                   b) {//generates a random expression with 3 numbers and 2 operators, ensuring that the expression is valid
    x = rand() % (10);
    y = rand() % (10);
    z = rand() % (10);
    char operands[6] = {'+', '-', '*', '/', '%', '^'};
    a = operands[rand() % 6];
    b = operands[rand() % 6];
    if (a == '/' || a == '%') {
        if (y == 0)
            y = 1;
        if (y > x && x != 0)
            y = x;

        while (y > 1 && x % y != 0) {
            y--;
        }
    }
    if (b == '/' || b == '%') {
        if (z == 0 && y != 0)
            z = 1;
        if (z > y)
            z = y;

        while (z > 1 && y % z != 0) {
            z--;
        }
    }

    if (a == '^' && b == '^') {
        b = '+';
    }

    if (a == '^' && y > 3) {
        y = 3;
    }

    if (b == '^' && z > 3) {
        z = 3;
    }
}

void displayScoreboard(std::string playerNames[], int scores[],
                       int numPlayers) {//displays the scoreboard and announces the winner

    if (numPlayers <= 0) {
        cout << "No players." << endl;
        return;
    }

    int maxScore = scores[0];

    // Print each player's score and find max
    for (int i = 0; i < numPlayers; i++) {
        cout << playerNames[i]
                << ": " << scores[i] << endl;

        if (scores[i] > maxScore) {
            maxScore = scores[i];
        }
    }

    // Count how many players have max score
    int winnerCount = 0;
    for (int i = 0; i < numPlayers; i++) {
        if (scores[i] == maxScore) {
            winnerCount++;
        }
    }

    // Announce winner(s)
    if (winnerCount == 1) {
        for (int i = 0; i < numPlayers; i++) {
            if (scores[i] == maxScore) {
                cout << "Winner: "
                        << playerNames[i]
                        << " with "
                        << maxScore
                        << " points."
                        << endl;
            }
        }
    } else {
        cout << "Tie between: ";
        for (int i = 0; i < numPlayers; i++) {
            if (scores[i] == maxScore) {
                cout << playerNames[i] << " ";
            }
        }
        cout << "with "
                << maxScore
                << " points."
                << endl;
    }
}
