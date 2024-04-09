#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


typedef struct Node 
{
    int value;
    struct Node* left, * right;
}Node, * NodePtr;

typedef struct BinarySortTree 
{
    NodePtr root;
} BinarySortTree, * BinarySortTreePtr;

int getNum(int* arr, char* num_c);
NodePtr createNode(int value);
NodePtr sortedArrayToBST(int* arr, int start, int end);
void findBST(BinarySortTreePtr Tree, int aim_num);
void insetTree(BinarySortTreePtr Tree, int num);
void delTree(BinarySortTreePtr Tree, int aim_num);

void preorderTree0(NodePtr root);
void inorderTree0(NodePtr root);
void postorderTree0(NodePtr root);

void preorderTree1(NodePtr root);
void inorderTree1(NodePtr root);
void postorderTree1(NodePtr root);


typedef struct QueueNode 
{
    Node* data;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue 
{
    QueueNode* front;
    QueueNode* rear;
} Queue;
void enqueue(Queue* queue, Node* data);
Node* dequeue(Queue* queue);
void levelTree(NodePtr root);


void TreeTravel(BinarySortTreePtr Tree);