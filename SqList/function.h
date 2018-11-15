#ifndef _function_H_
#define _function_H_
#include "SqList.h"

/*
* ��������ListIncrese
* �β��б���Ҫ���Ӵ���ռ�����Ա�ĵ�ַ
* �û����룺��
* ���ز�����status��״ָ̬ʾ����
* �������ܣ�Ϊ���Ա������ڴ�ռ�
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
* �������ƣ�input
* �β��б�������Ԫ�صĵ�ַ
* �û����룺��
* ���ز�������
* �������ܣ�����һ��Ԫ��
*/
void input(ElemType * e)
{
    char c;
    while(!scanf("%d", e))
    {
        printf("�������ݲ��Ϸ�\n");
        while ((c = getchar()) != EOF && c != '\n');
    }
    while ((c = getchar()) != EOF && c != '\n');
}

/*
* �������ƣ�print
* �β��б�����ӡԪ��
* �û����룺��
* ���ز�������
* �������ܣ���ӡһ��Ԫ��
*/
void print(ElemType e)
{
    printf("%d\n", e);
}

/*
* �������ƣ�InitailList
* �β��б�����ʼ�������Ա�ĵ�ַ
* ���ز�����status��״ָ̬ʾ����
* �û����룺���Ա������
* �������ܣ�����һ��Ԫ��
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
    printf("����������Ա�����֣�");
    scanf("%s", L->ListName);
    return OK;
}

/*
* �������ƣ�DestroyList
* �β��б������ٵ����Ա�ĵ�ַ
* �û����룺��
* ���ز�����status��״ָ̬ʾ����
* �������ܣ�����һ�����Ա�
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
* �������ƣ�InitailListd
* �β��б�����ʼ�������Ա���ĵ�ַ
* �û����룺��
* ���ز�����status��״ָ̬ʾ����
* �������ܣ���ʼ��һ�����Ա���
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
* �������ƣ�NewList
* �β��б����Ա���ĵ�ַ
* �û����룺��
* ���ز�����status��״ָ̬ʾ����
* �������ܣ������Ա������д���һ���µ����Ա�
*/
status NewList(Mul_SqList *L)
{
    if(!L)
        return INFEASIBLE;
    L->List_Num++;
//�������Ա���Ŀռ�
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
* �������ƣ�NewList
* �β��б����Ա���ĵ�ַ
* �û����룺��
* ���ز�����status��״ָ̬ʾ����
* �������ܣ�ɾ����ǰ���Ա�
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
* �������ƣ�ClearList
* �β��б���������Ա�ĵ�ַ
* �û����룺��
* ���ز�����status��״ָ̬ʾ����
* �������ܣ���յ�ǰ���Ա�
*/
status ClearList(SqList *L)
{
    if(!L)
        return INFEASIBLE;
    L->length = 0;
    return OK;
}

/*
* �������ƣ�ListEmpty
* �β��б����ж����Ա�
* �û����룺��
* ���ز�����status��״ָ̬ʾ����
* �������ܣ��ж����Ա��Ƿ�Ϊ��
*/
status ListEmpty(SqList L)
{
    if(L.length)
        return FALSE;
    else
        return TRUE;
}

/*
* �������ƣ�ListLength
* �β��б����ж����Ա�
* �û����룺��
* ���ز��������Ա���
* �������ܣ��������Ա���
*/
int ListLength(SqList L)
{
    return L.length;
}

/*
* �������ƣ�GetElem
* �β��б�ָ�����Ա� Ԫ��λ�ã� ���Ԫ�ص�λ��
* �û����룺Ԫ��λ��
* ���ز�����status(״ָ̬ʾ��)
* �������ܣ�ָ��λ�ã�ȡ��Ԫ��
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
* �������ƣ�LocateElem
* �β��б�ָ�����Ա� Ԫ��ֵ
* �û����룺Ԫ��ֵ
* ���ز�����Ԫ��λ��
* �������ܣ���λԪ��
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
* �������ƣ�samevalue
* �β��б����Ƚ�Ԫ��
* ���ز�����status(״ָ̬ʾ��)
* �������ܣ��Ƚ�����Ԫ���Ƿ����
*/
status samevalue(ElemType i, ElemType j)
{
    if(i == j)
        return TRUE;
    else
        return FALSE;
}


/*
* �������ƣ�PriorElem
* �β��б�ָ�����Ա�Ԫ��ֵ�����ڴ��Ԫ�صĿռ�
* �û����룺Ԫ��ֵ
* ���ز�����status(״ָ̬ʾ��)
* �������ܣ����ָ��Ԫ�ص�ǰ��Ԫ��
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
//֮��Ԫ����λ
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
* �������ƣ�NextElem
* �β��б�ָ�����Ա�Ԫ��ֵ�����ڴ�ź��Ԫ�صĿռ�
* �û����룺Ԫ��ֵ
* ���ز�����status(״ָ̬ʾ��)
* �������ܣ����ָ��Ԫ�صĺ��Ԫ��
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
//֮��Ԫ����λ
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
* �������ƣ�ListInsert
* �β��б�ָ�����Ա�Ԫ��λ�ã�Ԫ��ֵ
* �û����룺λ�ú�Ԫ��
* ���ز�����status(״ָ̬ʾ��)
* �������ܣ������Ա��i��Ԫ��֮ǰ����ָ��Ԫ��
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
//֮��Ԫ����λ
    for(; k >= i; k--)
    {
        L->elem[k] = L->elem[k - 1];
    }
    L->elem[i - 1] = e;
    return OK;
}

/*
* �������ƣ�ListDelete
* �β��б�ָ�����Ա�Ԫ��ֵ�����ڴ��Ԫ�صĿռ�
* �û����룺ɾ��Ԫ��λ��
* ���ز�����status(״ָ̬ʾ��)
* �������ܣ�ɾ�����Ա�ָ��λ�õ�Ԫ��
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
* �������ƣ�ListTraverse
* �β��б�ָ�����Ա�
* �û����룺��
* ���ز�����status(״ָ̬ʾ��)
* �������ܣ��������Ա�
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
* �������ƣ�ShowAllLists
* �β��б�ָ�����Ա���
* ���ز�����status(״ָ̬ʾ��)
* �������ܣ�չʾ�������Ա�
*/
void ShowAllLists(Mul_SqList L)
{
    int i;
    printf("���Ա��б����£�\n");
    for(i = 0; i < L.List_Num; i++)
    {
        printf("��%d�����Ա�%s\n", i + 1, L.Lists[i].ListName);
    }
}

/*
* �������ƣ�ChangeList
* �β��б�ָ�����Ա���
* ���ز�������
* �������ܣ��л���ǰ��������Ա�
*/
void ChangeList(Mul_SqList L, int *k)
{
    char ch;
    int i;
    ShowAllLists(L);
    printf("������Ҫ�л������Ա����ţ�");
    ch = getchar();
    i = ch - '0';
    while ((ch = getchar()) != EOF && ch != '\n');
    if(i > 0 && i <= L.List_Num)
    {
        *k = i;
        printf("�Ѿ��л������Ա�%s\n", L.Lists[i - 1].ListName);
    }
    else
    {
        printf("����������ݲ��Ϸ�\n");
    }
}

/*
* �������ƣ�StoreFiles
* �β��б�ָ�����Ա���
* ���ز�������
* �û����룺�������ļ�������
* �������ܣ����浱ǰ�ڴ��е����Ա�
*/
void StoreFiles(Mul_SqList *L)
{
    FILE *fp;
    char filename[60] = "./SqList/output_files/", name[30];
    if(L)
    {
        printf("���봴���ļ�����");
        gets(name);
        strcat(filename, name);
        if(fp = fopen(filename, "wb"))
        {
            printf("�����ļ��ɹ�\n");
//�Ѽ�¼���Ա��������¼��
            fwrite(L, sizeof(Mul_SqList), 1, fp);
            fwrite(L->Lists, sizeof(SqList), L->List_Num, fp);
//��ÿ�����Ա������¼��
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

/*
* �������ƣ�LoadFiels
* �β��б�ָ�����Ա���
* ���ز�����status��״ָ̬ʾ����
* �û����룺�����ļ�����
* �������ܣ�����ָ���ļ��е����Ա���
*/
status LoadFiles(Mul_SqList * L)
{
    FILE *fp;
    char flag, ch;
    char filename[60] = "./SqList/output_files/", name[30];
    printf("ֱ�Ӽ��ػᶪʧ����δ�洢���ݣ���Y��������S���浱ǰ���ݺ��������������˳�\n");
    flag = getchar();
    if(flag == 'S' || flag == 's' || flag == 'Y' || flag == 'y')
    {
        if(flag == 'S' || flag == 's')
        {
            StoreFiles(L);
        }
        printf("������ļ�����");
        while ((ch = getchar()) != EOF && ch != '\n');
        gets(name);
        strcat(filename, name);
        if(fp = fopen(filename, "rb"))
        {
//�������Ա���
            fread(L, sizeof(Mul_SqList), 1, fp);
            L->Lists = (SqList *)malloc(sizeof(SqList) * L->List_Num);
            fread(L->Lists, sizeof(SqList), L->List_Num, fp);
//�ָ�ÿ�����Ա��е�Ԫ��
            for(int i = 0; i < L->List_Num; i++)
            {
                L->Lists[i].elem = (ElemType *)malloc(sizeof(ElemType) * L->Lists[i].size);
                fread(L->Lists[i].elem, sizeof(ElemType), L->Lists[i].length, fp);
            }
            return OK;
        }
        else
        {
            printf("����ʧ�ܣ�\n");
            return ERROR;
        }
    }
    else
    {
        printf("���β����ѱ�����\n");
        return ERROR;
    }
}

/*
* �������ƣ�ChangeList
* �β��б���
* �û����룺��ɾ���ļ�����
* ���ز�����status��״ָ̬ʾ����
* �������ܣ�ɾ��ָ���ļ�
*/
status DeleteFiles()
{
    FILE *fp;
    char flag, ch;
    char filename[60] = "./SqList/output_files/", name[30];
    printf("�����ɾ���ļ�����\n");
    gets(name);
    strcat(filename, name);
    if(remove(filename) == 0)
    {
        printf("��ɾ�� %s��\n", filename);
        return OK;
    }
    else
    {
        perror("remove");
        return ERROR;
    }
}
#endif