#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct cha
{
	int atk;
	int def;
	int hp;
	int spd;
};
//������ɫģ��
int A(a, b, c)
{
	a = a + b - c;
	return a;
}
int as1(a,b,c)
{
	A(a,b,c);
	return a;
}
//ά��ޱ��������
int as2(a,b,c)
{
	a -= 20;
	a = a + b - c;
	return a;
}
int main()
{
	int atk1, def1, hp1, spd1, atk2, def2, hp2, spd2;
	//�����ĸ���������
	int buff1 = 0;//����
	int buff2 = 0;//��Ϣ
	int con = 1;//ά��ޱ����״̬
	int cd = 0;//��������CD
	//������λ
	printf("ά��ޱ����\n");
	printf("����:"); scanf("%d", &atk1);
	printf("����:"); scanf("%d", &def1);
	printf("Ѫ��:"); scanf("%d", &hp1);
	printf("�ٶ�:"); scanf("%d", &spd1);
	printf("ǧ������\n");
	printf("����:"); scanf("%d", &atk2);
	printf("����:"); scanf("%d", &def2);
	printf("Ѫ��:"); scanf("%d", &hp2);
	printf("�ٶ�:"); scanf("%d", &spd2);
	//��������
	struct cha w = { atk1,def1,hp1,spd1 };
	struct cha q = { atk2,def2,hp2,spd2 };
	//������ɫά��ޱ��ǧ��
	while (w.hp > 0 && q.hp > 0)
	{
		     if (w.spd > q.spd)
			 {
				if (cd = 2)
				{
					q.hp = as1(q.hp,q.def,w.atk);
					buff1 = 1;
					//ά��ޱ����
					if (q.hp > 10)
					{
						q.hp -= 10;
						w.hp = as2(w.hp,w.def,q.atk);
					}
					//ǧ�ټ���
					cd = 0;
				}
				else
				{
					if (buff2 == 1)//�ж�ǧ���Ƿ�����Ϣ
					{
						q.hp = A(q.hp,q.def,w.atk);
					}
					else
					{
						if (buff1 == 1)//�ж�ǧ���Ƿ��ڻ���
						{
							q.hp = A(q.hp,q.def,w.atk);
							q.hp = A(q.hp,q.def,q.atk);
						}
						else
						{
							q.hp = A(q.hp, q.def, w.atk);
							w.hp = A(w.hp, w.def, q.atk);
						}
					}
				}
			 }
			 //ά��ޱ����
			 else
			 {
			     if (cd = 2)
				 {
					 if (q.hp > 10)
					 {
						 q.hp -= 10;
						 w.hp = as2(w.hp, w.def, q.atk);
					 }
					 //ǧ�ټ���
					 q.hp = as1(q.hp);
					 buff1 = 1;
					 //ά��ޱ����
					 cd = 0;
				 }
				 else
				 {
					 if (buff2 == 1)//�ж�ǧ���Ƿ�����Ϣ
					 {
						 q.hp = A(q.hp, q.def, w.atk);
					 }
					 else
					 {
						 if (buff1 == 1)//�ж�ǧ���Ƿ��ڻ���
						 {
							 q.hp = A(q.hp, q.def, q.atk);
							 q.hp = A(q.hp, q.def, w.atk);
						 }
						 else
						 {
							 w.hp = A(w.hp, w.def, q.atk);
							 q.hp = A(q.hp, q.def, w.atk);
						 }
					 }
				 }
	          }
			 //ǧ������
			 cd += 1;
	}
	if (w.hp > q.hp)
	{
		printf("ά��ޱ��ʤ");
	}
	else
	{
		printf("ǧ�ٻ�ʤ");
	}

	return 0;
}