#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>      //获取键盘事件
#include <vector>
#include <windows.h>
using namespace std;
//常量
#define TABLE_LENGTH 4
#define Left_Arrow 75
#define Up_Arrow 72
#define Right_Arrow 77
#define Dw_Arrow 80

//功能函数
int start_win_show();       //开始动画
int menu_win_show_back();       //开始菜单
int set_difficulty(int diffct=0);       //选择难度
int set_game_mode(int gmode);       //选择游戏模式
int evaluate(void);     //局势评价函数
int win_judge(void);        //判断输赢
int place_num(void);        //随机放置2或4
int lose_win_show(void);        //失败界面前端
int lose_win_back(int cmd);     //失败界面后端
int pause_win_show(void);       //暂停界面前端
int pause_win_back(int cmd);        //暂停界面后端

//工具函数
/* void SetWindowSize(int cols, int lines);
void SetCursorPosition(const int x, const int y);
void SetColor(int colorID);
void SetBackColor(); */
int wait(int has_key=0,char key='c');
//类
class gtable{
public:
    int content[TABLE_LENGTH][TABLE_LENGTH];
    void draw(void);        //绘制
    void reset(void);       //重置
    int operate(int direction);     //返回值表示操作成功与否
};
void gtable::reset(void){
    for(int i=0;i<TABLE_LENGTH;i++){
        for(int j=0;j<TABLE_LENGTH;j++){
            content[i][j]=0;
        }
    }
}
void gtable::draw(void){
    cout<<"\n\n\n\n\n               ";
    for(int i=0;i<TABLE_LENGTH;i++){
        for(int j=0;j<TABLE_LENGTH;j++){
            cout<<setw(5)<<content[i][j];
        }
        cout<<"\n               ";
    }
}

