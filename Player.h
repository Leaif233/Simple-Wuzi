#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <vector>
using namespace std;
class  Player
{   private:
    public:
        void record(string winner,char winner_char,string loser,char loser_char);
        vector<string> winner_v;
        vector<char> winner_char_v;
        vector<string> loser_v;
        vector<char> loser_char_v;
        vector<string> time_v;
};

#endif