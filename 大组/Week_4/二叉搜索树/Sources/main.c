#include"..\Headers\BST.h"

int main()
{
	char num_c[1000];
	int arr[100];
	char main_choice = '0';
	int size;
	int n;
	BinarySortTreePtr Tree=(BinarySortTreePtr)malloc(sizeof(BinarySortTreePtr));
	Tree->root = NULL;
	while (main_choice-'0' != 6)
	{
		printf("\n�����������ܲ˵�\n");
		printf("1.��ʼ��������\n");
		printf("2.����\n");
		printf("3.����\n");
		printf("4.ɾ��\n");
		printf("5.����\n");
		printf("6.�˳�����\n");
		printf("������ѡ���ţ�");
		scanf("%c", &main_choice);
		getchar();
		system("cls");
		switch (main_choice)
		{
		case '1':
			if (Tree->root != NULL)
			{
				printf("���ѽ���   ");
				system("pause");
				system("cls");
				break;
			}
			printf("��������Ҫ���е����飨��ʲô�������У�\n");
			fgets(num_c, sizeof(num_c), stdin);
			system("cls");
			size = getNum(arr, num_c);
			Tree->root=sortedArrayToBST(arr, 0, size - 1);
			printf("��ʼ����ɣ�");
			system("pause");
			system("cls");
			break;
		case '2':
			if (Tree->root == NULL)
			{
				printf("��δ����   ");
				system("pause");
				system("cls");
				break;
			}
			printf("�������ѯ������");
			scanf("%d", &n);
			getchar();
			findBST(Tree, n);
			break;
		case '3':
			if (Tree->root == NULL)
			{
				printf("��δ����   ");
				system("pause");
				system("cls");
				break;
			}
			printf("��������������");
			scanf("%d", &n);
			getchar();
			insetTree(Tree, n);
			break;
		case '4':
			if (Tree->root == NULL)
			{
				printf("��δ����   ");
				system("pause");
				system("cls");
				break;
			}
			printf("������ɾ��������");
			scanf("%d", &n);
			getchar();
			delTree(Tree, n);
			break;
		case '5':
			if (Tree->root == NULL)
			{
				printf("��δ����   ");
				system("pause");
				system("cls");
				break;
			}
			TreeTravel(Tree);
			break;
		case 7:
		default:
			continue;
		}


	}
}