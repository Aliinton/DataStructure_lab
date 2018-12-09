#ifndef _H_functions_
#define _H_functions_
#include "BiTree.h"
//函数声明
void InitForest(Mul_BiTree * forest);
BiTree isDestory(Mul_BiTree *forest);
status InitBiTree(Mul_BiTree *forest);
status ClearBiTree(Mul_BiTree *forest);
void clear(BiTree *t);
void destroyBiTree(Mul_BiTree *forest);
status notContain(defination df, int n, char *s);
Defination setdefination();
void CreateBiTree(BiTree *t, defination df, int *loc, int n);
void PreOrderTraverse(BiTree t);
void InOrderTraverse(BiTree t);
void PostOrderTraverse(BiTree t);
status BiTreeEmpty(Mul_BiTree *forest);
BiTree Value(BiTree t, char * key);
BiTree Root(BiTree t);
status Assign(BiTree t, char *key, ValueType v);
BiTree Parent(BiTree t, char *key);
BiTree LeftChild(BiTree t, char *key);
BiTree RightChild(BiTree t, char *key);
BiTree LeftSibling(BiTree t, char *key);
BiTree RightSibling(BiTree t, char *key);
status NewTree(Mul_BiTree *forest);
void ChangeTree(Mul_BiTree *forest);
void DeleteTree(Mul_BiTree *forest);
void showTree(BiTree t, int level);
void Showforest(Mul_BiTree *forest);
/**
 * 函数名：judge
 * 参数：Defination指针
 * 返回值：合法返回1，非法返回0
 * 功能：判断是否合法
 */
int judge(Defination *df)
{
    if(df->n == 0)
        return 0;
    if(df->n == 1 && df->df[0] == NULL)
        return 1;
    if(df->n == 1 && df->df[0] != NULL)
        return 0;
    if(df->df[df->n -  1] == NULL && df->df[df->n - 2] == NULL)
        return 1;
    else
        return 0;
}

/**
 * 函数名：InitForest
 * 参数：待初始化森林地址
 * 返回值：成功返回OK，失败返回ERROR
 * 功能：初始化一个森林
 */
void InitForest(Mul_BiTree * forest)
{
    forest->treenum = 1;
    forest->Trees = (BiTree *)malloc(sizeof(BiTree) * forest->treenum);
    forest->Trees[0] = NULL;
    forest->loc = 1;
}

/**
 * 函数名：isDestroy
 * 参数：树林地址
 * 返回值：当前树已被销毁返回null，未被销毁返回根节点指针
 * 功能：判断二叉树是否存在
 */
BiTree isDestory(Mul_BiTree *forest)
{
    BiTree t = forest->Trees[forest->loc - 1];
    if(t == NULL)
    {
        printf("二叉树已被销毁\n");
        return NULL;
    }
    return t;
}

/**
 * 函数名：InitBiTree
 * 参数：树林地址
 * 返回值：初始化成功返回OK，失败返回ERROR
 * 功能：初始化一颗二叉树
 */
status InitBiTree(Mul_BiTree *forest)
{
    char ch;
    BiTree t = forest->Trees[forest->loc - 1];
    if(t)
    {
        if(ClearBiTree(forest) != OK)
            return ERROR;
    }
    else
    {
        if(!(forest->Trees[forest->loc - 1] = (BiTree)malloc(sizeof(BiTNode))))
            return ERROR;
        forest->Trees[forest->loc - 1]->lchild = NULL;
    }
    printf("输入树名：");
    scanf("%s", forest->Trees[forest->loc - 1]->key);
    while ((ch = getchar()) != EOF && ch != '\n');
    return OK;
}

/**
 * 函数名：ClearBiTree
 * 参数：树林地址
 * 返回值：清空成功返回OK，失败返回ERROR
 * 功能：清空一颗二叉树，得到初始化状态
 */
status ClearBiTree(Mul_BiTree *forest)
{
    BiTree t = isDestory(forest);
    if(t)
    {
        clear(&(t->lchild));
    }
    else
    {
        return ERROR;
    }
    return OK;
}

/**
 * 函数名：clear
 * 参数：待清空二叉树根节点
 * 返回值：空
 * 功能：清空二叉树的辅助函数
 */
