#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\LinkList.h"
#include<time.h>//����ʱ��

int hasCircle()
{
    printf("������������и��ʳɻ�\n");
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
    srand(time(NULL));//����ʱ������
    int linkc = rand() % (2*num + 1);//����ϵͳʱ������α���������ΧΪ0~2*num
    if(linkc <= num)//���������0~num�䣬�������������Ӧ�Ľڵ����ɻ�����֮�򲻳ɻ�
    {
        linknode1* temp = head->next;
        while (temp->next != NULL)//������β�ڵ�
        {
            temp = temp->next;
        }
        linknode1* cirnode = head;
        for (int i = 0; i < linkc; i++)//���������ӽڵ�
        {
            cirnode = cirnode->next;
        }
        temp->next = cirnode;
    }
    linknode1* fast = head;//��ָ��
    linknode1* slow = head;//��ָ��
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;//������
        slow = slow->next;//��һ��
        if (fast == slow)//���������˵���ɻ�
        {
            if (linkc == 0)
            {
                printf("������ɻ���β�ڵ���ͷ�ڵ�����\n");
            }
            else
            {
                printf("������ɻ���β�ڵ���ڵ�%d����\n", linkc);
            }
            system("pause");
            return 0;
        }
    }
    printf("�������ɻ�\n");
    system("pause");
    system("cls");
    return 0;
}
