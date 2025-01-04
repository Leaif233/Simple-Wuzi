#include <iostream>
#include <vector>
#include "Player.h"
#include "Game.h"

using namespace std;

void Player::record(string winner,char winner_char,string loser,char loser_char){
        winner_v.push_back(winner);
        winner_char_v.push_back(winner_char);
        loser_v.push_back(loser);
        loser_char_v.push_back(loser_char);
        time_v.push_back(get_time());
    }