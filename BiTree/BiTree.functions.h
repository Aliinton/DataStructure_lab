#ifndef _H_functions_
#define _H_functions_
#include "BiTree.h"
//��������
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
 * ��������judge
 * ������Definationָ��
 * ����ֵ���Ϸ�����1���Ƿ�����0
 * ���ܣ��ж��Ƿ�Ϸ�
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
 * ��������InitForest
 * ����������ʼ��ɭ�ֵ�ַ
 * ����ֵ���ɹ�����OK��ʧ�ܷ���ERROR
 * ���ܣ���ʼ��һ��ɭ��
 */
void InitForest(Mul_BiTree * forest)
{
    forest->treenum = 1;
    forest->Trees = (BiTree *)malloc(sizeof(BiTree) * forest->treenum);
    forest->Trees[0] = NULL;
    forest->loc = 1;
}

/**
 * ��������isDestroy
 * ���������ֵ�ַ
 * ����ֵ����ǰ���ѱ����ٷ���null��δ�����ٷ��ظ��ڵ�ָ��
 * ���ܣ��ж϶������Ƿ����
 */
BiTree isDestory(Mul_BiTree *forest)
{
    BiTree t = forest->Trees[forest->loc - 1];
    if(t == NULL)
    {
        printf("�������ѱ�����\n");
        return NULL;
    }
    return t;
}

/**
 * ��������InitBiTree
 * ���������ֵ�ַ
 * ����ֵ����ʼ���ɹ�����OK��ʧ�ܷ���ERROR
 * ���ܣ���ʼ��һ�Ŷ�����
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
    printf("����������");
    scanf("%s", forest->Trees[forest->loc - 1]->key);
    while ((ch = getchar()) != EOF && ch != '\n');
    return OK;
}

/**
 * ��������ClearBiTree
 * ���������ֵ�ַ
 * ����ֵ����ճɹ�����OK��ʧ�ܷ���ERROR
 * ���ܣ����һ�Ŷ��������õ���ʼ��״̬
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
 * ��������clear
 * ����������ն��������ڵ�
 * ����ֵ����
 * ���ܣ���ն������ĸ�������
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
 * ��������DestroyBiTree
 * ���������ֵ�ַ
 * ����ֵ����
 * ���ܣ��������ڴ���Ķ�����
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
        printf("���ٳɹ�");
    }
}
/**
 * ��������contain
 * ������ĳһ������defination��defination�еĽڵ�������������֦�����Ƚ�keyֵ
 * ����ֵ����������false������������true
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
 * ��������setdefination
 * ��������
 * ����ֵ�����ڵ�ָ������
 */
