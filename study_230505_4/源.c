#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType; // �������Ԫ�ص���������

// ���н������
typedef struct QNode
{
    ElemType data; // ����������
    struct QNode* next; // ����ָ����
}QNode, * QuenePtr;

// ��ʽ��������
typedef struct
{
    QuenePtr front; // ��ͷָ�룬ָ���ͷ���
    QuenePtr rear; // ��βָ�룬ָ���β���
}LinkQuene;

// ��ʼ������Q
void InitQuene(LinkQuene* Q)
{
    Q->front = Q->rear = (QuenePtr)malloc(sizeof(QNode)); // ����ͷ���
    if (!Q->front) // �ڴ����ʧ��
        exit(1);
    Q->front->next = NULL; // ͷ����ָ�����ÿ�
}

// ���ٶ���Q
void DestroyQuene(LinkQuene* Q)
{
    QuenePtr p = Q->front;
    while (p) // ����ͷŽ���ڴ�
    {
        Q->front = p->next;
        free(p);
        p = Q->front;
    }
    Q->front = Q->rear = NULL; // ������ָ���ÿ�
}


// ���ض���Q��Ԫ�ظ����������еĳ���
int QueneLength(LinkQuene Q)
{
    int count = 0;
    QuenePtr p = Q.front->next;
    while (p) // �������м���
    {
        count++;
        p = p->next;
    }
    return count;
}

// ��e���ض���Q�Ķ�ͷԪ��
bool GetHead(LinkQuene Q, ElemType* e)
{
    if (Q.front == Q.rear) // ����Ϊ�գ��޷�ȡ����ͷԪ��
        return false;
    *e = Q.front->next->data; // ����ͷԪ�ظ�ֵ��e
    return true;
}

// ��Ӳ���
bool EnQuene(LinkQuene* Q, ElemType e)
{
    QuenePtr p = (QuenePtr)malloc(sizeof(QNode)); // �����½��
    if (!p) // �ڴ����ʧ��
        return false;
    p->data = e; // ��Ԫ��e�洢���½����
    p->next = NULL; // ���½���nextָ����ΪNULL

    Q->rear->next = p; // ���½�����ӵ���β���ĺ���
    Q->rear = p; // ����βָ��ָ���½��

    return true;
}

// ���Ӳ���
bool DeQuene(LinkQuene* Q, ElemType* e)
{
    if (Q->front == Q->rear) // ����Ϊ�գ��޷�����
        return false;
    QuenePtr p = Q->front->next; // ָ���ͷ���
    *e = p->data; // ����ͷԪ�ظ�ֵ��e
    Q->front->next = p->next; // ����ͷ���ɾ��
    if (Q->rear == p) // �������ֻ��һ��Ԫ�أ����Ӻ����Ϊ�գ���Ҫ����βָ��ָ��ͷ���
        Q->rear = Q->front;
    free(p); // �ͷų��ӵĽ��Ŀռ�
    return true;
}