#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


 //��ʽ���нṹ
typedef struct node
{
    void* data;//������ָ��
    char type;
    struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node* front;                   //��ͷ
    Node* rear;                    //��β
    size_t length;            //���г���
} LQueue;

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;


int classElem(char* m);


void InitLQueue(LQueue* Q);


void DestoryLQueue(LQueue* Q);


Status IsEmptyLQueue(LQueue* Q);


Status GetHeadLQueue(LQueue* Q);


int LengthLQueue(LQueue* Q);


void EnLQueue(LQueue* Q,char* elem);


Status DeLQueue(LQueue* Q);


void ClearLQueue(LQueue* Q);


void TraverseLQueue(LQueue* Q);




#endif 