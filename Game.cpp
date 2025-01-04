#include <iostream>
#include <cstring>
#include <unistd.h>
#include <stack>
#include <vector>
#include "Game.h"
#include "Board.h"
#include "Menu.h"
#include "Player.h"
using namespace std;
Player player;//记录获胜玩家对象
//悔棋全局变量
int times1 = 1;
int times2 = 1;
int backname = 0;
Board Newboard;

string winner;
char winner_char;
string loser;
char loser_char;
vector<string> time_v;

//游戏开始

void game(){
    stack<int> history;//历史记录
    int times;//悔棋次数
    char tempname;//悔棋临时名称符号
    string name;
    int x, y;
    char currentPlayer;
    if(backname == 0){
        Newboard.setPlayer();//先手设置
        currentPlayer = Newboard.showPlayer();
        Newboard.newBoard();
    }
    //检测悔棋切换玩家
    else if(backname == 1){
        currentPlayer = 'X';
    }
    else if(backname == 2)
    {
        currentPlayer = 'O';
    }
    int boardSize = Newboard.showBoardSize();
    cout << "\033[2J"; // 清屏
    cout << "\33[0;0H"; // 移动光标到左上角
    while(true) {
        cout << "\033[2J"; // 清屏
        cout << "\33[0;0H"; // 移动光标到左上角
        Newboard.printBoard();
        if(currentPlayer == 'X'){tempname = 'O',name = name2;times = times2;backname = 2;}//对象反选
        else{tempname = 'X',name = name1;times = times1;backname = 1;}
        cout <<"悔棋:输入\"0\",玩家"<<color<<tempname<<":"<<name<<"\033[37m"<<"[可悔次数:"<<times<<"] "<<endl;
        cout <<"返回:输入\"-1\",结束游戏,返回菜单"<<endl;
        if(currentPlayer == 'X'){name = name1;}//对象正选
        else{name = name2;}
        cout << "玩家 " <<color<<currentPlayer<<":"<<name<<"\033[37m"<<" 请输入落子位置 (x y): ";
        cin >> x;
        if(x == 0){back(Newboard,history,times,backname);continue;}
        if(x == -1){newgame();show_mainMenu();}
        history.push(x);//记录落子X
        cin >> y;
        history.push(y);//记录落子Y
        if(x <= 0 || x > boardSize || y <= 0 || y > boardSize || Newboard.board[x-1][y-1] != Newboard.pattern) {
            cout << "无效的落子位置，请重新输入。" <<sleep(1)<<endl;
            continue;
        }
        Newboard.board[x-1][y-1] = currentPlayer;
        cout << "\033[2J"; // 清屏
        cout << "\33[0;0H"; // 移动光标到左上角
        Newboard.printBoard();
        if(Newboard.checkWin()) {
            cout << "\033[2J"; // 清屏
            cout << "\33[0;0H"; // 移动光标到左上角
            cout << "玩家 " << currentPlayer<<":"<<name<< " 获胜！" << endl;
            winner = name;
            winner_char = currentPlayer;
            loser = (currentPlayer == 'X') ? name2 : name1;
            loser_char = (currentPlayer == 'X') ? 'O' : 'X';
            player.record(winner,winner_char,loser,loser_char);
            sleep(2);
            newgame();
            show_mainMenu();
            break;
        }
        // 切换玩家
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

void back(Board &Newboard,stack<int> &history,int &times,int &backname){
    if(history.empty()){cout << "没有可悔棋的棋子！" << endl;sleep(1);return;}
    if(times == 0){cout << "没有可悔棋的次数！" << endl;sleep(1);return;}
    int y = history.top();
    history.pop();
    int x = history.top();
    history.pop();
    Newboard.board[x-1][y-1]=Newboard.pattern;
    if(backname == 1){times1--;}
    else{times2--;}//次数选择
    cout << "\033[2J"; // 清屏
    cout << "\33[0;0H"; // 移动光标到左上角
    game();
}

void newgame(){
    times1 = 1;
    times2 = 1;
    backname = 0;
}
