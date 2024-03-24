#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\Stack.h"

void initStack(LinkStack* stack, int sizes)
{
    // 设置栈容量
    stack->count = sizes;

    // 如果栈容量为0，则置顶指针为空
    if (stack->count == 0)
    {
        stack->top = NULL;
    }
    else
    {
        // 否则，依次创建节点并赋值数据
        int i = sizes;
        int n;
        while (i--)
        {
            StackNode* newnode = (StackNode*)malloc(sizeof(StackNode)); // 创建新节点
            if (newnode == NULL)
            {
                printf("开辟失败！.\n"); // 内存分配失败
                exit(EXIT_FAILURE); // 退出程序
            }
            printf("请输入%d节点的数据：", i + 1);
            scanf("%d", &n); // 输入数据
            getchar();
            newnode->data.integerData = n; // 赋值数据
            newnode->next = stack->top; // 新节点指向栈顶
            stack->top = newnode; // 栈顶指针更新为新节点
            system("cls"); // 清空屏幕
        }
    }
}

// 入栈操作
void pushStack(LinkStack* stack, int new_data)
{
    StackNode* newnode = (StackNode*)malloc(sizeof(StackNode)); // 创建新节点
    if (newnode == NULL)
    {
        printf("开辟失败！.\n"); // 内存分配失败
        exit(EXIT_FAILURE); // 退出程序
    }
    newnode->data.integerData = new_data; // 赋值数据
    newnode->next = stack->top; // 新节点指向栈顶
    stack->top = newnode; // 栈顶指针更新为新节点
    stack->count++; // 栈元素个数加1
}

// 出栈操作
int popStack(LinkStack* stack)
{
    StackNode* temp = stack->top; // 临时指针指向栈顶节点
    int pop_date = stack->top->data.integerData; // 获取栈顶节点的数据
    stack->top = stack->top->next; // 栈顶指针指向下一个节点
    free(temp); // 释放原栈顶节点内存
    stack->count--; // 栈元素个数减1
    return pop_date; // 返回出栈的数据
}

// 清空栈
void clearStack(LinkStack* stack, int clearNum)
{
    // 循环清空指定数量的节点
    while (clearNum--)
    {
        StackNode* temp = stack->top; // 临时指针指向栈顶节点
        stack->top = stack->top->next; // 栈顶指针指向下一个节点
        free(temp); // 释放原栈顶节点内存
    }
}

// 销毁栈
void destoryStack(LinkStack* stack)
{
    // 循环释放栈中所有节点的内存
    while (stack->top != NULL)
    {
        StackNode* temp = stack->top; // 临时指针指向栈顶节点
        stack->top = stack->top->next; // 栈顶指针指向下一个节点
        free(temp); // 释放原栈顶节点内存
    }
}

// 显示栈中的元素
void displayStack(LinkStack* stack)
{
    StackNode* temp = stack->top; // 临时指针指向栈顶节点
    printf("当前栈为： ");
    while (1)
    {
        if (temp == NULL) // 如果遍历到尾节点
        {
            printf("NULL");
            printf("\n");
            break;
        }
        printf("%d -> ", temp->data.integerData); // 打印节点数据
        temp = temp->next; // 移动到下一个节点
    }
}
