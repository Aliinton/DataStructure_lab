#include "BiTree.h"
#include "BiTree.functions.h"
int main()
{
//储存现在正在处理的森林
    Mul_BiTree forest;
    BiTree t, n;
    Defination df;
    FILE *fp;
    char key[10];
    ValueType v;
    InitForest(&forest);
    int op = 1, runonce = 1, d, loc;
    status s;
    char ch;
    while(op)
    {
        system("cls");
        printf("\n\n");
        printf("               Menu for BiTree         \n");
        printf("------------------------------------------------------\n");
        printf("    1.InitBiTree            2.DestroyBiTree\n");
        printf("    3.CreateBiTree          4.ClearBiTree\n");
        printf("    5.BiTreeEmpty           6.BiTreeDepth\n");
        printf("    7.Root                  8.Value\n");
        printf("    9.Assign                10.Parent\n");
        printf("    11.LeftChild            12.RightChild\n");
        printf("    13.LeftSibling          14.RightSibling\n");
        printf("    15.InsertChild          16.DeleteChild\n");
        printf("    17.PreOrderTraverse     18.InOrderTraverse\n");
        printf("    19.PostOrderTraverse    20.LevelOrderTraverse\n");
        printf("    21.Showforest           22.ChangeTree\n");
        printf("    23.NewTree              24.DeleteTree\n");
        printf("    25.SaveTree             26.LoadTree\n");
        printf("    0.exit\n");
        printf("------------------------------------------------------\n");
        printf("    输入执行项[0~25]:");
        while(!scanf("%d", &op))
        {
            printf("输入数据不合法\n");
            while ((ch = getchar()) != EOF && ch != '\n');
        }
        while ((ch = getchar()) != EOF && ch != '\n');
        if(runonce)
        {
            if(op == 1)
                runonce = 0;
            else
            {
                printf("请先创建树然后进行操作\n");
                getchar();
                continue;
            }
        }
        switch(op){
        case 1:
            printf("\n----InitBiTree\n");
            s = InitBiTree(&forest);
            if(s == OK)
                printf("树%s初始化成功\n", forest.Trees[forest.loc - 1]->key);
            else
                printf("树%s创建失败\n", forest.Trees[forest.loc - 1]->key);
            getchar();
            break;
        case 2:
            printf("\n----DestroyBiTree\n");
            DestroyBiTree(&forest);
            getchar();
            break;
        case 3:
            printf("----CreateBiTree\n");
            t = isDestory(&forest);
            if(t)
            {
                df = setdefination();
                if(judge(&df))
                {
                    loc = 0;
                    CreateBiTree(&t, df.df, &loc, df.n);
                    if(loc == df.n)
                    {
                        forest.Trees[forest.loc - 1]->lchild = t;
                        printf("树%s创建成功\n", forest.Trees[forest.loc - 1]->key);
                    }
                    else
                        printf("树%s创建失败\n", forest.Trees[forest.loc - 1]->key);
                }
                else
                {
                    printf("树%s创建失败\n", forest.Trees[forest.loc - 1]->key);
                }
            }
            else{
                printf("树已被销毁，操作失败\n");
            }
            getchar();
            break;
        case 4:
            printf("----ClearBiTree\n");
            s = ClearBiTree(&forest);
            if(s == OK)
                printf("树%s清空成功\n", forest.Trees[forest.loc - 1]->key);
            else
                printf("树%s清空失败\n", forest.Trees[forest.loc - 1]->key);
            getchar();
            break;
        case 5:
            printf("----BiTreeEmpty\n");
            s = BiTreeEmpty(&forest);
            if(s == TRUE)
                printf("树%s为空\n", forest.Trees[forest.loc - 1]->key);
            else if(s == FALSE)
                printf("树%s不为空\n", forest.Trees[forest.loc - 1]->key);
            else
                printf("操作失败\n");
            getchar();
            break;
        case 6:
            printf("----BiTreeDepth\n");
            t = isDestory(&forest);
            if(t)
            {
                d = BiTreeDepth(t->lchild);
                if(s == TRUE)
                    printf("树%s深度为%d\n", forest.Trees[forest.loc - 1]->key, d);
                else
                    printf("树%s深度为%d\n", forest.Trees[forest.loc - 1]->key, d);
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 7:
            printf("----Root\n");
            t = isDestory(&forest);
            if(t)
            {
                t = Root(t);
                if(t)
                {
                    printf("根节点为:\n");
                    getBiTNode(t);
                }
                else
                {
                    printf("空树\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 8:
            printf("----Value\n");
            t = isDestory(&forest);
            if(t)
            {
                if(t->lchild)
                {
                    printf("输入key：");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = Value(t->lchild, key);
                    if(t)
                        getValue(t->value);
                    else
                        printf("待查找节点不存在\n");
                }
                else
                {
                    printf("空树\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 9:
            printf("----Assign\n");
            t = isDestory(&forest);
            if(t)
            {
                if(t->lchild)
                {
                    printf("输入key：");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    printf("输入value：");
                    setValue(&v);
                    s = Assign(t->lchild, key, v);
                    if(s == OK)
                        printf("赋值成功\n");
                    else
                        printf("未找到对应key\n");
                }
                else
                {
                    printf("空树\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 10:
            printf("----Parent\n");
            t = isDestory(&forest);
            if(t)
            {
                if(t->lchild)
                {
                    printf("输入key：");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = Parent(t->lchild, key);
                    if(t)
                        getBiTNode(t);
                    else
                        printf("待查找父节点不存在\n");
                }
                else
                {
                    printf("空树\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 11:
            printf("----LeftChild\n");
            t = isDestory(&forest);
            if(t)
            {
                if(t->lchild)
                {
                    printf("输入key：");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = LeftChild(t->lchild, key);
                    if(t)
                        getBiTNode(t);
                    else
                        printf("待查找节点不存在\n");
                }
                else
                {
                    printf("空树\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 12:
            printf("----RightChild\n");
            t = isDestory(&forest);
            if(t)
            {
                if(t->lchild)
                {
                    printf("输入key：");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = RightChild(t->lchild, key);
                    if(t)
                        getBiTNode(t);
                    else
                        printf("待查找节点不存在\n");
                }
                else
                {
                    printf("空树\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 13:
            printf("----LeftSibling\n");
            t = isDestory(&forest);
            if(t)
            {
                if(t->lchild)
                {
                    printf("输入key：");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = LeftSibling(t->lchild, key);
                    if(t)
                        getBiTNode(t);
                    else
                        printf("待查找节点不存在\n");
                }
                else
                {
                    printf("空树\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 14:
            printf("----RightSibling\n");
            t = isDestory(&forest);
            if(t)
            {
                if(t->lchild)
                {
                    printf("输入key：");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = RightSibling(t->lchild, key);
                    if(t)
                        getBiTNode(t);
                    else
                        printf("待查找节点不存在\n");
                }
                else
                {
                    printf("空树\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;
        case 15:
            printf("----InsertChild\n");
            t = isDestory(&forest);
            if(t)
            {
                if(t->lchild)
                {
                    printf("创建待插入子树，右子树需为空\n");
                    df = setdefination();
                    if(judge(&df))
                    {
                        loc = 0;
                        CreateBiTree(&n, df.df, &loc, df.n);
                        if(loc != df.n)
                        {
                            printf("子树创建失败\n");
                        }
                        else if(n->rchild != NULL)
                        {
                            printf("右子树必须为空\n");
                        }
                        else if(judge2(n, t->lchild))
                        {
                            printf("存在关键字冲突，操作非法\n");
                        }
                        else
                        {
                            printf("子树创建成功\n");
                            printf("输入key：");
                            scanf("%s", key);
                            while ((ch = getchar()) != EOF && ch != '\n');
                            printf("插入到左子树输入0，右子树输入1\n");
                            scanf("%d", &d);
                            while(d != 1 && d!= 0)
                            {
                                printf("非法输入，重新输入：");
                                scanf("%d", &d);
                            }
                            while ((ch = getchar()) != EOF && ch != '\n');
                            s = InsertChild(t->lchild, key, d, n);
                            if(s == OK)
                            {
                                printf("插入成功\n");
                            }
                            else
                            {
                                printf("插入失败\n");
                            }
                        }
                    }
                    else
                    {
                        printf("子树创建失败\n");
                    }
                }
                else
                {
                    printf("空树\n");
                }
            }
            else
            {
                printf("树已被销毁，操作失败\n");
            }
            getchar();
            break;
        case 16:
            printf("----DeleteChild\n");
            t = isDestory(&forest);
            if(t)
            {
                if(t->lchild)
                {
                    printf("输入key：");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    printf("删除左子树输入0，右子树输入1\n");
                    scanf("%d", &d);
                    while(d != 1 && d!= 0)
                    {
                        printf("非法输入，重新输入：");
                        scanf("%d", &d);
                    }
                    s = DeleteChild(t->lchild, key, d);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    if(s == OK)
                        printf("删除成功\n");
                    else
                        printf("删除失败\n");
                }
                else
                {
                    printf("空树\n");
                }
            }
            else
            {
                printf("操作失败\n");
            }
            getchar();
            break;    
        case 17:
            printf("----PreOrderTraverse\n");
            t = isDestory(&forest);
            if(t)
            {
                t = t->lchild;
                if(t)
                    PreOrderTraverse(t);
                else
                    printf("空树\n");
            }
            getchar();
            break;
        case 18:
            printf("----InOrderTraverse\n");
            t = isDestory(&forest);
            if(t)
            {
                t = t->lchild;
                if(t)
                    InOrderTraverse(t);
                else
                    printf("空树\n");
            }
            getchar();
            break;
        case 19:
            printf("----PostOrderTraverse\n");
            t = isDestory(&forest);
            if(t)
            {
                t = t->lchild;
                if(t)
                    PostOrderTraverse(t);
                else
                    printf("空树\n");
            }
            getchar();
            break;
        case 20:
            printf("----LevelOrderTraverse\n");
            t = isDestory(&forest);
            if(t)
            {
                if(t->lchild)
                {
                    LevelOrderTraverse(t->lchild);
                }
                else
                {
                    printf("空树\n");
                }
            }
            getchar();
            break;
        case 21:
            printf("----Showforest\n");
            Showforest(&forest);
            getchar();
            break;
        case 22:
            printf("----ChangeTree\n");
            ChangeTree(&forest);
            getchar();
            break;
        case 23:
            printf("----NewTree\n");
            s = NewTree(&forest);
            if(s == OK)
            {
                printf("新建成功\n");
            }
            else
            {
                printf("新建失败\n");
            }
            getchar();
            break;
        case 24:
            printf("---DeleteTree\n");
            DeleteTree(&forest);
            getchar();
            break;
        case 25:
            printf("----SaveTree\n");
            char filename[] = {"./"}, name[30];
            printf("输入文件名\n");
            gets(name);
            strcat(filename, name);
            fp = fopen(filename, "wb");
            if(fp)
            {
                t = isDestory(&forest);
                if(t)
                {
                    SaveTree(fp, t->lchild);
                    printf("树%s已储存\n", t->key);
                }
                else
                {
                    printf("操作失败\n");
                }
            }
            else
            {
                perror("fopen");
                printf("文件创建失败\n");
            }
            fclose(fp);
            getchar();
            break;
        case 26:
            printf("----LoadTree\n");
            char filename1[] = {"./"}, name1[30];
            printf("输入文件名\n");
            gets(name1);
            strcat(filename1, name1);
            fp = fopen(filename1, "rb");
            if(fp)
            {
                t = isDestory(&forest);
                if(t)
                {
                    clear(&(t->lchild));
                    LoadTree(fp, &(t->lchild));
                    printf("文件内容已成功加载到树%s\n", t->key);
                }
                else
                {
                    printf("操作失败\n");
                }
            }
            else
            {
                perror("fopen");
                printf("文件读取失败\n");
            }
            fclose(fp);
            getchar();
            break;
        case 0:
            printf("欢迎下次使用本系统\n");
            getchar();
            break;
        default:
            printf("非法输入\n");
        }
    }
}