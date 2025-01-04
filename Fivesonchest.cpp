#include "Menu.h"
#include "Board.h"
#include "Game.h"
using namespace std;

int main() {
    cout << "\033[2J"; // 清屏
    cout << "\33[0;0H"; // 移动光标到左上角
    show_mainMenu();//开启主界面
    return 0;
}
