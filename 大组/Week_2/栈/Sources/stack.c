#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\Stack.h"

void initStack(LinkStack* stack, int sizes)
{
    // ����ջ����
    stack->count = sizes;

    // ���ջ����Ϊ0�����ö�ָ��Ϊ��
    if (stack->count == 0)
    {
        stack->top = NULL;
    }
    else
    {
        // �������δ����ڵ㲢��ֵ����
        int i = sizes;
        int n;
        while (i--)
        {
            StackNode* newnode = (StackNode*)malloc(sizeof(StackNode)); // �����½ڵ�
            if (newnode == NULL)
            {
                printf("����ʧ�ܣ�.\n"); // �ڴ����ʧ��
                exit(EXIT_FAILURE); // �˳�����
            }
            printf("������%d�ڵ�����ݣ�", i + 1);
            scanf("%d", &n); // ��������
            getchar();
            newnode->data.integerData = n; // ��ֵ����
            newnode->next = stack->top; // �½ڵ�ָ��ջ��
            stack->top = newnode; // ջ��ָ�����Ϊ�½ڵ�
            system("cls"); // �����Ļ
        }
    }
}

// ��ջ����
void pushStack(LinkStack* stack, int new_data)
{
    StackNode* newnode = (StackNode*)malloc(sizeof(StackNode)); // �����½ڵ�
    if (newnode == NULL)
    {
        printf("����ʧ�ܣ�.\n"); // �ڴ����ʧ��
        exit(EXIT_FAILURE); // �˳�����
    }
    newnode->data.integerData = new_data; // ��ֵ����
    newnode->next = stack->top; // �½ڵ�ָ��ջ��
    stack->top = newnode; // ջ��ָ�����Ϊ�½ڵ�
    stack->count++; // ջԪ�ظ�����1
}

// ��ջ����
int popStack(LinkStack* stack)
{
    StackNode* temp = stack->top; // ��ʱָ��ָ��ջ���ڵ�
    int pop_date = stack->top->data.integerData; // ��ȡջ���ڵ������
    stack->top = stack->top->next; // ջ��ָ��ָ����һ���ڵ�
    free(temp); // �ͷ�ԭջ���ڵ��ڴ�
    stack->count--; // ջԪ�ظ�����1
    return pop_date; // ���س�ջ������
}

// ���ջ
void clearStack(LinkStack* stack, int clearNum)
{
    // ѭ�����ָ�������Ľڵ�
    while (clearNum--)
    {
        StackNode* temp = stack->top; // ��ʱָ��ָ��ջ���ڵ�
        stack->top = stack->top->next; // ջ��ָ��ָ����һ���ڵ�
        free(temp); // �ͷ�ԭջ���ڵ��ڴ�
    }
}

// ����ջ
void destoryStack(LinkStack* stack)
{
    // ѭ���ͷ�ջ�����нڵ���ڴ�
    while (stack->top != NULL)
    {
        StackNode* temp = stack->top; // ��ʱָ��ָ��ջ���ڵ�
        stack->top = stack->top->next; // ջ��ָ��ָ����һ���ڵ�
        free(temp); // �ͷ�ԭջ���ڵ��ڴ�
    }
}

// ��ʾջ�е�Ԫ��
void displayStack(LinkStack* stack)
{
    StackNode* temp = stack->top; // ��ʱָ��ָ��ջ���ڵ�
    printf("��ǰջΪ�� ");
    while (1)
    {
        if (temp == NULL) // ���������β�ڵ�
        {
            printf("NULL");
            printf("\n");
            break;
        }
        printf("%d -> ", temp->data.integerData); // ��ӡ�ڵ�����
        temp = temp->next; // �ƶ�����һ���ڵ�
    }
}
