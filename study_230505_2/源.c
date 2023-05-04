#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // 队列的最大长度

typedef int ElemType; // 定义队列元素的数据类型

typedef struct
{
    ElemType* data; // 存储队列元素的数组
    int front; // 队头指针，指向队头元素
    int rear; // 队尾指针，指向队尾元素的下一个位置
} SqQueue;

// 构造空队列Q
void InitQueue(SqQueue* Q)
{
    Q->data = (ElemType*)malloc(MAX_SIZE * sizeof(ElemType)); // 动态分配数组空间
    Q->front = Q->rear = 0; // 初始化队头和队尾指针
}

// 队列Q销毁
void DestroyQueue(SqQueue* Q)
{
    free(Q->data); // 释放队列的数组空间
    Q->data = NULL; //将指针置空
    Q->front = Q->rear = 0; // 初始化队头和队尾指针
}

// 将队列Q清空
void ClearQueue(SqQueue* Q)
{
    Q->front = Q->rear = 0; // 将队头和队尾指针置为0，表示队列为空
}

// 返回队列Q的元素个数，即队列的长度
int QueueLength(SqQueue Q)
{
    return Q.rear - Q.front;
}

// 用e返回队列Q的队头元素
bool GetHead(SqQueue Q, ElemType* e)
{
    if (Q.front == Q.rear) // 队列为空，无法取出队头元素
    {
        return false;
    }
    *e = Q.data[Q.front]; // 将队头元素赋值给e
    return true;
}

// 插入元素e为队列Q的队尾元素
bool EnQueue(SqQueue* Q, ElemType e)
{
    if ((Q->rear + 1) % MAX_SIZE == Q->front) // 队列已满，插入失败
    {
        return false;
    }
    Q->data[Q->rear] = e; // 将元素e插入队尾
    Q->rear++; // 更新队尾指针
    return true;
}

// 删除队列Q的队头元素，并用e返回值
bool DeQueue(SqQueue* Q, ElemType* e)
{
    if (Q->front == Q->rear) // 队列为空，删除失败
    {
        return false;
    }
    *e = Q->data[Q->front]; // 将队头元素赋值给e
    Q->front++; // 更新队头指针
    return true;
}