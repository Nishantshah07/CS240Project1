#import <iostream>
#import "nishant_functions.h"
#import "braden_functions.h"

using std::cout;
using std::endl;
using std::cin;

// round settings
int total_rounds;

// time settings
int max_time;  // in seconds
int current_clock;
int total_round_time = 0;

// player settings
int num_players;
const int max_players = 64;
string player_names[max_players];
int scoreboard[max_players];

// round vars
int n1, n2, n3;
char op1, op2;
int playerAnswer;
int actualAnswer;
bool completedRoundOnTime = false;
int elapsedTime;


int main() {
    // this program uses random data, so set psuedorandom seed
    srand(time(0));

    // preload scoreboard
    for (int i = 0; i < max_players; i++) {
        scoreboard[i] = 0;
    }

    cout << "Welcome to the ______ game!\n" << endl;

    askGameSettings(total_rounds, max_time);
    askPlayerSettings(num_players, player_names, max_players);

    for (int current_player = 0; current_player < num_players; current_player++) {
        cout << player_names[current_player] << ", you're up!" << endl;

        for (int current_round = 0; current_round < total_rounds; current_round++) {
            // start round
            cout << "Round " << current_round + 1 << "/" << total_rounds << endl;
            current_clock = clock();

            // run round
            // generate expression and give to player
            generateExpression(n1, n2, n3, op1, op2);
            cout << player_names[current_player] << ", please give the answer to ";
            printExpression(n1, n2, n3, op1, op2);
            cout << ": ";

            // check answer
            cin >> playerAnswer;
            completedRoundOnTime = checkClock(current_clock, max_time, elapsedTime);
            actualAnswer = evaluateExpression(n1, n2, n3, op1, op2);
            if (playerAnswer == actualAnswer) {
                cout << "That is correct! ";
                if (completedRoundOnTime) {
                    cout << "+1 points." << endl;
                    scoreboard[current_player]++;
                } else {
                    cout << "But...you took " << max_time - elapsedTime << " too long. No points awarded." << endl;
                }
            } else {
                cout << "Wrong answer! No points awarded. Here's how you should have solved it: " << endl;
                explainEvaluation(n1, n2, n3, op1, op2);
            }

            // end round
            cout << player_names[current_player] << ", you currently have " << scoreboard[current_player] << " points."
                    << endl;
        }
    }

    // cout << "Game over! The current scores are:" << endl;
    // printScoreboard(player_names, scoreboard, num_players);
    //
    // int winner = determineWinner(scoreboard, num_players);
    // cout << player_names[winner] << ", you win!" << endl;

    return 0;
}
