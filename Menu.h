#ifndef MENU_H
#define MENU_H
#include <iostream>
extern std::string color;
extern int board_size;
extern std::string name1,name2;
void show_mainMenu();//���˵�
void show_setMenu();//���ò˵�
void show_setnameMenu();//�����ǳƲ˵�
void show_setplayerMenu();//�������ֲ˵�
void show_setsizeMenu();//�������̴�С�˵�
void show_history();//��ʷ��¼�˵�
void main_getco();//���˵���ȡ����
void setcolor();//����������ɫ
void color_getco();//����������ɫ��ȡ����
void set_getco();///���ò˵���ȡ����
void size_getco();//�������̴�С��ȡ����
std::string get_time();//��ȡ��ǰʱ��
#endif