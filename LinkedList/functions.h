#ifndef _H_FUNCTIONS_
#define _H_FUNCTIONS_
#include "LinkedList.h"
//��������
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
 * ��������InitialLists
 * ���������Ա���ָ��
 * ����ֵ����ʼ���ɹ�����OK��ʧ�ܷ���ERROR
 * ��ʼ��������
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
 * ��������InitialList
 * ����������ڵ�ָ��
 * ����ֵ���ɹ�����OK��ʧ�ܷ���ERROR
 * ��ʼ��һ������
*/
status InitialList(ListNode *l)
{
    if(l->head = (LinkedList) malloc (sizeof(Node)))
    {
        printf("������������Ա�����֣�\n");
        gets(l->name);
        l->head->next = NULL;
//ÿ�������ͷ�������������ڴ����������е�Ԫ�ظ���
        l->head->data = 0;
        printf("��ʼ���ɹ�\n");
        return OK;
    }
    else
    {
        perror("malloc");
        return ERROR;
    }
}

/**
 * ��������InitialList2
 * ������������ָ��
 * ����ֵ���ɹ�����OK��ʧ�ܷ���ERROR
 * ��ʼ����ǰ���ڴ��������
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
 * ��������DeleteList
 * ������������ָ�룬���ڴ����������
 * ����ֵ��ɾ���ɹ�����OK��ʧ�ܷ���ERROR
 * ɾ����ǰ���������
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
            printf("�ɹ�ɾ����ǰ��������û���������½���\n");
            L->head->next = (ListNode *) malloc (sizeof(ListNode));
            L->num = 1;
            InitialList(L->head->next);
            L->head->next->next = NULL;
        }
        else
        {
            printf("�ɹ�ɾ����ǰ������ǰ�����Բ����ã����л�\n");
            ChangeList(L);
        }
        return OK;
    }
    else
    {
        printf("��������\n");
        return ERROR;
    }
}

/**
 * ��������DestoryList
 * ������������ָ�룬���ڴ����������
 * ����ֵ�����ٳɹ�����OK��ʧ�ܷ���ERROR
 * ���ٵ�ǰ���������
 */
