#ifndef _H_GFUNCTIONS_H_
#define _H_GFUNCTIONS_H_
#include "Graph.h"

//函数声明
void printGraph(Graphs *gp);
void InitailGraphs(Graphs *GS);
AdjGraph * isDestroy(Graphs * g);
void createGraph(AdjGraph *gp);
int notContain(AdjGraph *gp, char * key);
status insertVex(AdjGraph * gp, VexType v);
status insertArc(AdjGraph *gp, char *key1, char *key2);
int getIndex(AdjGraph *gp, char *key);
status deleteVex(AdjGraph *gp, char *key);
status deleteArc(AdjGraph *gp, char* key1, char* key2);
void destroyGraph(AdjGraph **gp);
void initailGraph(Graphs *g);
status newGraph(Graphs *gp);
void changeGraph(Graphs * gp);
void deleteGraph(Graphs *gp);
VexType * firstAdjvex(AdjGraph *gp, char * key);
VexType * nextAdjvex(AdjGraph *gp, char *key1, char* key2);
status putVex(AdjGraph *gp, char *key);
VexType * getVex1(AdjGraph *gp, char * key);
void LocateVex(AdjGraph *gp, char *key);
status saveGraph(AdjGraph *gp);
status loadGraph(AdjGraph **gp);
void DFS(AdjGraph *gp, int start);
void DFSTraversal(AdjGraph *gp);
int notFinish(AdjGraph *gp);
void BFSTraversal(AdjGraph *gp);
void BFS(AdjGraph *gp, int start);

//调试用函数
void printGraph(Graphs *g)
{
    AdjGraph *gp;
    printf("现在正在处理图%d\n", g->loc);
    for(int i = 0; i < g->num; i++)
    {
        printf("图%d：", i + 1);   
        if(g->graphs[i])
        {
            gp = g->graphs[i];
            printf("%s\n", gp->name);
            printf("vexnum: %d  arcnum: %d\n", gp->vexnum, gp->arcnum);
            printf("--------------------------\n");
            for(int i = 0; i < gp->vexnum; i++)
            {
                printf("vex%d: ", i + 1);
                printf("%s\t", gp->arcclist[i].data.key);
                printf("adjvex: ");
                ArcNode * arcp = gp->arcclist[i].firstarc->nextarc;
                while(arcp)
                {
                    printf("%s\t", gp->arcclist[arcp->adjvex].data.key);
                    arcp = arcp->nextarc;
                }
                printf("\n");
            }
        }
        else
        {
            printf("图已被销毁\n");
        }
        printf("\n");
    }
}
/**
 * name:InitailGraphs
 * param: Graphs pointer
 * return: void
 * function: Initialize graphs
 */
void InitailGraphs(Graphs *g)
{
    g->num = g->loc = 1;
    g->graphs = (AdjGraph **)malloc(sizeof(AdjGraph *));
    g->graphs[0] = (AdjGraph *)malloc(sizeof(AdjGraph));
    g->graphs[0]->arcclist = NULL;
    g->graphs[0]->arcnum = 0;
    g->graphs[0]->vexnum = 0;
}

/**
 * name: initailGraph
 * param: Graphs poniter
 * return: void
 * function: Initialize graph
 */
void initailGraph(Graphs *g)
{
    g->graphs[g->loc - 1] = (AdjGraph *)malloc(sizeof(AdjGraph));
    g->graphs[g->loc - 1]->arcclist = NULL;
    g->graphs[g->loc - 1]->arcnum = g->graphs[g->loc - 1]->vexnum = 0;
    g->graphs[g->loc - 1]->name[0] = '\0';
}

/**
 * name: isDestroy
 * param: Graphs pointer
 * return: Grpah poniter(nul if destroyed)
 * functions: get the graph poniter
 */
AdjGraph * isDestroy(Graphs * g)
{
    if(g->graphs[g->loc - 1])
        return g->graphs[g->loc - 1];
    else
        return NULL;
}

/**
 * name: createGraph
 * param: graph pointer
 * return: void
 * function: create a graph by input
 */
