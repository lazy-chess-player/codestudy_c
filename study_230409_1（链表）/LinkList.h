#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//����ͷ�ļ�

typedef int ElemType;//�Զ�������Ԫ�����ͣ������������д洢������Ԫ������Ϊint

typedef struct Lnode
{
	 ElemType data;//������
	 Lnode* next;//ָ����
}Lnode,*LinkList;//��������ݽṹ��typedef����ΪLnode,Lnode��ָ��Lnode*����ΪLinkList�����Ӵ���ɶ��ԣ����㴴��ָ��

//�������ʼ��
bool InitList(LinkList L)
{
	L = (LinkList)malloc(sizeof(Lnode));
	if (!L)
		return false;//�ж��Ƿ񿪱ٿռ�ʧ�ܣ�ʧ���򷵻�false����
	L->next = NULL;//��nextָ���ÿ�
	return true;//��ʼ����ɷ���true
}

//ͷ�巨����������
bool CreateListH(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(Lnode));
	if (!L)
		return false;
	L->next = NULL;
	//����һ����ͷ���ĵ�����

	LinkList p = NULL;
	for (int i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(Lnode));
		if (!p)
			return false;
		p->next = NULL; 
		//�����½��p

		scanf("%d",p->data);//����Ԫ��ֵ

		p->next = L->next;
		L->next = p;
		//���뵽��ͷ
	}
	return true;
}

//β�巨����������
bool CreateListR(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(Lnode));
	if (!L)
		return false;
	L->next = NULL;
	//����һ����ͷ���ĵ�����
	
	LinkList r = L;//����βָ��rָ��ͷ���
	LinkList p = NULL;
	for (int i = 0; i < n; ++i)
	{
		p = (LinkList)malloc(sizeof(Lnode));
		if (!p)
			return false;
		p->next = NULL; 
		//�����½��p

		scanf("%d", p->data);//����Ԫ��ֵ

		r->next = p;//���뵽��β
		r = p;//rָ���µ�β���
	}
}

//�ж������Ƿ�Ϊ�ձ�
bool ListEmpty(LinkList L)
{
	if (L->next)//Ϊ�ձ�Ļ�nextָ��ΪNULL
		return false;
	else
		return true;
}

//���ٵ�����
void DestoryList(LinkList L)
{
	LinkList p;//��������ָ�룬���õ�ַ��ʧ
	while (L)//��L�ǿ�ʱһֱѭ����ֱ��ָ��NULL
	{
		p = L;//����ָ���������ָ��
		L = L->next;//��ָ���������ָ��ָ����һ�����
		free(p);//�ͷ�������Ŀռ�
		p = NULL;//��p�ÿգ���ֹ����Ұָ��
	}
}


//��յ�����
void ClearList(LinkList L)
{
	LinkList p, q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}//���������ٵ�����һ�£�ֻ����������ͷ��㣬����Ԫ��㿪ʼ����
	L->next = NULL;//��������Ԫ���֮��Ľ���ͷ����ָ�����ÿ�
}

//��õ�����ı�
int ListLength(LinkList L)
{
	LinkList p;
	p = L->next;//��pָ����Ԫ���
	int cnt = 0;//����������
	while (p)//ֱ��pָ��β����ָ����pΪ�յ������ֹͣ
	{
		cnt++;//û����һ����㣬������cnt��1
		p = p->next;//��p��������ת��Ϊָ����һ�����
	}
	return cnt;
}

//���ҵ�i������ֵ
bool GetElemI(LinkList L, int i,ElemType* e)//��e����õ�i��Ԫ�ص�ֵ
{
	LinkList p = L->next;
	int j = 1;
	//��ʼ��

	while (p&& j < i)//��������ֱ��pָ���i��Ԫ�ػ�pΪ��
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return false;//��i��Ԫ�ز������򷵻�false����

	*e = p->data;//�ѵ�i��Ԫ�ش��e��
	return true;
}

//����ֵΪe��Ԫ�ص�λ��
LinkList LocateELem(LinkList L, ElemType e)
{
	LinkList p = L->next;
	while (p && p->data != e)//������ֱ���ҵ�ֵΪe������Ԫ�صĵ�ַ��pָ��NULL
		p = p->next;
	return p;
}

//��ָ��λ��i������
bool ListInsert(LinkList L, int i, ElemType e)
{
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}//Ѱ�ҵ�i-1����㣬pָ��i-1���
	if (!p || j > i - 1 || i < 1)
		return false;//���i>������С��1������λ�÷Ƿ�,����fales����

	LinkList s = (LinkList)malloc(sizeof(Lnode));//�����½��s
	s->data = e;//�����s����������Ϊe

	s->next = p->next;
	p->next = s;
	//�����s����L��

	return true;
}

// ɾ�������е�i������Ԫ��
bool ListDeleteI(LinkList L, int i)
{
	LinkList p = L; 
	int j = 0;
	//��ʼ��

	while (p->next&& j < i - 1)
	{
		p = p->next;
		j++;
	}//Ѱ�ҵ�i����㣬����pָ����ǰ��

	if (!(p->next)||j > i - 1)
		return false;//���ɾ��λ�÷Ƿ�������false����

	LinkList q = p->next; //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
	p->next = q->next;//��ɾ������ǰ������ָ����ָ��ɾ�����ĺ�̽��
	free(q);
	q = NULL;//�ͷ�ɾ�����Ŀռ�
	return true;
}

//ѭ������ĺϲ�
LinkList Connect(LinkList Ra, LinkList Rb)//����Ra��Rb���Ƿǿյĵ�ѭ������
{
	LinkList p = Ra->next;//��p���ͷ���
	Ra->next = Rb->next->next;//��Rb��ͷ����Ra��β
	free(Rb->next);//���ͷ�Tb��ͷ���
	Rb->next = p;//���޸�ָ��
	return Rb;
}

//˫������Ķ���
typedef struct DuLNode{
	ElemType data;
	DuLNode* prior, * next;
} DuLNode, * DuLinkList;