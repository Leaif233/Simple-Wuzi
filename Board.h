#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include "Menu.h"
using namespace std;

class Board {
    private:
        //���̴�С:15*15
        int boardSize = board_size;
        //��ǰ���
        char player = 'X';
    public:
        //����
        vector<vector<char>> board;
        //����ͼ��
        char pattern = '.';
        //��������
        void setPlayer();
        //��ʼ������
        void newBoard();
        //��ӡ����
        void printBoard();
        //�ж��Ƿ��ʤ
        bool checkWin();
        //չʾ���
        char showPlayer(){return player;};
        //չʾ���̴�С
        int showBoardSize(){return boardSize;};
};

#endif