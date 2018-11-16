#ifndef _H_FUNCTIONS_
#define _H_FUNCTIONS_
#include "LinkedList.h"
//函数声明
status InitialLists(Mul_List* L);
status InitialList(ListNode *l);
status InitialList2(Mul_List * L, int k);
status DeleteList(Mul_List* L, int k);
status DestoryList(Mul_List* L, int k);
ListNode * LocateList(Mul_List *L, int k);
status NewList(Mul_List *L);
void ShowAllLists(Mul_List L);
void ChangeList(Mul_List *L);

/**
 * 函数名：InitialLists
 * 参数：线性表组指针
 * 返回值：初始化成功返回OK，失败返回ERROR
 * 初始化链表组
*/
status InitialLists(Mul_List* L)
{
    if(!(L->head = (ListNode *)malloc(sizeof(ListNode))))
        return ERROR;
    if(!(L->head->next = (ListNode *)malloc(sizeof(ListNode))))
        return ERROR;
    L->head->next->next = NULL;
    if(InitialList(L->head->next) == OK)
    {
        L->k = 0;
        L->num = 1;
        return OK;
    }
    else
        return ERROR;
}

/**
 * 函数名：InitialList
 * 参数：链表节点指针
 * 返回值：成功返回OK，失败返回ERROR
 * 初始化一个链表
*/
status InitialList(ListNode *l)
{
    if(l->head = (LinkedList) malloc (sizeof(Node)))
    {
        printf("请输入这个线性表的名字：\n");
        gets(l->name);
        l->head->next = NULL;
//每个链表的头结点的数据域用于存放这个链表中的元素个数
        l->head->data = 0;
        printf("初始化成功\n");
        return OK;
    }
    else
    {
        perror("malloc");
        return ERROR;
    }
}

/**
 * 函数名：InitialList2
 * 参数：链表组指针
 * 返回值：成功返回OK，失败返回ERROR
 * 初始化当前正在处理的链表
 */
status InitialList2(Mul_List * L, int k)
{
    ListNode *l = LocateList(L, k);
    if(!l)
        return ERROR;
    if(InitialList(l) == OK)
        return OK;
    else
        return ERROR;
}

/**
 * 函数名：DeleteList
 * 参数：链表组指针，正在处理的链表编号
 * 返回值：删除成功返回OK，失败返回ERROR
 * 删除当前处理的链表
 */
status DeleteList(Mul_List* L, int k)
{
    ListNode *l = L->head->next, *p = L->head;
    while(l && k--)
    {
        p = l;
        l = l->next;
    }
    if(l)
    {
        p->next = l->next;
        free(l);
        L->num--;
        if(!L->num)
        {
            printf("成功删除当前链表，现已没有链表，请新建：\n");
            L->head->next = (ListNode *) malloc (sizeof(ListNode));
            L->num = 1;
            InitialList(L->head->next);
            L->head->next->next = NULL;
        }
        else
        {
            printf("成功删除当前链表，当前链表以不可用，请切换\n");
            ChangeList(L);
        }
        return OK;
    }
    else
    {
        printf("参数有误\n");
        return ERROR;
    }
}

/**
 * 函数名：DestoryList
 * 参数：链表组指针，正在处理的链表编号
 * 返回值：销毁成功返回OK，失败返回ERROR
 * 销毁当前处理的链表
 */