void createGraph(AdjGraph *gp)
{
    VexType v;
    char s1[10], s2[10];
    int d1, d2;
    char ch;
    printf("输入图的名称：");
    scanf("%s", gp->name);
    printf("输入节点数：");
    setValue(&d1);
    printf("输入边数：");
    setValue(&d2);
    printf("输入节点\n");
    for(int i = 0; i < d1;)
    {
        setVex(&v);
        if(insertVex(gp, v) == OK)
            i++;
        else
            printf("关键字冲突\n");
    }
    printf("输入边\n");
    for(int i = 0; i < d2;)
    {
        printf("输入第%d条边\n", i + 1);
        scanf("%s", s1);
        scanf("%s", s2);
        if(insertArc(gp, s1, s2) == OK)
        {
            i++;
        }
        else
        {
            printf("非法输入");
        }
    }
    while ((ch = getchar()) != EOF && ch != '\n');
}

/**
 * name: notContain
 * param: graph pointer, key
 * return: contain return 0, not contain return 1
 * function: judge whether given graph contians certain key
 */
int notContain(AdjGraph *gp, char * key)
{
    for(int i = 0; i < gp->vexnum; i++)
    {
        if(!strcmp(gp->arcclist[i].data.key, key))
            return 0;
    }
    return 1;
}
/**
 * name: InsertVex
 * param: graph pointer, vexvalue
 * return: status(success return OK, fail return ERROR)
 * function: Insert a certain vex to the given graph
 */
status insertVex(AdjGraph * gp, VexType v)
{
    gp->arcclist = (VNode *)realloc(gp->arcclist, sizeof(VNode) * (gp->vexnum + 1));
    if(!gp->arcclist)
        return ERROR;
    if(notContain(gp, v.key))
    {
        gp->arcclist[gp->vexnum].data = v;
        gp->arcclist[gp->vexnum].firstarc = (ArcNode *)malloc(sizeof(ArcNode));
        gp->arcclist[gp->vexnum].firstarc->nextarc = NULL;
        gp->vexnum++;
    }
    else
    {
        return ERROR;
    }
    return OK;
}

/**
 * name: getIndex
 * param: key
 * return: if contian return index, not contain return -1
 * funtion: get the index according to the given key
 */
int getIndex(AdjGraph *gp, char *key)
{
    for(int i = 0; i < gp->vexnum; i++)
    {
        if(!strcmp(gp->arcclist[i].data.key, key))
            return i;
    }
    return -1;
}

/**
 * name: insetArc
 * param: two key
 * return: status(success return OK, fail return ERROR)
 * function: Insert arc key1->key2 to the given graph
 */
status insertArc(AdjGraph *gp, char *key1, char *key2)
{
    int i = getIndex(gp, key1), j = getIndex(gp, key2);
    if(i != -1 && j != -1)
    {
        ArcNode * arcp = gp->arcclist[i].firstarc->nextarc, *arcp2 = gp->arcclist[i].firstarc, *n;
        while(arcp && arcp->adjvex < j)
        {
            arcp2 = arcp;
            arcp = arcp->nextarc;
        }
        n = (ArcNode*)malloc(sizeof(ArcNode));
        n->adjvex = j;
        n->nextarc = arcp;
        arcp2->nextarc = n;
        gp->arcnum++;
        return OK;
    }
    else
        return ERROR;
}

/**
 * name: destroyGraph
 * param: graph pointer
 * return: void
 * function: destroy a graph
 */
void destroyGraph(AdjGraph **gp)
{
    while((*gp)->vexnum)
    {
        deleteVex(*gp, (*gp)->arcclist[0].data.key);
    }
    free((*gp)->arcclist);
    free(*gp);
    *gp = NULL;
}

/**
 * name: deleteVex
 * param: graph pointer, key
 * return: status(success return OK, fail return ERROR)
 * funciton: Delete a certain vex in the given graph
 */
