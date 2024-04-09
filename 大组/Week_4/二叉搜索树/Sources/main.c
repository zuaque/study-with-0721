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
		printf("\n二叉搜索树总菜单\n");
		printf("1.初始化二叉树\n");
		printf("2.搜索\n");
		printf("3.增加\n");
		printf("4.删除\n");
		printf("5.遍历\n");
		printf("6.退出程序\n");
		printf("请输入选项标号：");
		scanf("%c", &main_choice);
		getchar();
		system("cls");
		switch (main_choice)
		{
		case '1':
			if (Tree->root != NULL)
			{
				printf("树已建立   ");
				system("pause");
				system("cls");
				break;
			}
			printf("请输入想要排列的数组（拿什么隔开都行）\n");
			fgets(num_c, sizeof(num_c), stdin);
			system("cls");
			size = getNum(arr, num_c);
			Tree->root=sortedArrayToBST(arr, 0, size - 1);
			printf("初始化完成！");
			system("pause");
			system("cls");
			break;
		case '2':
			if (Tree->root == NULL)
			{
				printf("树未建立   ");
				system("pause");
				system("cls");
				break;
			}
			printf("请输入查询的数：");
			scanf("%d", &n);
			getchar();
			findBST(Tree, n);
			break;
		case '3':
			if (Tree->root == NULL)
			{
				printf("树未建立   ");
				system("pause");
				system("cls");
				break;
			}
			printf("请输入插入的数：");
			scanf("%d", &n);
			getchar();
			insetTree(Tree, n);
			break;
		case '4':
			if (Tree->root == NULL)
			{
				printf("树未建立   ");
				system("pause");
				system("cls");
				break;
			}
			printf("请输入删除的数：");
			scanf("%d", &n);
			getchar();
			delTree(Tree, n);
			break;
		case '5':
			if (Tree->root == NULL)
			{
				printf("树未建立   ");
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