#ifndef _H_BiTree_
#define _H_BiTree_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//���������б�
typedef enum {ERROR, OK, OVERFLOW = -2, INFEASIBLE, FALSE, TRUE} status;
//�������ڵ㶨��
typedef int ValueType;

typedef struct BiTNode
{
    char key[10];
    ValueType value;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree, **defination;

//����������
typedef struct Defination{
    defination df;
    int n;
}Defination;

//�������ڵ��IO����
void getValue(ValueType e)
{
    printf("%d\n", e);
}

void setValue(ValueType *e)
{
    char ch;
    while(!scanf("%d", e))
    {
        printf("�Ƿ����룬����������\n");
        while ((ch = getchar()) != EOF && ch != '\n');
    }
    while ((ch = getchar()) != EOF && ch != '\n');
}

void setBiTNode(BiTree n)
{
    printf("key:");
    scanf("%s", n->key);
    printf("\nvalue:\n");
    setValue(&n->value);
}

void getBiTNode(BiTree n)
{
    printf("key:%s\nvalue:", n->key);
    getValue(n->value);
}

//ɭ�ֵĶ���
typedef struct
{
    BiTree* Trees;
//ɭ���б������������
    int treenum;
//���ڴ�������ı�ţ���1��ʼ
    int loc;
}Mul_BiTree;

//keyset�Ķ���
typedef struct
{
    char ** keys;
    int num;
}keyset;
#endif