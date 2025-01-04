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
Player player;//��¼��ʤ��Ҷ���
//����ȫ�ֱ���
int times1 = 1;
int times2 = 1;
int backname = 0;
Board Newboard;

string winner;
char winner_char;
string loser;
char loser_char;
vector<string> time_v;

//��Ϸ��ʼ

void game(){
    stack<int> history;//��ʷ��¼
    int times;//�������
    char tempname;//������ʱ���Ʒ���
    string name;
    int x, y;
    char currentPlayer;
    if(backname == 0){
        Newboard.setPlayer();//��������
        currentPlayer = Newboard.showPlayer();
        Newboard.newBoard();
    }
    //�������л����
    else if(backname == 1){
        currentPlayer = 'X';
    }
    else if(backname == 2)
    {
        currentPlayer = 'O';
    }
    int boardSize = Newboard.showBoardSize();
    cout << "\033[2J"; // ����
    cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
    while(true) {
        cout << "\033[2J"; // ����
        cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
        Newboard.printBoard();
        if(currentPlayer == 'X'){tempname = 'O',name = name2;times = times2;backname = 2;}//����ѡ
        else{tempname = 'X',name = name1;times = times1;backname = 1;}
        cout <<"����:����\"0\",���"<<color<<tempname<<":"<<name<<"\033[37m"<<"[�ɻڴ���:"<<times<<"] "<<endl;
        cout <<"����:����\"-1\",������Ϸ,���ز˵�"<<endl;
        if(currentPlayer == 'X'){name = name1;}//������ѡ
        else{name = name2;}
        cout << "��� " <<color<<currentPlayer<<":"<<name<<"\033[37m"<<" ����������λ�� (x y): ";
        cin >> x;
        if(x == 0){back(Newboard,history,times,backname);continue;}
        if(x == -1){newgame();show_mainMenu();}
        history.push(x);//��¼����X
        cin >> y;
        history.push(y);//��¼����Y
        if(x <= 0 || x > boardSize || y <= 0 || y > boardSize || Newboard.board[x-1][y-1] != Newboard.pattern) {
            cout << "��Ч������λ�ã����������롣" <<sleep(1)<<endl;
            continue;
        }
        Newboard.board[x-1][y-1] = currentPlayer;
        cout << "\033[2J"; // ����
        cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
        Newboard.printBoard();
        if(Newboard.checkWin()) {
            cout << "\033[2J"; // ����
            cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
            cout << "��� " << currentPlayer<<":"<<name<< " ��ʤ��" << endl;
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
        // �л����
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

void back(Board &Newboard,stack<int> &history,int &times,int &backname){
    if(history.empty()){cout << "û�пɻ�������ӣ�" << endl;sleep(1);return;}
    if(times == 0){cout << "û�пɻ���Ĵ�����" << endl;sleep(1);return;}
    int y = history.top();
    history.pop();
    int x = history.top();
    history.pop();
    Newboard.board[x-1][y-1]=Newboard.pattern;
    if(backname == 1){times1--;}
    else{times2--;}//����ѡ��
    cout << "\033[2J"; // ����
    cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
    game();
}

void newgame(){
    times1 = 1;
    times2 = 1;
    backname = 0;
}
