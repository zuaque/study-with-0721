#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\LinkList.h"


void SwapOddEven()
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
    int current = 1;//��ǰ�ڵ���
    linknode1* temp2 = head->next;//��ʼ����
    printf("input�� ");
    while (1)
    {
        if (current == num)//�����β�ڵ�
        {
            printf("%d", temp2->date);
            printf("\n");
            break;
        }
        printf("%d -> ", temp2->date);
        temp2 = temp2->next;
        current++;
    }
    linknode1* h = head;//������һ�Խڵ��ǰһ���ڵ�
    linknode1* p = head->next;//�����ڵ�
    linknode1* q = p->next;//ż���ڵ�
    while (q != NULL && p != NULL)
    {
        linknode1* link_temp = q->next;//���潻���ڵ����Ľڵ��ַ
        h->next = q;//��ʼ����
        q->next = p;
        p->next = link_temp;
        h = p;//��ʱp��q��λ�÷�������
        p = h->next;
        if (p != NULL)
            q = p->next;
    }
    current = 1;//��ǰ�ڵ���
    temp2 = head->next;//��ʼ����
    printf("output�� ");
    while (1)
    {
        if (current == num)//�����β�ڵ�
        {
            printf("%d", temp2->date);
            printf("\n");
            break;
        }
        printf("%d -> ", temp2->date);
        temp2 = temp2->next;
        current++;
    }
    system("pause");
    system("cls");
}