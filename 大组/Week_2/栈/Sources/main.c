#define _CRT_SECURE_NO_WARNINGS

#include"..\Headers\Stack.h"

int main()
{
	int i=0;
	char expression[100];
	int main_choice = 0;
	while (main_choice != 3)
	{
		printf("\n栈和队列\n");
		printf("1.栈的基本操作\n");
		printf("2.四则运算表达式求值\n");
		printf("3.退出程序\n");
		printf("请输入选项标号：");
		scanf("%d", &main_choice);
		getchar();
		system("cls");
		switch (main_choice)
		{
		case 1:
			StackMenu();
			system("cls");
			break;
		case 2:
			while (1)
			{
				printf("输入中缀表达式: ");
				fgets(expression, sizeof(expression), stdin);
				int i = check(expression);
				if (i)
				{
					char postfix[100];
					infixToPostfix(expression, postfix);
					printf("转换成后缀表达式为: %s\n", postfix);

					float result = evaluatePostfix(postfix);
					printf("结果: %.2f\n", result);
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("表达式有误\n");
					system("pause");
					system("cls");
					continue;
				}
			}
			break;
		default:
			continue;
		}


	}
    
    return 0;
}