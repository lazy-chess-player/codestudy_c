#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;   // 定义栈元素的数据类型

typedef struct StackNode
{
    ElemType data;         // 数据域
    struct StackNode* next;   // 指向下一个结点的指针
} StackNode, * LinkStack;     // 定义链栈栈的类型

// 初始化操作
void InitStack(LinkStack* S)
{
    *S = NULL;   // 初始化栈顶指针为空
}

// 判定S是否为空栈
bool StackEmpty(LinkStack S)
{
    if (S == NULL)   // 栈顶指针为空时，即栈为空
        return true;
    else
        return false;
}

// 求栈的长度
int StackLength(LinkStack S)
{
    int len = 0;      // 栈的长度
    while (S != NULL)
    {
        S = S->next;  // 栈顶指针向下移动
        len++;       // 栈的长度加1
    }
    return len;
}

// 取栈顶元素操作
bool GetTop(LinkStack S, ElemType* e)
{
    if (S == NULL) // 栈为空时，返回FALSE
        return false;
    *e = S->data;   // 栈顶元素的值赋给e
    return true;
}

// 栈置空操作
void ClearStack(LinkStack* S)
{
    StackNode* p;
    while (*S != NULL)
    {
        p = *S;     // 指向栈顶结点
        *S = (*S)->next;   // 栈顶指针指向下一个结点
        free(p);    // 释放当前结点的内存空间
    }
}

// 插入元素e为新的栈顶元素
void Push(LinkStack* S, ElemType e)
{
    StackNode* p;
    p = (StackNode*)malloc(sizeof(StackNode));  // 创建新结点
    if (!p)   // 分配内存失败
    {
        exit(1);
    }
    p->data = e;     // 将元素e赋值给新结点的数据域
    p->next = *S;    // 新结点的next指针指向原栈顶指针指向的结点
    *S = p;          // 修改栈顶指针指向新的结点
}

// 删除S的栈顶元素an
bool Pop(LinkStack* S)
{
    StackNode* p;
    if (*S == NULL) // 栈为空时，返回FALSE
        return false;
    p = *S;         // p指向栈顶结点
    *S = p->next;   // 栈顶指针指向下一个结点
    free(p);        // 释放当前结点的内存空间
    return true;
}