void clear(BiTree *t)
{
    if(*t)
    {
        clear(&((*t)->lchild));
        clear(&((*t)->rchild));
        free(*t);
        *t = NULL;
    }
}

/**
 * 函数名：DestroyBiTree
 * 参数：树林地址
 * 返回值：空
 * 功能：销毁正在处理的二叉树
 */
void DestroyBiTree(Mul_BiTree *forest)
{
    BiTree t = isDestory(forest);
    if(t)
    {
        t = t->lchild;
        clear(&t);
        free(forest->Trees[forest->loc - 1]);
        forest->Trees[forest->loc - 1] = NULL;
        printf("销毁成功");
    }
}
/**
 * 函数名：contain
 * 参数：某一颗树的defination；defination中的节点数量，包括空枝；待比较key值
 * 返回值：包含返回false，不包含返回true
 */
status contain(defination df, int n, char *s)
{
    for(int i = 0; i < n; i++)
    {
        if(df[i])
        {
            if(!strcmp(df[i]->key, s))
            return TRUE;
        }
    }
    return FALSE;
}

/**
 * 函数名：setdefination
 * 参数：空
 * 返回值：树节点指针数组
 */
Defination setdefination()
{
    Defination* DF = (Defination *)malloc(sizeof(Defination));
    defination df = NULL;
    char key[10];
//保存现在有多少个结点，包括空枝
    int n = 0;
    printf("输入带空枝的前序遍历序列，用'#'代表空枝,用EOF结束输入\nkey:");
    while(scanf("%s", key) != EOF)
    {
        if(strcmp(key, "#"))
        {
            if(contain(df, n, key))
            {
                printf("关键字冲突,重新输入\n");
            }
            else
            {
                n++;
                if(!(df = (defination)realloc(df, sizeof(BiTree) * n)))
                    perror("realloc");
                df[n - 1] = (BiTree)malloc(sizeof(BiTNode));
                strcpy(df[n - 1]->key, key);
                printf("value：");
                setValue(&df[n - 1]->value);
                df[n - 1]->lchild = df[n - 1]->rchild = NULL;
            }
        }
        else
        {
            n++;
            if(!(df = (defination)realloc(df, sizeof(BiTree) * n)))
                perror("realloc");
            df[n - 1] = NULL;
        }
        /*
        for(int i = 0; i < n; i++)
        {
            printf("%x", df[i]);
            if(df[i])
                printf("----key:%svalue:%d----\n", df[i]->key, df[i]->value);
            else
                printf("空\n");
        }
        */
        printf("key:");
    }
    DF->df = df;
    DF->n = n;
    return *DF;
}

/**
 * 函数名：CreateBiTree
 * 参数：树根节点地址，定义，个数，正在写入的位置
 * 返回值：空
 * 功能：依据defination创建一颗二叉树
 */
void CreateBiTree(BiTree *t, defination df, int *loc, int n)
{
    if(*loc <= n)
    {
        if(!df[*loc])
        {
            *t = NULL;
            (*loc)++;
        }
        else
        {
            *t = df[*loc];
            (*loc)++;
            CreateBiTree(&((*t)->lchild), df, loc, n);
            CreateBiTree(&((*t)->rchild), df, loc, n);
        }
    }
}

/**
 * 函数名：BiTreeEmpty
 * 参数：森林地址
 * 返回值：为空返回TRUE，非空返回FALSE
 * 功能：判断这个树是否为空
 */
status BiTreeEmpty(Mul_BiTree *forest)
{
    BiTree t = isDestory(forest);
    if(t)
    {
        if(t->lchild)
            return FALSE;
        else
            return TRUE;
    }
    return INFEASIBLE;
}

/**
 * 函数名：BiTreeDepth
 * 参数：树根节点
 * 返回值：深度
 * 功能：求当前处理的树的深度
 */
int BiTreeDepth(BiTree t)
{
    int dl, dr, d;
    if(t == NULL)
        return 0;
    else
    {
        dl = BiTreeDepth(t->lchild);
        dr = BiTreeDepth(t->rchild);
        d = dl>dr?dl:dr;
        return d + 1;
    }
}

/**
 * 函数名：PreOrderTraverse
 * 参数：树根节点
 * 返回值：空
 * 功能：前序遍历
 */
