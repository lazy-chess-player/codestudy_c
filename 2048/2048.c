#define _CRT_SECURE_NO_DEPRECATE 
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

//��������
void start_game(); //��ʼ��Ϸ
void reset_game(); //������Ϸ

//�����������ĸ������ƶ�
void move_left();
void move_right();
void move_up();
void move_down();

void refresh_show();//ˢ�½���
void add_rand_num();//���������
void check_game_over();//����Ƿ������Ϸ
int get_null_count();//��ȡ��Ϸ����Ͽ�λ������
void player_action();//����ж�

//ȫ�ֱ���
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
    reset_game();//ˢ����Ϸ����
    char cmd;//����ָ��洢�ռ�
    while (1)
    {
        cmd = getch();//���ձ����ַ�����
        if (if_game_over)//�ж��Ƿ������Ϸ
        {
            if (cmd == 'y' || cmd == 'Y')
            {
                reset_game();//����y/N���½�����Ϸ
                continue;
            }
            else if (cmd == 'n' || cmd == 'N')
                return;//��������
            else
                continue;//��Ч��������ѭ��
        }
        player_action();
        score > best ? best = score : 1;//����¼�Ƿ񱻴���
        check_game_over();
        if (!if_game_over)
        {
            add_rand_num();
            refresh_show();
        }
    }
}

//�������̲������������������ƶ�
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
//������Ϸ
void reset_game()
{
    score = 0;
    if_game_over = 0;

    //�����λ�����ɳ�ʼ��
    add_rand_num();
    add_rand_num();

    //��ʾ����
    system("cls");
    refresh_show();
}

//���������
void add_rand_num()
{
    srand(time(NULL));
    int n = rand() % get_null_count();//�������һ��λ�����������
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0 && n-- == 0)
            {
                board[i][j] = (rand() % 3 ? 2 : 4);//�����������2�ĸ�����4�ĸ��ʵ�����
                return;
            }
        }
    }
}

//����λ������
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

//�����Ϸ�Ƿ����
void check_game_over()
{
    //����Ƿ��п�λ�ã�������Ϸ������
    if (get_null_count)
    {
        if_game_over = 0;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            //���������Ƚϰ��ŵ�����Ԫ���Ƿ���ȣ������������Ϸ������
            if (board[i][j] == board[i][j + 1] || board[j][i] == board[j + 1][i])
            {
                if_game_over = 0;
                return;
            }
        }
    }
    if_game_over = 1;
}

 //���Ʋ���
void move_left()
{
    //��˫ѭ����������
    for (int i = 0; i < 4; i++)
    {
        //jΪ���±꣬kΪ���ϲ����±�
        for (int j = 1, k = 0; j < 4; j++)
        {
            if (board[i][j] > 0) //�ҳ�k�����һ����Ϊ�յ����j���
            {
                if (board[i][k] == board[i][j]) //���1��k��j��ȣ��ϲ����ֲ��Ʒ�
                 {
                    score += board[i][k++] <<= 1;
                    board[i][j] = 0;
                }
                else if (board[i][k] == 0) //���2��kΪ�գ���j��ֵ��k��j�ƶ���k
                {
                    board[i][k] = board[i][j];
                    board[i][j] = 0;
                }
                else //���3��k��Ϊ�գ��Һ�j����ȣ���ʱ��j��ֵ��k+1��j�ƶ���k+1��λ��
                {
                    board[i][++k] = board[i][j];
                    if (j != k) //�ж�j��k�Ƿ�ԭ�ȾͰ���һ�����������j��ֵΪ0
                    {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
}

//���Ʋ���(�����Ʋ�������)
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

//���Ʋ���(�����Ʋ�������)
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

//���Ʋ���(�����Ʋ�������)
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

//��ӡ����
void refresh_show()
{
    system("cls");
    printf("      ��Ϸ: 2048     ����: %06d    ��߼�¼: %06d\n", score, best);
    printf("   --------------------------------------------------\n\n");
    printf("                �����������Щ��������Щ��������Щ���������\n");
    for (int i = 0; i < 4; i++)
    {
        printf("                ��");
        for (int j = 0; j < 4; j++)
        {
            //�ж����ִ�С����ֹ��ֵ����Խ�磬Ӱ������
            if (board[i][j] != 0)
            {
                if (board[i][j] < 10)
                    printf("  %d ��", board[i][j]);
                else if (board[i][j] < 100)
                    printf(" %d ��", board[i][j]);
                else if (board[i][j] < 1000)
                    printf(" %d��", board[i][j]);
                else if (board[i][j] < 10000)
                    printf("%4d��", board[i][j]);
                else
                {
                    int n = board[i][j];
                    for (int k = 1; k < 20; k++)
                    {
                        n >>= 1;
                        if (n == 1)
                        {
                            printf("2^%02d��", k);//������ʾλ�õ������ݼ�¼
                            break;
                        }
                    }
                }
            }
            else printf("    ��");
        }
        if (i < 3)
            printf("\n                �����������੤�������੤�������੤��������\n");
        else
            printf("\n                �����������ة��������ة��������ة���������\n");
    }
    printf("\n");
    printf("   --------------------------------------------------\n");
    printf("                    W��  A��  ��S  ��D");
    printf("\n             ��Ϸ�������Ƿ������Ϸ? [Y/N]");
    check_game_over();
    if (if_game_over)//�ж��Ƿ������Ϸ
        printf("\n                   ��Ϸ�������Ƿ������Ϸ? [Y/N]");
}