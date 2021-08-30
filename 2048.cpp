#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>      //获取键盘事件
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
//常量
#define TABLE_LENGTH 4
#define Left_Arrow 75
#define Up_Arrow 72
#define Right_Arrow 77
#define Dw_Arrow 80
#define key_p 112
#define key_esc 27
#define key_Arrow 224
#define Dirc_Left 1
#define Dirc_Up 2
#define Dirc_Right 3
#define Dirc_Dw 4
#define CMD_EXIT 1
#define MODE_NORMAL 0
#define END_OVERTIME 10
#define End_DEEPTH 20
#define MENU_CMD_QUICK_START 10
#define MENU_CMD_MODE_CHOOSE 20
#define MENU_CMD_OPTIONS 30
#define MENU_CMD_EXIT -100

//功能函数
int start_win_show();                   //开始动画
int menu_win_show_back();               //开始菜单
int set_difficulty(int diffct=0);       //选择难度
int set_game_mode(int gmode);           //选择游戏模式
int evaluate(void);                     //局势评价函数
int win_judge(void);                    //判断输赢
int lose_win_show(void);                //失败界面前端
int lose_win_back(int cmd);             //失败界面后端
int pause_win_show(void);               //暂停界面前端
int pause_win_back(int cmd);            //暂停界面后端
int option_win_show(void);              //设置界面前端
int option_win_back(int cmd);           //设置界面后端
int game_process(int gmode);            //游戏进程

