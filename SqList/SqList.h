#include "stdio.h"
#include "stdlib.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

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