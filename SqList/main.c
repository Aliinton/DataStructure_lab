#ifndef _main_H_
#define _main_H_
#include "function.h"
#include "document_handling.h"
#endif

int main(){
    Mul_SqList L;
//k代表现在正在处理的线性表的序号
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
        printf("    输入执行项[0~16]:");
        do
        {
            scanf("%d",&op);   
            if(op < 0 || op > 16)
                printf("未能找到相应执行项，重新输入：");
            else
                break;
        }
        while(1);
        switch(op){
        case 1:
            printf("\n----IntiaLists\n");
            k = 1;
            if(InitialLists(&L) == OK)
                printf("创建线性表序列成功！\n");
            else 
                printf("创建线性表序列失败！\n");
            getchar();getchar();
            break;
        case 2:
            printf("\n----DeleteList\n");
            if(DeleteList(&L, k - 1) == OK)
                printf("删除线性表成功！\n");
            else
                printf("删除线性表失败！\n");
            if(L.List_Num)
            {
                printf("当前线性表已不可用，请切换到另一线性表\n");
                ChangeList(L, &k);
            }
            else
            {
                printf("没有线性表，请新建：\n");
                if(NewList(&L) == OK)
                    printf("新建成功！\n");
                else
                    printf("新建失败！\n");
            }
            getchar();getchar();
            break;
        case 3:
            printf("\n----InitialList\n");
            if(InitialList(&L.Lists[k - 1]) == OK)
            {
                printf("初始化线性表成功！\n");
            }
            else
            {
                printf("初始化线性表失败！\n");
            }
        case 4:
            printf("\n----DestroyList\n");
            if(DestroyList())
        case 5:
            printf("\n----NewList\n");
            char ch;
            if(NewList(&L) == OK)
            {
                printf("成功创建一个新的线性表，是否切换到这个新的线性表?\nY(YES) N(no)\n");
                getchar();
                ch = getchar();
                if(ch == 'Y')
                {
                    k = L.List_Num;
                    printf("已切换到线性表%s\n", L.Lists[k - 1].ListName);
                }
            }
            else
            {
                printf("创建新的线性表失败！\n");
            }
            getchar();getchar();
            break;
        case 6:
            printf("\n----ShowAllLists\n");
            int i14;
            printf("共有%d个线性表\n现在正在处理第%d个线性表(%s)\n", L.List_Num, k, L.Lists[k - 1].ListName);
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
            printf("输入位置\n");
            scanf("%d", &i6);
            if(GetElem(L.Lists[k - 1], i6, &e6) == OK)
            {
                printf("第%d个元素为:\n", i6);
                print(e6);
            }
            else
            {
                printf("第%d个元素不存在\n", i6);
            }
            getchar();getchar();
            break;
        case 9:
            printf("\n----LocateElem\n");
            ElemType e7;
            int loc, f;
            status (*fun[10]) (ElemType, ElemType);
            fun[0] = &samevalue;
            printf("输入元素\n");
            input(&e7);
            printf("      Menu for compare function\n");
            printf("-------------------------------------------------\n");
            printf("          1.same value\n");
            printf("-------------------------------------------------\n");
            printf("    chose your opiton:");
            printf("选择用于比较的函数\n");
            do
            {
                scanf("%d", &f);
                if(f < 0 || f > 1)
                    printf("对应函数不存在，重新输入：\n");
                else
                    break;
            }
            while(1);
            loc = LocateElem(L.Lists[k - 1], e7, fun[f - 1]);
            if(loc)
                printf("满足关系的元素位置为%d!\n", loc);
            else
                printf("未能找到满足关系的元素！\n");
            getchar();getchar();
            break;
        case 10:
            printf("\n----PriorElem\n");
            ElemType cur8, pre;
            printf("输入元素\n");
            input(&cur8);
            if(PriorElem(L.Lists[k - 1], cur8, &pre) == OK)
            {
                printf("前驱元素存在！如下：\n");
                print(pre);
            }
            else
                printf("前驱元素不存在！¨\n");
            getchar();getchar();
            break;
        case 11:
            printf("\n----NextElem\n");
            ElemType cur9, next;
            printf("输入元素\n");
            input(&cur9);
            if(NextElem(L.Lists[k - 1], cur9, &next) == OK)
            {
                printf("后继元素存在！如下：\n");
                print(next);
            }
            else
                printf("后继元素不存在！¨\n");
            getchar();getchar();
            break;
        case 12:
            printf("\n----ListInsert!\n");
            int i10;
            ElemType e10;
            printf("输入位置\n");
            scanf("%d", &i10);
            printf("输入元素\n");
            input(&e10);
            if(ListInsert(&L.Lists[k - 1], i10, e10) == OK)
                printf("插入成功！\n");
            else
                printf("插入失败！\n");
            getchar();getchar();
            break;
        case 14:
            printf("\n----ListDelete\n");
            int i11;
            ElemType e11;
            printf("输入位置\n");
            scanf("%d", &i11);
            if(ListDelete(&L.Lists[k - 1], i11, &e11) == OK)
            {
                printf("删除元素：\n");
                print(e11);
                printf("删除成功！\n");
            }
            else
                printf("删除失败！\n");
            getchar();getchar();
            break;
        case 13:
            printf("\n----ListTrabverse!\n");
            if(!ListTraverse(L.Lists[k - 1], &getvalue))
            printf("遍历失败，或为空表\n");
            getchar();getchar();
            break;
        case 14:
            printf("\n----ClearList\n");
            if(ClearList(&L.Lists[k - 1]) == OK)
                printf("成功清空线性表！\n");
            else
                printf("清空失败！\n");
            getchar();getchar();
            break;
        case 15:
            printf("\n----ListEmpty\n");
            if(ListEmpty(L.Lists[k - 1]))
                printf("线性表为空！\n");
            else
                printf("线性表非空！\n");
            getchar();getchar();
            break;
        case 16:
            printf("\n----ListLength\n");
            printf("线性表长度为%d！\n", ListLength(L.Lists[k - 1]));
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
    printf("欢迎下次使用本系统\n");
    system("pause");
    return 0;
}
