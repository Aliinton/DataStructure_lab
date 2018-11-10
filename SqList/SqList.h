#ifndef _SqList_H_
#define _SqList_H_
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

//���������б�
typedef enum {ERROR, OK, OVERFLOW = -2, INFEASIBLE, FALSE, TRUE} status;

//Ԫ������
typedef int ElemType;

//���Ա�Ķ���
typedef struct
{
    ElemType *elem;
    int length;
    int size;
    char ListName[10];
}SqList;

//���Ա���Ķ���
typedef struct
{
    SqList *Lists;
    int List_Num;
}Mul_SqList;

#endif
