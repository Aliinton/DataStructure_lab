#ifndef _SqList_H_
#define _SqList_H_
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

//返回类型列表
typedef enum {ERROR, OK, OVERFLOW = -2, INFEASIBLE, FALSE, TRUE} status;

//元素类型
typedef int ElemType;

//线性表的定义
typedef struct
{
    ElemType *elem;
    int length;
    int size;
    char ListName[10];
}SqList;

//线性表组的定义
typedef struct
{
    SqList *Lists;
    int List_Num;
}Mul_SqList;

#endif
