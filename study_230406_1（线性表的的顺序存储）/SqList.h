#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//引用头文件

#define MAXLENGTH 100

typedef struct ElemType
{
    int data;
}ElemType;
//利用结构体储存数据元素，并命名为为ElemType，方便调用
//数据元素可以为任意数据类型,这里的数据元素为整形

typedef struct SqList
{
    ElemType* elem;
    //开辟数组空间
    int length;
    //存储线性表的表长
} SqList;
//创建结构体，包含数据元素数组和表长。

void InitList(SqList* L)
{
    L->elem = (ElemType*)malloc(sizeof(ElemType) * MAXLENGTH);
    //利用malloc开辟一块动态的储存空间
    L->length = MAXLENGTH;
    //MAXLENGTH一般由我们自己利用宏来定义，为线性表初始表长
    assert("初始化失败" && L->elem != NULL);
    //断言开辟空间成功，失败则停止程序
}

void DestroyList(SqList& L)
{
    free(L.elem);
    //释放线性表的存储空间
    L.elem = NULL;
    //将指针置空
    L.length = 0;
    //将长度归零
}

void ClearList(SqList& L)
{
    L.length = 0;
    //将长度归零
}

// 若线性表L为空表，则返回TRUE；否则返回FALSE
bool ListEmpty(SqList L)
{
    if (L.length == 0)
        return true;
    else
        return false;
}

// 返回线性表L中的数据元素个数
int ListLength(SqList L)
{
    return L.length;
}

// 用e返回线性表L中第i个数据元素的值
bool GetElem(SqList L, int i, ElemType& e)
{
    if (i < 1 || i > L.length)
        return false;
    //判断位置是否合法
    e = *(L.elem + i - 1);
    return true;
}

// 返回L中第1个与e满足compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0。
int LocateElem(SqList L, ElemType e, bool(*compare)(ElemType, ElemType))
{
    int i;
    ElemType* p = L.elem;
    //创建索引
    for (i = 1; i <= L.length; i++)
    {
        if (compare(*(p + i - 1), e))
            return i;
    }
    //枚举寻找目标元素，可以优化使用其他寻找方式
    return 0;
}

// 若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败；pre_e无意义。
bool PriorElem(SqList L, ElemType cur_e, ElemType& pre_e)
{
    int i;
    for (i = 2; i <= L.length; i++)
    {
        if ((L.elem + i - 1)->data == cur_e.data)
        {
            pre_e = *(L.elem + i - 2);
            return true;
        }
    }
    //枚举寻找cur_e
    return false;
}

// 若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败；next_e无意义。
bool NextElem(SqList L, ElemType cur_e, ElemType& next_e)
{
    int i;
    for (i = 1; i <= L.length - 1; i++)
    {
        if ((L.elem + i - 1)->data == cur_e.data)
        {
            next_e = *(L.elem + i);
            return true;
        }
    }
    //枚举寻找cur_e
    return false;
}

// 在L的第i个位置之前插入新的数据元素e，L的长度加1。
bool ListInsert(SqList& L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false; 
    //判断插入位置是否合法
    ElemType* q = &(L.elem[i - 1]);
    //q为插入位置
    for (ElemType* p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p + 1) = *p;
    //插入位置及之后的元素右移
    *q = e;
    ++L.length; 
    //长度加1
    return true;
}

// 删除L的第i个数据元素,并用e返回其值，L的长度减一。
bool ListDelete(SqList& L, int i, ElemType& e)
{
    if (i < 1 || i > L.length)
        return false;
    //判断删除位置是否合法
    ElemType* p = &(L.elem[i - 1]);
    //p为被删除元素的位置
    e = *p; // 被删除元素的值赋给e
    ElemType* q = L.elem + L.length - 1;
    //表尾元素位置
    for (++p; p <= q; ++p) *(p - 1) = *p;
    //被删除元素之后的元素左移
    --L.length;
    //长度减1
    return true;
}

// 依次对线性表中每个元素调用visit()，一旦visit()失败，则操作失败。
void ListTraverse(SqList L, void(*visit)(ElemType))
{
    ElemType *p = L.elem;
    for (int i = 1; i <= L.length; ++i)
        visit(*(p++));
}