Defination setdefination()
{
    Defination* DF = (Defination *)malloc(sizeof(Defination));
    defination df = NULL;
    char key[10];
//���������ж��ٸ���㣬������֦
    int n = 0;
    printf("�������֦��ǰ��������У���'#'�����֦,��EOF��������\nkey:");
    while(scanf("%s", key) != EOF)
    {
        if(strcmp(key, "#"))
        {
            if(contain(df, n, key))
            {
                printf("�ؼ��ֳ�ͻ,��������\n");
            }
            else
            {
                n++;
                if(!(df = (defination)realloc(df, sizeof(BiTree) * n)))
                    perror("realloc");
                df[n - 1] = (BiTree)malloc(sizeof(BiTNode));
                strcpy(df[n - 1]->key, key);
                printf("value��");
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
                printf("��\n");
        }
        */
        printf("key:");
    }
    DF->df = df;
    DF->n = n;
    return *DF;
}

/**
 * ��������CreateBiTree
 * �����������ڵ��ַ�����壬����������д���λ��
 * ����ֵ����
 * ���ܣ�����defination����һ�Ŷ�����
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
 * ��������BiTreeEmpty
 * ������ɭ�ֵ�ַ
 * ����ֵ��Ϊ�շ���TRUE���ǿշ���FALSE
 * ���ܣ��ж�������Ƿ�Ϊ��
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
 * ��������BiTreeDepth
 * �����������ڵ�
 * ����ֵ�����
 * ���ܣ���ǰ������������
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
 * ��������PreOrderTraverse
 * �����������ڵ�
 * ����ֵ����
 * ���ܣ�ǰ�����
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
 * ��������InOrderTraverse
 * �����������ڵ�
 * ����ֵ����
 * ���ܣ��������
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
 * ��������PostOrderTraverse
 * �����������ڵ�
 * ����ֵ����
 * ���ܣ��������
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
 * ��������Root
 * ������ɭ�ֵ�ַ
 * ����ֵ���������ĸ�ָ��
 * ���ܣ��õ���ǰ�������ĸ��ڵ�
 */
BiTree Root(BiTree t)
{
    return t->lchild;
}

/**
 * ��������Value
 * �����������ڵ㣬�ؼ���
 * ����ֵ�������ҽڵ�
 * ���ܣ����ݹؼ����Ҷ���
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
 * ��������Assign
 * �����������ڵ㣬key��value
 * ����ֵ����ֵ�ɹ�����OK��ʧ�ܷ���ERROR
 * ���ܣ���ؼ���Ϊkey�Ľڵ㸳ֵΪvalue
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
 * ��������Parent
 * �����������ڵ㣬keyֵ
 * ����ֵ���и��ڵ㷵�ظ��ڵ�ָ�룬û�з���NULL
 * ���ܣ����ָ���ڵ㸸�ڵ�
 */
BiTree Parent(BiTree t, char *key)
{
    BiTree *stack = (BiTree *)malloc(sizeof(BiTree)), n;
    int top = 0, flag = 0;
    if(!strcmp(t->key, key))
    {
        printf("���ڵ�\n");
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
    printf("�����ڸýڵ�\n");
    return NULL;
}

/**
 * ��������LeftChild
 * �����������ڵ㣬������keyֵ
 * ����ֵ����������ӷ�������ӣ�û�з���NULL
 * ���ܣ����ָ���ڵ�������
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
 * ��������RightChild
 * �����������ڵ㣬������keyֵ
 * ����ֵ�������Ҷ��ӷ����Ҷ���ָ�룬û�з���NULL
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
 * ��������LeftSibling
 * �����������ڵ㣬key
 * ����ֵ������leftsibling����ָ�룬�����ڷ���NULL
 * ���ܣ���leftsibling
 */
BiTree LeftSibling(BiTree t, char *key)
{
    if(!strcmp(t->key, key))
    {
        printf("���ڵ�\n");
        return NULL;
    }
    BiTree n = Parent(t, key);
    if(!strcmp(n->lchild->key, key))
        return NULL;
    else
        return n->lchild;
}

/**
 * ��������RightSibling
 * �����������ڵ㣬key
 * ����ֵ������rightsibling����ָ�룬�����ڷ���NULL
 * ���ܣ���rightsibling
 */
BiTree RightSibling(BiTree t, char *key)
{
    if(!strcmp(t->key, key))
    {
        printf("���ڵ�\n");
        return NULL;
    }
    BiTree n = Parent(t, key);
    if(!strcmp(n->rchild->key, key))
        return NULL;
    else
        return n->rchild;
}

/**
 * ��������NewTree
 * ������ɭ�ֵ�ַ
 * ����ֵ���½��ɹ�����OK��ʧ�ܷ���ERROR
 * ���ܣ��½�һ����
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
 * ��������ChangeTree
 * ������ɭ�ֵ�ַ
 * ����ֵ����
 * ���ܣ��л���
 */
void ChangeTree(Mul_BiTree *forest)
{
    int e;
    Showforest(forest);
    printf("�л�����");
    setValue(&e);
    while(e <= 0 || e >forest->treenum)
    {
        printf("�Ƿ����룬�������룺");
        setValue(&e);
    }
    forest->loc = e;
    printf("���л�����%s", forest->Trees[forest->loc - 1]->key);
    
}

/**
 * ��������DeleteTree
 * ������ɭ�ֵ�ַ
 * ����ֵ����
 * ���ܣ�ɾ����
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
    printf("ɾ���ɹ�\n");
    if(forest->treenum)
    {
        printf("ѡ��Ҫ�������(�������)\n");
        ChangeTree(forest);
    }
    else
    {
        printf("û���������½�\n");
        if(InitBiTree(forest) == OK)
        {
            printf("�½��ɹ�\n");
            forest->treenum++;
        }
        else
            printf("�½�ʧ��\n");
    }
}

/**
 * ��������Showforest
 * ������ɭ�ֵ�ַ
 * ����ֵ����
 * ���ܣ���ӡɭ��
 */
void Showforest(Mul_BiTree *forest)
{
    printf("���ڴ�����%s\n", forest->Trees[forest->loc - 1]->key);
    for(int i = 0; i < forest->treenum; i++)
    {
        printf("��%d������%s\n", i + 1, forest->Trees[i]->key);
        if(!forest->Trees[i])
        {
            printf("������\n");
        }
        else
        {
            if(forest->Trees[i]->lchild)
            {
                showTree(forest->Trees[i]->lchild, 1);
            }
            else
            {
                printf("����\n");
            }
        }
    }
}

/**
 * ��������showTree
 * ������������ַ
 * ����ֵ����
 * ���ܣ���ӡһ����
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