#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\LinkList.h"


void SwapOddEven()
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
    int current = 1;//当前节点标号
    linknode1* temp2 = head->next;//开始遍历
    printf("input： ");
    while (1)
    {
        if (current == num)//如果到尾节点
        {
            printf("%d", temp2->date);
            printf("\n");
            break;
        }
        printf("%d -> ", temp2->date);
        temp2 = temp2->next;
        current++;
    }
    linknode1* h = head;//交换的一对节点的前一个节点
    linknode1* p = head->next;//奇数节点
    linknode1* q = p->next;//偶数节点
    while (q != NULL && p != NULL)
    {
        linknode1* link_temp = q->next;//保存交换节点后面的节点地址
        h->next = q;//开始交换
        q->next = p;
        p->next = link_temp;
        h = p;//此时p与q的位置发生交换
        p = h->next;
        if (p != NULL)
            q = p->next;
    }
    current = 1;//当前节点标号
    temp2 = head->next;//开始遍历
    printf("output： ");
    while (1)
    {
        if (current == num)//如果到尾节点
        {
            printf("%d", temp2->date);
            printf("\n");
            break;
        }
        printf("%d -> ", temp2->date);
        temp2 = temp2->next;
        current++;
    }
    system("pause");
    system("cls");
}