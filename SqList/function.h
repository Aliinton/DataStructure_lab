#ifndef _function_H_
#define _function_H_
#include "SqList.h"
#endif

//为线性表增加内存空间
status ListIncrese(SqList * L)
{
    L->size += LISTINCREMENT;
    if(!(L->elem = (ElemType *) realloc (L->elem, sizeof(ElemType) * (L->size))))
    {
        printf("OVERFLOW\n");
        return OVERFLOW;
    }
    return OK;
}

//elemnt input and output begin
void input(ElemType * e)
{
    scanf("%d", e);
}

void print(ElemType e)
{
    printf("%d\n", e);
}
//element input and output end

//初始化一个线性表
status InitialList(SqList *L)
{
    if(!L)
        return INFEASIBLE;
    if(!(L->elem = (ElemType *) malloc (sizeof(ElemType) * LIST_INIT_SIZE)))
    {
        printf("OVERFLOW\n");
        return OVERFLOW;
    }
    L->size = LIST_INIT_SIZE;
    L->length = 0;
    printf("输入这个线性表的名字：");
    scanf("%s", L->ListName);
    return OK;
}

//初始化线性表序列
status InitialLists(Mul_SqList *L)
{
    if(!L)
        return INFEASIBLE;
    L->List_Num = 1;
    if(!(L->Lists = (SqList *) malloc (sizeof (SqList))))
    {
        printf("OVERFLOW\n");
        return OVERFLOW;
    }
    if(!(InitialList(L->Lists)))
        return ERROR;
    else
        return OK;
}

//在线性表序列中创建一个新的线性表
status NewList(Mul_SqList *L)
{
    if(!L)
        return INFEASIBLE;
    L->List_Num++;
    if(!(L->Lists = (SqList *) realloc (L->Lists, sizeof(SqList) * L->List_Num)))
    {
        printf("OVERFLOW\n");
        return OVERFLOW;
    }
    if(!InitialList(L->Lists + L->List_Num - 1))
        return ERROR;
    else
        return OK;
}

//删除当前处理的线性表
status DeleteList(Mul_SqList *L, int k)
{
    if(!L)
        return INFEASIBLE;
    for(; k < L->List_Num - 1; k++)
    {
        L->Lists[k] = L->Lists[k + 1];
    }
    L->List_Num--;
    return OK;
}

//清空线性表
status ClearList(SqList *L)
{
    if(!L)
        return INFEASIBLE;
    L->length = 0;
    return OK;
}

//判断线性表是否为空
status ListEmpty(SqList L)
{
    if(L.length)
        return FALSE;
    else
        return TRUE;
}

//判断线性表长度
int ListLength(SqList L)
{
    return L.length;
}

//获得位置为元素
status GetElem(SqList L, int i, ElemType *e)
{
    if(i < 1 || i > L.length)
    {
        printf("INFEASIBLE\n");
        return INFEASIBLE;
    }
    *e = L.elem[i - 1];
    return OK;
}

//定位满足关系compare的元素
int LocateElem(SqList L, ElemType e, status (*compare) (ElemType, ElemType))
{
    ElemType* p = L.elem;
    int i = 0;
    while(i <= L.length && !(*compare)(p[i++], e));
    if(i >L.length)
        return 0;
    else
        return i;
}

//cmpare function
status samevalue(ElemType i, ElemType j)
{
    if(i == j)
        return TRUE;
    else
        return FALSE;
}
//the end of compare function

//获得指定元素的前驱元素
status PriorElem(SqList L, ElemType cur_e, ElemType * next_e)
{
    if(L.elem[0] == cur_e)
    {
        printf("INFASIBLE(cur_e is the first element)\n");
        return INFEASIBLE;
    }
    else
    {
        int i;
        for(i = 1; i < L.length && L.elem[i] != cur_e; i++);
        if(i < L.length)
        {
            *next_e = L.elem[i - 1];
            return OK;
        }
        else
        {
            printf("INFASIBLE(not found cur_e in the list)\n");
            return INFEASIBLE;
        }
    }
}

//获得指定元素的后继元素
status NextElem(SqList L, ElemType cur_e, ElemType * next_e)
{
    if(L.elem[L.length - 1] == cur_e)
    {
        printf("INFASIBLE\n");
        return INFEASIBLE;
    }
    else
    {
        int i;
        for(i = 0; i < L.length - 1 && L.elem[i] != cur_e; i++);
        if(i < L.length - 1)
        {
            *next_e = L.elem[i + 1];
            return OK;
        }
        else
        {
            printf("INFASIBEL(not found cur_e in the list)\n");
            return INFEASIBLE;
        }
    }
}

//在线性表第i个元素之前插入
status ListInsert(SqList* L, int i, ElemType e)
{
    if(!L)
        return INFEASIBLE;
    if(i < 1 || i > L->length + 1)
        return ERROR;
    int k = L->length;
    if(L->length == L->size)
        if(ListIncrese(L) != OK)
            return OVERFLOW;
    L->length++;
    for(; k >= i; k--)
    {
        L->elem[k] = L->elem[k - 1];
    }
    L->elem[i - 1] = e;
    return OK;
}

//删除线性表指定位置的元素
status ListDelete(SqList* L, int i, ElemType* e)
{
    int k;
    if(!L || ListEmpty(*L))
        return INFEASIBLE;
    if(i < 1 || i > L->length)
        return ERROR;
    *e = L->elem[i - 1];
    for(k = i; k <= L->length - 1; k++)
    {
        L->elem[k - 1] = L->elem[k];
    }
    L->length--;
    return OK;
}

//按照visit方法遍历线性表
status ListTraverse(SqList L, status (*visit) (ElemType e))
{
    int i;
    if(!L.length)
        return ERROR;
    for(i = 0; i < L.length; i++)
    {
        if(!visit(L.elem[i]))
            return ERROR;
    }
    return OK;
}

//visit function begin
status getvalue(ElemType e)
{
    printf("%d\t", e);
    return OK;
}
//visit function end

//打印所有的线性表序号及其名称
void ShowAllLists(Mul_SqList L)
{
    int i;
    printf("线性表列表如下：\n");
    for(i = 0; i < L.List_Num; i++)
    {
        printf("第%d个线性表：%s\n", i + 1, L.Lists[i].ListName);
    }
}

//切换当前处理的线性表
void ChangeList(Mul_SqList L, int *k)
{
    int i;
    ShowAllLists(L);
    printf("输入想要切换的线性表的序号：");
    scanf("%d", &i);
    *k = i;
    printf("已经切换到线性表%s\n", L.Lists[i - 1].ListName);
}