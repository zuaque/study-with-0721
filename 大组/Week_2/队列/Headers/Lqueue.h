#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


 //链式队列结构
typedef struct node
{
    void* data;//数据域指针
    char type;
    struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node* front;                   //队头
    Node* rear;                    //队尾
    size_t length;            //队列长度
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