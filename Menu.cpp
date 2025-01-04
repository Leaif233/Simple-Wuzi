#include <iostream>
#include <unistd.h>
#include <ctime>
#include "Menu.h"
#include "Game.h"
#include "Player.h"
using namespace std;
string color = "\033[37m";//����Ĭ�ϰ�ɫ
int board_size =15;//����Ĭ�ϴ�С
string name1,name2;

void show_mainMenu(){
    cout << "\033[2J"; // ����
    cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
    cout<<"=========  ˫��������  ========="<<endl;
	cout<<"          1.��ʼ��Ϸ"<<endl;
    cout<<"          2.����ǳ�"<<endl;
    cout<<"          3.��ʷ��¼"<<endl;
	cout<<"          4.����ѡ��"<<endl;
	cout<<"          0.�˳���Ϸ"<<endl;
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
    cout << "\033[2J"; // ����
    cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
    cout<<"=========== ����ǳ� =========="<<endl;
    cout<<"  "<<"\033[47m "<<"\033[30m "<<"���\"X\"�ǳ�:"<<"\033[40m "<<"\033[37m"<<endl;
    cout<<"  ���\"O\"�ǳ�:"<<endl;
    cout<<"=============================="<<endl;
    cin>>name1;
    printf("\a");//����
    cout << "\033[2J"; // ����
    cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
    cout<<"=========== ����ǳ� =========="<<endl;
    cout<<"  ���\"X\"�ǳ�:"<<color<<name1<<"\033[37m"<<endl;
    cout<<"  "<<"\033[47m "<<"\033[30m "<<"���\"O\"�ǳ�:"<<"\033[40m "<<"\033[37m"<<endl;
    cout<<"=============================="<<endl;
    cin>>name2;
    printf("\a");//����
    cout << "\033[2J"; // ����
    cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
    cout<<"=========== ����ǳ� =========="<<endl;
    cout<<"  ���\"X\"�ǳ�:"<<color<<name1<<"\033[37m"<<endl;
    cout<<"  ���\"O\"�ǳ�:"<<color<<name2<<"\033[37m"<<endl;
    cout<<"========== ~���óɹ�~ ========="<<endl;
    sleep(1);
    show_mainMenu();
}

void show_setplayerMenu(){
    cout << "\033[2J"; // ����
    cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
    cout<<"===========  ����  ==========="<<endl;
	cout<<"             1.X:"<<color<<name1<<"\033[37m"<<endl;
	cout<<"             2.O:"<<color<<name2<<"\033[37m"<<endl;
    cout<<"             3.���"<<endl;
	cout<<"=============================="<<endl;
}

void show_setMenu(){
    cout << "\033[2J"; // ����
    cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
    cout<<"=========  ����ѡ��  ========="<<endl;
	cout<<"          1.������ɫ"<<endl;
    cout<<"          2.���̴�С"<<endl;
	cout<<"          0.����"<<endl;
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
    cout << "\033[2J"; // ����
    cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
    cout<<"=========  ������ɫ  ========="<<endl;
    cout<<"\033[36m"<<"          1.�߶���"<<endl;
    cout<<"\033[32m"<<"          2.������"<<endl;
    cout<<"\033[37m"<<"          3.Ĭ�ϰ�"<<endl;
    cout<<"\033[37m"<<"=============================="<<endl;
    color_getco();
}

void color_getco(){
    enum Color{WHITE = 1, GREEN = 2, BLACK = 3};
    int x;
    cin>>x;
    string output;
    switch(Color(x)){
        case 1:color = "\033[36m";output = "�߶���";break;
        case 2:color = "\033[32m";output = "������";break;
        case 3:color = "\033[37m";output = "Ĭ�ϰ�";break;
    }
    cout<<"\a";//����
    cout<<"������ɫ���óɹ���"<<color<<output<<"\033[37m"<<endl;
    sleep(1);
    show_mainMenu();
}

void show_setsizeMenu(){
    cout << "\033[2J"; // ����
    cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
    cout<<"=========  ���̴�С  ========="<<endl;
    cout<<"          1.Ĭ��(15*15)"<<endl;
    cout<<"          2.��С(10*10)"<<endl;
    cout<<"          3.�Դ�(20*20)"<<endl;
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
    cout<<"\a";//����
    cout<<"���̴�С���óɹ���"<<board_size<<"*"<<board_size<<endl;
    sleep(1);
    show_mainMenu();
}

void show_history(){
    cout << "\033[2J"; // ����
    cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
    cout<<"=========  ��ʷ��¼  ========="<<endl;
    if(player.winner_v.empty()){
        cout<<"                    "<<endl;
        cout<<"         ������ʷ��¼"<<endl;
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
    cout<<"======����\"-1\"������ҳ��======"<<endl;
    int x;
    cin>>x;
    if(x == -1){show_mainMenu();return;}
}

//��ȡʱ��
string get_time()
{
   // ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
   time_t now = time(0);
   // �� now ת��Ϊ�ַ�����ʽ
   char* dt = ctime(&now);
   // �� now ת��Ϊ tm �ṹ
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   return dt;
}