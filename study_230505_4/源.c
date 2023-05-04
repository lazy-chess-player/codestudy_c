#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType; // 定义队列元素的数据类型

// 队列结点类型
typedef struct QNode
{
    ElemType data; // 结点的数据域
    struct QNode* next; // 结点的指针域
}QNode, * QuenePtr;

// 链式队列类型
typedef struct
{
    QuenePtr front; // 队头指针，指向队头结点
    QuenePtr rear; // 队尾指针，指向队尾结点
}LinkQuene;

// 初始化队列Q
void InitQuene(LinkQuene* Q)
{
    Q->front = Q->rear = (QuenePtr)malloc(sizeof(QNode)); // 创建头结点
    if (!Q->front) // 内存分配失败
        exit(1);
    Q->front->next = NULL; // 头结点的指针域置空
}

// 销毁队列Q
void DestroyQuene(LinkQuene* Q)
{
    QuenePtr p = Q->front;
    while (p) // 逐个释放结点内存
    {
        Q->front = p->next;
        free(p);
        p = Q->front;
    }
    Q->front = Q->rear = NULL; // 将队列指针置空
}


// 返回队列Q的元素个数，即队列的长度
int QueneLength(LinkQuene Q)
{
    int count = 0;
    QuenePtr p = Q.front->next;
    while (p) // 遍历队列计数
    {
        count++;
        p = p->next;
    }
    return count;
}

// 用e返回队列Q的队头元素
bool GetHead(LinkQuene Q, ElemType* e)
{
    if (Q.front == Q.rear) // 队列为空，无法取出队头元素
        return false;
    *e = Q.front->next->data; // 将队头元素赋值给e
    return true;
}

// 入队操作
bool EnQuene(LinkQuene* Q, ElemType e)
{
    QuenePtr p = (QuenePtr)malloc(sizeof(QNode)); // 创建新结点
    if (!p) // 内存分配失败
        return false;
    p->data = e; // 将元素e存储到新结点中
    p->next = NULL; // 将新结点的next指针置为NULL

    Q->rear->next = p; // 将新结点链接到队尾结点的后面
    Q->rear = p; // 将队尾指针指向新结点

    return true;
}

// 出队操作
bool DeQuene(LinkQuene* Q, ElemType* e)
{
    if (Q->front == Q->rear) // 队列为空，无法出队
        return false;
    QuenePtr p = Q->front->next; // 指向队头结点
    *e = p->data; // 将队头元素赋值给e
    Q->front->next = p->next; // 将队头结点删除
    if (Q->rear == p) // 如果队列只有一个元素，出队后队列为空，需要将队尾指针指向头结点
        Q->rear = Q->front;
    free(p); // 释放出队的结点的空间
    return true;
}