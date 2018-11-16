#ifndef _H_LINKEDLIST_
#define _H_LINKEDLIST_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//���������б�
typedef enum {ERROR, OK, OVERFLOW = -2, INFEASIBLE, FALSE, TRUE} status;

//���д���Ԫ�صĶ���������������
typedef int ElemType;

void print(ElemType e)
{
    printf("%d\n", e);
}

void scan(ElemType *e)
{
    char ch;
    while(!scanf("%d", e))
    {
        printf("�Ƿ����룬����������\n");
    }
    while ((ch = getchar()) != EOF && ch != '\n');
}

//������ڵ�Ķ���
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node, *LinkedList;

//��������ڵ�Ķ���
typedef struct ListNode
{
    char name[100];
    LinkedList head;
    struct ListNode *next;
}ListNode;

//��������������
typedef struct
{
//���ڴ�������Ա��ţ���0��ʼ
    int k;
    int num;
//ָ��������ͷ���
    ListNode* head;
}Mul_List;


#endif