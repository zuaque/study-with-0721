#include"..\Headers\Sort.h"

void Sort_menu()
{
    int choice = 1;//ѡ�����
    int choice0 = 1;
    double cost_time;
    char num_c[1000];
    int arr[100];
    int size;
    while (choice != 6)
    {
        printf("\n����˵�:\n ");
        printf("1. ��������\n");
        printf("2. �鲢����\n");
        printf("3. �������򣨵ݹ飩\n");
        printf("4. ��������\n");
        printf("5. ��������\n");
        printf("6. �������˵�\n");
        printf("������ѡ���ţ�");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case 1:
            printf("1. �ֶ�������������\n");
            printf("2. �����ݲ�����ʱ\n");
            printf("3. ����С���ݲ�����ʱ\n");
            printf("������ѡ���ţ�");
            scanf("%d", &choice0);
            getchar();
            system("cls");
            system("cls");
            switch (choice0)
            {
            case 1:
                printf("��������Ҫ���е����飨��ʲô�������У�\n");
                fgets(num_c, sizeof(num_c), stdin);
                system("cls");
                size = getNum(arr, num_c);
                printf("����ǰ��");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                InsetSort(arr, size);
                printf("\n");
                printf("�����");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("10000��������ʱ��%lf ��\n", TimeTest1(1, 10000));
                printf("50000��������ʱ��%lf ��\n", TimeTest1(1, 50000));
                printf("200000��������ʱ��%lf ��\n", TimeTest1(1, 200000));
                system("pause");
                system("cls");
                break;
            case 3:
                printf("100������100000�������ʱ��%lf ��\n", TimeTest2(1));
                system("pause");
                system("cls");
                break;
            default:
                break;
            }
            break;
        case 2:
            printf("1. �ֶ�������������\n");
            printf("2. �����ݲ�����ʱ\n");
            printf("3. ����С���ݲ�����ʱ\n");
            printf("������ѡ���ţ�");
            scanf("%d", &choice0);
            getchar();
            system("cls");
            switch (choice0)
            {
            case 1:
                printf("��������Ҫ���е����飨��ʲô�������У�\n");
                fgets(num_c, sizeof(num_c), stdin);
                system("cls");
                size = getNum(arr, num_c);
                printf("����ǰ��");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                MergeSort(arr, 0, size - 1);
                printf("\n");
                printf("�����");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("10000��������ʱ��%lf ��\n", TimeTest1(2, 10000));
                printf("50000��������ʱ��%lf ��\n", TimeTest1(2, 50000));
                printf("200000��������ʱ��%lf ��\n", TimeTest1(2, 200000));
                system("pause");
                system("cls");
                break;
            case 3:
                printf("100������100000�������ʱ��%lf ��\n", TimeTest2(2));
                system("pause");
                system("cls");
                break;
            default:
                break;
            }
            break;

        case 3:
            printf("1. �ֶ�������������\n");
            printf("2. �����ݲ�����ʱ\n");
            printf("3. ����С���ݲ�����ʱ\n");
            printf("������ѡ���ţ�");
            scanf("%d", &choice0);
            getchar();
            system("cls");
            switch (choice0)
            {
            case 1:
                printf("��������Ҫ���е����飨��ʲô�������У�\n");
                fgets(num_c, sizeof(num_c), stdin);
                system("cls");
                size = getNum(arr, num_c);
                printf("����ǰ��");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                QuickSort(arr, 0, size - 1);
                printf("\n");
                printf("�����");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("10000��������ʱ��%lf ��\n", TimeTest1(3, 10000));
                printf("50000��������ʱ��%lf ��\n", TimeTest1(3, 50000));
                printf("200000��������ʱ��%lf ��\n", TimeTest1(3, 200000));
                system("pause");
                system("cls");
                break;
            case 3:
                printf("100������100000�������ʱ��%lf ��\n", TimeTest2(3));
                system("pause");
                system("cls");
                break;
            default:
                break;
            }
            break;

        case 4:
            printf("1. �ֶ�������������\n");
            printf("2. �����ݲ�����ʱ\n");
            printf("3. ����С���ݲ�����ʱ\n");
            printf("������ѡ���ţ�");
            scanf("%d", &choice0);
            getchar();
            system("cls");
            switch (choice0)
            {
            case 1:
                printf("��������Ҫ���е����飨��ʲô�������У�\n");
                fgets(num_c, sizeof(num_c), stdin);
                system("cls");
                size = getNum(arr, num_c);
                printf("����ǰ��");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                CountSort(arr, size);
                printf("\n");
                printf("�����");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("10000��������ʱ��%lf ��\n", TimeTest1(4, 10000));
                printf("50000��������ʱ��%lf ��\n", TimeTest1(4, 50000));
                printf("200000��������ʱ��%lf ��\n", TimeTest1(4, 200000));
                system("pause");
                system("cls");
                break;
            case 3:
                printf("100������100000�������ʱ��%lf ��\n", TimeTest2(4));
                system("pause");
                system("cls");
                break;
            default:
                break;
            }
            break;

        case 5:
            printf("1. �ֶ�������������\n");
            printf("2. �����ݲ�����ʱ\n");
            printf("3. ����С���ݲ�����ʱ\n");
            printf("������ѡ���ţ�");
            scanf("%d", &choice0);
            getchar();
            system("cls");
            switch (choice0)
            {
            case 1:
                printf("��������Ҫ���е����飨��ʲô�������У�\n");
                fgets(num_c, sizeof(num_c), stdin);
                system("cls");
                size = getNum(arr, num_c);
                printf("����ǰ��");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                RadixCountSort(arr, size);
                printf("\n");
                printf("�����");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("10000��������ʱ��%lf ��\n", TimeTest1(1, 10000));
                printf("50000��������ʱ��%lf ��\n", TimeTest1(1, 50000));
                printf("200000��������ʱ��%lf ��\n", TimeTest1(1, 200000));
                system("pause");
                system("cls");
                break;
            case 3:
                printf("100������100000�������ʱ��%lf ��\n", TimeTest2(1));
                system("pause");
                system("cls");
                break;
            default:
                break;
            }
            break;

        default:
            break;
        }


    }
}

void FileMenu()
{
    int size = 0;
    int choice = 1;//ѡ�����
    while (choice != 3)
    {
        printf("\n�ļ��˵�:\n ");
        printf("1. �������鵽�ļ�\n");
        printf("2. ��ȡ�ļ����в�����\n");
        printf("3.�˳�\n");
        printf("������ѡ���ţ�");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case 1:
            if (size != 0)
            {
                printf("�ļ�������   ");
                system("pause");
                system("cls");
                break;
            }
            printf("��������������");
            scanf("%d", &size);
            getchar();
            system("cls");
            srand(time(NULL));//����ʱ������
            int* arr = (int*)malloc(size * sizeof(int));
            for (int i = 0; i < size; i++)
            {
                arr[i] = rand() % (size + 1);
            }
            Save(arr, size);
            printf("�ļ�������   ");
            system("pause");
            system("cls");
            break;
        case 2:
            if (size == 0)
            {
                printf("�ļ���δ����   ");
                system("pause");
                system("cls");
                break;
            }
            int* arr0 = (int*)malloc(size * sizeof(int));
            Read(arr0, size);
            CountSort(arr0, size);
            Save(arr0, size);
            printf("�ļ��Ѹ���   ");
            size = 0;
            system("pause");
            system("cls");
            break;
        }
        
    }
}