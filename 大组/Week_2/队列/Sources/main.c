#include"..\Headers\Lqueue.h"


int main()
{
    LQueue Q;
    char elem[100];
    Q.front = NULL;
    Q.rear = NULL;
    Q.length = 0;
    int choice = 1;//选项变量
    int t = 0;
    while (choice != 9)
    {
        printf("\n队列菜单:\n ");
        printf("1. 初始化队列\n");
        printf("2. 进队\n");
        printf("3. 出队\n");
        printf("4. 返回对头元素\n");
        printf("5. 清空队列\n");
        printf("6. 销毁队列\n");
        printf("7. 队列判空\n");
        printf("8.获取队列长度\n");
        printf("9. 退出程序\n");
        if (Q.front != NULL)
        {
            TraverseLQueue(&Q);
        }
        printf("请输入选项标号：");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case 1:
            InitLQueue(&Q);
            system("cls");
            break;
        case 2:
            printf("输入所存储的元素 ");
            gets(elem, sizeof(elem), stdin);
            EnLQueue(&Q,elem);
            system("cls");
            break;
        case 3:
            t = DeLQueue(&Q);
            system("cls");
            break;
        case 4:
            t = GetHeadLQueue(&Q);
            system("pause");
            system("cls");
            break;
        case 5:
            ClearLQueue(&Q);
            system("cls");
            break;
        case 6:
            DestoryLQueue(&Q);
            system("cls");
            break;
        case 7:
            t = IsEmptyLQueue(&Q);
            if (t)
            {
                printf("队列为空   ");
            }
            else
            {
                printf("队列不为空   ");
            }
            system("pause");
            system("cls");
            break;
        case 8:
            t = LengthLQueue(&Q);
            printf("队列长度为%d\n", t);
            system("pause");
            system("cls");
            break;
        default:
            continue;
        }
    }

}
