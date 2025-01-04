#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "Menu.h"
using namespace std;

class Board {
    private:
        //棋盘大小:15*15
        int boardSize = board_size;
        //当前玩家
        char player = 'X';
    public:
        //棋盘
        vector<vector<char>> board;
        //棋盘图案
        char pattern = '.';
        //设置先手
        void setPlayer();
        //初始化棋盘
        void newBoard();
        //打印棋盘
        void printBoard();
        //判断是否获胜
        bool checkWin();
        //展示玩家
        char showPlayer(){return player;};
        //展示棋盘大小
        int showBoardSize(){return boardSize;};
};

#endif