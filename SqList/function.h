#ifndef _function_H_
#define _function_H_
#include "SqList.h"

//Ϊ���Ա������ڴ�ռ�
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

//��ʼ��һ�����Ա�
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
    printf("����������Ա�����֣�");
    scanf("%s", L->ListName);
    return OK;
}

//���ٵ�ǰ���Ա�
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

//��ʼ�����Ա�����
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

//�����Ա������д���һ���µ����Ա�
status NewList(Mul_SqList *L)
{
    if(!L)
        return INFEASIBLE;
    L->List_Num++;
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

//ɾ����ǰ��������Ա�
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

//������Ա�
status ClearList(SqList *L)
{
    if(!L)
        return INFEASIBLE;
    L->length = 0;
    return OK;
}

//�ж����Ա��Ƿ�Ϊ��
status ListEmpty(SqList L)
{
    if(L.length)
        return FALSE;
    else
        return TRUE;
}

//�ж����Ա���
int ListLength(SqList L)
{
    return L.length;
}

//���λ��ΪԪ��
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

//��λ�����ϵcompare��Ԫ��
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

//���ָ��Ԫ�ص�ǰ��Ԫ��
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

//���ָ��Ԫ�صĺ��Ԫ��
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

//�����Ա��i��Ԫ��֮ǰ����
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

//ɾ�����Ա�ָ��λ�õ�Ԫ��
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

//����visit�����������Ա�
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

//��ӡ���е����Ա���ż�������
void ShowAllLists(Mul_SqList L)
{
    int i;
    printf("���Ա��б����£�\n");
    for(i = 0; i < L.List_Num; i++)
    {
        printf("��%d�����Ա�%s\n", i + 1, L.Lists[i].ListName);
    }
}

//�л���ǰ��������Ա�
void ChangeList(Mul_SqList L, int *k)
{
    int i;
    ShowAllLists(L);
    printf("������Ҫ�л������Ա����ţ�");
    scanf("%d", &i);
    *k = i;
    printf("�Ѿ��л������Ա�%s\n", L.Lists[i - 1].ListName);
}

//�����������е����Ա�
void StoreFiles(Mul_SqList *L)
{
    FILE *fp;
    char filename[60] = "D:/data_structure_lab/SqList/output_files/", name[30];
    if(L)
    {
        printf("���봴���ļ�����");
        gets(name);
        strcat(filename, name);
        if(fp = fopen(filename, "wb"))
        {
            printf("�����ļ��ɹ�\n");
            fwrite(L, sizeof(Mul_SqList), 1, fp);
            fwrite(L->Lists, sizeof(SqList), L->List_Num, fp);
            for(int i = 0; i < L->List_Num; i++)
            {
                fwrite(L->Lists[i].elem, sizeof(ElemType), L->Lists[i].length, fp);
            }
        }
        else
        {
            perror("fopen");
            printf("����ʧ��\n");
        }
    }
    else
    {
        printf("�ڴ���û�пɴ�������\n");
    }
    fclose(fp);
}

//����ָ���ļ��е��������Ա�
void LoadFiles(Mul_SqList * L)
{
    FILE *fp;
    char flag;
    char filename[60] = "D:/data_structure_lab/SqList/output_files/", name[30];
    printf("ֱ�Ӽ��ػᶪʧ����δ�洢���ݣ���Y��������S���浱ǰ���ݺ��������������˳�\n");
    flag = getchar();
    getchar();
    if(flag == 'S' || flag == 's' || flag == 'Y' || flag == 'y')
    {
        if(flag == 'S' || flag == 's')
        {
            StoreFiles(L);
        }
        printf("������ļ�����");
        gets(name);
        strcat(filename, name);
        if(fp = fopen(filename, "rb"))
        {
            fread(L, sizeof(Mul_SqList), 1, fp);
            L->Lists = (SqList *)malloc(sizeof(SqList) * L->List_Num);
            fread(L->Lists, sizeof(SqList), L->List_Num, fp);
            for(int i = 0; i < L->List_Num; i++)
            {
                L->Lists[i].elem = (ElemType *)malloc(sizeof(ElemType) * L->Lists[i].size);
                fread(L->Lists[i].elem, sizeof(ElemType), L->Lists[i].length, fp);
            }
        }
        else
        {
            printf("����ʧ�ܣ�\n");
        }
    }
    else
    {
        printf("���β����ѱ�����\n");
    }
}
#endif