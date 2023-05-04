#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // ���е���󳤶�

typedef int ElemType; // �������Ԫ�ص���������

typedef struct
{
    ElemType* data; // �洢����Ԫ�ص�����
    int front; // ��ͷָ�룬ָ���ͷԪ��
    int rear; // ��βָ�룬ָ���βԪ�ص���һ��λ��
} SqQueue;

// ����ն���Q
void InitQueue(SqQueue* Q)
{
    Q->data = (ElemType*)malloc(MAX_SIZE * sizeof(ElemType)); // ��̬��������ռ�
    Q->front = Q->rear = 0; // ��ʼ����ͷ�Ͷ�βָ��
}

// ����Q����
void DestroyQueue(SqQueue* Q)
{
    free(Q->data); // �ͷŶ��е�����ռ�
    Q->data = NULL; //��ָ���ÿ�
    Q->front = Q->rear = 0; // ��ʼ����ͷ�Ͷ�βָ��
}

// ������Q���
void ClearQueue(SqQueue* Q)
{
    Q->front = Q->rear = 0; // ����ͷ�Ͷ�βָ����Ϊ0����ʾ����Ϊ��
}

// ���ض���Q��Ԫ�ظ����������еĳ���
int QueueLength(SqQueue Q)
{
    return Q.rear - Q.front;
}

// ��e���ض���Q�Ķ�ͷԪ��
bool GetHead(SqQueue Q, ElemType* e)
{
    if (Q.front == Q.rear) // ����Ϊ�գ��޷�ȡ����ͷԪ��
    {
        return false;
    }
    *e = Q.data[Q.front]; // ����ͷԪ�ظ�ֵ��e
    return true;
}

// ����Ԫ��eΪ����Q�Ķ�βԪ��
bool EnQueue(SqQueue* Q, ElemType e)
{
    if ((Q->rear + 1) % MAX_SIZE == Q->front) // ��������������ʧ��
    {
        return false;
    }
    Q->data[Q->rear] = e; // ��Ԫ��e�����β
    Q->rear++; // ���¶�βָ��
    return true;
}

// ɾ������Q�Ķ�ͷԪ�أ�����e����ֵ
bool DeQueue(SqQueue* Q, ElemType* e)
{
    if (Q->front == Q->rear) // ����Ϊ�գ�ɾ��ʧ��
    {
        return false;
    }
    *e = Q->data[Q->front]; // ����ͷԪ�ظ�ֵ��e
    Q->front++; // ���¶�ͷָ��
    return true;
}