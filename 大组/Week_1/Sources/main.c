#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"LinkList.h"


int main()
{
	
	int main_choice=0;
	while (main_choice != 7)
	{
		printf("\n�����ܲ˵�\n");
		printf("1.������ADT\n");
		printf("2.˫������ADT\n");
		printf("3.��������żת��\n");
		printf("4.�ҵ��������е�\n");
		printf("5.�ж������Ƿ�ɻ�\n");
		printf("6.��ת����\n");
		printf("7.�˳�����\n");
		printf("������ѡ���ţ�");
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