#include "BiTree.h"
#include "BiTree.functions.h"
int main()
{
//�����������ڴ����ɭ��
    Mul_BiTree forest;
    BiTree t;
    Defination df;
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
        printf("    ����ִ����[0~25]:");
        while(!scanf("%d", &op))
        {
            printf("�������ݲ��Ϸ�\n");
            while ((ch = getchar()) != EOF && ch != '\n');
        }
        while ((ch = getchar()) != EOF && ch != '\n');
        if(runonce)
        {
            if(op == 1)
                runonce = 0;
            else
            {
                printf("���ȴ�����Ȼ����в���\n");
                getchar();
                continue;
            }
        }
        switch(op){
        case 1:
            printf("\n----InitBiTree\n");
            s = InitBiTree(&forest);
            if(s == OK)
                printf("��%s��ʼ���ɹ�\n", forest.Trees[forest.loc - 1]->key);
            else
                printf("��%s����ʧ��\n", forest.Trees[forest.loc - 1]->key);
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
                        printf("��%s�����ɹ�\n", forest.Trees[forest.loc - 1]->key);
                    }
                    else
                        printf("��%s����ʧ��\n", forest.Trees[forest.loc - 1]->key);
                }
                else
                {
                    printf("��%s����ʧ��\n", forest.Trees[forest.loc - 1]->key);
                }
            }
            else{
                printf("���ѱ����٣�����ʧ��\n");
            }
            getchar();
            break;
        case 4:
            printf("----ClearBiTree\n");
            s = ClearBiTree(&forest);
            if(s == OK)
                printf("��%s��ճɹ�\n", forest.Trees[forest.loc - 1]->key);
            else
                printf("��%s���ʧ��\n", forest.Trees[forest.loc - 1]->key);
            getchar();
            break;
        case 5:
            printf("----BiTreeEmpty\n");
            s = BiTreeEmpty(&forest);
            if(s == TRUE)
                printf("��%sΪ��\n", forest.Trees[forest.loc - 1]->key);
            else if(s == FALSE)
                printf("��%s��Ϊ��\n", forest.Trees[forest.loc - 1]->key);
            else
                printf("����ʧ��\n");
            getchar();
            break;
        case 6:
            printf("----BiTreeDepth\n");
            t = isDestory(&forest);
            if(t)
            {
                d = BiTreeDepth(t->lchild);
                if(s == TRUE)
                    printf("��%s���Ϊ%d\n", forest.Trees[forest.loc - 1]->key, d);
                else
                    printf("��%s���Ϊ%d\n", forest.Trees[forest.loc - 1]->key, d);
            }
            else
            {
                printf("����ʧ��\n");
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
                    printf("���ڵ�Ϊ:\n");
                    getBiTNode(t);
                }
                else
                {
                    printf("����\n");
                }
            }
            else
            {
                printf("����ʧ��\n");
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
                    printf("����key��");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = Value(t->lchild, key);
                    if(t)
                        getValue(t->value);
                    else
                        printf("�����ҽڵ㲻����\n");
                }
                else
                {
                    printf("����\n");
                }
            }
            else
            {
                printf("����ʧ��\n");
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
                    printf("����key��");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    printf("����value��");
                    setValue(&v);
                    s = Assign(t->lchild, key, v);
                    if(s == OK)
                        printf("��ֵ�ɹ�\n");
                    else
                        printf("δ�ҵ���Ӧkey\n");
                }
                else
                {
                    printf("����\n");
                }
            }
            else
            {
                printf("����ʧ��\n");
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
                    printf("����key��");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = Parent(t->lchild, key);
                    if(t)
                        getBiTNode(t);
                    else
                        printf("�����Ҹ��ڵ㲻����\n");
                }
                else
                {
                    printf("����\n");
                }
            }
            else
            {
                printf("����ʧ��\n");
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
                    printf("����key��");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = LeftChild(t->lchild, key);
                    if(t)
                        getBiTNode(t);
                    else
                        printf("�����ҽڵ㲻����\n");
                }
                else
                {
                    printf("����\n");
                }
            }
            else
            {
                printf("����ʧ��\n");
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
                    printf("����key��");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = RightChild(t->lchild, key);
                    if(t)
                        getBiTNode(t);
                    else
                        printf("�����ҽڵ㲻����\n");
                }
                else
                {
                    printf("����\n");
                }
            }
            else
            {
                printf("����ʧ��\n");
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
                    printf("����key��");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = LeftSibling(t->lchild, key);
                    if(t)
                        getBiTNode(t);
                    else
                        printf("�����ҽڵ㲻����\n");
                }
                else
                {
                    printf("����\n");
                }
            }
            else
            {
                printf("����ʧ��\n");
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
                    printf("����key��");
                    scanf("%s", key);
                    while ((ch = getchar()) != EOF && ch != '\n');
                    t = RightSibling(t->lchild, key);
                    if(t)
                        getBiTNode(t);
                    else
                        printf("�����ҽڵ㲻����\n");
                }
                else
                {
                    printf("����\n");
                }
            }
            else
            {
                printf("����ʧ��\n");
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
                    printf("����\n");
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
                    printf("����\n");
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
                    printf("����\n");
            }
            getchar();
            break;
        case 20:
            printf("----");
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
                printf("�½��ɹ�\n");
            }
            else
            {
                printf("�½�ʧ��\n");
            }
            getchar();
            break;
        case 24:
            printf("---DeleteTree\n");
            DeleteTree(&forest);
            getchar();
            break;
        case 25:
            printf("");
        case 0:
            printf("��ӭ�´�ʹ�ñ�ϵͳ\n");
            getchar();
            break;
        default:
            printf("�Ƿ�����\n");
        }
    }
}