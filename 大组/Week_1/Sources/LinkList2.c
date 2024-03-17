#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\LinkList.h"

linknode2* Createlinknode2(linknode2* head, int a)
{
    linknode2* new_node = (linknode2*)malloc(sizeof(linknode2));//�����½ڵ�
    //�������ʧ�ܣ�������
    if (new_node == NULL)
    {
        printf("����ʧ�ܣ�.\n");
        exit(EXIT_FAILURE);
    }
    new_node->date = a;//��ֵ����
    new_node->next = NULL;
    linknode2* temp = head;//��ʼ����
    if (head->next == NULL)
    {
        head->next = new_node;
        new_node->prev = head;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;//��������һ���ڵ�
        }
        temp->next = new_node;//�������ڵ��������
        new_node->prev = temp;
    }
    return head;//����ͷ�ڵ�
}


void DelNode2(linknode2* head, int* n, int del_num)
{
    linknode2* current = head->next;//ָ��ͷ�ڵ���һ�ڵ�
    linknode2* p = head;//ָ��ǰ�ڵ��ǰһ���ڵ�
    int m = 1;//����
    while (del_num != m)
    {
        p = current;
        m++;
        current = current->next;
    }//��������Ҫɾ���Ľڵ�
    linknode2* temp = current->next;
    p->next = current->next;//ɾ���ڵ�
    temp->prev = p;
    free(current);//�ͷ��ڴ�
    *n -= 1;//�ڵ�����һ
}

void Insetnode2(linknode2* head, int* n, int inset_num, int new_date)
{
    linknode2* new_node = (linknode2*)malloc(sizeof(linknode2));//�����½ڵ�
    new_node->date = new_date;//��ֵ
    linknode2* current = head->next;//��ʼ����
    int m = 1;//����
    while (inset_num != m)
    {
        m++;
        current = current->next;
    }//��������ӵ�λ��
    if (current->next != NULL)
    {
        linknode2* temp = current->next;
        temp->prev = new_node;
    }
    new_node->next = current->next;//�½ڵ���ϲ���λ�ú������
    current->next = new_node;
    new_node->prev = current;//����λ��ǰ����������½ڵ�
    *n += 1;//�ڵ�����һ
}

void Destory2(linknode2* head)
{
    linknode2* current = head->next;//��ʼ����
    linknode2* p = current->next;//������ǰ�ڵ�ĺ����ڵ�λ��
    while (p != NULL)
    {
        free(current);//�ͷ��ڴ�
        current = p;//������
        p = current->next;
    }
}

int FindDate2(linknode2* head, int* arr, int find_date, int num)
{
    linknode2* current = head->next;//��ʼ����
    int find_num = 1;//��ǰ�ڵ���
    int n = 0;//���������
    int total_num = 0;//�ܹ����ҵ�������
    while (find_num <= num)
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

void displaynode2(linknode2* head, int num)//չʾĿǰ�������
{
    int current = 1;//��ǰ�ڵ���
    linknode2* temp = head->next;//��ʼ����
    printf("��ǰ����Ϊ�� ");
    while (1)
    {
        if (current == num)//�����β�ڵ�
        {
            printf("%d", temp->date);
            printf("\n");
            break;
        }
        printf("%d <--> ", temp->date);
        temp = temp->next;
        current++;
    }
}