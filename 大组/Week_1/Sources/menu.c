#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"

void LinkNode1Menu() //������˵�
{
    linknode1* head=NULL;
    int num;
    int choice=1;//ѡ�����
    int chooice_num;
    while (choice != 6)
    {
        printf("\n������˵�:\n ");
        printf("1. ��������\n");
        printf("2. ��������\n");
        printf("3. ɾ������\n");
        printf("4. ��������\n");
        printf("5. ��������\n");
        printf("6. �������˵�\n");
        if (head != NULL)
        {
            displaynode1(head, num);
        }
        printf("������ѡ���ţ�");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case 1:
        {
            if (head != NULL)//������
            {
                printf("�����Ѿ�����    \n");
                system("pause");
                system("cls");
                break;
            }
            head = (linknode1*)malloc(sizeof(linknode1));//����ͷ�ڵ�
            head->next = NULL;
            printf("���봴������Ľڵ�����:");
            scanf("%d", &num);//��������ڵ�����
            getchar();
            system("cls");
            for (int i = 0; i < num; i++)//����ÿ���ڵ������
            {
                int temp;
                printf("����ڵ�%d�����ݣ�", i + 1);
                scanf("%d", &temp);
                getchar();
                head=Createlinknode1(head, temp);
                system("cls");
            }

            break;
        }
        case 2:
        {
            if (head == NULL)//������
            {
                printf("������δ����   ");
                system("pause");
                system("cls");
                break;
            }
            int new_date;
            while (1)//������
            {
                printf("������Ҫ����ڼ����ڵ�֮�󣨵�ǰ�ڵ���Ϊ%d��:", num);
                scanf("%d", &chooice_num);
                getchar();
                if (chooice_num <= 0 || chooice_num > num)
                    printf("��������ȷ�ڵ�����\n");
                else
                    break;
                system("pause");
                system("cls");
            }
            printf("���������ڵ�����ݣ�");
            scanf("%d", &new_date);
            getchar();
            system("cls");
            Insetnode(head, &num, chooice_num, new_date);
            break;
        }
        case 3:
        {
            if (head == NULL)//������
            {
                printf("������δ����   ");
                system("pause");
                system("cls");
                break;
            }
            while (1)//������
            {
                printf("������Ҫɾ���ڼ����ڵ㣨��ǰ�ڵ���Ϊ%d��:", num);
                scanf("%d", &chooice_num);
                getchar();
                if (chooice_num <= 0 || chooice_num > num)
                    printf("��������ȷ�ڵ�����\n");
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
            if (head == NULL)//������
            {
                printf("������δ����  ");
                system("pause");
                system("cls");
                break;
            }
            int aim_date;
            int* arr = (int*)malloc(num * sizeof(int));
            printf("������Ҫ���ҵ����ݣ�");
            scanf("%d", &aim_date);
            getchar();
            system("cls");
            int total_num = FindDate(head, arr, aim_date,num);
            if (total_num)
            {
                printf("�������ڽڵ�Ϊ��");
                for (int i = 0; i < total_num; i++)
                {
                    printf("�ڵ�%d  ", arr[i]);
                }
            }
            else
            {
                printf("�������ڸ�����   ");
            }
            free(arr);
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            if (head == NULL)//������
            {
                printf("������δ����   ");
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

void LinkNode2Menu() //˫������˵�
{
    linknode2* head = NULL;
    int num;
    int choice = 1;
    int chooice_num;
    while (choice != 6)
    {
        printf("\n˫������˵�:\n ");
        printf("1. ��������\n");
        printf("2. ��������\n");
        printf("3. ɾ������\n");
        printf("4. ��������\n");
        printf("5. ��������\n");
        printf("6. �������˵�\n");
        if (head != NULL)
        {
            displaynode2(head, num);
        }
        printf("������ѡ���ţ�");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case 1:
        {
            if (head != NULL)//������
            {
                printf("�����Ѿ�����    \n");
                system("pause");
                system("cls");
                break;
            }
            head = (linknode2*)malloc(sizeof(linknode2));//����ͷ�ڵ�
            head->next = NULL;
            printf("���봴������Ľڵ�����:");
            scanf("%d", &num);//��������ڵ�����
            getchar();
            system("cls");
            for (int i = 0; i < num; i++)//����ÿ���ڵ������
            {
                int temp;
                printf("����ڵ�%d�����ݣ�", i + 1);
                scanf("%d", &temp);
                getchar();
                head = Createlinknode2(head, temp);
                system("cls");
            }

            break;
        }
        case 2:
        {
            if (head == NULL)//������
            {
                printf("������δ����   ");
                system("pause");
                system("cls");
                break;
            }
            int new_date;
            while (1)//������
            {
                printf("������Ҫ����ڼ����ڵ�֮�󣨵�ǰ�ڵ���Ϊ%d��:", num);
                scanf("%d", &chooice_num);
                getchar();
                if (chooice_num <= 0 || chooice_num > num)
                    printf("��������ȷ�ڵ�����\n");
                else
                    break;
                system("pause");
                system("cls");
            }
            printf("���������ڵ�����ݣ�");
            scanf("%d", &new_date);
            getchar();
            system("cls");
            Insetnode2(head, &num, chooice_num, new_date);
            break;
        }
        case 3:
        {
            if (head == NULL)//������
            {
                printf("������δ����   ");
                system("pause");
                system("cls");
                break;
            }
            while (1)
            {
                printf("������Ҫɾ���ڼ����ڵ㣨��ǰ�ڵ���Ϊ%d��:", num);
                scanf("%d", &chooice_num);
                getchar();
                if (chooice_num <= 0 || chooice_num > num)
                    printf("��������ȷ�ڵ�����\n");
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
            if (head == NULL)//������
            {
                printf("������δ����  ");
                system("pause");
                system("cls");
                break;
            }
            int aim_date;//Ŀ�����ݱ���
            int* arr = (int*)malloc(num * sizeof(int));
            printf("������Ҫ���ҵ����ݣ�");
            scanf("%d", &aim_date);
            getchar();
            system("cls");
            int total_num = FindDate2(head, arr, aim_date,num);
            if (total_num)
            {
                printf("�������ڽڵ�Ϊ��");
                for (int i = 0; i < total_num; i++)
                {
                    printf("�ڵ�%d  ", arr[i]);
                }
            }
            else
            {
                printf("�������ڸ�����    ");
            }
            free(arr);
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            if (head == NULL)//������
            {
                printf("������δ����   ");
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
    linknode1* head = (linknode1*)malloc(sizeof(linknode1));//����ͷ�ڵ�
    if (head == NULL)
    {
        printf("����ʧ�ܣ�.\n");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;
    printf("���봴������Ľڵ�����:");
    scanf("%d", &num);//��������ڵ�����
    getchar();
    system("cls");
    for (int i = 0; i < num; i++)//����ÿ���ڵ������
    {
        int temp;
        printf("����ڵ�%d�����ݣ�", i + 1);
        scanf("%d", &temp);
        getchar();
        head = Createlinknode1(head, temp);
        system("cls");
    }
    int choice = 1;
    while (1)
    {
        printf("1. ʹ�õݹ���ת\n");
        printf("2. ʹ�õ�����ת\n");
        printf("����ѡ���ţ�");
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
        head = reverse1(head);//�ݹ��㷨
        printf("��ת��");
        new_displaynode1(head, num);
        system("pause");
        system("cls");
        break;
    case 2:
        displaynode1(head, num);
        head = reverse2(head);//�����㷨
        printf("��ת��");
        new_displaynode1(head, num);
        system("pause");
        system("cls");
        break;
    }

    
    
}