status deleteVex(AdjGraph *gp, char *key)
{
    int loc = getIndex(gp, key);
    ArcNode *pre, *next;
    if(loc == -1)
        return ERROR;
    for(int i = 0; i < gp->vexnum; i++)
    {
        deleteArc(gp, gp->arcclist[i].data.key, key);
        pre = gp->arcclist[i].firstarc->nextarc;
        while(pre)
        {
            if(pre->adjvex > loc)
                pre->adjvex--;
            pre = pre->nextarc;
        }
    }
    pre = next = gp->arcclist[loc].firstarc;
    while(pre)
    {
        next = pre->nextarc;
        free(pre);
        pre = next;
        gp->arcnum--;
    }
    gp->arcnum++;
    for(int i = loc; i < gp->vexnum - 1; i++)
        gp->arcclist[i] = gp->arcclist[i + 1];
    gp->vexnum--;
    return OK;
}

/**
 * name: deleteArc
 * param: graph pointer, key1, key2
 * return: status(success return OK, fail return ERROR)
 * function: delete arc key1->key2 in the given graph
 */
status deleteArc(AdjGraph *gp, char* key1, char* key2)
{
    int loc1 = getIndex(gp, key1), loc2 = getIndex(gp, key2);
    if(loc1 != -1 && loc2 != -1)
    {
        ArcNode * pre = gp->arcclist[loc1].firstarc, * next = pre->nextarc;
        while(next && next->adjvex != loc2)
        {
            pre = next;
            next = next->nextarc;
        }
        if(next)
        {
            pre->nextarc = next->nextarc;
            free(next);
            gp->arcnum--;
            return OK;
        }
    }
    return ERROR;
}

/**
 * name: newGraph
 * param: Graphs adress
 * return: status(success return OK, fail return ERROR)
 * function: new a graph
 */
status newGraph(Graphs *gp)
{
    gp->graphs = (AdjGraph **)realloc(gp->graphs, sizeof(AdjGraph *) * (gp->num + 1));
    if(!gp->graphs)
    {
        perror("realloc");
        return ERROR;
    }
    gp->graphs[gp->num] = (AdjGraph *)malloc(sizeof(AdjGraph));
    if(!gp->graphs[gp->num])
    {
        perror("malloc");
        return ERROR;
    }
    gp->graphs[gp->num]->arcclist = NULL;
    gp->graphs[gp->num]->arcnum = gp->graphs[gp->num]->vexnum = 0;
    gp->graphs[gp->num]->name[0] = '\0';
    gp->num++;
    return OK;
}

/**
 * name: changeGraph
 * param: Grpahs adress
 * return: void
 * function: change the graph
 */
void changeGraph(Graphs *gp)
{
    printGraph(gp);
    printf("切换到：");
    scanf("%d", &gp->loc);
    while(gp->loc <= 0 || gp->loc > gp->num)
    {
        printf("没有对应图，重新输入：");
        scanf("%d", &gp->loc);
    }
    printf("切换成功\n");
    getchar();
}

/**
 * name: deleteGraph
 * param: Graphs adress
 * return: void
 * function: delete the Graph
 */
void deleteGraph(Graphs *gp)
{
    gp->num--;
    for(int i = gp->loc - 1; i < gp->num; i++)
    {
        gp->graphs[i] = gp->graphs[i + 1];
    }
    if(gp->num)
    {
        changeGraph(gp);
    }
    else
    {
        printf("没有图，已新建\n");
        newGraph(gp);
    }
}

/**
 * name: firstAdjvex
 * param: Grpah adress
 * return: vex pointer
 * function: get the fist adjacent vex
 */
VexType * firstAdjvex(AdjGraph *gp, char* key)
{
    int loc;
    loc = getIndex(gp, key);
    if(loc == -1)
    {
        printf("没有对应顶点\n");
    }
    else
    {
        ArcNode *arcp = gp->arcclist[loc].firstarc->nextarc;
        if(arcp)
        {
            return &(gp->arcclist[arcp->adjvex].data);
        }
        else
        {
            return NULL;
        }
    }
}

/**
 * name: nextAdjvex
 * param: graph adress, key1, kye2
 * return: vex pointer
 * function: get the next adjvex
 */
