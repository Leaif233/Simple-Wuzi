#ifndef MENU_H
#define MENU_H
#include <iostream>
extern std::string color;
extern int board_size;
extern std::string name1,name2;
void show_mainMenu();//主菜单
void show_setMenu();//设置菜单
void show_setnameMenu();//设置昵称菜单
void show_setplayerMenu();//设置先手菜单
void show_setsizeMenu();//设置棋盘大小菜单
void show_history();//历史记录菜单
void main_getco();//主菜单获取输入
void setcolor();//设置棋盘颜色
void color_getco();//设置棋盘颜色获取输入
void set_getco();///设置菜单获取输入
void size_getco();//设置棋盘大小获取输入
std::string get_time();//获取当前时间
#endif