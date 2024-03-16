#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"


int main()
{
	
	int main_choice=0;
	while (main_choice != 7)
	{
		printf("\n链表总菜单\n");
		printf("1.单链表ADT\n");
		printf("2.双向链表ADT\n");
		printf("3.单链表奇偶转换\n");
		printf("4.找到单链表中点\n");
		printf("5.判断链表是否成环\n");
		printf("6.反转链表\n");
		printf("7.退出程序\n");
		printf("请输入选项标号：");
		scanf("%d", &main_choice);
		getchar();
		system("cls");
		switch (main_choice)
		{
		case 1:
			LinkNode1Menu();
			break;
		case 2:
			LinkNode2Menu();
			break;
		case 3:
			SwapOddEven();
			break;
		case 4:
			findMiddleNode();
			break;
		case 5:
			hasCircle();
			break;
		case 6:
			ReverseMenu();
			break;
		default:
			continue;
		}
		

	}
}