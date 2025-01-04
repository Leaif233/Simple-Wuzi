#include <iostream>
#include <unistd.h>
#include <ctime>
#include "Menu.h"
#include "Game.h"
#include "Player.h"
using namespace std;
string color = "\033[37m";//棋盘默认白色
int board_size =15;//棋盘默认大小
string name1,name2;

void show_mainMenu(){
    cout << "\033[2J"; // 清屏
    cout << "\33[0;0H"; // 移动光标到左上角
    cout<<"=========  双人五子棋  ========="<<endl;
	cout<<"          1.开始游戏"<<endl;
    cout<<"          2.玩家昵称"<<endl;
    cout<<"          3.历史记录"<<endl;
	cout<<"          4.设置选项"<<endl;
	cout<<"          0.退出游戏"<<endl;
	cout<<"==============================="<<endl;
    main_getco();
}
void main_getco(){
    int x;
    cin>>x;
    switch(x){
        case 1:game();
        case 2:show_setnameMenu();break;
        case 3:show_history();break;
        case 4:show_setMenu();break;
        case 0:exit(0);break;
    }
}

void show_setnameMenu(){
    cout << "\033[2J"; // 清屏
    cout << "\33[0;0H"; // 移动光标到左上角
    cout<<"=========== 玩家昵称 =========="<<endl;
    cout<<"  "<<"\033[47m "<<"\033[30m "<<"玩家\"X\"昵称:"<<"\033[40m "<<"\033[37m"<<endl;
    cout<<"  玩家\"O\"昵称:"<<endl;
    cout<<"=============================="<<endl;
    cin>>name1;
    printf("\a");//响铃
    cout << "\033[2J"; // 清屏
    cout << "\33[0;0H"; // 移动光标到左上角
    cout<<"=========== 玩家昵称 =========="<<endl;
    cout<<"  玩家\"X\"昵称:"<<color<<name1<<"\033[37m"<<endl;
    cout<<"  "<<"\033[47m "<<"\033[30m "<<"玩家\"O\"昵称:"<<"\033[40m "<<"\033[37m"<<endl;
    cout<<"=============================="<<endl;
    cin>>name2;
    printf("\a");//响铃
    cout << "\033[2J"; // 清屏
    cout << "\33[0;0H"; // 移动光标到左上角
    cout<<"=========== 玩家昵称 =========="<<endl;
    cout<<"  玩家\"X\"昵称:"<<color<<name1<<"\033[37m"<<endl;
    cout<<"  玩家\"O\"昵称:"<<color<<name2<<"\033[37m"<<endl;
    cout<<"========== ~设置成功~ ========="<<endl;
    sleep(1);
    show_mainMenu();
}

void show_setplayerMenu(){
    cout << "\033[2J"; // 清屏
    cout << "\33[0;0H"; // 移动光标到左上角
    cout<<"===========  先手  ==========="<<endl;
	cout<<"             1.X:"<<color<<name1<<"\033[37m"<<endl;
	cout<<"             2.O:"<<color<<name2<<"\033[37m"<<endl;
    cout<<"             3.随机"<<endl;
	cout<<"=============================="<<endl;
}

void show_setMenu(){
    cout << "\033[2J"; // 清屏
    cout << "\33[0;0H"; // 移动光标到左上角
    cout<<"=========  设置选项  ========="<<endl;
	cout<<"          1.画面颜色"<<endl;
    cout<<"          2.棋盘大小"<<endl;
	cout<<"          0.返回"<<endl;
	cout<<"=============================="<<endl;
    set_getco();
}
void set_getco(){
    int x;
    cin>>x;
    switch(x){
        case 1:setcolor();break;
        case 2:show_setsizeMenu();break;
        case 0:show_mainMenu();break;
    }
}
void setcolor(){
    cout << "\033[2J"; // 清屏
    cout << "\33[0;0H"; // 移动光标到左上角
    cout<<"=========  棋盘颜色  ========="<<endl;
    cout<<"\033[36m"<<"          1.高端青"<<endl;
    cout<<"\033[32m"<<"          2.护眼绿"<<endl;
    cout<<"\033[37m"<<"          3.默认白"<<endl;
    cout<<"\033[37m"<<"=============================="<<endl;
    color_getco();
}

void color_getco(){
    enum Color{WHITE = 1, GREEN = 2, BLACK = 3};
    int x;
    cin>>x;
    string output;
    switch(Color(x)){
        case 1:color = "\033[36m";output = "高端青";break;
        case 2:color = "\033[32m";output = "护眼绿";break;
        case 3:color = "\033[37m";output = "默认白";break;
    }
    cout<<"\a";//响铃
    cout<<"棋盘颜色设置成功："<<color<<output<<"\033[37m"<<endl;
    sleep(1);
    show_mainMenu();
}

void show_setsizeMenu(){
    cout << "\033[2J"; // 清屏
    cout << "\33[0;0H"; // 移动光标到左上角
    cout<<"=========  棋盘大小  ========="<<endl;
    cout<<"          1.默认(15*15)"<<endl;
    cout<<"          2.略小(10*10)"<<endl;
    cout<<"          3.略大(20*20)"<<endl;
    cout<<"=============================="<<endl;
    size_getco();
}

void size_getco(){
    int x;
    cin>>x;
    switch(x){
        case 1:board_size = 15;break;
        case 2:board_size = 10;break;
        case 3:board_size = 20;break;
    }
    cout<<"\a";//响铃
    cout<<"棋盘大小设置成功："<<board_size<<"*"<<board_size<<endl;
    sleep(1);
    show_mainMenu();
}

void show_history(){
    cout << "\033[2J"; // 清屏
    cout << "\33[0;0H"; // 移动光标到左上角
    cout<<"=========  历史记录  ========="<<endl;
    if(player.winner_v.empty()){
        cout<<"                    "<<endl;
        cout<<"         暂无历史记录"<<endl;
        cout<<"                    "<<endl;
        cout<<"=============================="<<endl;
        sleep(1);show_mainMenu();return;}
    else{
        for(int i=0;i<player.winner_v.size();i++){
            if(player.winner_char_v[i]=='X'){
                cout<<"                    "<<endl;
                cout<<player.time_v[i]<<"X:"<<player.winner_v[i]<<"-vs-"<<"O:"<<player.loser_v[i]<<" "<<player.winner_char_v[i]<< player.winner_v[i]<<"-Win!!"<<endl;
                cout<<"                    "<<endl;
            }else{
                cout<<"                    "<<endl;
                cout<<player.time_v[i]<<"X:"<<player.loser_v[i]<<"-vs-"<<"O:"<<player.winner_v[i]<<" "<<player.winner_char_v[i]<< player.winner_v[i]<<"-Win!!"<<endl;
                cout<<"                    "<<endl;
            }
        }
    }    
    cout<<"======输入\"-1\"返回主页面======"<<endl;
    int x;
    cin>>x;
    if(x == -1){show_mainMenu();return;}
}

//获取时间
string get_time()
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
   // 把 now 转换为字符串形式
   char* dt = ctime(&now);
   // 把 now 转换为 tm 结构
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   return dt;
}