#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef union
{
	int integerData;
	float floatData;
	char charData;

}ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;


void initStack(LinkStack* stack, int sizes);
void pushStack(LinkStack* stack, int new_data);
int popStack(LinkStack* stack);
void clearStack(LinkStack* stack, int clearNum);
void destoryStack(LinkStack* stack);
void displayStack(LinkStack* stack);
void StackMenu();

int check(char* expression);
int priority(char op);
void infixToPostfix(char* expression, char* postfix);
float evaluatePostfix(char* postfix);