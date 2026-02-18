#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "nishant_functions.h"
#include "braden_functions.h"


using std::cout;
using std::endl;
using std::cin;

int main() {
    // round settings
    int total_rounds;

    // time settings
    int max_time;  // in seconds

    // player settings
    int num_players;
    const int max_players = 64;
    std::string player_names[max_players];
    int scoreboard[max_players];

    // round vars
    int n1, n2, n3;
    char op1, op2;
    double player_answer;
    int actual_answer;
    bool completed_round_on_time = false;
    int elapsed_time_per_round;


    // this program uses random data, so set psuedorandom seed
    srand(time(0));

    // preload scoreboard
    for (int i = 0; i < max_players; i++) {
        scoreboard[i] = 0;
    }

    cout << "Welcome to the multiplayer math game!\n" << endl;

    askGameSettings(total_rounds, max_time);
    askPlayerSettings(num_players, player_names, max_players);

    for (int current_player = 0; current_player < num_players; current_player++) {
        cout << "\n" << player_names[current_player] << ", you're up!" << endl;
        int round_start_time = time(0);

        for (int current_round = 0; current_round < total_rounds; current_round++) {
            // start round
            cout << "\nRound " << current_round + 1 << "/" << total_rounds << endl;
            int current_time = time(0);

            // run round
            // generate expression and give to player
            generateExpression(n1, n2, n3, op1, op2);
            cout << player_names[current_player] << ", please give the answer to ";
            printExpression(n1, n2, n3, op1, op2);
            cout << ": ";

            // check answer
            cin >> player_answer;

            completed_round_on_time = checkTime(current_time, max_time, elapsed_time_per_round);
            actual_answer = evaluateExpression(n1, n2, n3, op1, op2);
            if (player_answer == static_cast<int>(player_answer) && static_cast<int>(player_answer) == actual_answer) {
                cout << "That is correct! ";
                if (completed_round_on_time) {
                    cout << "+1 points. You answered in " << elapsed_time_per_round << " seconds." << endl;
                    scoreboard[current_player]++;
                } else {
                    cout << "But...you took " << elapsed_time_per_round - max_time <<
                            " seconds too long. No points awarded." << endl;
                }
            } else {
                cout << "Wrong answer! No points awarded. Here's how you should have solved it: " << endl;
                explainEvaluation(n1, n2, n3, op1, op2);
            }
        }

        // end round
        int elapsed_time_total_round = time(0) - round_start_time;
        cout << player_names[current_player] << ", it took you " << elapsed_time_total_round <<
                " seconds and you currently have " << scoreboard[current_player] << " points." << endl;
    }

    cout << "Game over! The current scores are:" << endl;
    displayScoreboard(player_names, scoreboard, num_players);
    //
    // int winner = determineWinner(scoreboard, num_players);
    // cout << player_names[winner] << ", you win!" << endl;

    return 0;
}
