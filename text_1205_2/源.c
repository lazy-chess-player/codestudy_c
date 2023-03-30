#include <stdio.h>
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2);
typedef struct ListNode
{
    int val;
    struct listNode* next;
}Node;
Node* Creat_Node(num)
{
    Node* p = (Node*)malloc(sizeof(Node));
    Node* temp = p;
    for (int i = 1; i < num; i++)
    {
        Node* a = (Node*)malloc(sizeof(Node));
        a->val = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}
void print(Node* head)
{
    Node* p;
    int count = 0;
    for (p = head; p; p = p->next)
    {
        printf("%d\t", p->val);
        count++;
        if (count % 5 == 0)
        {
            printf("\n");
        }
    }
}
int main()
{
    Node* list1 = Creat_Node(5);
    Node* list2 = Creat_Node(4);
    Node* list3 = mergeTwoLists(list1, list2);
    print(list3);
    return 0;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* list3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p3 = list3;
    struct ListNode* head = list3;
    if (list1 == NULL)
    {
        return list2;
    }
    else if (list2 == NULL)
    {
        return list1;
    }
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            p3->next = list1;
            p3 = p3->next;
            list1 = list1->next;
            p3->next = NULL;
        }
        else
        {
            p3->next = list2;
            p3 = p3->next;
            list2 = list2->next;
            p3->next = NULL;
        }
    }
    if (list1)
    {
        p3->next = list1;
    }
    if (list2)
    {
        p3->next = list2;
    }
    return head->next;
}