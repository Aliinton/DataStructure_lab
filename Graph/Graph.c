#include "Graph.h"
#include "Gfunctions.h"

int main()
{
    Graphs G;
    AdjGraph * g;
    VexType v, *vp;
    char key1[10], key2[10];
    int op = 1, runonce = 1;
    char ch;
    InitailGraphs(&G);
    while(op)
    {
        system("cls");
        printf("\n\n");
        printf("            Menu of Graph          \n");
        printf("-----------------------------------\n");
        printf("1.CreateGraph       2.DestroyGraph\n");
        printf("3.LocateVex         4.GetVex\n");
        printf("5.PutVex            6.FirstAdjVex\n");
        printf("7.NextAdjVex        8.InsertVex\n");
        printf("9.DeleteVex         10.InsertArc\n");
        printf("11.DeleteArc        12.DFSTraverse\n");
        printf("13.BFSTraverse      14.InitialGraph\n");
        printf("15.NewGraph         16.DeleteGraph\n");
        printf("17.ChangeGraph      18.ShowAllGraph\n");
        printf("0.exit\n");
        printf("-----------------------------------\n");
        printf("输入你的操作：");
        while(!scanf("%d", &op))
        {
            printf("输入数据不合法\n");
            while ((ch = getchar()) != EOF && ch != '\n');
        }
        while ((ch = getchar()) != EOF && ch != '\n');
        if(runonce)
        {
            if(op != 1)
            {
                printf("请先建立一个图再进行后续操作\n");
                getchar();
                continue;
            }
            else
            {
                runonce = 0;
            }
        }
        switch(op){
        case 1:
            printf("----CreateGraph\n");
            g = isDestroy(&G);
            if(g)
            {
                destroyGraph(&(G.graphs[G.loc - 1]));
                initailGraph(&G);
                createGraph(g);
            }
            else
            {
                initailGraph(&G);
                createGraph(G.graphs[G.loc - 1]);
            }
            while ((ch = getchar()) != EOF && ch != '\n');
            printf("创建成功\n");
            getchar();
            break;
        case 2:
            printf("----DestroyGraph\n");
            g = isDestroy(&G);
            if(g)
            {
               destroyGraph(&(G.graphs[G.loc - 1]));
               printf("销毁成功\n");
            }
            else
            {
                printf("图已销毁，操作失败\n");
            }
            getchar();
            break;
        case 3:
            printf("----LocateVex\n");
            g = isDestroy(&G);
            if(g)
            {
                printf("key:");
                scanf("%s", key1);
                while ((ch = getchar()) != EOF && ch != '\n');
                LocateVex(g, key1);
            }
            else
            {
                printf("图已销毁，操作失败\n");
            }
            getchar();
            break;
        case 4:
            printf("----GetVex\n");
            g = isDestroy(&G);
            if(g)
            {
                printf("key:");
                scanf("%s", key1);
                while ((ch = getchar()) != EOF && ch != '\n');
                vp = getVex1(g, key1);
                if(vp)
                {
                    printf("value：");
                    getValue(vp->value);
                }
                else
                {
                    printf("没有该顶点\n");
                }
            }
            else
            {
                printf("图已销毁，操作失败\n");
            }
            getchar();
            break;
        case 5:
            printf("----PutVex\n");
            g = isDestroy(&G);
            if(g)
            {
                printf("key:");
                scanf("%s", key1);
                while ((ch = getchar()) != EOF && ch != '\n');
                if(putVex(g, key1) == OK)
                {
                    printf("赋值成功\n");
                }
                else
                {
                    printf("赋值失败\n");
                }
            }
            else
            {
                printf("图已销毁，操作失败\n");
            }
            getchar();
            break;
        case 6:
            printf("----FirstAdjVex\n");
            g = isDestroy(&G);
            if(g)
            {
                printf("key:");
                scanf("%s", key1);
                while ((ch = getchar()) != EOF && ch != '\n');
                vp = firstAdjvex(g, key1);
                if(vp)
                {
                    getVex(*vp);
                }
                else
                {
                    printf("没有相邻顶点\n");
                }
            }
            else
            {
                printf("图以销毁，操作失败\n");
            }
            getchar();
            break;
        case 7:
            printf("----NextAdjVex\n");
            g = isDestroy(&G);
            if(g)
            {
                printf("vex key:");
                scanf("%s", key1);
                printf("adjvex key:");
                scanf("%s", key2);
                while ((ch = getchar()) != EOF && ch != '\n');
                vp = nextAdjvex(g, key1, key2);
                if(vp)
                {
                    getVex(*vp);
                }
                else
                {
                    printf("没有下一个相邻顶点\n");
                }
            }
            else
            {
                printf("图已销毁，操作失败\n");
            }
            getchar();
            break;
        case 8:
            printf("----InsertVex\n");
            g = isDestroy(&G);
            if(g)
            {
                setVex(&v);
                if(insertVex(g, v) == OK)
                {
                    printf("插入成功\n");
                }
                else
                {
                    printf("插入失败\n");
                }
            }
            else
            {
                printf("图以销毁，操作失败\n");
            }
            getchar();
            break;
        case 9:
            printf("----DeleteVex\n");
            g = isDestroy(&G);
            if(g)
            {
                printf("输入待删除节点\n");
                scanf("%s", key1);
                getchar();
                if(deleteVex(g, key1) == OK)
                {
                    printf("删除成功\n");
                }
                else
                {
                    printf("删除失败\n");
                }
            }
            else
            {
                printf("图已销毁，操作失败\n");
            }
            getchar();
            break;
        case 10:
            printf("----InsertArc\n");
            g = isDestroy(&G);
            if(g)
            {
                printf("输入边：\n");
                scanf("%s", key1);
                scanf("%s", key2);
                while ((ch = getchar()) != EOF && ch != '\n');
                if(insertArc(g, key1, key2) == OK)
                {
                    printf("边%s—>%s插入成功\n", key1, key2);
                }
                else
                {
                    printf("边%s—>%s插入失败\n", key1, key2);
                }
            }
            else
            {
                printf("图已销毁，操作失败\n");
            }
            getchar();
            break;
        case 11:
            printf("----DeleteArc\n");
            g = isDestroy(&G);
            if(g)
            {
                printf("输入边：\n");
                scanf("%s", key1);
                scanf("%s", key2);
                while ((ch = getchar()) != EOF && ch != '\n');
                if(deleteArc(g, key1, key2) == OK)
                {
                    printf("边%s—>%s删除成功\n", key1, key2);
                }
                else
                {
                    printf("边%s—>%s删除失败\n", key1, key2);
                }
                
            }
            else
            {
                printf("图已销毁，操作失败\n");
            }
            getchar();
            break;
        case 12:
            printf("----DFSTraversal\n");
            g = isDestroy(&G);
            if(g)
            {

            }
            else
            {
                printf("图已销毁，操作失败\n");
            }
            getchar();
            break;
        case 13:
            printf("----BFSTraversal\n");
            g = isDestroy(&G);
            if(g)
            {
                
            }
            else
            {
                printf("图已销毁，操作失败\n");
            }
            getchar();
            break;
        case 14:
            printf("InitialGraph\n");
            g = isDestroy(&G);
            if(g)
            {
                destroyGraph(&(G.graphs[G.loc - 1]));
                initailGraph(&G);
                printf("初始化成功\n");
            }
            else
            {
                printf("图已销毁，操作失败\n");
            }
            getchar();
            break;
        case 15:
            printf("----NewGraph\n");
            if(newGraph(&G) == OK)
            {
                printf("新建成功\n");
            }
            else
                printf("新建失败\n");
            getchar();
            break;
        case 16:
            printf("----DeleteGraph\n");
            deleteGraph(&G);
            getchar();
            break;
        case 17:
            printf("----ChangeGraph\n");
            changeGraph(&G);
            getchar();
            break;
        case 18:
            printf("----ShowAllGraph\n");
            printGraph(&G);
            getchar();
            break;
        case 0:
            printf("欢迎下次使用\n");
            getchar();
        default:
            printf("非法输入，请重新输入：");
        }
        
    }
}