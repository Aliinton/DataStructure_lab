#ifndef _H_LINKEDLIST_
#define _H_LINKEDLIST_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//返回类型列表
typedef enum {ERROR, OK, OVERFLOW = -2, INFEASIBLE, FALSE, TRUE} status;

//表中储存元素的定义和输入输出操作
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
        printf("非法输入，请重新输入\n");
    }
    while ((ch = getchar()) != EOF && ch != '\n');
}

//单个表节点的定义
typedef struct Node{
    ElemType data;
    struct Node *next;
}Node, *LinkedList;

//整个链表节点的定义
typedef struct ListNode
{
    char name[100];
    LinkedList head;
    struct ListNode *next;
}ListNode;

//用来管理多个链表
typedef struct
{
//正在处理的线性表编号，从0开始
    int k;
    int num;
//指向链表组头结点
    ListNode* head;
}Mul_List;


#endif