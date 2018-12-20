#ifndef _H_Graph
#define _H_Graph
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef int ValueType;
//���������б�
typedef enum {ERROR, OK, OVERFLOW = -2, INFEASIBLE, FALSE, TRUE} status;
//ͼ�ж���Ķ���
typedef struct
{
    char key[10];
    ValueType value;
}VexType;

//ͼ�бߵĶ���
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode * nextarc;
}ArcNode;

//�ڽӱ���Ԫ�صĶ���
typedef struct
{
    VexType data;
    ArcNode *firstarc;
    status mark;
}VNode;

//�ڽӱ�Ķ���
typedef struct
{
    VNode *arcclist;
    int vexnum, arcnum;
    char name[10];
}AdjGraph;

//���Ķ���
typedef struct
{
    AdjGraph **graphs;   
    int num;            //����һ���ж��ٸ�ͼ
    int loc;            //�����������ڴ����ͼ��λ�򣬴�1��ʼ
}Graphs;

//����IO����
void setValue(ValueType *value)
{
    char ch;
    while(!scanf("%d", value))
    {
        printf("�������ݲ��Ϸ�\n");
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
    printf("����key:");
    scanf("%s", v->key);
    printf("����ֵ��");
    setValue(&(v->value));
}

void getVex(VexType v)
{
    printf("key: %s\t", v.key);
    printf("value: ");
    getValue(v.value);
}
//����IO��������

#endif