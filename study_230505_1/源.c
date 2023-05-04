#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;   // ����ջԪ�ص���������

typedef struct StackNode
{
    ElemType data;         // ������
    struct StackNode* next;   // ָ����һ������ָ��
} StackNode, * LinkStack;     // ������ջջ������

// ��ʼ������
void InitStack(LinkStack* S)
{
    *S = NULL;   // ��ʼ��ջ��ָ��Ϊ��
}

// �ж�S�Ƿ�Ϊ��ջ
bool StackEmpty(LinkStack S)
{
    if (S == NULL)   // ջ��ָ��Ϊ��ʱ����ջΪ��
        return true;
    else
        return false;
}

// ��ջ�ĳ���
int StackLength(LinkStack S)
{
    int len = 0;      // ջ�ĳ���
    while (S != NULL)
    {
        S = S->next;  // ջ��ָ�������ƶ�
        len++;       // ջ�ĳ��ȼ�1
    }
    return len;
}

// ȡջ��Ԫ�ز���
bool GetTop(LinkStack S, ElemType* e)
{
    if (S == NULL) // ջΪ��ʱ������FALSE
        return false;
    *e = S->data;   // ջ��Ԫ�ص�ֵ����e
    return true;
}

// ջ�ÿղ���
void ClearStack(LinkStack* S)
{
    StackNode* p;
    while (*S != NULL)
    {
        p = *S;     // ָ��ջ�����
        *S = (*S)->next;   // ջ��ָ��ָ����һ�����
        free(p);    // �ͷŵ�ǰ�����ڴ�ռ�
    }
}

// ����Ԫ��eΪ�µ�ջ��Ԫ��
void Push(LinkStack* S, ElemType e)
{
    StackNode* p;
    p = (StackNode*)malloc(sizeof(StackNode));  // �����½��
    if (!p)   // �����ڴ�ʧ��
    {
        exit(1);
    }
    p->data = e;     // ��Ԫ��e��ֵ���½���������
    p->next = *S;    // �½���nextָ��ָ��ԭջ��ָ��ָ��Ľ��
    *S = p;          // �޸�ջ��ָ��ָ���µĽ��
}

// ɾ��S��ջ��Ԫ��an
bool Pop(LinkStack* S)
{
    StackNode* p;
    if (*S == NULL) // ջΪ��ʱ������FALSE
        return false;
    p = *S;         // pָ��ջ�����
    *S = p->next;   // ջ��ָ��ָ����һ�����
    free(p);        // �ͷŵ�ǰ�����ڴ�ռ�
    return true;
}
