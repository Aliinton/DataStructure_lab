#include "LinkedList.h"
#include "functions.h"

int main()
{
    Mul_List L;
    int i, op = 1, runonce = 1;
    ElemType t, e;
    status s;
    char ch;
    while(op)
    {
        system("cls");	printf("\n\n");
        printf("      Menu for Linear Table On Sequence Structure \n");
        printf("-------------------------------------------------\n");
        printf("    	  1. InitialLists     11. NextElem\n");
        printf("    	  2. DeleteList       12. ListInsert\n"); 
        printf("          3. InitilalList     13. ListDelete\n");
        printf("          4. DestroyList      14. ListTrabverse\n");
        printf("    	  5. NewList          15. ClearList\n");
        printf("    	  6. ShowAllLists     16. ListEmpty\n");
        printf("    	  7. ChangeList       17. ListLength\n");
        printf("    	  8. GetElem          18. SaveFiles\n");
        printf("          9. LocateElem       19. LoadFiles\n");
        printf("          10. PriorElem       20. DeleteFiles\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    ����ִ����[0~20]:");
        while(!scanf("%d", &op))
        {
            printf("�������ݲ��Ϸ�\n");
            while ((ch = getchar()) != EOF && ch != '\n');
        }
        while ((ch = getchar()) != EOF && ch != '\n');
//ȷ���û�ֻ�����ڴ��������Ա��������¼�������
        if(runonce)
        { 
            if(op == 1 || op == 19)
            {
                runonce = 0;
            }
            else
            {
                printf("�״ν���ϵͳ��Ҫ����򴴽�һ�����Ա�������޷����к�������\n");
                getchar();
                continue;
            }
        }
        switch(op){
        case 1:
            printf("\n----IntiaLists\n");
            if(InitialLists(&L) == OK)
                printf("�������Ա����гɹ���\n");
            else 
                printf("�������Ա�����ʧ�ܣ�\n");
            getchar();
            break;
        case 2:
            printf("\n----DeleteList\n");
            DeleteList(&L, L.k);
            getchar();
            break;
        case 3:
            printf("----InitilaList\n");
            InitialList2(&L, L.k);
            getchar();
            break;
        case 4:
            printf("----DestroyList\n");
            DestoryList(&L, L.k);
            getchar();
            break;
        case 5:
            printf("----NewList\n");
            NewList(&L);
            getchar();
            break;
        case 6:
            printf("----ShowAllLists\n");
            printf("���ڹ���%d����������������, �������ڴ�������%d\n", L.num, L.k + 1);
            ShowAllLists(L);
            getchar();
            break;
        case 7:
            printf("----ChangeList\n");
            printf("�������ڴ�������%d\n", L.k + 1);
            ChangeList(&L);
            getchar();
            break;
        case 8:
            printf("----GetElem\n");
            while(!scanf("%d", &i))
            {
                printf("�Ƿ����룬��������\n");
            }
            while ((ch = getchar()) != EOF && ch != '\n');
            s = GetElem(&L, i, &e);
            if(s == OK)
            {
                printf("λ��%d�ϵ�Ԫ��Ϊ��", i);
                print(e);
            }
            else if(s == INFEASIBLE)
            {
                printf("���Ա��ѱ����٣�����ʧ��\n");
            }
            else
                printf("�Ƿ�����\n");
            getchar();
            break;
        case 9:
            printf("----LocateElem\n");
            printf("���������Ԫ��\n");
            scan(&e);
            i = LocateElem(&L, e, &SameValue);
            if(i)
                printf("������Ԫ��λ��Ϊ%d\n", i);
            else
                printf("������Ԫ�ز�����\n");
            getchar();
            break;
        case 10:
            printf("----PriorElem\n");
            printf("����Ԫ��\n");
            scan(&t);
            s = PriorElem(&L, t, &e);
            if(s == INFEASIBLE)
                printf("���ǵ�һ��Ԫ�أ���ǰ���ڵ�\n");
            else if(s == ERROR)
                printf("�����в��������Ԫ��\n");
            else
            {
                printf("ǰ��Ԫ��Ϊ:\n");
                print(e);
            }
            getchar();
            break;
        case 11:
            printf("----NextElem\n");
            printf("����Ԫ��\n");
            scan(&t);
            s = NextElem(&L, t, &e);
            if(s == INFEASIBLE)
                printf("�������һ��Ԫ�أ��޺�̽ڵ�\n");
            else if(s == ERROR)
                printf("�����в��������Ԫ��\n");
            else
            {
                printf("��̽ڵ�Ϊ��\n");
                print(e);
            }
            getchar();
            break;
        case 12:
            printf("----ListInSert\n");
            printf("�������λ�ã�");
            while(!scanf("%d", &i))
            {
                printf("�Ƿ����룬��������\n");
            }
            while ((ch = getchar()) != EOF && ch != '\n');
            printf("�������Ԫ�أ�");
            scan(&e);
            if(ListInsert(&L, i, e) == OK)
            {
                printf("����ɹ�\n");
            }
            else
            {
                printf("����ʧ��\n");
            }
            getchar();
            break;
        case 13:
            printf("----ListDelete\n");
            printf("�����ɾ��Ԫ��λ��");
            while(!scanf("%d", &i))
            {
                printf("�Ƿ����룬��������\n");
            }
            while ((ch = getchar()) != EOF && ch != '\n');
            s = ListDelete(&L, i, &e);
            if(s == OK)
            {
                printf("�ѳɹ�ɾ��Ԫ�أ�");
                print(e);
            }
            else
            {
                printf("ɾ��ʧ��\n");
            }
            getchar();
            break;
        case 14:
            printf("----ListTraverse\n");
            ListTraverse(&L, &print);
            getchar();
            break;
        case 15:
            printf("----ClearList\n");
            s = ClearList(&L);
            if(s == OK)
                printf("��ճɹ�\n");
            else
                printf("���ʧ��\n");
            getchar();
            break;
        case 16:
            printf("----ListEmpty\n");
            s = ListEmpty(&L);
            if(s == TRUE)
                printf("�ñ�Ϊ��\n");
            else if(s == FALSE)
                printf("�ñ�ǿ�\n");
            getchar();
            break;
        case 17:
            printf("----ListLength\n");
            i = ListLength(&L);
            if(i != -1)
            {
                printf("��ǰ����������Ϊ��%d\n", i);
            }
            getchar();
            break;
        default:
            printf("������Ч�����������룺");
            getchar();
        }
    }
    printf("��ӭ�´�ʹ�ñ�ϵͳ\n");
    system("pause");
    return 0;
}