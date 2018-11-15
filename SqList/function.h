#ifndef _function_H_
#define _function_H_
#include "SqList.h"

/*
* 函数名：ListIncrese
* 形参列表：需要增加储存空间的线性表的地址
* 用户输入：无
* 返回参数：status（状态指示量）
* 函数功能：为线性表增加内存空间
*/
status ListIncrese(SqList * L)
{
    L->size += LISTINCREMENT;
    if(!(L->elem = (ElemType *) realloc (L->elem, sizeof(ElemType) * (L->size))))
    {
        perror("ERROR: ");
        return OVERFLOW;
    }
    return OK;
}

/*
* 函数名称：input
* 形参列表：待输入元素的地址
* 用户输入：无
* 返回参数：空
* 函数功能：输入一个元素
*/
void input(ElemType * e)
{
    char c;
    while(!scanf("%d", e))
    {
        printf("输入数据不合法\n");
        while ((c = getchar()) != EOF && c != '\n');
    }
    while ((c = getchar()) != EOF && c != '\n');
}

/*
* 函数名称：print
* 形参列表：待打印元素
* 用户输入：无
* 返回参数：空
* 函数功能：打印一个元素
*/
void print(ElemType e)
{
    printf("%d\n", e);
}

/*
* 函数名称：InitailList
* 形参列表：代初始化的线性表的地址
* 返回参数：status（状态指示量）
* 用户输入：线性表的名字
* 函数功能：输入一个元素
*/
status InitialList(SqList *L)
{
    if(!L)
        return INFEASIBLE;
    if(!(L->elem = (ElemType *) malloc (sizeof(ElemType) * LIST_INIT_SIZE)))
    {
        perror("ERROR: ");
        return OVERFLOW;
    }
    L->size = LIST_INIT_SIZE;
    L->length = 0;
    printf("输入这个线性表的名字：");
    scanf("%s", L->ListName);
    return OK;
}

/*
* 函数名称：DestroyList
* 形参列表：待销毁的线性表的地址
* 用户输入：无
* 返回参数：status（状态指示量）
* 函数功能：销毁一个线性表
*/
status DestroyList(SqList *L)
{
    if(!L)
    {
        perror("ERROR: ");
        return INFEASIBLE;
    }
    else
    {
        free(L->elem);
        L->elem = NULL;
        L->size = 0;
        L->length = 0;
        return OK;
    }
}

/*
* 函数名称：InitailListd
* 形参列表：代初始化的线性表组的地址
* 用户输入：无
* 返回参数：status（状态指示量）
* 函数功能：初始化一个线性表组
*/
status InitialLists(Mul_SqList *L)
{
    if(!L)
        return INFEASIBLE;
    L->List_Num = 1;
    if(!(L->Lists = (SqList *) malloc (sizeof (SqList))))
    {
        perror("ERROR: ");
        return OVERFLOW;
    }
    if(!(InitialList(L->Lists)))
        return ERROR;
    else
        return OK;
}

/*
* 函数名称：NewList
* 形参列表：线性表组的地址
* 用户输入：空
* 返回参数：status（状态指示量）
* 函数功能：在线性表序列中创建一个新的线性表
*/
status NewList(Mul_SqList *L)
{
    if(!L)
        return INFEASIBLE;
    L->List_Num++;
//增加线性表组的空间
    if(!(L->Lists = (SqList *) realloc (L->Lists, sizeof(SqList) * L->List_Num)))
    {
        perror("ERROR: ");
        return OVERFLOW;
    }
    if(!InitialList(L->Lists + L->List_Num - 1))
        return ERROR;
    else
        return OK;
}

/*
* 函数名称：NewList
* 形参列表：线性表组的地址
* 用户输入：无
* 返回参数：status（状态指示量）
* 函数功能：删除当前线性表
*/
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

/*
* 函数名称：ClearList
* 形参列表：待清空线性表的地址
* 用户输入：无
* 返回参数：status（状态指示量）
* 函数功能：清空当前线性表
*/
status ClearList(SqList *L)
{
    if(!L)
        return INFEASIBLE;
    L->length = 0;
    return OK;
}

/*
* 函数名称：ListEmpty
* 形参列表：待判断线性表
* 用户输入：无
* 返回参数：status（状态指示量）
* 函数功能：判断线性表是否为空
*/
status ListEmpty(SqList L)
{
    if(L.length)
        return FALSE;
    else
        return TRUE;
}

/*
* 函数名称：ListLength
* 形参列表：待判断线性表
* 用户输入：无
* 返回参数：线性表长度
* 函数功能：返回线性表长度
*/
int ListLength(SqList L)
{
    return L.length;
}

/*
* 函数名称：GetElem
* 形参列表：指定线性表， 元素位置， 存放元素的位置
* 用户输入：元素位置
* 返回参数：status(状态指示量)
* 函数功能：指定位置，取出元素
*/
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

/*
* 函数名称：LocateElem
* 形参列表：指定线性表， 元素值
* 用户输入：元素值
* 返回参数：元素位置
* 函数功能：定位元素
*/
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

/*
* 函数名称：samevalue
* 形参列表：待比较元素
* 返回参数：status(状态指示量)
* 函数功能：比较两个元素是否相等
*/
status samevalue(ElemType i, ElemType j)
{
    if(i == j)
        return TRUE;
    else
        return FALSE;
}


