#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\LinkList.h"

linknode1* reverse1(linknode1* head) 
{
    if (head == NULL || head->next == NULL)
        return head;//�������ͷ�ڵ��ֻ��һ���ڵ�ֱ�ӷ���head

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
        next = current->next; // ������һ���ڵ�
        current->next = prev; // ��ǰ�ڵ�� next ָ��ָ��ǰһ���ڵ�
        prev = current; // ����ǰһ���ڵ�Ϊ��ǰ�ڵ�
        current = next; // ���µ�ǰ�ڵ�Ϊ��һ���ڵ�
    }

    // �� current Ϊ NULL ʱ��prev ��Ϊ��ת���ͷ�ڵ�
    return prev;
}

void new_displaynode1(linknode1* head, int num)//չʾĿǰ�������
{
    int current = 1;
    linknode1* temp = head;
    printf("��ǰ����Ϊ�� ");
    while (1)
    {
        if (current == num)//���������β�ڵ�
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