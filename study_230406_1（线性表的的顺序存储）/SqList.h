#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//����ͷ�ļ�

#define MAXLENGTH 100

typedef struct ElemType
{
    int data;
}ElemType;
//���ýṹ�崢������Ԫ�أ�������ΪΪElemType���������
//����Ԫ�ؿ���Ϊ������������,���������Ԫ��Ϊ����

typedef struct SqList
{
    ElemType* elem;
    //��������ռ�
    int length;
    //�洢���Ա�ı�
} SqList;
//�����ṹ�壬��������Ԫ������ͱ���

void InitList(SqList* L)
{
    L->elem = (ElemType*)malloc(sizeof(ElemType) * MAXLENGTH);
    //����malloc����һ�鶯̬�Ĵ���ռ�
    L->length = MAXLENGTH;
    //MAXLENGTHһ���������Լ����ú������壬Ϊ���Ա��ʼ��
    assert("��ʼ��ʧ��" && L->elem != NULL);
    //���Կ��ٿռ�ɹ���ʧ����ֹͣ����
}

void DestroyList(SqList& L)
{
    free(L.elem);
    //�ͷ����Ա�Ĵ洢�ռ�
    L.elem = NULL;
    //��ָ���ÿ�
    L.length = 0;
    //�����ȹ���
}

void ClearList(SqList& L)
{
    L.length = 0;
    //�����ȹ���
}

// �����Ա�LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
bool ListEmpty(SqList L)
{
    if (L.length == 0)
        return true;
    else
        return false;
}

// �������Ա�L�е�����Ԫ�ظ���
int ListLength(SqList L)
{
    return L.length;
}

// ��e�������Ա�L�е�i������Ԫ�ص�ֵ
bool GetElem(SqList L, int i, ElemType& e)
{
    if (i < 1 || i > L.length)
        return false;
    //�ж�λ���Ƿ�Ϸ�
    e = *(L.elem + i - 1);
    return true;
}

// ����L�е�1����e����compare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
int LocateElem(SqList L, ElemType e, bool(*compare)(ElemType, ElemType))
{
    int i;
    ElemType* p = L.elem;
    //��������
    for (i = 1; i <= L.length; i++)
    {
        if (compare(*(p + i - 1), e))
            return i;
    }
    //ö��Ѱ��Ŀ��Ԫ�أ������Ż�ʹ������Ѱ�ҷ�ʽ
    return 0;
}

// ��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�����塣
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
    //ö��Ѱ��cur_e
    return false;
}

// ��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�����塣
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
    //ö��Ѱ��cur_e
    return false;
}

// ��L�ĵ�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1��
bool ListInsert(SqList& L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false; 
    //�жϲ���λ���Ƿ�Ϸ�
    ElemType* q = &(L.elem[i - 1]);
    //qΪ����λ��
    for (ElemType* p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p + 1) = *p;
    //����λ�ü�֮���Ԫ������
    *q = e;
    ++L.length; 
    //���ȼ�1
    return true;
}

// ɾ��L�ĵ�i������Ԫ��,����e������ֵ��L�ĳ��ȼ�һ��
bool ListDelete(SqList& L, int i, ElemType& e)
{
    if (i < 1 || i > L.length)
        return false;
    //�ж�ɾ��λ���Ƿ�Ϸ�
    ElemType* p = &(L.elem[i - 1]);
    //pΪ��ɾ��Ԫ�ص�λ��
    e = *p; // ��ɾ��Ԫ�ص�ֵ����e
    ElemType* q = L.elem + L.length - 1;
    //��βԪ��λ��
    for (++p; p <= q; ++p) *(p - 1) = *p;
    //��ɾ��Ԫ��֮���Ԫ������
    --L.length;
    //���ȼ�1
    return true;
}

// ���ζ����Ա���ÿ��Ԫ�ص���visit()��һ��visit()ʧ�ܣ������ʧ�ܡ�
void ListTraverse(SqList L, void(*visit)(ElemType))
{
    ElemType *p = L.elem;
    for (int i = 1; i <= L.length; ++i)
        visit(*(p++));
}