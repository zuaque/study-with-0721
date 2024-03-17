#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\LinkList.h"

linknode1* reverse1(linknode1* head) 
{
    if (head == NULL || head->next == NULL)
        return head;//如果仅有头节点或只有一个节点直接返回head

    linknode1* new_head = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

linknode1* reverse2(linknode1* head)
{
    linknode1* prev = NULL;
    linknode1* current = head;
    linknode1* next = NULL;

    while (current != NULL) {
        next = current->next; // 保存下一个节点
        current->next = prev; // 当前节点的 next 指针指向前一个节点
        prev = current; // 更新前一个节点为当前节点
        current = next; // 更新当前节点为下一个节点
    }

    // 当 current 为 NULL 时，prev 即为反转后的头节点
    return prev;
}

void new_displaynode1(linknode1* head, int num)//展示目前链表情况
{
    int current = 1;
    linknode1* temp = head;
    printf("当前链表为： ");
    while (1)
    {
        if (current == num)//如果遍历到尾节点
        {
            printf("%d", temp->date);
            printf("\n");
            break;
        }
        printf("%d -> ", temp->date);
        temp = temp->next;
        current++;
    }
}