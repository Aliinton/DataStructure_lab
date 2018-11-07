#ifndef _SqList_H_
#define _SqList_H_
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
//一个文件中可以保存的线性表的上限
#define MAX_LIST_NUM 10

typedef enum {ERROR, OK, OVERFLOW = -2, INFEASIBLE, FALSE, TRUE} status;

typedef int ElemType;

typedef struct
{
    ElemType *elem;
    int length;
    int size;
    char ListName[10];
}SqList;

typedef struct
{
    SqList *Lists;
    int List_Num;
}Mul_SqList;

#endif
