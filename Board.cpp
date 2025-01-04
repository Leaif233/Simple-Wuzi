#include <iostream>
#include <cstdlib>
#include <vector>
#include <iomanip>
#include "Board.h"
#include "Menu.h"
using namespace std;


//��������
void Board::setPlayer() {
    show_setplayerMenu();
    int p=0;
    cin >> p;
    switch(p){
        case 1:player = 'X';break;
        case 2:player = 'O';break;
        case 3:player = (rand() % 2 == 0)? 'X' : 'O';break;
        default:cout << "û�и�ѡ��"<<endl;exit(0);
    }
}

// ����һ����������ʼ������
void Board::newBoard() {
    if(!board.empty()){
        board.clear();
    }
    for(int i = 0; i < boardSize; ++i) {
        board.push_back(vector<char>(boardSize, pattern));
    }
}

// ����һ����������ӡ����
void Board::printBoard() {
        for(int i = -3; i < boardSize; ++i) {
        for(int j = -3; j < boardSize; ++j) {
            if(i == -3 && j >= 0){cout<<(j+1)/10<<' ';}
            else if(j == -3 && i >= 0){cout<<setw(2)<<(i+1)/10;}
            else if(i == -2 && j >= 0){cout<<(j+1)%10<<' ';}
            else if(j == -2 && i >= 0){cout<<setw(2)<<(i+1)%10;}
            else if(i == -1 && j == -1){cout<<"��";}
            else if(i == -1 && j != -1){cout<<"����";}
            else if(j == -1 && i != -1){cout<<"��";}
            else if(j >= 0 && i >= 0 )cout << color << right << board[i][j] <<"\033[37m"<<' ';
            else{//���ⶨ��
                if(i == -3 && j == -3){cout<<setw(2)<<"˫";}
                else if(i == -3 && j == -2){cout<<setw(2)<<"��";}
                else if(i == -2 && j == -3){cout<<setw(2)<<"��";}
                else if(i == -2 && j == -2){cout<<setw(2)<<"��";}
            }
        }
        cout << endl;
        }
}

bool Board::checkWin() {
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            if(board[i][j] == player) {
                // ���ᡢ��������б��
                if(j <= boardSize - 5 && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player && board[i][j + 4] == player) return true;
                if(i <= boardSize - 5 && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player && board[i + 4][j] == player) return true;
                if(i <= boardSize - 5 && j <= boardSize - 5 && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player && board[i + 4][j + 4] == player) return true;
                if(i <= boardSize - 5 && j >= 4 && board[i + 1][j - 1] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == player && board[i + 4][j - 4] == player) return true;
            }
        }
    }
    return false;
}