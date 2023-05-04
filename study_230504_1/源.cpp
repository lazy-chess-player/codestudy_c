#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100    // ����ջ����󳤶�

typedef int ElemType;   // ����ջԪ�ص���������

typedef struct
{
    ElemType* base;    // ָ��ջ�׵�ָ��
    ElemType* top;     // ָ��ջ����ָ��
    int stacksize;     // ջ�ĵ�ǰ����
} SqStack;            // ����˳��ջ������

// ��ʼ������
void InitStack(SqStack* S)
{
    S->base = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));  // ����洢�ռ�
    if (!S->base)  // ����ʧ��
    {
        exit(1);
    }
    S->top = S->base;   // ջ����ջ��ָ���ʼָ��ͬһλ��
    S->stacksize = MAXSIZE;   // ջ���������
}

// ����ջ����
void DestroyStack(SqStack* S)
{
    free(S->base);   // �ͷŴ洢�ռ�
    S->base = S->top = NULL;   // ��ջ�׺�ջ��ָ����ΪNULL
    S->stacksize = 0;   // ��ǰջ������Ϊ0
}

// �ж�S�Ƿ�Ϊ��ջ
bool StackEmpty(SqStack S)
{
    if (S.top == S.base)  // ջ����ջ��ָ����ͬʱ����ջΪ��
        return true;   // ����TRUE
    else
        return false;   // ����FALSE
}

// ��ջ�ĳ���
int StackLength(SqStack S)
{
    return (S.top - S.base);  // ջ��ָ���ȥջ��ָ�����ջ�ĳ���
}

// ȡջ��Ԫ�ز���
bool GetTop(SqStack S, ElemType* e)
{
    if (S.top == S.base) // ջΪ��ʱ������FALSE
        return false;
    *e = *(S.top - 1);   // ջ��Ԫ�ص�ֵ����e
    return true;
}

// ջ�ÿղ���
void ClearStack(SqStack* S)
{
    S->top = S->base;   // ��ջ����ջ��ָ��ָ��ͬһλ��
}

// ����Ԫ��eΪ�µ�ջ��Ԫ��
void Push(SqStack* S, ElemType e)
{
    if (S->top - S->base == S->stacksize) // ջ��ʱ������洢�ռ�
    {
        S->base = (ElemType*)realloc(S->base, (S->stacksize + MAXSIZE) * sizeof(ElemType));
        if (!S->base)
        {
            exit(1);
        }
        S->top = S->base + S->stacksize; // ջ��ָ�벻�䣬ջ��ָ��ָ���µ�λ��
        S->stacksize += MAXSIZE;         // ջ������������� MAXSIZE
    }
    *(S->top++) = e;  // Ԫ�� e ��ջ��ջ��ָ���1
}

// ɾ��S��ջ��Ԫ��an
bool Pop(SqStack* S)
{
    if (S->top == S->base) // ջΪ��ʱ������FALSE
    {
        return false;
    }
    S--;
    return true;
}