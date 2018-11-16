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
        printf("    输入执行项[0~20]:");
        while(!scanf("%d", &op))
        {
            printf("输入数据不合法\n");
            while ((ch = getchar()) != EOF && ch != '\n');
        }
        while ((ch = getchar()) != EOF && ch != '\n');
//确保用户只能在内存中有线性表组的情况下继续操作
        if(runonce)
        { 
            if(op == 1 || op == 19)
            {
                runonce = 0;
            }
            else
            {
                printf("首次进入系统需要导入或创建一个线性表组否则无法进行后续操作\n");
                getchar();
                continue;
            }
        }
        switch(op){
        case 1:
            printf("\n----IntiaLists\n");
            if(InitialLists(&L) == OK)
                printf("创建线性表序列成功！\n");
            else 
                printf("创建线性表序列失败！\n");
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
            printf("现在共有%d个链表在链表组内, 现在正在处理链表%d\n", L.num, L.k + 1);
            ShowAllLists(L);
            getchar();
            break;
        case 7:
            printf("----ChangeList\n");
            printf("现在正在处理链表%d\n", L.k + 1);
            ChangeList(&L);
            getchar();
            break;
        case 8:
            printf("----GetElem\n");
            while(!scanf("%d", &i))
            {
                printf("非法输入，重新输入\n");
            }
            while ((ch = getchar()) != EOF && ch != '\n');
            s = GetElem(&L, i, &e);
            if(s == OK)
            {
                printf("位置%d上的元素为：", i);
                print(e);
            }
            else if(s == INFEASIBLE)
            {
                printf("线性表已被销毁，操作失败\n");
            }
            else
                printf("非法输入\n");
            getchar();
            break;
        case 9:
            printf("----LocateElem\n");
            printf("输入待查找元素\n");
            scan(&e);
            i = LocateElem(&L, e, &SameValue);
            if(i)
                printf("待查找元素位置为%d\n", i);
            else
                printf("待查找元素不存在\n");
            getchar();
            break;
        case 10:
            printf("----PriorElem\n");
            printf("输入元素\n");
            scan(&t);
            s = PriorElem(&L, t, &e);
            if(s == INFEASIBLE)
                printf("这是第一个元素，无前驱节点\n");
            else if(s == ERROR)
                printf("链表中不存在这个元素\n");
            else
            {
                printf("前驱元素为:\n");
                print(e);
            }
            getchar();
            break;
        case 11:
            printf("----NextElem\n");
            printf("输入元素\n");
            scan(&t);
            s = NextElem(&L, t, &e);
            if(s == INFEASIBLE)
                printf("这是最后一个元素，无后继节点\n");
            else if(s == ERROR)
                printf("链表中不存在这个元素\n");
            else
            {
                printf("后继节点为：\n");
                print(e);
            }
            getchar();
            break;
        case 12:
            printf("----ListInSert\n");
            printf("输入插入位置：");
            while(!scanf("%d", &i))
            {
                printf("非法输入，重新输入\n");
            }
            while ((ch = getchar()) != EOF && ch != '\n');
            printf("输入插入元素：");
            scan(&e);
            if(ListInsert(&L, i, e) == OK)
            {
                printf("插入成功\n");
            }
            else
            {
                printf("插入失败\n");
            }
            getchar();
            break;
        case 13:
            printf("----ListDelete\n");
            printf("输入待删除元素位序：");
            while(!scanf("%d", &i))
            {
                printf("非法输入，重新输入\n");
            }
            while ((ch = getchar()) != EOF && ch != '\n');
            s = ListDelete(&L, i, &e);
            if(s == OK)
            {
                printf("已成功删除元素：");
                print(e);
            }
            else
            {
                printf("删除失败\n");
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
                printf("清空成功\n");
            else
                printf("清空失败\n");
            getchar();
            break;
        case 16:
            printf("----ListEmpty\n");
            s = ListEmpty(&L);
            if(s == TRUE)
                printf("该表为空\n");
            else if(s == FALSE)
                printf("该表非空\n");
            getchar();
            break;
        case 17:
            printf("----ListLength\n");
            i = ListLength(&L);
            if(i != -1)
            {
                printf("当前处理链表长度为：%d\n", i);
            }
            getchar();
            break;
        default:
            printf("输入无效，请重新输入：");
            getchar();
        }
    }
    printf("欢迎下次使用本系统\n");
    system("pause");
    return 0;
}