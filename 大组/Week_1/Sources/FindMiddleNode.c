#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\LinkList.h"

void findMiddleNode()
{
    int num = 0;
    linknode1* head = (linknode1*)malloc(sizeof(linknode1));//����ͷ�ڵ�
    if (head == NULL)
    {
        printf("����ʧ�ܣ�.\n");
        exit(EXIT_FAILURE);
    }
    head->next = NULL;
    printf("���봴������Ľڵ�����:");
    scanf("%d", &num);//��������ڵ�����
    getchar();
    system("cls");
    for (int i = 0; i < num; i++)//����ÿ���ڵ������
    {
        int temp;
        printf("����ڵ�%d�����ݣ�", i + 1);
        scanf("%d", &temp);
        getchar();
        head = Createlinknode1(head, temp);
        system("cls");
    }
    linknode1* fast = head->next;//��ָ��
    linknode1* slow = head->next;//��ָ��
    int f = 1;//��¼��ǰ�ڵ���
    while (fast != NULL&&fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        f++;
    }
    displaynode1(head, num);
    printf("�������е�Ϊ�ڵ�%d,��ֵΪ%d\n", f, slow->date);
    system("pause");
    system("cls");
}