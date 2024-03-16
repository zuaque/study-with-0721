#define _CRT_SECURE_NO_WARNINGS
#include"LinkList.h"

linknode1* Createlinknode1(linknode1* head,int a)
{
    linknode1* new_node = (linknode1*)malloc(sizeof(linknode1));//�����½ڵ�
    //�������ʧ�ܣ�������
    if (new_node == NULL)
    {
        printf("����ʧ�ܣ�.\n");
        exit(EXIT_FAILURE);
    }
    new_node->date = a;//��ֵ����
    new_node->next = NULL;
    linknode1* temp = head;//��ʼ����
    if (head->next == NULL)
    {
        head->next = new_node;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;//��������һ���ڵ�
        }
        temp->next = new_node;//�������ڵ��������
    }
    return head;//����ͷ�ڵ�
}

void DelNode(linknode1* head,int *n,int del_num)
{
    linknode1* current = head->next;//ָ��ͷ�ڵ���һ�ڵ�
    linknode1* p=head;//ָ��ǰ�ڵ��ǰһ���ڵ�
    int m = 1;//����
    while (del_num != m)
    {
        p = current;
        m++;
        current = current->next;
    }//��������Ҫɾ���Ľڵ�
    p->next = current->next;//ɾ���ڵ�
    free(current);//�ͷ��ڴ�
    *n-=1;//�ڵ�����һ
}

void Insetnode(linknode1* head,int *n,int inset_num,int new_date)
{
    linknode1* new_node = (linknode1*)malloc(sizeof(linknode1));//�����½ڵ�
    new_node->date = new_date;//��ֵ
    linknode1* current = head->next;//��ʼ����
    int m = 1;//����
    while (inset_num != m)
    {
        m++;
        current = current->next;
    }//��������ӵ�λ��
    new_node->next = current->next;//�½ڵ���ϲ���λ�ú������
    current->next = new_node;//����λ��ǰ����������½ڵ�
    *n+=1;//�ڵ�����һ
}

void Destory(linknode1* head)
{
    linknode1* current = head->next;//��ʼ����
    linknode1* p = current->next;//������ǰ�ڵ�ĺ����ڵ�λ��
    while (p != NULL)
    {
        free(current);//�ͷ��ڴ�
        current = p;//������
        p = current->next;
    }
}

int FindDate(linknode1* head, int* arr,int find_date,int num)
{
    linknode1* current = head->next;//��ʼ����
    int find_num=1;
    int n = 0;
    int total_num = 0;
    while (find_num<=num)
    {
        if (current->date == find_date)//����ҵ���¼λ����Ϣ
        {
            arr[n++] = find_num;
            total_num++;
        }
        current = current->next;//��������һ���ڵ�
        find_num++;
    }
    return total_num;
}

void displaynode1(linknode1* head,int num)//չʾĿǰ�������
{
    int current=1;
    linknode1* temp = head->next;
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