#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>      //��ȡ�����¼�
#include <vector>
#include <windows.h>
using namespace std;
//����
#define TABLE_LENGTH 4
#define Left_Arrow 75
#define Up_Arrow 72
#define Right_Arrow 77
#define Dw_Arrow 80

//���ܺ���
int start_win_show();       //��ʼ����
int menu_win_show_back();       //��ʼ�˵�
int set_difficulty(int diffct=0);       //ѡ���Ѷ�
int set_game_mode(int gmode);       //ѡ����Ϸģʽ
int evaluate(void);     //�������ۺ���
int win_judge(void);        //�ж���Ӯ
int place_num(void);        //�������2��4
int lose_win_show(void);        //ʧ�ܽ���ǰ��
int lose_win_back(int cmd);     //ʧ�ܽ�����
int pause_win_show(void);       //��ͣ����ǰ��
int pause_win_back(int cmd);        //��ͣ������

//���ߺ���
/* void SetWindowSize(int cols, int lines);
void SetCursorPosition(const int x, const int y);
void SetColor(int colorID);
void SetBackColor(); */
int wait(int has_key=0,char key='c');
//��
class gtable{
public:
    int content[TABLE_LENGTH][TABLE_LENGTH];
    void draw(void);        //����
    void reset(void);       //����
    int operate(int direction);     //����ֵ��ʾ�����ɹ����
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

int main(){     //����
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
    switch (selected_id)        //��̨����
    {
    case 0:     //���ٿ�ʼ
        break;
    case 1:     //ѡ��ģʽ
        break;
    case 2:     //����
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
/* void SetWindowSize(int cols, int lines)//���ô��ڴ�С
{
    system("title ̰����");//���ô��ڱ���
    char cmd[30];
    sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, lines);//һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
    system(cmd);//system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�
}

void SetCursorPosition(const int x, const int y)//���ù��λ��
{
    COORD position;
    position.X = x * 2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetColor(int colorID)//�����ı���ɫ
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}

void SetBackColor()//�����ı�����ɫ
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                            FOREGROUND_BLUE |
                            BACKGROUND_BLUE |
                            BACKGROUND_GREEN |
                            BACKGROUND_RED );
} */
