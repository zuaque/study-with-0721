#include <stdio.h>
#include <stdlib.h>

typedef struct linknode1//������ṹ��
{
    int date;
    struct linknode1* next;
} linknode1;

linknode1* Createlinknode1(linknode1* head,int a);//���쵥����
void DelNode(linknode1* head,int* n,int del_num);//ɾ��
void Insetnode(linknode1* head, int* n, int inset_num, int new_date);//����
void Destory(linknode1* head);//����
int FindDate(linknode1* head, int* arr, int find_date, int num);//����
void displaynode1(linknode1* head, int num);//չʾ
void LinkNode1Menu();//�ֲ˵�


typedef struct linknode2//˫������ṹ��
{
    int date;
    struct linknode2* prev;
    struct linknode2* next;
} linknode2;

linknode2* Createlinknode2(linknode2* head, int a);//����
void DelNode2(linknode2* head, int* n, int del_num);//ɾ��
void Insetnode2(linknode2* head, int* n, int inset_num, int new_date);//����
void Destory2(linknode2* head);//����
int FindDate2(linknode2* head, int* arr, int find_date, int num);//����
void displaynode2(linknode2* head, int num);//չʾ
void LinkNode2Menu();//�ֲ˵�
//����������������������Ϊ��������Ҫ����������Ϊѡ����Ҫ��������������������������������

void SwapOddEven();//��żת��


void findMiddleNode();//�����нڵ�


int hasCircle();//�Ƿ�ɻ�


//��ת
linknode1* reverse1(linknode1* head);//�ݹ�
linknode1* reverse2(linknode1* head);//����
void ReverseMenu();//�ֲ˵�
void new_displaynode1(linknode1* head, int num);//��չʾ�������п�ֵ��ͷ�ڵ㣬��ת��β�ڵ�����ֵ��