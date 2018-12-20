#ifndef _H_Graph
#define _H_Graph
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef int ValueType;
//返回类型列表
typedef enum {ERROR, OK, OVERFLOW = -2, INFEASIBLE, FALSE, TRUE} status;
//图中顶点的定义
typedef struct
{
    char key[10];
    ValueType value;
}VexType;

//图中边的定义
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode * nextarc;
}ArcNode;

//邻接表中元素的定义
typedef struct
{
    VexType data;
    ArcNode *firstarc;
    status mark;
}VNode;

//邻接表的定义
typedef struct
{
    VNode *arcclist;
    int vexnum, arcnum;
    char name[10];
}AdjGraph;

//多表的定义
typedef struct
{
    AdjGraph **graphs;   
    int num;            //保存一共有多少个图
    int loc;            //保存现在正在处理的图的位序，从1开始
}Graphs;

//基本IO操作
void setValue(ValueType *value)
{
    char ch;
    while(!scanf("%d", value))
    {
        printf("输入数据不合法\n");
        while ((ch = getchar()) != EOF && ch != '\n');
    }
    while ((ch = getchar()) != EOF && ch != '\n');
}

void getValue(ValueType v)
{
    printf("%d", v);
}

void setVex(VexType *v)
{
    printf("输入key:");
    scanf("%s", v->key);
    printf("输入值：");
    setValue(&(v->value));
}

void getVex(VexType v)
{
    printf("key: %s\t", v.key);
    printf("value: ");
    getValue(v.value);
}
//基本IO操作结束

#endif