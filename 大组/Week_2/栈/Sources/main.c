#define _CRT_SECURE_NO_WARNINGS

#include"..\Headers\Stack.h"

int main()
{
	int i=0;
	char expression[100];
	int main_choice = 0;
	while (main_choice != 3)
	{
		printf("\nջ�Ͷ���\n");
		printf("1.ջ�Ļ�������\n");
		printf("2.����������ʽ��ֵ\n");
		printf("3.�˳�����\n");
		printf("������ѡ���ţ�");
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
				printf("������׺���ʽ: ");
				fgets(expression, sizeof(expression), stdin);
				int i = check(expression);
				if (i)
				{
					char postfix[100];
					infixToPostfix(expression, postfix);
					printf("ת���ɺ�׺���ʽΪ: %s\n", postfix);

					float result = evaluatePostfix(postfix);
					printf("���: %.2f\n", result);
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("���ʽ����\n");
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