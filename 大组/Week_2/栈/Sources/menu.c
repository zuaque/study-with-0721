#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\Stack.h"

void StackMenu() //单链表菜单
{
    LinkStack stack;
    stack.top= NULL;
    stack.count = 0;
    int num;
    int sizes;
    int choice = 1;//选项变量
    int chooice_num;
    while (choice != 7)
    {
        printf("\n栈菜单:\n ");
        printf("1. 初始化栈\n");
        printf("2. 压入栈\n");
        printf("3. 弹出栈\n");
        printf("4. 返回栈顶元素\n");
        printf("5. 清空栈\n");
        printf("6. 销毁栈\n");
        printf("7. 返回主菜单\n");
        if (stack.top != NULL)
        {
            displayStack(&stack);
        }
        printf("请输入选项标号：");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case 1:
            if (stack.top != NULL)//出错处理
            {
                printf("栈已创建   ");
                system("pause");
                system("cls");
                break;
            }
            printf("请预设栈的大小：");
            while (1)
            {
                scanf("%d", &sizes);
                if (sizes >= 0)
                {
                    getchar();
                    system("cls");
                    break;
                }
                else
                {
                    printf("请输入数字   ");
                    system("pause");
                    system("cls");
                }
            }
            system("cls");
            initStack(&stack, sizes);
            break;
        
        case 2:
            if (stack.top == NULL)//出错处理
            {
                printf("栈尚未创建   ");
                system("pause");
                system("cls");
                break;
            }
            int new_data;
            printf("输入压入栈的数据：");
            while (1)
            {
                scanf("%d", &new_data);
                if (new_data >= 0)
                {
                    getchar();
                    system("cls");
                    break;
                }
                else
                {
                    printf("请输入数字   ");
                    system("pause");
                    system("cls");
                }
            }
            system("cls");
            pushStack(&stack, new_data);
            break;
        
        case 3:
            if (stack.top == NULL)//出错处理
            {
                printf("栈尚未创建   ");
                system("pause");
                system("cls");
                break;
            }
            int pop_data;
            pop_data = popStack(&stack);
            printf("弹出的数据为：%d\n", pop_data);
            system("pause");
            system("cls");
            break;
        
        case 4:
            if (stack.top == NULL)//出错处理
            {
                printf("栈为空   ");
                system("pause");
                system("cls");
                break;
            }
            printf("栈顶元素为：%d\n", stack.top->data);
            system("pause");
            system("cls");
            break;
        
        case 5:
            printf("请输入清空的节点数（目前栈大小为%d）：", stack.count);
            int clearNum;
            while (1)
            {
                scanf("%d", &clearNum);
                getchar();
                if (clearNum >= 0)
                {
                    system("cls");
                    break;
                }
                else
                {
                    printf("请输入数字   ");
                    system("pause");
                    system("cls");
                }
            }
            clearStack(&stack, clearNum);
            break;
        
        case 6:
            destoryStack(&stack);
            break;
        
        default:
            continue;

        }


    }
}