#ifndef _H_BiTree_
#define _H_BiTree_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//返回类型列表
typedef enum {ERROR, OK, OVERFLOW = -2, INFEASIBLE, FALSE, TRUE} status;
//二叉树节点定义
typedef int ValueType;

typedef struct BiTNode
{
    char key[10];
    ValueType value;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree, **defination;

//二叉树定义
typedef struct Defination{
    defination df;
    int n;
}Defination;

//二叉树节点的IO操作
void getValue(ValueType e)
{
    printf("%d\n", e);
}

void setValue(ValueType *e)
{
    char ch;
    while(!scanf("%d", e))
    {
        printf("非法输入，请重新输入\n");
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

//森林的定义
typedef struct
{
    BiTree* Trees;
//森林中保存的树的数量
    int treenum;
//正在处理的树的编号，从1开始
    int loc;
}Mul_BiTree;

//keyset的定义
typedef struct
{
    char ** keys;
    int num;
}keyset;
#endif