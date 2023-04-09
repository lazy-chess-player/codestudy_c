#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//引用头文件

typedef int ElemType;//自定义数据元素类型，这里在链表中存储的数据元素类型为int

typedef struct Lnode
{
	 ElemType data;//数据域
	 Lnode* next;//指针域
}Lnode,*LinkList;//将这个数据结构用typedef定义为Lnode,Lnode的指针Lnode*定义为LinkList，增加代码可读性，方便创建指针

//单链表初始化
bool InitList(LinkList L)
{
	L = (LinkList)malloc(sizeof(Lnode));
	if (!L)
		return false;//判断是否开辟空间失败，失败则返回false报错
	L->next = NULL;//将next指针置空
	return true;//初始化完成返回true
}

//头插法建立单链表
bool CreateListH(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(Lnode));
	if (!L)
		return false;
	L->next = NULL;
	//建立一个带头结点的单链表

	LinkList p = NULL;
	for (int i = n; i > 0; --i)
	{
		p = (LinkList)malloc(sizeof(Lnode));
		if (!p)
			return false;
		p->next = NULL; 
		//生成新结点p

		scanf("%d",p->data);//输入元素值

		p->next = L->next;
		L->next = p;
		//插入到表头
	}
	return true;
}

//尾插法建立单链表
bool CreateListR(LinkList L, int n)
{
	L = (LinkList)malloc(sizeof(Lnode));
	if (!L)
		return false;
	L->next = NULL;
	//建立一个带头结点的单链表
	
	LinkList r = L;//创建尾指针r指向头结点
	LinkList p = NULL;
	for (int i = 0; i < n; ++i)
	{
		p = (LinkList)malloc(sizeof(Lnode));
		if (!p)
			return false;
		p->next = NULL; 
		//生成新结点p

		scanf("%d", p->data);//输入元素值

		r->next = p;//插入到表尾
		r = p;//r指向新的尾结点
	}
}

//判断链表是否为空表
bool ListEmpty(LinkList L)
{
	if (L->next)//为空表的话next指针为NULL
		return false;
	else
		return true;
}

//销毁单链表
void DestoryList(LinkList L)
{
	LinkList p;//创建缓存指针，放置地址丢失
	while (L)//当L非空时一直循环，直到指向NULL
	{
		p = L;//缓存指向这个结点的指针
		L = L->next;//将指向这个结点的指针指向下一个结点
		free(p);//释放这个结点的空间
		p = NULL;//将p置空，防止出现野指针
	}
}


//清空单链表
void ClearList(LinkList L)
{
	LinkList p, q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}//步骤与销毁单链表一致，只不过跳过了头结点，从首元结点开始销毁
	L->next = NULL;//销毁完寿元结点之后的结点后将头结点的指针域置空
}

//获得单链表的表长
int ListLength(LinkList L)
{
	LinkList p;
	p = L->next;//将p指向首元结点
	int cnt = 0;//创建计数器
	while (p)//直到p指向尾结点的指针域即p为空的情况下停止
	{
		cnt++;//没经过一个结点，计数器cnt加1
		p = p->next;//将p从这个结点转变为指向下一个结点
	}
	return cnt;
}

//查找第i个结点的值
bool GetElemI(LinkList L, int i,ElemType* e)//用e来获得第i个元素的值
{
	LinkList p = L->next;
	int j = 1;
	//初始化

	while (p&& j < i)//向后遍历，直到p指向第i个元素或p为空
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return false;//第i个元素不存在则返回false报错

	*e = p->data;//把第i个元素存进e中
	return true;
}

//查找值为e的元素的位置
LinkList LocateELem(LinkList L, ElemType e)
{
	LinkList p = L->next;
	while (p && p->data != e)//向后遍历直到找到值为e的数据元素的地址或p指向NULL
		p = p->next;
	return p;
}

//在指定位置i插入结点
bool ListInsert(LinkList L, int i, ElemType e)
{
	LinkList p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}//寻找第i-1个结点，p指向i-1结点
	if (!p || j > i - 1 || i < 1)
		return false;//如果i>表长或者小于1，插入位置非法,返回fales报错

	LinkList s = (LinkList)malloc(sizeof(Lnode));//生成新结点s
	s->data = e;//将结点s的数据域置为e

	s->next = p->next;
	p->next = s;
	//将结点s插入L中

	return true;
}

// 删除链表中第i个数据元素
bool ListDeleteI(LinkList L, int i)
{
	LinkList p = L; 
	int j = 0;
	//初始化

	while (p->next&& j < i - 1)
	{
		p = p->next;
		j++;
	}//寻找第i个结点，并令p指向其前驱

	if (!(p->next)||j > i - 1)
		return false;//如果删除位置非法，返回false报错

	LinkList q = p->next; //临时保存被删结点的地址以备释放
	p->next = q->next;//将删除结点的前驱结点的指针域指向删除结点的后继结点
	free(q);
	q = NULL;//释放删除结点的空间
	return true;
}

//循环链表的合并
LinkList Connect(LinkList Ra, LinkList Rb)//假设Ra、Rb都是非空的单循环链表
{
	LinkList p = Ra->next;//①p存表头结点
	Ra->next = Rb->next->next;//②Rb表头连结Ra表尾
	free(Rb->next);//③释放Tb表头结点
	Rb->next = p;//④修改指针
	return Rb;
}

//双向链表的定义
typedef struct DuLNode{
	ElemType data;
	DuLNode* prior, * next;
} DuLNode, * DuLinkList;