void PreOrderTraverse(BiTree t)
{
    if(t)
    {
        getBiTNode(t);
        PreOrderTraverse(t->lchild);
        PreOrderTraverse(t->rchild);
    }
}

/**
 * 函数名：InOrderTraverse
 * 参数：树根节点
 * 返回值：空
 * 功能：中序遍历
 */
void InOrderTraverse(BiTree t)
{
    if(t)
    {
        InOrderTraverse(t->lchild);
        getBiTNode(t);
        InOrderTraverse(t->rchild);
    }
}

/**
 * 函数名：PostOrderTraverse
 * 参数：树根节点
 * 返回值：空
 * 功能：后序遍历
 */
void PostOrderTraverse(BiTree t)
{
    if(t)
    {
        PostOrderTraverse(t->lchild);
        PostOrderTraverse(t->rchild);
        getBiTNode(t);
    }
}

/**
 * 函数名：Root
 * 参数：森林地址
 * 返回值：返回树的根指针
 * 功能：得到当前处理树的根节点
 */
BiTree Root(BiTree t)
{
    return t->lchild;
}

/**
 * 函数名：Value
 * 参数：树根节点，关键字
 * 返回值：待查找节点
 * 功能：依据关键字找顶点
 */
BiTree Value(BiTree t, char * key)
{
    BiTree* stack = (BiTree *)malloc(sizeof(BiTree));
    int top = 0;
    if(strcmp(key, t->key))
        stack[top++] = t;
    else
        return t;
    while(top)
    {
        t = stack[--top];
        if(t->rchild)
        {
            if(strcmp(t->rchild->key, key))
            {
                stack = (BiTree *)realloc(stack, sizeof(BiTree) * (top + 1));
                stack[top++] = t->rchild;
            }
            else
                return t->rchild;
        }
        if(t->lchild)
        {
            if(strcmp(t->lchild->key, key))
            {
                stack = (BiTree *)realloc(stack, sizeof(BiTree) * (top + 1));
                stack[top++] = t->lchild;
            }
            else
                return t->lchild;
        }
    }
    return NULL;
}

/**
 * 函数名：Assign
 * 参数：树根节点，key，value
 * 返回值：赋值成功返回OK，失败返回ERROR
 * 功能：向关键字为key的节点赋值为value
 */
status Assign(BiTree t, char *key, ValueType v)
{
    t = Value(t, key);
    if(t)
    {
        t->value = v;
        return OK;
    }
    else
    {
        return ERROR;
    }
}

/**
 * 函数名：Parent
 * 参数：树根节点，key值
 * 返回值：有父节点返回父节点指针，没有返回NULL
 * 功能：获得指定节点父节点
 */
BiTree Parent(BiTree t, char *key)
{
    BiTree *stack = (BiTree *)malloc(sizeof(BiTree)), n;
    int top = 0, flag = 0;
    if(!strcmp(t->key, key))
    {
        printf("根节点\n");
        return NULL;
    }
    stack[top++] = t;
    while(top)
    {
        while(t = stack[top - 1])
        {
            if(!strcmp(t->key, key))
            {
                return stack[top - 2];
            }
            else
            {
                stack = (BiTree *)realloc(stack, sizeof(BiTree) * (top + 1));
                stack[top++] = t->lchild;
            }
        } 
        t = stack[--top];
        flag = 1;
        while(top && flag)
        {
            n = stack[top - 1];
            if(n->rchild == t)
            {
                t = stack[--top];
            }
            else
            {
                if(n->rchild && !strcmp(n->rchild->key, key))
                {
                    return n;
                }
                else
                {
                    stack = (BiTree *)realloc(stack, sizeof(BiTree) * (top + 1));
                    stack[top++] = n->rchild;
                    flag = 0;
                }
            }
        }
    }
    printf("不存在该节点\n");
    return NULL;
}

/**
 * 函数名：LeftChild
 * 参数：树根节点，待查找key值
 * 返回值：存在左儿子返回左儿子，没有返回NULL
 * 功能：获得指定节点的左儿子
 */
BiTree LeftChild(BiTree t, char *key)
{
    t = Value(t, key);
    if(t)
        return t->lchild;
    else
        return NULL;
}

/**
 * 函数名：RightChild
 * 参数：树根节点，待查找key值
 * 返回值：存在右儿子返回右儿子指针，没有返回NULL
 */