VexType * nextAdjvex(AdjGraph *gp, char *key1, char *key2)
{
    int loc1 = getIndex(gp, key1), loc2 = getIndex(gp, key2);
    if(loc1 == -1 || loc2 == -1)
    {
        printf("非法输入\n");
        return NULL;
    }
    ArcNode *arcp = gp->arcclist[loc1].firstarc->nextarc;
    while(arcp && arcp->adjvex != loc2)
        arcp = arcp->nextarc;
    if(!arcp)
    {
        printf("没有这个邻接点\n");
        return NULL;
    }
    if(arcp->nextarc)
    {
        loc1 = arcp->nextarc->adjvex;
        return &(gp->arcclist[loc1].data);
    }
    else
    {
        printf("已是最后一个邻接点\n");
        return NULL;
    }
}

/**
 * name: putVex
 * param: Graph adress, key
 * return: status(success return OK, fail return ERROR)
 * function: change vex value
 */
status putVex(AdjGraph *gp, char *key)
{
    int loc = getIndex(gp, key);
    if(loc == -1)
        return ERROR;
    printf("value：");
    setValue(&(gp->arcclist[loc].data.value));    
    return OK;
}

/**
 * name: getVex1
 * param: graph adress, key
 * return: vex pointer
 * function: get certain vex
 */
VexType * getVex1(AdjGraph *gp, char * key)
{
    int loc = getIndex(gp, key);
    if(loc == -1)
        return NULL;
    return &(gp->arcclist[loc].data);
}

/**
 * name: LocateVex
 * param: graph adress, key
 * return: void
 * function: locate the vex
 */
void LocateVex(AdjGraph *gp, char *key)
{
    int loc = getIndex(gp, key);
    if(loc == -1)
        printf("没有该顶点\n");
    else
    {
        ArcNode *arcp = gp->arcclist[loc].firstarc->nextarc;
        printf("顶点%s可到达：", key);
        while(arcp)
        {
            printf("%-10s", gp->arcclist[arcp->adjvex].data.key);
            arcp = arcp->nextarc;
        }
        printf("顶点%s可被以下顶点到达：", key);
        for(int i = 0; i < gp->vexnum; i++)
        {
            if(i != loc)
            {
            arcp = gp->arcclist[i].firstarc->nextarc;
                while(arcp)
                {
                    if(arcp->adjvex == loc)
                    {
                        printf("%-10s\t", gp->arcclist[i].data.key);
                        break;
                    }
                    arcp = arcp->nextarc;
                }
            }
        }
    }
}

/**
 * name: saveGraph
 * param: Graph adress
 * return: status(success return OK, fail return ERROR)
 * function: save a graph into the file
 */
status saveGraph(AdjGraph *gp)
{
    FILE *fp;
    ArcNode *arcp;
    char filename[] = {"./"}, name[20];
    int loc;
    gets(name);
    strcat(filename, name);
    if(!(fp = fopen(filename, "wb")))
    {
        perror("fopen");
        return ERROR;
    }
    fwrite(gp, sizeof(AdjGraph), 1, fp);
    for(int i = 0; i < gp->vexnum; i++)
    {
        fwrite(&(gp->arcclist[i]), sizeof(VNode), 1, fp);
        arcp = gp->arcclist[i].firstarc->nextarc;
        while(arcp)
        {
            loc = arcp->adjvex;
            fwrite(&loc, sizeof(int), 1, fp);
            arcp = arcp->nextarc;
        }
        loc = -1;
        fwrite(&loc, sizeof(int), 1, fp);
    }
    fclose(fp);
    return OK;
}

/**
 * name: loadGraph
 * param: Graph adress
 * return: status(success return OK, fail return ERROR)
 * function: load a graph from the file
 */
status loadGraph(AdjGraph **gp)
{
    FILE *fp;
    ArcNode *head, *pre, *n;
    char filename[] = "./", name[20];
    int loc;
    gets(name);
    strcat(filename, name);
    if(!(fp = fopen(filename, "rb")))
    {
        perror("fopen");
        return ERROR;
    }
    *gp = (AdjGraph *)malloc(sizeof(AdjGraph));
    fread(*gp, sizeof(AdjGraph), 1, fp);
    (*gp)->arcclist = (VNode *)malloc(sizeof(VNode) * (*gp)->vexnum);
    for(int i = 0; i < (*gp)->vexnum; i++)
    {
        fread(&((*gp)->arcclist[i]), sizeof(VNode), 1, fp);
        n = (ArcNode *)malloc(sizeof(ArcNode));
        head = pre = n;
        fread(&loc, sizeof(int), 1, fp);
        while(loc != -1)
        {
            n = (ArcNode *)malloc(sizeof(ArcNode));
            n->adjvex = loc;
            pre->nextarc = n;
            pre = n;
            fread(&loc, sizeof(int), 1, fp);
        }
        pre->nextarc = NULL;
        (*gp)->arcclist[i].firstarc = head;
    }
    fclose(fp);
    return OK;
}

