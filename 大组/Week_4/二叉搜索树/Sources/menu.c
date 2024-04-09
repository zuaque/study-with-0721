#include"..\Headers\BST.h"

void TreeTravel(BinarySortTreePtr Tree)
{
    char choice='0';
    while (choice-'0' != 8)
    {
        printf("1.前序遍历(递归)\n");
        printf("2.中序遍历(递归)\n");
        printf("3.后序排列(递归)\n");
        printf("4.前序排列(非递归)\n");
        printf("5.中序排列(非递归)\n");
        printf("6.后序排列(非递归)\n");
        printf("7.层次排列\n");
        printf("8.返回\n");
        printf("请输入选项标号：");
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