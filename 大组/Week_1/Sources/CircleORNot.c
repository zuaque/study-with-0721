#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\LinkList.h"
#include<time.h>//引入时间

int hasCircle()
{
    printf("输入的链表将会有概率成环\n");
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
    srand(time(NULL));//引入时间数据
    int linkc = rand() % (2*num + 1);//根据系统时间生成伪随机数，范围为0~2*num
    if(linkc <= num)//若随机数在0~num间，将根据随机数对应的节点数成环，反之则不成环
    {
        linknode1* temp = head->next;
        while (temp->next != NULL)//遍历到尾节点
        {
            temp = temp->next;
        }
        linknode1* cirnode = head;
        for (int i = 0; i < linkc; i++)//遍历到所接节点
        {
            cirnode = cirnode->next;
        }
        temp->next = cirnode;
    }
    linknode1* fast = head;//快指针
    linknode1* slow = head;//慢指针
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;//走两步
        slow = slow->next;//走一步
        if (fast == slow)//如果相遇则说明成环
        {
            if (linkc == 0)
            {
                printf("该链表成环，尾节点与头节点相连\n");
            }
            else
            {
                printf("该链表成环，尾节点与节点%d相连\n", linkc);
            }
            system("pause");
            return 0;
        }
    }
    printf("该链表不成环\n");
    system("pause");
    system("cls");
    return 0;
}
