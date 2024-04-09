#include"..\Headers\BST.h"

void TreeTravel(BinarySortTreePtr Tree)
{
    char choice='0';
    while (choice-'0' != 8)
    {
        printf("1.ǰ�����(�ݹ�)\n");
        printf("2.�������(�ݹ�)\n");
        printf("3.��������(�ݹ�)\n");
        printf("4.ǰ������(�ǵݹ�)\n");
        printf("5.��������(�ǵݹ�)\n");
        printf("6.��������(�ǵݹ�)\n");
        printf("7.�������\n");
        printf("8.����\n");
        printf("������ѡ���ţ�");
        scanf("%c", &choice);
        getchar();
        system("cls");
        switch (choice)
        {
        case '1':
            preorderTree0(Tree->root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '2':
            inorderTree0(Tree->root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '3':
            postorderTree0(Tree->root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '4':
            preorderTree1(Tree->root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '5':
            inorderTree1(Tree->root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '6':
            postorderTree1(Tree->root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case '7':
            levelTree(Tree->root);
            printf("\n");
            system("pause");
            system("cls");
            break;
        }
    }
}