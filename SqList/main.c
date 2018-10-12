#ifndef _main_H_
#define _main_H_
#include "function.h"
#include "document_handling.h"
#endif

int main(){
    Mul_SqList L;
//k�����������ڴ�������Ա�����
    int op = 1, k = 0;
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
        printf("    	  6. ShowAllLists     16.ListEmpty\n");
        printf("    	  7. ChangeList       17. ListLength\n");
        printf("    	  8. GetElem          18. Go to document handling system\n");
        printf("          9. LocateElem\n");
        printf("          10. PriorElem\n");
        printf("    	  0. Exit\n");
        printf("-------------------------------------------------\n");
        printf("    ����ִ����[0~16]:");
        do
        {
            scanf("%d",&op);   
            if(op < 0 || op > 16)
                printf("δ���ҵ���Ӧִ����������룺");
            else
                break;
        }
        while(1);
        switch(op){
        case 1:
            printf("\n----IntiaLists\n");
            k = 1;
            if(InitialLists(&L) == OK)
                printf("�������Ա����гɹ���\n");
            else 
                printf("�������Ա�����ʧ�ܣ�\n");
            getchar();getchar();
            break;
        case 2:
            printf("\n----DeleteList\n");
            if(DeleteList(&L, k - 1) == OK)
                printf("ɾ�����Ա�ɹ���\n");
            else
                printf("ɾ�����Ա�ʧ�ܣ�\n");
            if(L.List_Num)
            {
                printf("��ǰ���Ա��Ѳ����ã����л�����һ���Ա�\n");
                ChangeList(L, &k);
            }
            else
            {
                printf("û�����Ա����½���\n");
                if(NewList(&L) == OK)
                    printf("�½��ɹ���\n");
                else
                    printf("�½�ʧ�ܣ�\n");
            }
            getchar();getchar();
            break;
        case 3:
            printf("\n----InitialList\n");
            if(InitialList(&L.Lists[k - 1]) == OK)
            {
                printf("��ʼ�����Ա�ɹ���\n");
            }
            else
            {
                printf("��ʼ�����Ա�ʧ�ܣ�\n");
            }
        case 4:
            printf("\n----DestroyList\n");
            if(DestroyList())
        case 5:
            printf("\n----NewList\n");
            char ch;
            if(NewList(&L) == OK)
            {
                printf("�ɹ�����һ���µ����Ա��Ƿ��л�������µ����Ա�?\nY(YES) N(no)\n");
                getchar();
                ch = getchar();
                if(ch == 'Y')
                {
                    k = L.List_Num;
                    printf("���л������Ա�%s\n", L.Lists[k - 1].ListName);
                }
            }
            else
            {
                printf("�����µ����Ա�ʧ�ܣ�\n");
            }
            getchar();getchar();
            break;
        case 6:
            printf("\n----ShowAllLists\n");
            int i14;
            printf("����%d�����Ա�\n�������ڴ����%d�����Ա�(%s)\n", L.List_Num, k, L.Lists[k - 1].ListName);
            ShowAllLists(L);
            getchar();getchar();
            break;
        case 7:
            printf("\n----ChangeList\n");
            ChangeList(L, &k);
            getchar();getchar();
            break;
        case 8:
            printf("\n----GetElem\n");
            int i6;
            ElemType e6;
            printf("����λ��\n");
            scanf("%d", &i6);
            if(GetElem(L.Lists[k - 1], i6, &e6) == OK)
            {
                printf("��%d��Ԫ��Ϊ:\n", i6);
                print(e6);
            }
            else
            {
                printf("��%d��Ԫ�ز�����\n", i6);
            }
            getchar();getchar();
            break;
        case 9:
            printf("\n----LocateElem\n");
            ElemType e7;
            int loc, f;
            status (*fun[10]) (ElemType, ElemType);
            fun[0] = &samevalue;
            printf("����Ԫ��\n");
            input(&e7);
            printf("      Menu for compare function\n");
            printf("-------------------------------------------------\n");
            printf("          1.same value\n");
            printf("-------------------------------------------------\n");
            printf("    chose your opiton:");
            printf("ѡ�����ڱȽϵĺ���\n");
            do
            {
                scanf("%d", &f);
                if(f < 0 || f > 1)
                    printf("��Ӧ���������ڣ��������룺\n");
                else
                    break;
            }
            while(1);
            loc = LocateElem(L.Lists[k - 1], e7, fun[f - 1]);
            if(loc)
                printf("�����ϵ��Ԫ��λ��Ϊ%d!\n", loc);
            else
                printf("δ���ҵ������ϵ��Ԫ�أ�\n");
            getchar();getchar();
            break;
        case 10:
            printf("\n----PriorElem\n");
            ElemType cur8, pre;
            printf("����Ԫ��\n");
            input(&cur8);
            if(PriorElem(L.Lists[k - 1], cur8, &pre) == OK)
            {
                printf("ǰ��Ԫ�ش��ڣ����£�\n");
                print(pre);
            }
            else
                printf("ǰ��Ԫ�ز����ڣ���\n");
            getchar();getchar();
            break;
        case 11:
            printf("\n----NextElem\n");
            ElemType cur9, next;
            printf("����Ԫ��\n");
            input(&cur9);
            if(NextElem(L.Lists[k - 1], cur9, &next) == OK)
            {
                printf("���Ԫ�ش��ڣ����£�\n");
                print(next);
            }
            else
                printf("���Ԫ�ز����ڣ���\n");
            getchar();getchar();
            break;
        case 12:
            printf("\n----ListInsert!\n");
            int i10;
            ElemType e10;
            printf("����λ��\n");
            scanf("%d", &i10);
            printf("����Ԫ��\n");
            input(&e10);
            if(ListInsert(&L.Lists[k - 1], i10, e10) == OK)
                printf("����ɹ���\n");
            else
                printf("����ʧ�ܣ�\n");
            getchar();getchar();
            break;
        case 14:
            printf("\n----ListDelete\n");
            int i11;
            ElemType e11;
            printf("����λ��\n");
            scanf("%d", &i11);
            if(ListDelete(&L.Lists[k - 1], i11, &e11) == OK)
            {
                printf("ɾ��Ԫ�أ�\n");
                print(e11);
                printf("ɾ���ɹ���\n");
            }
            else
                printf("ɾ��ʧ�ܣ�\n");
            getchar();getchar();
            break;
        case 13:
            printf("\n----ListTrabverse!\n");
            if(!ListTraverse(L.Lists[k - 1], &getvalue))
            printf("����ʧ�ܣ���Ϊ�ձ�\n");
            getchar();getchar();
            break;
        case 14:
            printf("\n----ClearList\n");
            if(ClearList(&L.Lists[k - 1]) == OK)
                printf("�ɹ�������Ա�\n");
            else
                printf("���ʧ�ܣ�\n");
            getchar();getchar();
            break;
        case 15:
            printf("\n----ListEmpty\n");
            if(ListEmpty(L.Lists[k - 1]))
                printf("���Ա�Ϊ�գ�\n");
            else
                printf("���Ա�ǿգ�\n");
            getchar();getchar();
            break;
        case 16:
            printf("\n----ListLength\n");
            printf("���Ա���Ϊ%d��\n", ListLength(L.Lists[k - 1]));
            getchar();getchar();
            break;
        case 17:
            document_handling_system(L);
            getchar();getchar();
            break;
        case 0:
            break;
        }
    }
    printf("��ӭ�´�ʹ�ñ�ϵͳ\n");
    system("pause");
    return 0;
}
