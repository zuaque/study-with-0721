#include"..\Headers\Sort.h"

int main()
{
	int main_choice = 0;
	int size;
	while (main_choice != 5)
	{
		printf("\n排序算法总菜单\n");
		printf("1.排序算法实现与测试\n");
		printf("2.文件操作\n");
		printf("3.颜色排序\n");
		printf("4.找到第k大的数\n");
		printf("5.退出程序\n");
		printf("请输入选项标号：");
		scanf("%d", &main_choice);
		getchar();
		system("cls");
		switch (main_choice)
		{
		case 1:
			Sort_menu();
			break;
		case 2:
			FileMenu();
			break;
		case 3:
			printf("输入数组大小：");
			scanf("%d", &size);
			getchar();
			srand(time(NULL));//引入时间数据
			int* arr1 = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; i++)
			{
				arr1[i] = rand() % 3;
			}
			system("cls");
			printf("当前数组为：");
			for (int i = 0; i < size; i++)
			{
				printf("%d ", arr1[i]);
			}
			ColorSort(arr1, size);
			printf("\n");
			printf("排序后：");
			for (int i = 0; i < size; i++)
			{
				printf("%d ", arr1[i]);
			}
			printf("\n");
			system("pause");
			system("cls");
			break;
			break;
		case 4:
			printf("输入数组大小：");
			scanf("%d", &size);
			getchar();
			srand(time(NULL));//引入时间数据
			int* arr2 = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; i++)
			{
				arr2[i] = rand() % (size+1);
			}
			system("cls");
			printf("当前数组为：");
			for (int i = 0; i < size; i++)
			{
				printf("%d ", arr2[i]);
			}
			printf("\n");
			int k;
			printf("输入k：");
			scanf("%d", &k);
			getchar();
			int k_num = FindK(arr2, 0, size - 1, k);
			printf("\n");
			printf("第%d大的数为：%d\n", k, k_num);
			system("pause");
			system("cls");
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		default:
			continue;
		}


	}
}