//工具函数
/* void SetWindowSize(int cols, int lines);
void SetCursorPosition(const int x, const int y);
void SetColor(int colorID);
void SetBackColor(); */
int wait(int has_key=0,char key='c');
//类
class gtable{
public:
    int score;
    int content[TABLE_LENGTH][TABLE_LENGTH];
    void draw(void);        //绘制
    void reset(void);       //重置
    //int operate(int direction);     //返回值表示操作成功与否
    void place_num(void);            //随机放置2或4
    int move_left(void);            //四方向移动
    int move_up(void);
    int move_right(void);
    int move_down(void);
    int is_2048(void);
    int is_lose(void);
    double evaluate(void);           //对当前局面评分
    int max_num(void);          //最大数
    int empty_cell(void);            //空格数
    // double monotonicity(void);
    double monotonicity2(void);         //单调度
    double smoothness(void);            //平滑度
    void tree(int end_way=END_OVERTIME,int num=1000);            //创建格局树
};
void gtable::reset(void){
    for(int i=0;i<TABLE_LENGTH;i++){
        for(int j=0;j<TABLE_LENGTH;j++){
            content[i][j]=0;
        }
    }
    score=0;
    return;
}
void gtable::draw(void){
    system("cls");
    cout<<"\n\n             Score:"<<score;
    cout<<"\n\n\n\n\n\n             #########################\n";
    for(int j=0;j<TABLE_LENGTH;j++){
        cout<<setw(0)<<"             #";
        for(int i=0;i<TABLE_LENGTH;i++){
            if(0==content[i][j]){
                cout<<setw(5)<<" "<<setw(0)<<"|";
            }else{
                cout<<setw(5)<<content[i][j]<<setw(0)<<"|";
            }
        }
        cout<<setw(0)<<"\b#\n";
        if(j<TABLE_LENGTH-1)cout<<"             #-----------------------#\n";
        //cout<<setw(0)<<"             #\n             #\n";
    }
    cout<<"             #########################";
    return;
}
void gtable::place_num(void){
    int num=0;
    int i=0,j=0;
    i=rand()%TABLE_LENGTH;
    j=rand()%TABLE_LENGTH;
    for(;content[i][j]!=0;){
        i=rand()%TABLE_LENGTH;
        j=rand()%TABLE_LENGTH;
    }
    num=rand()%2+1;
    num*=2;
    content[i][j]=num;
    return;
}
int gtable::move_left(void){
    int can_move=0;
    /* for(int i=0;i<TABLE_LENGTH;i++){
        for(int j=0;j<TABLE_LENGTH;j++){
            
        }
    } */
    for(int cnt=0;cnt<TABLE_LENGTH;cnt++){            //循环4次
        for(int j=0;j<TABLE_LENGTH;j++){
            for(int i=1;i<TABLE_LENGTH;i++){
                if(content[i-1][j]==content[i][j]&&content[i][j]>0){
                    can_move=1;
                    content[i-1][j]+=content[i-1][j];
                    content[i-1][j]=-content[i-1][j];
                    content[i][j]=0;
                    score-=content[i-1][j];
                }
                if(content[i-1][j]==0&&content[i][j]>0){
                    can_move=1;
                    content[i-1][j]=content[i][j];
                    content[i][j]=0;
                }
            }
        }
    }

    for(int j=0;j<TABLE_LENGTH;j++){
        for(int i=0;i<TABLE_LENGTH;i++){
            if(content[i][j]<0){
                content[i][j]=-content[i][j];
            }
        }
    }

    for(int cnt=0;cnt<2;cnt++){            //循环2次
        for(int j=0;j<TABLE_LENGTH;j++){
            for(int i=1;i<TABLE_LENGTH;i++){
                if(content[i-1][j]==0&&content[i][j]>0){
                    content[i-1][j]=content[i][j];
                    content[i][j]=0;
                }
            }
        }
    }
    return can_move;
}
int gtable::move_up(void){
    int can_move=0;
    for(int cnt=0;cnt<TABLE_LENGTH;cnt++){            //循环4次
        for(int j=1;j<TABLE_LENGTH;j++){
            for(int i=0;i<TABLE_LENGTH;i++){
                if(content[i][j-1]==content[i][j]&&content[i][j]>0){
                    can_move=1;
                    content[i][j-1]+=content[i][j-1];
                    content[i][j-1]=-content[i][j-1];
                    content[i][j]=0;
                    score-=content[i][j-1];
                }
                if(content[i][j-1]==0&&content[i][j]>0){
                    can_move=1;
                    content[i][j-1]=content[i][j];
                    content[i][j]=0;
                }
            }
        }
    }

    for(int j=0;j<TABLE_LENGTH;j++){
        for(int i=0;i<TABLE_LENGTH;i++){
            if(content[i][j]<0){
                content[i][j]=-content[i][j];
            }
        }
    }

    for(int cnt=0;cnt<2;cnt++){            //循环2次
        for(int j=1;j<TABLE_LENGTH;j++){
            for(int i=0;i<TABLE_LENGTH;i++){
                if(content[i][j-1]==0&&content[i][j]>0){
                    content[i][j-1]=content[i][j];
                    content[i][j]=0;
                }
            }
        }
    }
    return can_move;
}
int gtable::move_right(void){
    int can_move=0;
    for(int cnt=0;cnt<TABLE_LENGTH;cnt++){            //循环4次
        for(int j=0;j<TABLE_LENGTH;j++){
            for(int i=TABLE_LENGTH-2;i>-1;i--){
                if(content[i+1][j]==content[i][j]&&content[i][j]>0){
                    can_move=1;
                    content[i+1][j]+=content[i+1][j];
                    content[i+1][j]=-content[i+1][j];
                    content[i][j]=0;
                    score-=content[i+1][j];
                }
                if(content[i+1][j]==0&&content[i][j]>0){
                    can_move=1;
                    content[i+1][j]=content[i][j];
                    content[i][j]=0;
                }
            }
        }
    }

    for(int j=0;j<TABLE_LENGTH;j++){
        for(int i=0;i<TABLE_LENGTH;i++){
            if(content[i][j]<0){
                content[i][j]=-content[i][j];
            }
        }
    }

    for(int cnt=0;cnt<2;cnt++){            //循环2次
        for(int j=0;j<TABLE_LENGTH;j++){
            for(int i=0;i<TABLE_LENGTH-1;i++){
                if(content[i+1][j]==0&&content[i][j]>0){
                    content[i+1][j]=content[i][j];
                    content[i][j]=0;
                }
            }
        }
    }
    return can_move;
}
int gtable::move_down(void){
    int can_move=0;
    for(int cnt=0;cnt<TABLE_LENGTH;cnt++){            //循环4次
        for(int j=TABLE_LENGTH-2;j>-1;j--){
            for(int i=0;i<TABLE_LENGTH;i++){
                if(content[i][j+1]==content[i][j]&&content[i][j]>0){
                    can_move=1;
                    content[i][j+1]+=content[i][j+1];
                    content[i][j+1]=-content[i][j+1];
                    content[i][j]=0;
                    score-=content[i][j+1];
                }
                if(content[i][j+1]==0&&content[i][j]>0){
                    can_move=1;
                    content[i][j+1]=content[i][j];
                    content[i][j]=0;
                }
            }
        }
    }

    for(int j=0;j<TABLE_LENGTH;j++){
        for(int i=0;i<TABLE_LENGTH;i++){
            if(content[i][j]<0){
                content[i][j]=-content[i][j];
            }
        }
    }

    for(int cnt=0;cnt<2;cnt++){            //循环2次
        for(int j=0;j<TABLE_LENGTH-1;j++){
            for(int i=0;i<TABLE_LENGTH;i++){
                if(content[i][j+1]==0&&content[i][j]>0){
                    content[i][j+1]=content[i][j];
                    content[i][j]=0;
                }
            }
        }
    }
    return can_move;
}
int gtable::is_2048(void){
    int win_flag=0;
    for(int j=0;j<TABLE_LENGTH;j++){
        for(int i=0;i<TABLE_LENGTH;i++){
            if(content[i][j]>2047)win_flag=1;
        }
    }
    return win_flag;
}
int gtable::is_lose(void){
    for(int j=0;j<TABLE_LENGTH;j++){
        for(int i=0;i<TABLE_LENGTH;i++){
            if(content[i][j]==0){
                return 0;
            }
        }
    }
    for(int j=0;j<TABLE_LENGTH-1;j++){
        for(int i=0;i<TABLE_LENGTH-1;i++){
            if(content[i][j]==content[i][j+1]||content[i][j]==content[i+1][j]){
                return 0;
            }
        }
    }
    return 1;
}
double gtable::evaluate(void){
    //设置权重值
    double smoothWeight=0.1;
    // double monoWeight=0.0;
    double mono2Weight=1.0;
    double emptyWeight=2.7;
    double maxWeight=1.0;
    double rtn=0;
    rtn=this->monotonicity2()*mono2Weight+this->smoothness()*smoothWeight+this->empty_cell()*emptyWeight+this->max_num()*maxWeight;
    return rtn;
}
int gtable::max_num(void){
    int max_num=0;
    for(int j=0;j<TABLE_LENGTH;j++){
        for(int i=0;i<TABLE_LENGTH;i++){
            if(content[i][j]>max_num)max_num=content[i][j];
        }
    }
    return max_num;
}
int gtable::empty_cell(void){
    int empty_num=0;
    for(int j=0;j<TABLE_LENGTH;j++){
        for(int i=0;i<TABLE_LENGTH;i++){
            if(content[i][j]==0)empty_num++;
        }
    }
    return empty_num;
}
double gtable::monotonicity2(void){
    // double 
    return 0;
}
double gtable::smoothness(void){
    double smoothness=0;
    int cnt;
    for(int j=0;j<TABLE_LENGTH-1;j++){
        for(int i=0;i<TABLE_LENGTH-1;i++){
            if(content[i][j]!=0){
                if(content[i+1][j]!=0){
                    smoothness+=(content[i+1][j]-content[i][j])*(content[i+1][j]-content[i][j]);
                    cnt++;
                }
                if(content[i][j+1]!=0){
                    smoothness+=(content[i][j+1]-content[i][j])*(content[i][j+1]-content[i][j]);
                    cnt++;
                }
            }
        }
    }
    smoothness/=cnt;
    return smoothness;
}

