#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100    // 定义栈的最大长度

typedef int ElemType;   // 定义栈元素的数据类型

typedef struct
{
    ElemType* base;    // 指向栈底的指针
    ElemType* top;     // 指向栈顶的指针
    int stacksize;     // 栈的当前容量
} SqStack;            // 定义顺序栈的类型

// 初始化操作
void InitStack(SqStack* S)
{
    S->base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));  // 分配存储空间
    if (!S->base)  // 分配失败
    {
        exit(1);
    }
    S->top = S->base;   // 栈顶和栈底指针初始指向同一位置
    S->stacksize = MAXSIZE;   // 栈的最大容量
}

// 销毁栈操作
void DestroyStack(SqStack* S)
{
    free(S->base);   // 释放存储空间
    S->base = S->top = NULL;   // 将栈底和栈顶指针置为NULL
    S->stacksize = 0;   // 当前栈的容量为0
}

// 判定S是否为空栈
bool StackEmpty(SqStack S)
{
    if (S.top == S.base)  // 栈顶和栈底指针相同时，即栈为空
        return true;   // 返回TRUE
    else
        return false;   // 返回FALSE
}

// 求栈的长度
int StackLength(SqStack S)
{
    return (S.top - S.base);  // 栈顶指针减去栈底指针就是栈的长度
}

// 取栈顶元素操作
bool GetTop(SqStack S, ElemType* e)
{
    if (S.top == S.base) // 栈为空时，返回FALSE
        return false;
    *e = *(S.top - 1);   // 栈顶元素的值赋给e
    return true;
}

// 栈置空操作
void ClearStack(SqStack* S)
{
    S->top = S->base;   // 将栈顶和栈底指针指向同一位置
}

// 插入元素e为新的栈顶元素
void Push(SqStack* S, ElemType e)
{
    if (S->top - S->base == S->stacksize) // 栈满时，扩充存储空间
    {
        S->base = (ElemType*)realloc(S->base, (S->stacksize + MAXSIZE) * sizeof(ElemType));
        if (!S->base)
        {
            exit(1);
        }
        S->top = S->base + S->stacksize; // 栈底指针不变，栈顶指针指向新的位置
        S->stacksize += MAXSIZE;         // 栈的最大容量增加 MAXSIZE
    }
    *(S->top++) = e;  // 元素 e 入栈，栈顶指针加1
}

// 删除S的栈顶元素an
bool Pop(SqStack* S)
{
    if (S->top == S->base) // 栈为空时，返回FALSE
    {
        return false;
    }
    S--;
    return true;
}