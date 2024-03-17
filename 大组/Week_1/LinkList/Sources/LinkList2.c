#define _CRT_SECURE_NO_WARNINGS
#include"..\Headers\LinkList.h"

linknode2* Createlinknode2(linknode2* head, int a)
{
    linknode2* new_node = (linknode2*)malloc(sizeof(linknode2));//开辟新节点
    //如果开辟失败，出错处理
    if (new_node == NULL)
    {
        printf("开辟失败！.\n");
        exit(EXIT_FAILURE);
    }
    new_node->date = a;//赋值数据
    new_node->next = NULL;
    linknode2* temp = head;//开始遍历
    if (head->next == NULL)
    {
        head->next = new_node;
        new_node->prev = head;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;//遍历到下一个节点
        }
        temp->next = new_node;//将新增节点接上链表
        new_node->prev = temp;
    }
    return head;//返回头节点
}


void DelNode2(linknode2* head, int* n, int del_num)
{
    linknode2* current = head->next;//指向头节点下一节点
    linknode2* p = head;//指向当前节点的前一个节点
    int m = 1;//计数
    while (del_num != m)
    {
        p = current;
        m++;
        current = current->next;
    }//遍历到需要删除的节点
    linknode2* temp = current->next;
    p->next = current->next;//删除节点
    temp->prev = p;
    free(current);//释放内存
    *n -= 1;//节点数减一
}

void Insetnode2(linknode2* head, int* n, int inset_num, int new_date)
{
    linknode2* new_node = (linknode2*)malloc(sizeof(linknode2));//开辟新节点
    new_node->date = new_date;//赋值
    linknode2* current = head->next;//开始遍历
    int m = 1;//计数
    while (inset_num != m)
    {
        m++;
        current = current->next;
    }//遍历到添加的位置
    if (current->next != NULL)
    {
        linknode2* temp = current->next;
        temp->prev = new_node;
    }
    new_node->next = current->next;//新节点接上插入位置后的链表
    current->next = new_node;
    new_node->prev = current;//插入位置前的链表接上新节点
    *n += 1;//节点数加一
}

void Destory2(linknode2* head)
{
    linknode2* current = head->next;//开始遍历
    linknode2* p = current->next;//保留当前节点的后续节点位置
    while (p != NULL)
    {
        free(current);//释放内存
        current = p;//向后遍历
        p = current->next;
    }
}

int FindDate2(linknode2* head, int* arr, int find_date, int num)
{
    linknode2* current = head->next;//开始遍历
    int find_num = 1;//当前节点标号
    int n = 0;//数组计数器
    int total_num = 0;//总共查找到的数量
    while (find_num <= num)
    {
        if (current->date == find_date)//如果找到记录位置信息
        {
            arr[n++] = find_num;
            total_num++;
        }
        current = current->next;//遍历到下一个节点
        find_num++;
    }
    return total_num;
}

void displaynode2(linknode2* head, int num)//展示目前链表情况
{
    int current = 1;//当前节点标号
    linknode2* temp = head->next;//开始遍历
    printf("当前链表为： ");
    while (1)
    {
        if (current == num)//如果到尾节点
        {
            printf("%d", temp->date);
            printf("\n");
            break;
        }
        printf("%d <--> ", temp->date);
        temp = temp->next;
        current++;
    }
}