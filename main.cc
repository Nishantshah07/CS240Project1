#import <iostream>
#import "nishant_functions.h"
#import "braden_functions.h"

using std::cout;
using std::endl;
using std::cin;

// round settings
int current_round = 0;
int total_rounds;

// time settings
int max_time;
int current_clock;

// player settings
int current_player = 0;
int num_players;
int max_players = 64;
string player_names[64] = {};


int main() {
    askGameSettings(total_rounds, max_time);
    askPlayerSettings(num_players, player_names, max_players);

    return 0;
}
