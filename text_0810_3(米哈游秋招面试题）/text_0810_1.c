#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

struct cha
{
	int atk;
	int def;
	int hp;
	int spd;
};
//创建角色模板
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
//维尔薇主动技能
int as2(a,b,c)
{
	a -= 20;
	a = a + b - c;
	return a;
}
int main()
{
	int atk1, def1, hp1, spd1, atk2, def2, hp2, spd2;
	//创建四个基础属性
	int buff1 = 0;//混乱
	int buff2 = 0;//休息
	int con = 1;//维尔薇被动状态
	int cd = 0;//主动技能CD
	//创建槽位
	printf("维尔薇属性\n");
	printf("攻击:"); scanf("%d", &atk1);
	printf("防御:"); scanf("%d", &def1);
	printf("血量:"); scanf("%d", &hp1);
	printf("速度:"); scanf("%d", &spd1);
	printf("千劫属性\n");
	printf("攻击:"); scanf("%d", &atk2);
	printf("防御:"); scanf("%d", &def2);
	printf("血量:"); scanf("%d", &hp2);
	printf("速度:"); scanf("%d", &spd2);
	//属性输入
	struct cha w = { atk1,def1,hp1,spd1 };
	struct cha q = { atk2,def2,hp2,spd2 };
	//创建角色维尔薇和千劫
	while (w.hp > 0 && q.hp > 0)
	{
		     if (w.spd > q.spd)
			 {
				if (cd = 2)
				{
					q.hp = as1(q.hp,q.def,w.atk);
					buff1 = 1;
					//维尔薇技能
					if (q.hp > 10)
					{
						q.hp -= 10;
						w.hp = as2(w.hp,w.def,q.atk);
					}
					//千劫技能
					cd = 0;
				}
				else
				{
					if (buff2 == 1)//判断千劫是否处于休息
					{
						q.hp = A(q.hp,q.def,w.atk);
					}
					else
					{
						if (buff1 == 1)//判断千劫是否处于混乱
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
			 //维尔薇先手
			 else
			 {
			     if (cd = 2)
				 {
					 if (q.hp > 10)
					 {
						 q.hp -= 10;
						 w.hp = as2(w.hp, w.def, q.atk);
					 }
					 //千劫技能
					 q.hp = as1(q.hp);
					 buff1 = 1;
					 //维尔薇技能
					 cd = 0;
				 }
				 else
				 {
					 if (buff2 == 1)//判断千劫是否处于休息
					 {
						 q.hp = A(q.hp, q.def, w.atk);
					 }
					 else
					 {
						 if (buff1 == 1)//判断千劫是否处于混乱
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
			 //千劫先手
			 cd += 1;
	}
	if (w.hp > q.hp)
	{
		printf("维尔薇获胜");
	}
	else
	{
		printf("千劫获胜");
	}

	return 0;
}