status DestoryList(Mul_List* L, int k)
{
    ListNode *l = LocateList(L, k);
    if(l)
    {
        l->head = NULL;
        printf("成功销毁线性表：%s\n", l->name);
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/**
 * 函数名：LocateList
 * 参数：链表组指针，正在处理的链表编号
 * 返回值：现在正在处理的链表指针，参数有误返回null；
 * 定位到正在处理的链表
 */
ListNode * LocateList(Mul_List *L, int k)
{
    ListNode *l = L->head->next;
    while(l && k--)
    {
        l = l->next;
    }
    if(l)
    {
        return l;
    }
    else
    {
        printf("参数有误\n");
        return NULL;
    }
}

/**
 * 函数名：NewList
 * 参数：链表组指针
 * 返回值：新建成功返回OK，失败返回ERROR
 * 新建一个链表
 */
status NewList(Mul_List *L)
{
    char ch;
    ListNode *l = LocateList(L, L->num - 1);
    if(!l)
    {
        return ERROR;
    }
    l->next = (ListNode *)malloc(sizeof(ListNode));
    l = l->next;
    l->next = NULL;
    L->num++;
    if(InitialList(l) == OK)
    {
        printf("创建成功，是否切换到新链表，按y/Y切换，其余键不切换\n");
        ch = getchar();
        if(ch == 'y' || ch == 'Y')
        {
            L->k = L->num - 1;
            printf("切换完成\n");
        }
        else
        {
            printf("未切换\n");
        }
        while ((ch = getchar()) != EOF && ch != '\n');
        return OK;
    }
    else
    {
        printf("创建失败\n");
        return ERROR;
    }
    
}

/**
 * 函数名：ShowAllLists
 * 参数：链表组指针
 * 返回值：空
 * 遍历所有链表，显示链表数量，并且打印每个链表的名字
 */
void ShowAllLists(Mul_List L)
{
    int k = 1;
    ListNode * l = L.head->next;
    while(l)
    {
        printf("链表%d---name:%s\n", k++, l->name);
        l = l->next;
    }
}

/**
 * 函数名：ChangeList
 * 参数：链表组指针
 * 返回值：空
 * 改变当前处理的链表编号
 */
void ChangeList(Mul_List *L)
{
    int k;
    char ch;
    ShowAllLists(*L);
    printf("切换到：");
    while(1)
    {
        if(scanf("%d", &k) && k > 0 && k <= L->num)
        {
            L->k = k - 1;
            printf("切换完成\n");
            while ((ch = getchar()) != EOF && ch != '\n');
            break;
        }
        else
        {
            printf("输入数据不合法，重新输入\n");
        }
    }
}

/**
 * 函数名：GetElem
 * 参数：链表组指针，待查找元素位置，元素储存单元指针
 * 返回值：找到返回OK，找不到返回ERROR，线性表已被销毁返回INFEASIBLE
 * 寻找指定位置上的元素
 */
status GetElem(Mul_List * L, int i, ElemType *e)
{
    ListNode *list = LocateList(L, L->k);
    LinkedList l =  list->head;
    if(!l)
        return INFEASIBLE;
    if(i < 1 || i > l->data)
        return ERROR;
    while(i--)
    {
        l = l->next;
    }
    *e = l->data;
    return OK;
}

/**
 * 函数名：LocateElem
 * 参数：线性表组指针，待查找元素，比较关系函数指针
 * 返回值：存在返回元素位序，不存在返回0
 * 获得与待查找元素满足特定关系的元素的位序(从1开始)
 */
int LocateElem(Mul_List *L, ElemType e, int (*compare)(ElemType i, ElemType j))
{
    int i = 1;
    ListNode *list = LocateList(L, L->k);
    LinkedList l = list->head;
    if(l)
    {
        l = l->next;
    }
    else
    {
        printf("线性表已被销毁，无法执行操作\n");
        return 0;
    }
    while(l && !compare(e, l->data))
    {
        l = l->next;
        i++;
    }
    if(l)
    {
        return i;
    }
    else
        return 0;
}

//比较函数开始
/**
 * 函数名：SameValue
 * 参数：两个链表元素
 * 返回值：相等返回1，不相等返回0
 * 判断两个链表元素是否相等
 */
int SameValue(ElemType i, ElemType j)
{
    if(i == j)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//比较函数结束

/**
 * 函数名：PriorElem
 * 参数：链表组指针，目标元素，前驱元素储存单元地址
 * 返回值：若是第一个元素，返回INFEASIBLE；若未找到目标元素，返回ERROR；找到则返回OK
 * 寻找指定元素的前驱元素，并将其复制到对应储存单元
 */
status PriorElem(Mul_List * L, ElemType t, ElemType* e)
{
    int i = LocateElem(L, t, &SameValue) - 1;
    ListNode *list = LocateList(L, L->k);
    LinkedList l = list->head;
    if(!l)
    {
        return ERROR;
    }
    if(i == -1)
        return ERROR;
//若是第一个元素，返回INFEASIBLE
    else if(i == 0)
        return INFEASIBLE;
    else
    {
        while(i--)
        {
            l = l->next;
        }
        *e = l->data;
        return OK;
    }
}

/**
 * 函数名：NextElem
 * 参数：链表组指针，目标元素，后继元素储存单元地址
 * 返回值：若是最后一个元素，返回INFEASIBLE；若未找到目标元素，返回ERROR；找到则返回OK
 * 寻找指定元素的后继元素，并将其复制到对应储存单元
 */
status NextElem(Mul_List *L, ElemType t, ElemType *e)
{
    ListNode *list = LocateList(L, L->k);
    LinkedList l = list->head;
    int i = LocateElem(L, t, &SameValue);
    if(i == 0 || l == NULL)
        return ERROR;
    if(i == l->data)
        return INFEASIBLE;
    i++;
    while(i--)
    {
        l = l->next;
    }
    *e = l->data;
    return OK;
}

/**
 * 函数名：ListInsert
 * 参数：链表组指针，插入位序（从1开始），插入元素
 * 返回值：插入成功，返回OK；失败返回ERROR
 * 向链表中插入元素
 */
status ListInsert(Mul_List* L, int i, ElemType e)
{
    ListNode *list = LocateList(L, L->k);
    LinkedList l = list->head, n, head;
    head = l;
    if(head == NULL)
    {
        printf("线性表已被销毁，若要插入，请先初始化\n");
        return ERROR;
    }
    if((i > l->data + 1) || (i < 0))
        return ERROR;
    i--;
    while(i--)
    {
        l = l->next;
    }
    n = (LinkedList)malloc(sizeof(Node));
    n->data = e;
    n->next = l->next;
    l->next = n;
    head->data++;
    return OK;
}

/**
 * 函数名：ListDelete
 * 参数：链表组指针，待删除元素位序，储存被删除元素的单元的地址
 * 返回值：删除成功返回OK，否则返回ERROR
 * 删除指定元素，并将他的值赋给指定变量
 */
status ListDelete(Mul_List *L, int i, ElemType *e)
{
    ListNode *list = LocateList(L, L->k);
    LinkedList p = list->head, q = NULL;
    if(!p)
    {
        printf("线性表已被销毁，无法执行操作\n");
        return ERROR;
    }
    while(p && i--)
    {
        q = p;
        p = p->next;
    }
    if(p)
    {
        q->next = p->next;
        *e = p->data;
        free(p);
        list->head->data--;
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/**
 * 函数名：ListTraverse
 * 参数：链表组指针，visit函数指针
 * 返回值：空
 * 遍历这个链表
 */
void ListTraverse(Mul_List *L, void (*visit)(ElemType i))
{
    ListNode *list = LocateList(L, L->k);
    LinkedList l = list->head;
    if(!l)
    {
        printf("线性表已被销毁，遍历失败\n");
    }
    else if(l->data)
    {
        l = l->next;
        while(l)
        {
            visit(l->data);
            l = l->next;
        }
    }
    else
    {
        printf("线性表为空\n");
    }
}

/**
 * 函数名：ClearList
 * 参数：链表组指针
 * 返回值：清空成功返回OK，失败返回ERROR
 * 清空正在操作的链表
 */
status ClearList(Mul_List *L)
{
    ListNode *list = LocateList(L, L->k);
    LinkedList p = list->head, q;
    if(!p)
    {
        printf("线性表已被销毁,无法执行操作\n");
        return ERROR;
    }
    else
    {
        p->data = 0;
        p = p->next;
        while(p)
        {
            q = p;
            p = p->next;
            free(q);
        }
        list->head->next = NULL;
        return OK;
    }
}

/**
 * 函数名：ListEmpty
 * 参数：链表组指针
 * 返回值：为空返回true，非空返回false
 * 判断一个链表是否为空
 */
status ListEmpty(Mul_List *L)
{
    ListNode *list = LocateList(L, L->k);
    LinkedList l = list->head;
    if(!l)
    {
        printf("链表已被销毁，无法执行操作\n");
        return INFEASIBLE;
    }
    if(l->data)
        return FALSE;
    else
        return TRUE;
}

/**
 * 函数名：ListLength
 * 参数：链表组指针
 * 返回值：链表长度
 * 获得当前处理链表的长度
 */
int ListLength(Mul_List * L)
{
    ListNode *list = LocateList(L, L->k);
    LinkedList l = list->head;
    if(!l)
    {
        printf("链表已被销毁，无法执行操作\n");
        return -1;
    }
    return l->data;
}
#endif