#include "Menu.h"
#include "Board.h"
#include "Game.h"
using namespace std;

int main() {
    cout << "\033[2J"; // ����
    cout << "\33[0;0H"; // �ƶ���굽���Ͻ�
    show_mainMenu();//����������
    return 0;
}
