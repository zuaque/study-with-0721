#include"..\Headers\Sort.h"

void Sort_menu()
{
    int choice = 1;//选项变量
    int choice0 = 1;
    double cost_time;
    char num_c[1000];
    int arr[100];
    int size;
    while (choice != 6)
    {
        printf("\n排序菜单:\n ");
        printf("1. 插入排序\n");
        printf("2. 归并排序\n");
        printf("3. 快速排序（递归）\n");
        printf("4. 计数排序\n");
        printf("5. 基数排序\n");
        printf("6. 返回主菜单\n");
        printf("请输入选项标号：");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case 1:
            printf("1. 手动输入数据排序\n");
            printf("2. 大数据测试用时\n");
            printf("3. 大量小数据测试用时\n");
            printf("请输入选项标号：");
            scanf("%d", &choice0);
            getchar();
            system("cls");
            system("cls");
            switch (choice0)
            {
            case 1:
                printf("请输入想要排列的数组（拿什么隔开都行）\n");
                fgets(num_c, sizeof(num_c), stdin);
                system("cls");
                size = getNum(arr, num_c);
                printf("排序前：");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                InsetSort(arr, size);
                printf("\n");
                printf("排序后：");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("10000数据量耗时：%lf 秒\n", TimeTest1(1, 10000));
                printf("50000数据量耗时：%lf 秒\n", TimeTest1(1, 50000));
                printf("200000数据量耗时：%lf 秒\n", TimeTest1(1, 200000));
                system("pause");
                system("cls");
                break;
            case 3:
                printf("100数据量100000次排序耗时：%lf 秒\n", TimeTest2(1));
                system("pause");
                system("cls");
                break;
            default:
                break;
            }
            break;
        case 2:
            printf("1. 手动输入数据排序\n");
            printf("2. 大数据测试用时\n");
            printf("3. 大量小数据测试用时\n");
            printf("请输入选项标号：");
            scanf("%d", &choice0);
            getchar();
            system("cls");
            switch (choice0)
            {
            case 1:
                printf("请输入想要排列的数组（拿什么隔开都行）\n");
                fgets(num_c, sizeof(num_c), stdin);
                system("cls");
                size = getNum(arr, num_c);
                printf("排序前：");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                MergeSort(arr, 0, size - 1);
                printf("\n");
                printf("排序后：");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("10000数据量耗时：%lf 秒\n", TimeTest1(2, 10000));
                printf("50000数据量耗时：%lf 秒\n", TimeTest1(2, 50000));
                printf("200000数据量耗时：%lf 秒\n", TimeTest1(2, 200000));
                system("pause");
                system("cls");
                break;
            case 3:
                printf("100数据量100000次排序耗时：%lf 秒\n", TimeTest2(2));
                system("pause");
                system("cls");
                break;
            default:
                break;
            }
            break;

        case 3:
            printf("1. 手动输入数据排序\n");
            printf("2. 大数据测试用时\n");
            printf("3. 大量小数据测试用时\n");
            printf("请输入选项标号：");
            scanf("%d", &choice0);
            getchar();
            system("cls");
            switch (choice0)
            {
            case 1:
                printf("请输入想要排列的数组（拿什么隔开都行）\n");
                fgets(num_c, sizeof(num_c), stdin);
                system("cls");
                size = getNum(arr, num_c);
                printf("排序前：");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                QuickSort(arr, 0, size - 1);
                printf("\n");
                printf("排序后：");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("10000数据量耗时：%lf 秒\n", TimeTest1(3, 10000));
                printf("50000数据量耗时：%lf 秒\n", TimeTest1(3, 50000));
                printf("200000数据量耗时：%lf 秒\n", TimeTest1(3, 200000));
                system("pause");
                system("cls");
                break;
            case 3:
                printf("100数据量100000次排序耗时：%lf 秒\n", TimeTest2(3));
                system("pause");
                system("cls");
                break;
            default:
                break;
            }
            break;

        case 4:
            printf("1. 手动输入数据排序\n");
            printf("2. 大数据测试用时\n");
            printf("3. 大量小数据测试用时\n");
            printf("请输入选项标号：");
            scanf("%d", &choice0);
            getchar();
            system("cls");
            switch (choice0)
            {
            case 1:
                printf("请输入想要排列的数组（拿什么隔开都行）\n");
                fgets(num_c, sizeof(num_c), stdin);
                system("cls");
                size = getNum(arr, num_c);
                printf("排序前：");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                CountSort(arr, size);
                printf("\n");
                printf("排序后：");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("10000数据量耗时：%lf 秒\n", TimeTest1(4, 10000));
                printf("50000数据量耗时：%lf 秒\n", TimeTest1(4, 50000));
                printf("200000数据量耗时：%lf 秒\n", TimeTest1(4, 200000));
                system("pause");
                system("cls");
                break;
            case 3:
                printf("100数据量100000次排序耗时：%lf 秒\n", TimeTest2(4));
                system("pause");
                system("cls");
                break;
            default:
                break;
            }
            break;

        case 5:
            printf("1. 手动输入数据排序\n");
            printf("2. 大数据测试用时\n");
            printf("3. 大量小数据测试用时\n");
            printf("请输入选项标号：");
            scanf("%d", &choice0);
            getchar();
            system("cls");
            switch (choice0)
            {
            case 1:
                printf("请输入想要排列的数组（拿什么隔开都行）\n");
                fgets(num_c, sizeof(num_c), stdin);
                system("cls");
                size = getNum(arr, num_c);
                printf("排序前：");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                RadixCountSort(arr, size);
                printf("\n");
                printf("排序后：");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                system("pause");
                system("cls");
                break;
            case 2:
                printf("10000数据量耗时：%lf 秒\n", TimeTest1(1, 10000));
                printf("50000数据量耗时：%lf 秒\n", TimeTest1(1, 50000));
                printf("200000数据量耗时：%lf 秒\n", TimeTest1(1, 200000));
                system("pause");
                system("cls");
                break;
            case 3:
                printf("100数据量100000次排序耗时：%lf 秒\n", TimeTest2(1));
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
    int choice = 1;//选项变量
    while (choice != 3)
    {
        printf("\n文件菜单:\n ");
        printf("1. 保存数组到文件\n");
        printf("2. 读取文件排列并保存\n");
        printf("3.退出\n");
        printf("请输入选项标号：");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case 1:
            if (size != 0)
            {
                printf("文件已生成   ");
                system("pause");
                system("cls");
                break;
            }
            printf("请输入数据量：");
            scanf("%d", &size);
            getchar();
            system("cls");
            srand(time(NULL));//引入时间数据
            int* arr = (int*)malloc(size * sizeof(int));
            for (int i = 0; i < size; i++)
            {
                arr[i] = rand() % (size + 1);
            }
            Save(arr, size);
            printf("文件已生成   ");
            system("pause");
            system("cls");
            break;
        case 2:
            if (size == 0)
            {
                printf("文件尚未生成   ");
                system("pause");
                system("cls");
                break;
            }
            int* arr0 = (int*)malloc(size * sizeof(int));
            Read(arr0, size);
            CountSort(arr0, size);
            Save(arr0, size);
            printf("文件已更新   ");
            size = 0;
            system("pause");
            system("cls");
            break;
        }
        
    }
}