/*
* 函数名称：PriorElem
* 形参列表：指定线性表，元素值，用于存放元素的空间
* 用户输入：元素值
* 返回参数：status(状态指示量)
* 函数功能：获得指定元素的前驱元素
*/
status PriorElem(SqList L, ElemType cur_e, ElemType * next_e)
{
    if(!L.elem)
        return ERROR;
    if(L.elem[0] == cur_e)
    {
        printf("INFASIBLE(cur_e is the first element)\n");
        return INFEASIBLE;
    }
    else
    {
        int i;
//之后元素移位
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

/*
* 函数名称：NextElem
* 形参列表：指定线性表，元素值，用于存放后继元素的空间
* 用户输入：元素值
* 返回参数：status(状态指示量)
* 函数功能：获得指定元素的后继元素
*/
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
//之后元素移位
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

/*
* 函数名称：ListInsert
* 形参列表：指定线性表，元素位置，元素值
* 用户输入：位置和元素
* 返回参数：status(状态指示量)
* 函数功能：在线性表第i个元素之前插入指定元素
*/
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
//之后元素移位
    for(; k >= i; k--)
    {
        L->elem[k] = L->elem[k - 1];
    }
    L->elem[i - 1] = e;
    return OK;
}

/*
* 函数名称：ListDelete
* 形参列表：指定线性表，元素值，用于存放元素的空间
* 用户输入：删除元素位置
* 返回参数：status(状态指示量)
* 函数功能：删除线性表指定位置的元素
*/
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

/*
* 函数名称：ListTraverse
* 形参列表：指定线性表
* 用户输入：无
* 返回参数：status(状态指示量)
* 函数功能：遍历线性表
*/
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

/*
* 函数名称：ShowAllLists
* 形参列表：指定线性表组
* 返回参数：status(状态指示量)
* 函数功能：展示所有线性表
*/
void ShowAllLists(Mul_SqList L)
{
    int i;
    printf("线性表列表如下：\n");
    for(i = 0; i < L.List_Num; i++)
    {
        printf("第%d个线性表：%s\n", i + 1, L.Lists[i].ListName);
    }
}

/*
* 函数名称：ChangeList
* 形参列表：指定线性表组
* 返回参数：空
* 函数功能：切换当前处理的线性表
*/
void ChangeList(Mul_SqList L, int *k)
{
    char ch;
    int i;
    ShowAllLists(L);
    printf("输入想要切换的线性表的序号：");
    ch = getchar();
    i = ch - '0';
    while ((ch = getchar()) != EOF && ch != '\n');
    if(i > 0 && i <= L.List_Num)
    {
        *k = i;
        printf("已经切换到线性表%s\n", L.Lists[i - 1].ListName);
    }
    else
    {
        printf("您输入的数据不合法\n");
    }
}

/*
* 函数名称：StoreFiles
* 形参列表：指定线性表组
* 返回参数：空
* 用户输入：待储存文件的名字
* 函数功能：储存当前内存中的线性表
*/
void StoreFiles(Mul_SqList *L)
{
    FILE *fp;
    char filename[60] = "./SqList/output_files/", name[30];
    if(L)
    {
        printf("输入创建文件名：");
        gets(name);
        strcat(filename, name);
        if(fp = fopen(filename, "wb"))
        {
            printf("创建文件成功\n");
//把记录线性表组的数据录入
            fwrite(L, sizeof(Mul_SqList), 1, fp);
            fwrite(L->Lists, sizeof(SqList), L->List_Num, fp);
//把每个线性表的数据录入
            for(int i = 0; i < L->List_Num; i++)
            {
                fwrite(L->Lists[i].elem, sizeof(ElemType), L->Lists[i].length, fp);
            }
        }
        else
        {
            perror("fopen");
            printf("储存失败\n");
        }
    }
    else
    {
        printf("内存中没有可储存数据\n");
    }
    fclose(fp);
}

/*
* 函数名称：LoadFiels
* 形参列表：指定线性表组
* 返回参数：status（状态指示量）
* 用户输入：待打开文件名称
* 函数功能：加载指定文件中的线性表组
*/
status LoadFiles(Mul_SqList * L)
{
    FILE *fp;
    char flag, ch;
    char filename[60] = "./SqList/output_files/", name[30];
    printf("直接加载会丢失所有未存储数据，按Y继续，按S保存当前数据后继续，按其余键退出\n");
    flag = getchar();
    if(flag == 'S' || flag == 's' || flag == 'Y' || flag == 'y')
    {
        if(flag == 'S' || flag == 's')
        {
            StoreFiles(L);
        }
        printf("输入打开文件名：");
        while ((ch = getchar()) != EOF && ch != '\n');
        gets(name);
        strcat(filename, name);
        if(fp = fopen(filename, "rb"))
        {
//加载线性表组
            fread(L, sizeof(Mul_SqList), 1, fp);
            L->Lists = (SqList *)malloc(sizeof(SqList) * L->List_Num);
            fread(L->Lists, sizeof(SqList), L->List_Num, fp);
//恢复每个线性表中的元素
            for(int i = 0; i < L->List_Num; i++)
            {
                L->Lists[i].elem = (ElemType *)malloc(sizeof(ElemType) * L->Lists[i].size);
                fread(L->Lists[i].elem, sizeof(ElemType), L->Lists[i].length, fp);
            }
            return OK;
        }
        else
        {
            printf("加载失败！\n");
            return ERROR;
        }
    }
    else
    {
        printf("本次操作已被放弃\n");
        return ERROR;
    }
}

/*
* 函数名称：ChangeList
* 形参列表：空
* 用户输入：待删除文件名称
* 返回参数：status（状态指示符）
* 函数功能：删除指定文件
*/
status DeleteFiles()
{
    FILE *fp;
    char flag, ch;
    char filename[60] = "./SqList/output_files/", name[30];
    printf("输入待删除文件名称\n");
    gets(name);
    strcat(filename, name);
    if(remove(filename) == 0)
    {
        printf("已删除 %s。\n", filename);
        return OK;
    }
    else
    {
        perror("remove");
        return ERROR;
    }
}
#endif