BiTree RightChild(BiTree t, char *key)
{
    t = Value(t, key);
    if(t)
        return t->rchild;
    else
        return NULL;
}

/**
 * 函数名：LeftSibling
 * 参数：树根节点，key
 * 返回值：存在leftsibling返回指针，不存在返回NULL
 * 功能：求leftsibling
 */
BiTree LeftSibling(BiTree t, char *key)
{
    if(!strcmp(t->key, key))
    {
        printf("根节点\n");
        return NULL;
    }
    BiTree n = Parent(t, key);
    if(!strcmp(n->lchild->key, key))
        return NULL;
    else
        return n->lchild;
}

/**
 * 函数名：RightSibling
 * 参数：树根节点，key
 * 返回值：存在rightsibling返回指针，不存在返回NULL
 * 功能：求rightsibling
 */
BiTree RightSibling(BiTree t, char *key)
{
    if(!strcmp(t->key, key))
    {
        printf("根节点\n");
        return NULL;
    }
    BiTree n = Parent(t, key);
    if(!strcmp(n->rchild->key, key))
        return NULL;
    else
        return n->rchild;
}

/**
 * 函数名：NewTree
 * 参数：森林地址
 * 返回值：新建成功返回OK，失败返回ERROR
 * 功能：新建一颗树
 */
status NewTree(Mul_BiTree *forest)
{
    int loc = forest->loc;
    status s;
    forest->Trees = (BiTree *)realloc(forest->Trees, sizeof(BiTree) * (forest->treenum + 1));
    forest->loc = forest->treenum + 1;
    forest->Trees[forest->treenum] = NULL;
    s = InitBiTree(forest);
    forest->treenum++;
    forest->loc = loc;
    if(s == OK)
        return OK;
    else
        return ERROR; 
}

/**
 * 函数名：ChangeTree
 * 参数：森林地址
 * 返回值：空
 * 功能：切换树
 */
void ChangeTree(Mul_BiTree *forest)
{
    int e;
    Showforest(forest);
    printf("切换到：");
    setValue(&e);
    while(e <= 0 || e >forest->treenum)
    {
        printf("非法输入，重新输入：");
        setValue(&e);
    }
    forest->loc = e;
    printf("已切换到树%s", forest->Trees[forest->loc - 1]->key);
    
}

/**
 * 函数名：DeleteTree
 * 参数：森林地址
 * 返回值：空
 * 功能：删除树
 */
void DeleteTree(Mul_BiTree *forest)
{
    int loc = forest->loc;
    BiTree t;
    for(int i = loc - 1; i < forest->treenum  - 1; i++)
    {
        t = forest->Trees[i];
        forest->Trees[i] = forest->Trees[i + 1];
        forest->Trees[i + 1] = t;
    }
    forest->treenum--;
    printf("删除成功\n");
    if(forest->treenum)
    {
        printf("选择要处理的树(输入序号)\n");
        ChangeTree(forest);
    }
    else
    {
        printf("没有树，请新建\n");
        if(InitBiTree(forest) == OK)
        {
            printf("新建成功\n");
            forest->treenum++;
        }
        else
            printf("新建失败\n");
    }
}

/**
 * 函数名：Showforest
 * 参数：森林地址
 * 返回值；空
 * 功能：打印森林
 */
void Showforest(Mul_BiTree *forest)
{
    printf("正在处理树%s\n", forest->Trees[forest->loc - 1]->key);
    for(int i = 0; i < forest->treenum; i++)
    {
        printf("第%d颗树：%s\n", i + 1, forest->Trees[i]->key);
        if(!forest->Trees[i])
        {
            printf("被销毁\n");
        }
        else
        {
            if(forest->Trees[i]->lchild)
            {
                showTree(forest->Trees[i]->lchild, 1);
            }
            else
            {
                printf("空树\n");
            }
        }
    }
}

/**
 * 函数名：showTree
 * 参数：树根地址
 * 返回值：空
 * 功能：打印一颗树
 */
void showTree(BiTree t, int level)
{
    printf("%*c", level, ' ');
    if(!t)
    {
        printf("#\n");
    }
    else
    {
        printf("%s-%d\n", t->key, t->value);
        showTree(t->lchild, level + 4);
        showTree(t->rchild, level + 4);
    }
}
#endif