status DestoryList(Mul_List* L, int k)
{
    ListNode *l = LocateList(L, k);
    if(l)
    {
        l->head = NULL;
        printf("�ɹ��������Ա�%s\n", l->name);
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/**
 * ��������LocateList
 * ������������ָ�룬���ڴ����������
 * ����ֵ���������ڴ��������ָ�룬�������󷵻�null��
 * ��λ�����ڴ��������
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
        printf("��������\n");
        return NULL;
    }
}

/**
 * ��������NewList
 * ������������ָ��
 * ����ֵ���½��ɹ�����OK��ʧ�ܷ���ERROR
 * �½�һ������
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
        printf("�����ɹ����Ƿ��л�����������y/Y�л�����������л�\n");
        ch = getchar();
        if(ch == 'y' || ch == 'Y')
        {
            L->k = L->num - 1;
            printf("�л����\n");
        }
        else
        {
            printf("δ�л�\n");
        }
        while ((ch = getchar()) != EOF && ch != '\n');
        return OK;
    }
    else
    {
        printf("����ʧ��\n");
        return ERROR;
    }
    
}

/**
 * ��������ShowAllLists
 * ������������ָ��
 * ����ֵ����
 * ��������������ʾ�������������Ҵ�ӡÿ�����������
 */
void ShowAllLists(Mul_List L)
{
    int k = 1;
    ListNode * l = L.head->next;
    while(l)
    {
        printf("����%d---name:%s\n", k++, l->name);
        l = l->next;
    }
}

/**
 * ��������ChangeList
 * ������������ָ��
 * ����ֵ����
 * �ı䵱ǰ�����������
 */
void ChangeList(Mul_List *L)
{
    int k;
    char ch;
    ShowAllLists(*L);
    printf("�л�����");
    while(1)
    {
        if(scanf("%d", &k) && k > 0 && k <= L->num)
        {
            L->k = k - 1;
            printf("�л����\n");
            while ((ch = getchar()) != EOF && ch != '\n');
            break;
        }
        else
        {
            printf("�������ݲ��Ϸ�����������\n");
        }
    }
}

/**
 * ��������GetElem
 * ������������ָ�룬������Ԫ��λ�ã�Ԫ�ش��浥Ԫָ��
 * ����ֵ���ҵ�����OK���Ҳ�������ERROR�����Ա��ѱ����ٷ���INFEASIBLE
 * Ѱ��ָ��λ���ϵ�Ԫ��
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
 * ��������LocateElem
 * ���������Ա���ָ�룬������Ԫ�أ��ȽϹ�ϵ����ָ��
 * ����ֵ�����ڷ���Ԫ��λ�򣬲����ڷ���0
 * ����������Ԫ�������ض���ϵ��Ԫ�ص�λ��(��1��ʼ)
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
        printf("���Ա��ѱ����٣��޷�ִ�в���\n");
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

//�ȽϺ�����ʼ
/**
 * ��������SameValue
 * ��������������Ԫ��
 * ����ֵ����ȷ���1������ȷ���0
 * �ж���������Ԫ���Ƿ����
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
//�ȽϺ�������

/**
 * ��������PriorElem
 * ������������ָ�룬Ŀ��Ԫ�أ�ǰ��Ԫ�ش��浥Ԫ��ַ
 * ����ֵ�����ǵ�һ��Ԫ�أ�����INFEASIBLE����δ�ҵ�Ŀ��Ԫ�أ�����ERROR���ҵ��򷵻�OK
 * Ѱ��ָ��Ԫ�ص�ǰ��Ԫ�أ������临�Ƶ���Ӧ���浥Ԫ
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
//���ǵ�һ��Ԫ�أ�����INFEASIBLE
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
 * ��������NextElem
 * ������������ָ�룬Ŀ��Ԫ�أ����Ԫ�ش��浥Ԫ��ַ
 * ����ֵ���������һ��Ԫ�أ�����INFEASIBLE����δ�ҵ�Ŀ��Ԫ�أ�����ERROR���ҵ��򷵻�OK
 * Ѱ��ָ��Ԫ�صĺ��Ԫ�أ������临�Ƶ���Ӧ���浥Ԫ
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
 * ��������ListInsert
 * ������������ָ�룬����λ�򣨴�1��ʼ��������Ԫ��
 * ����ֵ������ɹ�������OK��ʧ�ܷ���ERROR
 * �������в���Ԫ��
 */
status ListInsert(Mul_List* L, int i, ElemType e)
{
    ListNode *list = LocateList(L, L->k);
    LinkedList l = list->head, n, head;
    head = l;
    if(head == NULL)
    {
        printf("���Ա��ѱ����٣���Ҫ���룬���ȳ�ʼ��\n");
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
 * ��������ListDelete
 * ������������ָ�룬��ɾ��Ԫ��λ�򣬴��汻ɾ��Ԫ�صĵ�Ԫ�ĵ�ַ
 * ����ֵ��ɾ���ɹ�����OK�����򷵻�ERROR
 * ɾ��ָ��Ԫ�أ���������ֵ����ָ������
 */
status ListDelete(Mul_List *L, int i, ElemType *e)
{
    ListNode *list = LocateList(L, L->k);
    LinkedList p = list->head, q = NULL;
    if(!p)
    {
        printf("���Ա��ѱ����٣��޷�ִ�в���\n");
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
 * ��������ListTraverse
 * ������������ָ�룬visit����ָ��
 * ����ֵ����
 * �����������
 */
void ListTraverse(Mul_List *L, void (*visit)(ElemType i))
{
    ListNode *list = LocateList(L, L->k);
    LinkedList l = list->head;
    if(!l)
    {
        printf("���Ա��ѱ����٣�����ʧ��\n");
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
        printf("���Ա�Ϊ��\n");
    }
}

/**
 * ��������ClearList
 * ������������ָ��
 * ����ֵ����ճɹ�����OK��ʧ�ܷ���ERROR
 * ������ڲ���������
 */
status ClearList(Mul_List *L)
{
    ListNode *list = LocateList(L, L->k);
    LinkedList p = list->head, q;
    if(!p)
    {
        printf("���Ա��ѱ�����,�޷�ִ�в���\n");
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
 * ��������ListEmpty
 * ������������ָ��
 * ����ֵ��Ϊ�շ���true���ǿշ���false
 * �ж�һ�������Ƿ�Ϊ��
 */
status ListEmpty(Mul_List *L)
{
    ListNode *list = LocateList(L, L->k);
    LinkedList l = list->head;
    if(!l)
    {
        printf("�����ѱ����٣��޷�ִ�в���\n");
        return INFEASIBLE;
    }
    if(l->data)
        return FALSE;
    else
        return TRUE;
}

/**
 * ��������ListLength
 * ������������ָ��
 * ����ֵ��������
 * ��õ�ǰ��������ĳ���
 */
int ListLength(Mul_List * L)
{
    ListNode *list = LocateList(L, L->k);
    LinkedList l = list->head;
    if(!l)
    {
        printf("�����ѱ����٣��޷�ִ�в���\n");
        return -1;
    }
    return l->data;
}
#endif