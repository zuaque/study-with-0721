#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\Stack.h"



int check(char* expression) //检查表达式是否有误
{
    int n = 0;//括号匹配数
    int num = 0;//数字
    int symbal = 0;//符号
    int i = 0;

    while (expression[i] != '\0') 
    {
        if (isdigit(expression[i])) 
        {
            // 数字作为操作数
            num++;
            // 跳过整个数字
            while (isdigit(expression[i]) || expression[i] == '.') 
            {
                i++;
            }
        }
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') 
        {
            // 运算符
            symbal++;
            i++;
        }
        else if (expression[i] == '(') 
        {
            // 左括号
            n++;
            i++;
        }
        else if (expression[i] == ')') 
        {
            // 右括号
            n--;
            if (n < 0) 
            {
                // 右括号数量大于左括号数量
                return 0;
            }
            i++;
        }
        else if (expression[i] == ' ' || expression[i] == '\n') 
        {
            // 跳过空格、换行
            i++;
        }
        else 
        {
            // 非法字符
            return 0;
        }
    }

    if (num <= symbal || n != 0) 
    {
        // 操作数少于运算符或左括号数量大于右括号数量
        return 0;
    }

    // 最后一个字符不能是运算符或左括号
    if (expression[i - 1] == '+' || expression[i - 1] == '-' || expression[i - 1] == '*' || expression[i - 1] == '/' || expression[i - 1] == '(') 
    {
        return 0;
    }

    return 1;
}



// 获取运算符优先级
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

// 将中缀表达式转换为后缀表达式
void infixToPostfix(char* expression, char* postfix)
{
    LinkStack stack;
    stack.top = NULL;
    stack.count = 0;
    int i = 0, j = 0;

    while (expression[i] != '\0')
    {
        // 如果当前字符是数字，或者当前字符是负号且位于表达式开头或左括号后面
        if (isdigit(expression[i]) || (expression[i] == '-' && (i == 0 || expression[i - 1] == '(')))
        {
            // 将数字或负号添加到后缀表达式中
            postfix[j++] = expression[i++];
            // 处理数字的其余部分（包括小数点）
            while (isdigit(expression[i]) || expression[i] == '.')
            {
                postfix[j++] = expression[i++];
            }
            // 在数字或负号之后添加空格
            postfix[j++] = ' ';
        }
        // 如果当前字符是左括号，将其入栈
        else if (expression[i] == '(')
        {
            StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
            newNode->data.charData = '(';
            newNode->next = stack.top;
            stack.top = newNode;
            stack.count++;
            i++;
        }
        // 如果当前字符是右括号
        else if (expression[i] == ')')
        {
            // 将栈顶元素弹出，直到遇到左括号
            while (stack.top != NULL && stack.top->data.charData != '(')
            {
                postfix[j++] = stack.top->data.charData;
                postfix[j++] = ' ';
                LinkStackPtr temp = stack.top;
                stack.top = stack.top->next;
                free(temp);
                stack.count--;
            }
            // 弹出左括号
            if (stack.top != NULL && stack.top->data.charData == '(')
            {
                LinkStackPtr temp = stack.top;
                stack.top = stack.top->next;
                free(temp);
                stack.count--;
            }
            i++;
        }
        // 如果当前字符是运算符
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
        {
            // 将栈顶优先级高于等于当前运算符的运算符弹出，直到栈为空或遇到左括号
            while (stack.top != NULL && priority(stack.top->data.charData) >= priority(expression[i]))
            {
                postfix[j++] = stack.top->data.charData;
                postfix[j++] = ' ';
                LinkStackPtr temp = stack.top;
                stack.top = stack.top->next;
                free(temp);
                stack.count--;
            }
            // 将当前运算符入栈
            StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
            newNode->data.charData = expression[i];
            newNode->next = stack.top;
            stack.top = newNode;
            stack.count++;
            i++;
        }
        // 如果当前字符是空格，直接跳过
        else
        {
            i++;
        }
    }

    // 将栈中剩余的运算符依次弹出，加入到后缀表达式中
    while (stack.top != NULL)
    {
        postfix[j++] = stack.top->data.charData;
        postfix[j++] = ' ';
        LinkStackPtr temp = stack.top;
        stack.top = stack.top->next;
        free(temp);
        stack.count--;
    }
    // 在后缀表达式末尾添加结束符
    postfix[j] = '\0';
}


// 求值后缀表达式
// 从后缀表达式中计算结果
float evaluatePostfix(char* postfix)
{
    LinkStack stack;
    stack.top = NULL;
    stack.count = 0;
    int i = 0;
    float m, n;

    // 遍历后缀表达式
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i]) || (postfix[i] == '-' && isdigit(postfix[i + 1])))
        {
            // 处理数字（包括正数和负数）
            if (isdigit(postfix[i]))
            {
                // 如果是正数，直接读取数字
                char numStr[20];
                int k = 0;
                while (isdigit(postfix[i]) || postfix[i] == '.')
                {
                    numStr[k++] = postfix[i++];
                }
                numStr[k] = '\0';
                float num = atof(numStr); // 将字符转换为浮点数
                StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
                newNode->data.floatData = num;
                newNode->next = stack.top;
                stack.top = newNode;
                stack.count++;
            }
            else
            {
                // 如果是负数，跳过负号，然后读取数字
                char numStr[20];
                int k = 0;
                i += 1;
                while (isdigit(postfix[i]) || postfix[i] == '.')
                {
                    numStr[k++] = postfix[i++];
                }
                numStr[k] = '\0';
                float num = 0 - atof(numStr); // 将字符转换为浮点数
                StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
                newNode->data.floatData = num;
                newNode->next = stack.top;
                stack.top = newNode;
                stack.count++;
            }
        }
        else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
        {
            // 处理运算符
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
            // 根据运算符进行计算
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
            // 将计算结果入栈
            StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
            newNode->data.floatData = result;
            newNode->next = stack.top;
            stack.top = newNode;
            stack.count++;
            i++;
        }
        else
        {
            // 忽略空格
            i++;
        }
    }
    // 获取最终结果
    float finalResult = stack.top->data.floatData;
    StackNode* temp = stack.top;
    stack.top = stack.top->next;
    free(temp);
    stack.count--;
    return finalResult;
}