/**
 * name: BFS
 * param: Graph adress
 * return: void
 * function: BFS
 */
void DFS(AdjGraph *gp, int start)
{
    int stack[100], top = 0, loc;
    ArcNode *arcp;
    stack[top++] = start;
    printf("%s\t", gp->arcclist[start].data.key);
    gp->arcclist[start].mark = TRUE;
    while(top)
    {
        loc = stack[top - 1];
        arcp = gp->arcclist[loc].firstarc->nextarc;
        while(arcp && gp->arcclist[arcp->adjvex].mark == TRUE)
            arcp = arcp->nextarc;
        if(arcp)
        {
            stack[top++] = arcp->adjvex;
            printf("%s\t", gp->arcclist[arcp->adjvex].data.key);
            gp->arcclist[arcp->adjvex].mark = TRUE;
        }
        else
            top--;
    }
}

/**
 * name: notFinish
 * param: Grpah adress
 * return: finish -1, not finish return the not visit vex index
 * function: judge whether all the vex in graph is visited
 */
int notFinish(AdjGraph *gp)
{
    for(int i = 0; i < gp->vexnum; i++)
    {
        if(gp->arcclist[i].mark == FALSE)
            return i;
    }
    return -1;
}
/**
 * name: BFSTraversal
 * param: Graph adress
 * return: void
 * function: BFS
 */
void DFSTraversal(AdjGraph *gp)
{
    char key[10], ch;
    int loc;
    printf("输入起点节点：");
    scanf("%s", key);
    while ((ch = getchar()) != EOF && ch != '\n');
    for(int i = 0; i < gp->vexnum; i++)
        gp->arcclist[i].mark = FALSE;
    if(getIndex(gp, key) != -1)
    {
        DFS(gp, getIndex(gp, key));
        while(loc = notFinish(gp), loc != -1)
            DFS(gp, loc);
    }
    else
    {
        printf("非法输入\n");
    }
}

/**
 * name: BFSTraversal
 * param: Graph adress
 * return: void
 * function: BFS
 */
void BFSTraversal(AdjGraph *gp)
{
    char key[10], ch;
    int loc;
    printf("输入起点节点：");
    scanf("%s", key);
    while ((ch = getchar()) != EOF && ch != '\n');
    for(int i = 0; i < gp->vexnum; i++)
        gp->arcclist[i].mark = FALSE;
    if(getIndex(gp, key) != -1)
    {
        BFS(gp, getIndex(gp, key));
        while(loc = notFinish(gp), loc != -1)
            BFS(gp, loc);
    }
    else
    {
        printf("非法输入\n");
    }
}

/**
 * name: BFS
 * param: Graph adress
 * return: void
 * function: BFS
 */
void BFS(AdjGraph *gp, int start)
{
    ArcNode *arcp;
    int queue[100], rear = 0, front = 0, loc;
    queue[rear++] = start;
    printf("%s\t", gp->arcclist[start].data.key);
    gp->arcclist[start].mark = TRUE;
    while(rear != front)
    {
        loc = queue[front++];
        arcp = gp->arcclist[loc].firstarc->nextarc;
        while(arcp)
        {
            if(gp->arcclist[arcp->adjvex].mark == FALSE)
            {
                printf("%s\t", gp->arcclist[arcp->adjvex].data.key);
                gp->arcclist[arcp->adjvex].mark = TRUE;
                queue[rear++] = arcp->adjvex;
                rear %= 100;
            }
            arcp = arcp->nextarc;
        }
    }
}
#endif