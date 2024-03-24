#include"..\Headers\Lqueue.h"


int main()
{
    LQueue Q;
    char elem[100];
    Q.front = NULL;
    Q.rear = NULL;
    Q.length = 0;
    int choice = 1;//ѡ�����
    int t = 0;
    while (choice != 9)
    {
        printf("\n���в˵�:\n ");
        printf("1. ��ʼ������\n");
        printf("2. ����\n");
        printf("3. ����\n");
        printf("4. ���ض�ͷԪ��\n");
        printf("5. ��ն���\n");
        printf("6. ���ٶ���\n");
        printf("7. �����п�\n");
        printf("8.��ȡ���г���\n");
        printf("9. �˳�����\n");
        if (Q.front != NULL)
        {
            TraverseLQueue(&Q);
        }
        printf("������ѡ���ţ�");
        scanf("%d", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case 1:
            InitLQueue(&Q);
            system("cls");
            break;
        case 2:
            printf("�������洢��Ԫ�� ");
            gets(elem, sizeof(elem), stdin);
            EnLQueue(&Q,elem);
            system("cls");
            break;
        case 3:
            t = DeLQueue(&Q);
            system("cls");
            break;
        case 4:
            t = GetHeadLQueue(&Q);
            system("pause");
            system("cls");
            break;
        case 5:
            ClearLQueue(&Q);
            system("cls");
            break;
        case 6:
            DestoryLQueue(&Q);
            system("cls");
            break;
        case 7:
            t = IsEmptyLQueue(&Q);
            if (t)
            {
                printf("����Ϊ��   ");
            }
            else
            {
                printf("���в�Ϊ��   ");
            }
            system("pause");
            system("cls");
            break;
        case 8:
            t = LengthLQueue(&Q);
            printf("���г���Ϊ%d\n", t);
            system("pause");
            system("cls");
            break;
        default:
            continue;
        }
    }

}
