#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\Stack.h"



int check(char* expression) //�����ʽ�Ƿ�����
{
    int n = 0;//����ƥ����
    int num = 0;//����
    int symbal = 0;//����
    int i = 0;

    while (expression[i] != '\0') 
    {
        if (isdigit(expression[i])) 
        {
            // ������Ϊ������
            num++;
            // ������������
            while (isdigit(expression[i]) || expression[i] == '.') 
            {
                i++;
            }
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') 
        {
            // �����
            symbal++;
            i++;
        }
        else if (expression[i] == '(') 
        {
            // ������
            n++;
            i++;
        }
        else if (expression[i] == ')') 
        {
            // ������
            n--;
            if (n < 0) 
            {
                // ������������������������
                return 0;
            }
            i++;
        }
        else if (expression[i] == ' ' || expression[i] == '\n') 
        {
            // �����ո񡢻���
            i++;
        }
        else 
        {
            // �Ƿ��ַ�
            return 0;
        }
    }

    if (num <= symbal || n != 0) 
    {
        // �����������������������������������������
        return 0;
    }

    // ���һ���ַ��������������������
    if (expression[i - 1] == '+' || expression[i - 1] == '-' || expression[i - 1] == '*' || expression[i - 1] == '/' || expression[i - 1] == '(') 
    {
        return 0;
    }

    return 1;
}



// ��ȡ��������ȼ�
int priority(char op) 
{
    if (op == '(')
        return 0;
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return -1;
}

// ����׺���ʽת��Ϊ��׺���ʽ
void infixToPostfix(char* expression, char* postfix)
{
    LinkStack stack;
    stack.top = NULL;
    stack.count = 0;
    int i = 0, j = 0;

    while (expression[i] != '\0')
    {
        // �����ǰ�ַ������֣����ߵ�ǰ�ַ��Ǹ�����λ�ڱ��ʽ��ͷ�������ź���
        if (isdigit(expression[i]) || (expression[i] == '-' && (i == 0 || expression[i - 1] == '(')))
        {
            // �����ֻ򸺺���ӵ���׺���ʽ��
            postfix[j++] = expression[i++];
            // �������ֵ����ಿ�֣�����С���㣩
            while (isdigit(expression[i]) || expression[i] == '.')
            {
                postfix[j++] = expression[i++];
            }
            // �����ֻ򸺺�֮����ӿո�
            postfix[j++] = ' ';
        }
        // �����ǰ�ַ��������ţ�������ջ
        else if (expression[i] == '(')
        {
            StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
            newNode->data.charData = '(';
            newNode->next = stack.top;
            stack.top = newNode;
            stack.count++;
            i++;
        }
        // �����ǰ�ַ���������
        else if (expression[i] == ')')
        {
            // ��ջ��Ԫ�ص�����ֱ������������
            while (stack.top != NULL && stack.top->data.charData != '(')
            {
                postfix[j++] = stack.top->data.charData;
                postfix[j++] = ' ';
                LinkStackPtr temp = stack.top;
                stack.top = stack.top->next;
                free(temp);
                stack.count--;
            }
            // ����������
            if (stack.top != NULL && stack.top->data.charData == '(')
            {
                LinkStackPtr temp = stack.top;
                stack.top = stack.top->next;
                free(temp);
                stack.count--;
            }
            i++;
        }
        // �����ǰ�ַ��������
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            // ��ջ�����ȼ����ڵ��ڵ�ǰ������������������ֱ��ջΪ�ջ�����������
            while (stack.top != NULL && priority(stack.top->data.charData) >= priority(expression[i]))
            {
                postfix[j++] = stack.top->data.charData;
                postfix[j++] = ' ';
                LinkStackPtr temp = stack.top;
                stack.top = stack.top->next;
                free(temp);
                stack.count--;
            }
            // ����ǰ�������ջ
            StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
            newNode->data.charData = expression[i];
            newNode->next = stack.top;
            stack.top = newNode;
            stack.count++;
            i++;
        }
        // �����ǰ�ַ��ǿո�ֱ������
        else
        {
            i++;
        }
    }

    // ��ջ��ʣ�����������ε��������뵽��׺���ʽ��
    while (stack.top != NULL)
    {
        postfix[j++] = stack.top->data.charData;
        postfix[j++] = ' ';
        LinkStackPtr temp = stack.top;
        stack.top = stack.top->next;
        free(temp);
        stack.count--;
    }
    // �ں�׺���ʽĩβ��ӽ�����
    postfix[j] = '\0';
}


// ��ֵ��׺���ʽ
// �Ӻ�׺���ʽ�м�����
float evaluatePostfix(char* postfix)
{
    LinkStack stack;
    stack.top = NULL;
    stack.count = 0;
    int i = 0;
    float m, n;

    // ������׺���ʽ
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i]) || (postfix[i] == '-' && isdigit(postfix[i + 1])))
        {
            // �������֣����������͸�����
            if (isdigit(postfix[i]))
            {
                // �����������ֱ�Ӷ�ȡ����
                char numStr[20];
                int k = 0;
                while (isdigit(postfix[i]) || postfix[i] == '.')
                {
                    numStr[k++] = postfix[i++];
                }
                numStr[k] = '\0';
                float num = atof(numStr); // ���ַ�ת��Ϊ������
                StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
                newNode->data.floatData = num;
                newNode->next = stack.top;
                stack.top = newNode;
                stack.count++;
            }
            else
            {
                // ����Ǹ������������ţ�Ȼ���ȡ����
                char numStr[20];
                int k = 0;
                i += 1;
                while (isdigit(postfix[i]) || postfix[i] == '.')
                {
                    numStr[k++] = postfix[i++];
                }
                numStr[k] = '\0';
                float num = 0 - atof(numStr); // ���ַ�ת��Ϊ������
                StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
                newNode->data.floatData = num;
                newNode->next = stack.top;
                stack.top = newNode;
                stack.count++;
            }
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            // ���������
            n = stack.top->data.floatData;
            StackNode* temp = stack.top;
            stack.top = stack.top->next;
            free(temp);
            stack.count--;
            m = stack.top->data.floatData;
            temp = stack.top;
            stack.top = stack.top->next;
            free(temp);
            stack.count--;

            float result;
            // ������������м���
            switch (postfix[i])
            {
            case '+':
                result = m + n;
                break;
            case '-':
                result = m - n;
                break;
            case '*':
                result = m * n;
                break;
            case '/':
                result = m / n;
                break;
            }
            // ����������ջ
            StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
            newNode->data.floatData = result;
            newNode->next = stack.top;
            stack.top = newNode;
            stack.count++;
            i++;
        }
        else
        {
            // ���Կո�
            i++;
        }
    }
    // ��ȡ���ս��
    float finalResult = stack.top->data.floatData;
    StackNode* temp = stack.top;
    stack.top = stack.top->next;
    free(temp);
    stack.count--;
    return finalResult;
}