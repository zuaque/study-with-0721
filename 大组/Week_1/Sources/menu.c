#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"

void LinkNode1Menu() //单链表菜单
{
    linknode1* head=NULL;
    int num;
    int choice=1;//选项变量
    int chooice_num;
    while (choice != 6)
    {
        printf("\n单链表菜单:\n ");
        printf("1. 创建链表\n");
        printf("2. 插入链表\n");
        printf("3. 删除链表\n");
        printf("4. 查找链表\n");
        printf("5. 销毁链表\n");
        printf("6. 返回主菜单\n");
        if (head != NULL)
        {
            displaynode1(head, num);
        }
        printf("请输入选项标号：");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case 1:
        {
            if (head != NULL)//出错处理
            {
                printf("链表已经创建    \n");
                system("pause");
                system("cls");
                break;
            }
            head = (linknode1*)malloc(sizeof(linknode1));//开辟头节点
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
                head=Createlinknode1(head, temp);
                system("cls");
            }

            break;
        }
        case 2:
        {
            if (head == NULL)//出错处理
            {
                printf("链表尚未创建   ");
                system("pause");
                system("cls");
                break;
            }
            int new_date;
            while (1)//出错处理
            {
                printf("请输入要插入第几个节点之后（当前节点数为%d）:", num);
                scanf("%d", &chooice_num);
                getchar();
                if (chooice_num <= 0 || chooice_num > num)
                    printf("请输入正确节点数！\n");
                else
                    break;
                system("pause");
                system("cls");
            }
            printf("请输入插入节点的数据：");
            scanf("%d", &new_date);
            getchar();
            system("cls");
            Insetnode(head, &num, chooice_num, new_date);
            break;
        }
        case 3:
        {
            if (head == NULL)//出错处理
            {
                printf("链表尚未创建   ");
                system("pause");
                system("cls");
                break;
            }
            while (1)//出错处理
            {
                printf("请输入要删除第几个节点（当前节点数为%d）:", num);
                scanf("%d", &chooice_num);
                getchar();
                if (chooice_num <= 0 || chooice_num > num)
                    printf("请输入正确节点数！\n");
                else
                    break;
                system("pause");
                system("cls");
            }
            DelNode(head, &num, chooice_num);
            break;
        }
        case 4:
        {
            if (head == NULL)//出错处理
            {
                printf("链表尚未创建  ");
                system("pause");
                system("cls");
                break;
            }
            int aim_date;
            int* arr = (int*)malloc(num * sizeof(int));
            printf("请输入要查找的数据：");
            scanf("%d", &aim_date);
            getchar();
            system("cls");
            int total_num = FindDate(head, arr, aim_date,num);
            if (total_num)
            {
                printf("数据所在节点为：");
                for (int i = 0; i < total_num; i++)
                {
                    printf("节点%d  ", arr[i]);
                }
            }
            else
            {
                printf("链表不存在该数据   ");
            }
            free(arr);
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            if (head == NULL)//出错处理
            {
                printf("链表尚未创建   ");
                system("pause");
                system("cls");
                break;
            }
            Destory(head);
            head = NULL;
            break;
        }
        default:
        {
            continue;
        }
        }
        

    }
}

void LinkNode2Menu() //双向链表菜单
{
    linknode2* head = NULL;
    int num;
    int choice = 1;
    int chooice_num;
    while (choice != 6)
    {
        printf("\n双向链表菜单:\n ");
        printf("1. 创建链表\n");
        printf("2. 插入链表\n");
        printf("3. 删除链表\n");
        printf("4. 查找链表\n");
        printf("5. 销毁链表\n");
        printf("6. 返回主菜单\n");
        if (head != NULL)
        {
            displaynode2(head, num);
        }
        printf("请输入选项标号：");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case 1:
        {
            if (head != NULL)//出错处理
            {
                printf("链表已经创建    \n");
                system("pause");
                system("cls");
                break;
            }
            head = (linknode2*)malloc(sizeof(linknode2));//开辟头节点
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
                head = Createlinknode2(head, temp);
                system("cls");
            }

            break;
        }
        case 2:
        {
            if (head == NULL)//出错处理
            {
                printf("链表尚未创建   ");
                system("pause");
                system("cls");
                break;
            }
            int new_date;
            while (1)//出错处理
            {
                printf("请输入要插入第几个节点之后（当前节点数为%d）:", num);
                scanf("%d", &chooice_num);
                getchar();
                if (chooice_num <= 0 || chooice_num > num)
                    printf("请输入正确节点数！\n");
                else
                    break;
                system("pause");
                system("cls");
            }
            printf("请输入插入节点的数据：");
            scanf("%d", &new_date);
            getchar();
            system("cls");
            Insetnode2(head, &num, chooice_num, new_date);
            break;
        }
        case 3:
        {
            if (head == NULL)//出错处理
            {
                printf("链表尚未创建   ");
                system("pause");
                system("cls");
                break;
            }
            while (1)
            {
                printf("请输入要删除第几个节点（当前节点数为%d）:", num);
                scanf("%d", &chooice_num);
                getchar();
                if (chooice_num <= 0 || chooice_num > num)
                    printf("请输入正确节点数！\n");
                else
                    break;
                system("pause");
                system("cls");
            }
            DelNode2(head, &num, chooice_num);
            break;
        }
        case 4:
        {
            if (head == NULL)//出错处理
            {
                printf("链表尚未创建  ");
                system("pause");
                system("cls");
                break;
            }
            int aim_date;//目标数据变量
            int* arr = (int*)malloc(num * sizeof(int));
            printf("请输入要查找的数据：");
            scanf("%d", &aim_date);
            getchar();
            system("cls");
            int total_num = FindDate2(head, arr, aim_date,num);
            if (total_num)
            {
                printf("数据所在节点为：");
                for (int i = 0; i < total_num; i++)
                {
                    printf("节点%d  ", arr[i]);
                }
            }
            else
            {
                printf("链表不存在该数据    ");
            }
            free(arr);
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            if (head == NULL)//出错处理
            {
                printf("链表尚未创建   ");
                system("pause");
                system("cls");
                break;
            }
            Destory2(head);
            head = NULL;
            break;
        }
        default:
        {
            continue;
        }
        }


    }
}

void ReverseMenu()
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
    int choice = 1;
    while (1)
    {
        printf("1. 使用递归逆转\n");
        printf("2. 使用迭代逆转\n");
        printf("输入选项标号：");
        scanf("%d", &choice);
        getchar();
        system("cls");
        if (choice == 1 || choice == 2)
            break;
    }
    switch (choice)
    {
    case 1:
        displaynode1(head, num);
        head = reverse1(head);//递归算法
        printf("逆转后，");
        new_displaynode1(head, num);
        system("pause");
        system("cls");
        break;
    case 2:
        displaynode1(head, num);
        head = reverse2(head);//迭代算法
        printf("逆转后，");
        new_displaynode1(head, num);
        system("pause");
        system("cls");
        break;
    }

    
    
}