int main(){     //主控
    //SetConsoleTitle("2048 GAME!");
    start_win_show();
    printf("\n\n\n\n\n");
    Sleep(200);
    wait();
    menu_win_show_back();
    printf("\n\n\n\n\n");
    wait();
    Sleep(100);
    return 0;
    gtable table;
    system("cls");
    //table.draw();
    table.reset();
    table.draw();

    system("pause");
    cout<<"finish.";
    Sleep(1000);
}
int start_win_show(){
    int space_cnt=42;
    int interval=50;
    while (!_kbhit()&&space_cnt>=20)
    {
        system("cls");
        printf("\n\n\n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("     ___           ___           ___           ___         \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("    /  /\\         /  /\\         /__/\\         /  /\\         \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("   /  /::\\       /  /::\\        \\  \\:\\       /  /::\\      \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("  /  /:/\\:\\     /  /:/\\:\\        \\__\\:\\     /  /:/\\:\\   \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf(" /  /:/~/:/_   /  /:/  \\:\\   ___ /  /::\\   /  /:/ /::\\  \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("/__/:/ /:/ /\\ /  /:/ \\__\\:\\ /  /\\  /::\\:\\ /  /:/ /:/\\:\\ \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("\\__\\/ /:/ /:/ \\  \\:\\ /  /:/ \\  \\:\\/:/__\\/ \\  \\:\\/:/ /:/  \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("  /  /:/ /:/   \\  \\:\\  /:/   \\  \\::/       \\  \\::/ /:/    \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("  \\  \\:\\/:/     \\  \\:\\/:/     \\__\\/         \\  \\:\\/:/  \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("   \\  \\::/       \\  \\::/                     \\  \\::/     \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("    \\__\\/         \\__\\/                       \\__\\/      \n");
        space_cnt--;
        Sleep(interval);
    }
    if(space_cnt>20){
        space_cnt=20;
        system("cls");
        printf("\n\n\n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("     ___           ___           ___           ___         \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("    /  /\\         /  /\\         /__/\\         /  /\\         \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("   /  /::\\       /  /::\\        \\  \\:\\       /  /::\\      \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("  /  /:/\\:\\     /  /:/\\:\\        \\__\\:\\     /  /:/\\:\\   \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf(" /  /:/~/:/_   /  /:/  \\:\\   ___ /  /::\\   /  /:/ /::\\  \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("/__/:/ /:/ /\\ /  /:/ \\__\\:\\ /  /\\  /::\\:\\ /  /:/ /:/\\:\\ \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("\\__\\/ /:/ /:/ \\  \\:\\ /  /:/ \\  \\:\\/:/__\\/ \\  \\:\\/:/ /:/  \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("  /  /:/ /:/   \\  \\:\\  /:/   \\  \\::/       \\  \\::/ /:/    \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("  \\  \\:\\/:/     \\  \\:\\/:/     \\__\\/         \\  \\:\\/:/  \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("   \\  \\::/       \\  \\::/                     \\  \\::/     \n");
        for(int i=0;i<space_cnt;i++){
            printf(" ");
        }
        printf("    \\__\\/         \\__\\/                       \\__\\/      \n");
    }
    Sleep(100);
    return 0;
}

int menu_win_show_back(){
    system("cls");
    int selected_id=0;
    int last_selected_id=0;
    int max_optionid=2;
    printf("\n\n\n\n\n\n\n\n");
    printf("                                     MAIN MENU                   \n");
    printf("\n");
    printf("                                  # Quick start                 \n");
    printf("                                    Mode chooce                 \n");
    printf("                                      Options                     \n");
    while(1){
        int ch;
        int flag=1;
        if(_kbhit()&&flag){
            ch=_getch();
            flag=0;
        }
        if(ch==13){
            break;
        }
        if(ch==Up_Arrow){
            selected_id--;
            if(selected_id<0){selected_id=0;}
        }
        if(ch==Dw_Arrow){
            selected_id++;
            if(selected_id>max_optionid){selected_id=max_optionid;}
        }
        if(last_selected_id!=selected_id){
            if(selected_id==0){
                system("cls");
                printf("\n\n\n\n\n\n\n\n");
                printf("                                     MAIN MENU                   \n");
                printf("\n");
                printf("                                  # Quick start                 \n");
                printf("                                    Mode chooce                 \n");
                printf("                                      Options                     \n");
            }
            if(selected_id==1){
                system("cls");
                printf("\n\n\n\n\n\n\n\n");
                printf("                                     MAIN MENU                   \n");
                printf("\n");
                printf("                                    Quick start                 \n");
                printf("                                  # Mode chooce                 \n");
                printf("                                      Options                     \n");
            }
            if(selected_id==2){
                system("cls");
                printf("\n\n\n\n\n\n\n\n");
                printf("                                     MAIN MENU                   \n");
                printf("\n");
                printf("                                    Quick start                 \n");
                printf("                                    Mode chooce                 \n");
                printf("                                  #   Options                     \n");
            }
            ch=0;
            last_selected_id=selected_id;
        }
        Sleep(100);
        flag=1;

    }
    switch (selected_id)        //后台处理
    {
    case 0:     //快速开始
        break;
    case 1:     //选择模式
        break;
    case 2:     //设置
        break;
    default:
        break;
    }

    return 0;
}

int wait(int has_key,char key){
    /* int tmp=_kbhit();
    cout<<"\n"<<tmp; */
    if(has_key){
            printf("\r                                Press '%c' to continue",key);
            Sleep(500);
    }else{
            printf("\r                             Press any key to continue");
            Sleep(500);
    }
    /* tmp=_kbhit();
    cout<<"\n"<<tmp; */
    if(has_key){
        while(!_kbhit()&&key!=_getch()){
            printf("\r                                Press '%c' to continue",key);
            Sleep(500);
            printf("\r                                                      ");
            Sleep(500);
        }
        Sleep(100);
        return 0;
    }else{
        while(!_kbhit()){
            printf("\r                             Press any key to continue");
            Sleep(500);
            printf("\r                                                      ");
            Sleep(500);
        }
        Sleep(100);
        return 0;
    }
}
/* void SetWindowSize(int cols, int lines)//设置窗口大小
{
    system("title 贪吃蛇");//设置窗口标题
    char cmd[30];
    sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//一个图形■占两个字符，故宽度乘以2
    system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
}

void SetCursorPosition(const int x, const int y)//设置光标位置
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID)//设置文本颜色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//设置文本背景色
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                            BACKGROUND_BLUE |
                            BACKGROUND_GREEN |
                            BACKGROUND_RED );
} */
