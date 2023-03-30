#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

//函数声明
void start_game(); //开始游戏
void reset_game(); //重置游戏

//往左右上下四个方向移动
void move_left();
void move_right();
void move_up();
void move_down();

void refresh_show();//刷新界面
void add_rand_num();//生成随机数
void check_game_over();//检测是否输掉游戏
int get_null_count();//获取游戏面板上空位置数量
void player_action();//玩家行动

//全局变量
int board[4][4];
int score; 
int best;
int if_game_over;


int main()
{
    start_game();
    return 0;
}

void start_game()
{
    reset_game();//刷新游戏界面
    char cmd;//开辟指令存储空间
    while (1)
    {
        cmd = getch();//接收标入字符命令
        if (if_game_over)//判断是否输掉游戏
        {
            if (cmd == 'y' || cmd == 'Y')
            {
                reset_game();//输入y/N重新进行游戏
                continue;
            }
            else if (cmd == 'n' || cmd == 'N')
                return;//结束函数
            else
                continue;//无效输入重新循环
        }
        player_action();
        score > best ? best = score : 1;//检测记录是否被打破
        check_game_over();
        if (!if_game_over)
        {
            add_rand_num();
            refresh_show();
        }
    }
}

//解析键盘操作，进行上下左右移动
void player_action()
{
    char act_cmd = getch();
    switch (act_cmd)
    {
    case 'a':
    case 'A':
    case 75:
        move_left();
        break;
    case 's':
    case 'S':
    case 80:
        move_down();
        break;
    case 'w':
    case 'W':
    case 72:
        move_up();
        break;
    case 'd':
    case 'D':
    case 77:
        move_right();
        break;
    }
}
//重置游戏
void reset_game()
{
    score = 0;
    if_game_over = 0;

    //在随机位置生成初始数
    add_rand_num();
    add_rand_num();

    //显示界面
    system("cls");
    refresh_show();
}

//生成随机数
void add_rand_num()
{
    srand(time(NULL));
    int n = rand() % get_null_count();//随机生成一个位置生成随机数
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0 && n-- == 0)
            {
                board[i][j] = (rand() % 3 ? 2 : 4);//生成随机数，2的概率是4的概率的两倍
                return;
            }
        }
    }
}

//检测空位置数量
int get_null_count()
{
    int n = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] == 0 ? n++ : 1;
        }
    }
    return n;
}

//检查游戏是否结束
void check_game_over()
{
    //检查是否有空位置，有则游戏不结束
    if (get_null_count)
    {
        if_game_over = 0;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //横向和纵向比较挨着的两个元素是否相等，若有相等则游戏不结束
            if (board[i][j] == board[i][j + 1] || board[j][i] == board[j + 1][i])
            {
                if_game_over = 0;
                return;
            }
        }
    }
    if_game_over = 1;
}

 //左移操作
void move_left()
{
    //用双循环遍历数组
    for (int i = 0; i < 4; i++)
    {
        //j为列下标，k为待合并项下标
        for (int j = 1, k = 0; j < 4; j++)
        {
            if (board[i][j] > 0) //找出k后面第一个不为空的项，用j标记
            {
                if (board[i][k] == board[i][j]) //情况1：k和j相等，合并数字并计分
                 {
                    score += board[i][k++] <<= 1;
                    board[i][j] = 0;
                }
                else if (board[i][k] == 0) //情况2：k为空，把j赋值给k，j移动到k
                {
                    board[i][k] = board[i][j];
                    board[i][j] = 0;
                }
                else //情况3：k不为空，且和j不相等，此时把j赋值给k+1，j移动到k+1的位置
                {
                    board[i][++k] = board[i][j];
                    if (j != k) //判断j和k是否原先就挨在一起，若不是则把j赋值为0
                    {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
}

//右移操作(与左移操作类似)
void move_right()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 2, k = 3; j >= 0; j--)
        {
            if (board[i][j] > 0)
            {
                if (board[i][k] == board[i][j])
                {
                    score += board[i][k--] <<= 1;
                    board[i][j] = 0;
                }
                else if (board[i][k] == 0)
                {
                    board[i][k] = board[i][j];
                    board[i][j] = 0;
                }
                else
                {
                    board[i][--k] = board[i][j];
                    if (j != k)
                    {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
}

//上移操作(与左移操作类似)
void move_up()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1, k = 0; j < 4; j++)
        {
            if (board[j][i] > 0)
            {
                if (board[k][i] == board[j][i])
                {
                    score += board[k++][i] <<= 1;
                    board[j][i] = 0;
                }
                else if (board[k][i] == 0)
                {
                    board[k][i] = board[j][i];
                    board[j][i] = 0;
                }
                else
                {
                    board[++k][i] = board[j][i];
                    if (j != k)
                    {
                        board[j][i] = 0;
                    }
                }
            }
        }
    }
}

//下移操作(与左移操作类似)
void move_down()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 2, k = 3; j >= 0; j--)
        {
            if (board[j][i] > 0)
            {
                if (board[k][i] == board[j][i])
                {
                    score += board[k--][i] <<= 1;
                    board[j][i] = 0;
                }
                else if (board[k][i] == 0)
                {
                    board[k][i] = board[j][i];
                    board[j][i] = 0;
                }
                else
                {
                    board[--k][i] = board[j][i];
                    if (j != k)
                    {
                        board[j][i] = 0;
                    }
                }
            }
        }
    }
}

//打印界面
void refresh_show()
{
    system("cls");
    printf("      游戏: 2048     分数: %06d    最高记录: %06d\n", score, best);
    printf("   --------------------------------------------------\n\n");
    printf("                ┌────┬────┬────┬────┐\n");
    for (int i = 0; i < 4; i++)
    {
        printf("                │");
        for (int j = 0; j < 4; j++)
        {
            //判断数字大小，防止数值过大越界，影响美观
            if (board[i][j] != 0)
            {
                if (board[i][j] < 10)
                    printf("  %d │", board[i][j]);
                else if (board[i][j] < 100)
                    printf(" %d │", board[i][j]);
                else if (board[i][j] < 1000)
                    printf(" %d│", board[i][j]);
                else if (board[i][j] < 10000)
                    printf("%4d│", board[i][j]);
                else
                {
                    int n = board[i][j];
                    for (int k = 1; k < 20; k++)
                    {
                        n >>= 1;
                        if (n == 1)
                        {
                            printf("2^%02d│", k);//超出显示位置的数用幂记录
                            break;
                        }
                    }
                }
            }
            else printf("    │");
        }
        if (i < 3)
            printf("\n                ├────┼────┼────┼────┤\n");
        else
            printf("\n                └────┴────┴────┴────┘\n");
    }
    printf("\n");
    printf("   --------------------------------------------------\n");
    printf("                    W↑  A←  ↓S  →D");
    printf("\n             游戏结束！是否继续游戏? [Y/N]");
    check_game_over();
    if (if_game_over)//判断是否输掉游戏
        printf("\n                   游戏结束！是否继续游戏? [Y/N]");
}