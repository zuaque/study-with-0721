#include"..\Headers\Sort.h"

int main()
{
	int main_choice = 0;
	int size;
	while (main_choice != 5)
	{
		printf("\n�����㷨�ܲ˵�\n");
		printf("1.�����㷨ʵ�������\n");
		printf("2.�ļ�����\n");
		printf("3.��ɫ����\n");
		printf("4.�ҵ���k�����\n");
		printf("5.�˳�����\n");
		printf("������ѡ���ţ�");
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
			printf("���������С��");
			scanf("%d", &size);
			getchar();
			srand(time(NULL));//����ʱ������
			int* arr1 = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; i++)
			{
				arr1[i] = rand() % 3;
			}
			system("cls");
			printf("��ǰ����Ϊ��");
			for (int i = 0; i < size; i++)
			{
				printf("%d ", arr1[i]);
			}
			ColorSort(arr1, size);
			printf("\n");
			printf("�����");
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
			printf("���������С��");
			scanf("%d", &size);
			getchar();
			srand(time(NULL));//����ʱ������
			int* arr2 = (int*)malloc(size * sizeof(int));
			for (int i = 0; i < size; i++)
			{
				arr2[i] = rand() % (size+1);
			}
			system("cls");
			printf("��ǰ����Ϊ��");
			for (int i = 0; i < size; i++)
			{
				printf("%d ", arr2[i]);
			}
			printf("\n");
			int k;
			printf("����k��");
			scanf("%d", &k);
			getchar();
			int k_num = FindK(arr2, 0, size - 1, k);
			printf("\n");
			printf("��%d�����Ϊ��%d\n", k, k_num);
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