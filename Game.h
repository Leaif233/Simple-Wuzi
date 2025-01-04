#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"
#include <stack>
using namespace std;

//胜负记录变量
extern Player player;

void newgame();
void game();
void back(Board &Newboard,stack<int> &history,int &times,int &backname);
#endif