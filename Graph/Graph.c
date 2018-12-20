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
        printf("������Ĳ�����");
        while(!scanf("%d", &op))
        {
            printf("�������ݲ��Ϸ�\n");
            while ((ch = getchar()) != EOF && ch != '\n');
        }
        while ((ch = getchar()) != EOF && ch != '\n');
        if(runonce)
        {
            if(op != 1)
            {
                printf("���Ƚ���һ��ͼ�ٽ��к�������\n");
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
            printf("�����ɹ�\n");
            getchar();
            break;
        case 2:
            printf("----DestroyGraph\n");
            g = isDestroy(&G);
            if(g)
            {
               destroyGraph(&(G.graphs[G.loc - 1]));
               printf("���ٳɹ�\n");
            }
            else
            {
                printf("ͼ�����٣�����ʧ��\n");
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
                printf("ͼ�����٣�����ʧ��\n");
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
                    printf("value��");
                    getValue(vp->value);
                }
                else
                {
                    printf("û�иö���\n");
                }
            }
            else
            {
                printf("ͼ�����٣�����ʧ��\n");
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
                    printf("��ֵ�ɹ�\n");
                }
                else
                {
                    printf("��ֵʧ��\n");
                }
            }
            else
            {
                printf("ͼ�����٣�����ʧ��\n");
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
                    printf("û�����ڶ���\n");
                }
            }
            else
            {
                printf("ͼ�����٣�����ʧ��\n");
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
                    printf("û����һ�����ڶ���\n");
                }
            }
            else
            {
                printf("ͼ�����٣�����ʧ��\n");
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
                    printf("����ɹ�\n");
                }
                else
                {
                    printf("����ʧ��\n");
                }
            }
            else
            {
                printf("ͼ�����٣�����ʧ��\n");
            }
            getchar();
            break;
        case 9:
            printf("----DeleteVex\n");
            g = isDestroy(&G);
            if(g)
            {
                printf("�����ɾ���ڵ�\n");
                scanf("%s", key1);
                getchar();
                if(deleteVex(g, key1) == OK)
                {
                    printf("ɾ���ɹ�\n");
                }
                else
                {
                    printf("ɾ��ʧ��\n");
                }
            }
            else
            {
                printf("ͼ�����٣�����ʧ��\n");
            }
            getchar();
            break;
        case 10:
            printf("----InsertArc\n");
            g = isDestroy(&G);
            if(g)
            {
                printf("����ߣ�\n");
                scanf("%s", key1);
                scanf("%s", key2);
                while ((ch = getchar()) != EOF && ch != '\n');
                if(insertArc(g, key1, key2) == OK)
                {
                    printf("��%s��>%s����ɹ�\n", key1, key2);
                }
                else
                {
                    printf("��%s��>%s����ʧ��\n", key1, key2);
                }
            }
            else
            {
                printf("ͼ�����٣�����ʧ��\n");
            }
            getchar();
            break;
        case 11:
            printf("----DeleteArc\n");
            g = isDestroy(&G);
            if(g)
            {
                printf("����ߣ�\n");
                scanf("%s", key1);
                scanf("%s", key2);
                while ((ch = getchar()) != EOF && ch != '\n');
                if(deleteArc(g, key1, key2) == OK)
                {
                    printf("��%s��>%sɾ���ɹ�\n", key1, key2);
                }
                else
                {
                    printf("��%s��>%sɾ��ʧ��\n", key1, key2);
                }
                
            }
            else
            {
                printf("ͼ�����٣�����ʧ��\n");
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
                printf("ͼ�����٣�����ʧ��\n");
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
                printf("ͼ�����٣�����ʧ��\n");
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
                printf("��ʼ���ɹ�\n");
            }
            else
            {
                printf("ͼ�����٣�����ʧ��\n");
            }
            getchar();
            break;
        case 15:
            printf("----NewGraph\n");
            if(newGraph(&G) == OK)
            {
                printf("�½��ɹ�\n");
            }
            else
                printf("�½�ʧ��\n");
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
            printf("��ӭ�´�ʹ��\n");
            getchar();
        default:
            printf("�Ƿ����룬���������룺");
        }
        
    }
}