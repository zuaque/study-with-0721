#include <stdio.h>
#include <stdlib.h>

typedef struct linknode1//单链表结构体
{
    int date;
    struct linknode1* next;
} linknode1;

linknode1* Createlinknode1(linknode1* head,int a);//创造单链表
void DelNode(linknode1* head,int* n,int del_num);//删除
void Insetnode(linknode1* head, int* n, int inset_num, int new_date);//插入
void Destory(linknode1* head);//销毁
int FindDate(linknode1* head, int* arr, int find_date, int num);//查找
void displaynode1(linknode1* head, int num);//展示
void LinkNode1Menu();//分菜单


typedef struct linknode2//双向链表结构体
{
    int date;
    struct linknode2* prev;
    struct linknode2* next;
} linknode2;

linknode2* Createlinknode2(linknode2* head, int a);//创建
void DelNode2(linknode2* head, int* n, int del_num);//删除
void Insetnode2(linknode2* head, int* n, int inset_num, int new_date);//插入
void Destory2(linknode2* head);//销毁
int FindDate2(linknode2* head, int* arr, int find_date, int num);//查找
void displaynode2(linknode2* head, int num);//展示
void LinkNode2Menu();//分菜单
//—————————以上为必做题主要函数，以下为选做主要函数——————————————

void SwapOddEven();//奇偶转换


void findMiddleNode();//查找中节点


int hasCircle();//是否成环


//逆转
linknode1* reverse1(linknode1* head);//递归
linknode1* reverse2(linknode1* head);//迭代
void ReverseMenu();//分菜单
void new_displaynode1(linknode1* head, int num);//新展示（由于有空值的头节点，逆转后尾节点无数值）