int main(){     //主控
    //SetConsoleTitle("2048 GAME!");
    srand((unsigned int)time(NULL));
    int cmd;
    while (1)
    {
        system("cls");
        start_win_show();
        printf("\n\n\n\n\n");
        Sleep(200);
        fflush(stdin);
        wait();
        cmd=menu_win_show_back();
        if(cmd==MENU_CMD_EXIT){
            return 0;
        }else if(cmd==MENU_CMD_QUICK_START){
            game_process(MODE_NORMAL);
        }else if(cmd==MENU_CMD_MODE_CHOOSE){
            cout<<"\n\n\n\n\n\t\t开发中";
            Sleep(1000);
        }else if(cmd==MENU_CMD_OPTIONS){
            cout<<"\n\n\n\n\n\t\t开发中";
            Sleep(1000);
        }

        
    }
    
    system("pause");
    return 0;
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
    fflush(stdin);
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
    int max_optionid=3;
    printf("\n\n\n\n\n\n\n\n");
    printf("                                     MAIN MENU                   \n");
    printf("\n");
    printf("                                  # Quick start                 \n");
    printf("                                    Mode chooce                 \n");
    printf("                                      Options                     \n");
    printf("                                       Exit                     \n");
    while(1){           //选择界面
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
                printf("                                       Exit                     \n");
            }
            if(selected_id==1){
                system("cls");
                printf("\n\n\n\n\n\n\n\n");
                printf("                                     MAIN MENU                   \n");
                printf("\n");
                printf("                                    Quick start                 \n");
                printf("                                  # Mode chooce                 \n");
                printf("                                      Options                     \n");
                printf("                                       Exit                     \n");
            }
            if(selected_id==2){
                system("cls");
                printf("\n\n\n\n\n\n\n\n");
                printf("                                     MAIN MENU                   \n");
                printf("\n");
                printf("                                    Quick start                 \n");
                printf("                                    Mode chooce                 \n");
                printf("                                  #   Options                     \n");
                printf("                                       Exit                     \n");
            }
            if(selected_id==3){
                system("cls");
                printf("\n\n\n\n\n\n\n\n");
                printf("                                     MAIN MENU                   \n");
                printf("\n");
                printf("                                    Quick start                 \n");
                printf("                                    Mode chooce                 \n");
                printf("                                      Options                     \n");
                printf("                                  #    Exit                     \n");
            }
            ch=0;
            last_selected_id=selected_id;
        }
        Sleep(100);
        flag=1;
        
    }
    int cmd=0;
    switch (selected_id)        //后台处理
    {
    case 0:     //快速开始
        cmd=MENU_CMD_QUICK_START;
        break;
    case 1:     //选择模式
        cmd=MENU_CMD_MODE_CHOOSE;
        break;
    case 2:     //设置
        cmd=MENU_CMD_OPTIONS;
        break;
    case 3:
        cmd=MENU_CMD_EXIT;
        break;
    default:
        break;
    }

    return cmd;
}

