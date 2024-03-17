#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\LinkList.h"

void findMiddleNode()
{
    int num = 0;
    linknode1* head = (linknode1*)malloc(sizeof(linknode1));//开辟头节点
    if (head == NULL)
    {
        printf("开辟失败！.\n");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;
    printf("输入创造链表的节点数量:");
    scanf("%d", &num);//设置链表节点数量
    getchar();
    system("cls");
    for (int i = 0; i < num; i++)//输入每个节点的数据
    {
        int temp;
        printf("输入节点%d的数据：", i + 1);
        scanf("%d", &temp);
        getchar();
        head = Createlinknode1(head, temp);
        system("cls");
    }
    linknode1* fast = head->next;//快指针
    linknode1* slow = head->next;//慢指针
    int f = 1;//记录当前节点数
    while (fast != NULL&&fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        f++;
    }
    displaynode1(head, num);
    printf("该链表中点为节点%d,数值为%d\n", f, slow->date);
    system("pause");
    system("cls");
}