#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\Stack.h"

void StackMenu() //������˵�
{
    LinkStack stack;
    stack.top= NULL;
    stack.count = 0;
    int num;
    int sizes;
    int choice = 1;//ѡ�����
    int chooice_num;
    while (choice != 7)
    {
        printf("\nջ�˵�:\n ");
        printf("1. ��ʼ��ջ\n");
        printf("2. ѹ��ջ\n");
        printf("3. ����ջ\n");
        printf("4. ����ջ��Ԫ��\n");
        printf("5. ���ջ\n");
        printf("6. ����ջ\n");
        printf("7. �������˵�\n");
        if (stack.top != NULL)
        {
            displayStack(&stack);
        }
        printf("������ѡ���ţ�");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case 1:
            if (stack.top != NULL)//������
            {
                printf("ջ�Ѵ���   ");
                system("pause");
                system("cls");
                break;
            }
            printf("��Ԥ��ջ�Ĵ�С��");
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
                    printf("����������   ");
                    system("pause");
                    system("cls");
                }
            }
            system("cls");
            initStack(&stack, sizes);
            break;
        
        case 2:
            if (stack.top == NULL)//������
            {
                printf("ջ��δ����   ");
                system("pause");
                system("cls");
                break;
            }
            int new_data;
            printf("����ѹ��ջ�����ݣ�");
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
                    printf("����������   ");
                    system("pause");
                    system("cls");
                }
            }
            system("cls");
            pushStack(&stack, new_data);
            break;
        
        case 3:
            if (stack.top == NULL)//������
            {
                printf("ջ��δ����   ");
                system("pause");
                system("cls");
                break;
            }
            int pop_data;
            pop_data = popStack(&stack);
            printf("����������Ϊ��%d\n", pop_data);
            system("pause");
            system("cls");
            break;
        
        case 4:
            if (stack.top == NULL)//������
            {
                printf("ջΪ��   ");
                system("pause");
                system("cls");
                break;
            }
            printf("ջ��Ԫ��Ϊ��%d\n", stack.top->data);
            system("pause");
            system("cls");
            break;
        
        case 5:
            printf("��������յĽڵ�����Ŀǰջ��СΪ%d����", stack.count);
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
                    printf("����������   ");
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