int pause_win_show(void){

    return 0;
}

int lose_win_show(){
    int cmd=0;
    cout<<"\nyou lose.\n";
    system("pause");
    return cmd;
}

int game_process(int gmode){
    system("cls");
    gtable Gtable;
    Gtable.reset();
    Gtable.place_num();
    Gtable.place_num();
    Gtable.draw();
    int ch=0;
    while(1){
        if(_kbhit()){
            ch=_getch();
        }
        switch (ch)
        {
        case key_esc:
            /* return CMD_EXIT;
            break; */
        case key_p:
            pause_win_show();
            break;
        case Left_Arrow:
            if(Gtable.is_lose()){
                lose_win_show();
                //(失败界面后端)
            }
            //cout<<"Left_Arrow";
            if(Gtable.move_left()){
                Gtable.draw();
                Gtable.place_num();
                Sleep(500);
                Gtable.draw();
            }
            break;
        case Up_Arrow:
            if(Gtable.is_lose()){
                lose_win_show();
                //(失败界面后端)
            }
            //cout<<"Up_Arrow";
            if(Gtable.move_up()){
                Gtable.draw();
                Gtable.place_num();
                Sleep(500);
                Gtable.draw();
            }
            break;
        case Right_Arrow:
            if(Gtable.is_lose()){
                lose_win_show();
                //(失败界面后端)
            }
            //cout<<"Right_Arrow";
            if(Gtable.move_right()){
                Gtable.draw();
                Gtable.place_num();
                Sleep(500);
                Gtable.draw();
            }
            break;
        case Dw_Arrow:
            //cout<<"Dw_Arrow";
            if(Gtable.is_lose()){
                lose_win_show();
                //(失败界面后端)
            }
            if(Gtable.move_down()){
                Gtable.draw();
                Gtable.place_num();
                Sleep(500);
                Gtable.draw();
            }
            break;
        default:
            ch=0;
            break;
        }
        ch=0;
    }
}

int wait(int has_key,char key){
    /* int tmp=_kbhit();
    cout<<"\n"<<tmp; */
    /* tmp=_kbhit();
    cout<<"\n"<<tmp; */
    
    Sleep(1000);
    if(has_key){
        do{
            printf("\r                             Press '%c' to continue",key);
            Sleep(500);
            printf("\r                                                   ");
            Sleep(500);
        }while(!_kbhit()&&key!=_getch());
        Sleep(100);
        return 0;
    }else{
        do{
            printf("\r                             Press any key to continue");
            Sleep(500);
            printf("\r                                                      ");
            Sleep(500);
        }while(!_kbhit());
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
