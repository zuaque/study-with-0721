#include"..\Headers\Lqueue.h"
#define _CRT_SECURE_NO_WARNINGS


void InitLQueue(LQueue* Q) 
{
	Q->front = NULL;  // 将队头指针置为空
	Q->rear = NULL;   // 将队尾指针置为空
	Q->length = 0;    // 将队列长度置为 0
}


void DestoryLQueue(LQueue* Q)
{
	while (Q->front != NULL)
	{
		Node* p = Q->front;
		Q->front = Q->front->next;
		if (Q->front == NULL)
			Q->rear = NULL;

		// 检查并释放节点数据所占用的内存
		if (p->data != NULL) 
		{
			free(p->data);
		}

		free(p);
		Q->length--;
	}
}

Status IsEmptyLQueue(LQueue* Q)
{
	if (Q->front == Q->rear && Q->length == 0)
		return TRUE;
	else
		return FALSE;

}

Status GetHeadLQueue(LQueue* Q)
{
	if (Q == NULL)
	{
		printf("队列未创建！\n"); // 打印错误消息：队列未创建
		return FALSE; // 返回FALSE，表示操作失败
	}
	else if (Q->front == NULL)
	{
		printf("队列为空！\n"); // 打印错误消息：队列为空
		return FALSE; // 返回FALSE，表示操作失败
	}
	else
	{
		char* temp; // 临时指针，用于存储队头元素的字符串
		void* e = Q->front->data; // 获取队头元素的数据指针
		switch (Q->front->type) // 根据队头元素的类型进行不同的处理
		{
		case 'd':
			printf("队头元素为：%d\n", *((int*)e)); // 打印队头元素为整数类型
			break;
		case 'f':
			printf("队头元素为：%g\n", *((float*)e)); // 打印队头元素为浮点数类型
			break;
		case 'c':
			printf("队头元素为：%c\n", *((char*)e)); // 打印队头元素为字符类型
			break;
		case 's':
			temp = (char*)e; // 将队头元素强制转换为字符指针
			if (temp != NULL)
				printf("队头元素为：%s\n", temp); // 如果队头元素不为空，则打印字符串
			else
				printf("队头元素为空字符串！\n"); // 如果队头元素为空，则打印空字符串提示
			break;
		}
		return TRUE; // 返回TRUE，表示成功获取到队头元素
	}
}


int LengthLQueue(LQueue* Q)
{
	return (Q->length);
}


void EnLQueue(LQueue* Q, char* elem)
{
	// 分配新节点内存
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		printf("内存分配失败\n"); // 打印内存分配失败消息
		return; // 返回，表示操作失败
	}

	newnode->next = NULL; // 将新节点的next指针置为空

	// 根据元素类型进行处理
	int i = classElem(elem); // 获取元素类型
	switch (i)
	{
	case 1: // 整数类型
		newnode->data = malloc(sizeof(int));
		if (newnode->data == NULL)
		{
			printf("内存分配失败\n"); // 打印内存分配失败消息
			free(newnode); // 释放新节点内存
			return; // 返回，表示操作失败
		}
		*((int*)newnode->data) = atoi(elem); // 将字符串转换为整数并存储在新节点的data中
		newnode->type = 'd'; // 设置新节点的类型为整数类型
		break;
	case 2: // 浮点数类型
		newnode->data = malloc(sizeof(float));
		if (newnode->data == NULL)
		{
			printf("内存分配失败\n"); // 打印内存分配失败消息
			free(newnode); // 释放新节点内存
			return; // 返回，表示操作失败
		}
		*((float*)newnode->data) = atof(elem); // 将字符串转换为浮点数并存储在新节点的data中
		newnode->type = 'f'; // 设置新节点的类型为浮点数类型
		break;
	case 3: // 字符类型
		newnode->data = malloc(sizeof(char));
		if (newnode->data == NULL)
		{
			printf("内存分配失败\n"); // 打印内存分配失败消息
			free(newnode); // 释放新节点内存
			return; // 返回，表示操作失败
		}
		*((char*)newnode->data) = elem[0]; // 将字符串的第一个字符存储在新节点的data中
		newnode->type = 'c'; // 设置新节点的类型为字符类型
		break;
	case 4: // 字符串类型
		newnode->data = _strdup(elem);
		if (newnode->data == NULL)
		{
			printf("内存分配失败\n"); // 打印内存分配失败消息
			free(newnode); // 释放新节点内存
			return; // 返回，表示操作失败
		}
		newnode->type = 's'; // 设置新节点的类型为字符串类型
		break;
	}

	// 将新节点加入队列
	if (Q->length == 0)
	{
		Q->front = newnode;
		Q->rear = newnode;
	}
	else
	{
		Q->rear->next = newnode;
		Q->rear = newnode;
	}
	Q->length++;
}


Status DeLQueue(LQueue* Q)
{
	if (Q->front == NULL)
	{
		printf("队列为空！"); // 打印错误消息：队列为空
		system("pause"); // 暂停程序运行，等待用户按下任意键继续
		system("cls"); // 清空屏幕
		return FALSE; // 返回FALSE，表示操作失败
	}
	else
	{
		Node* temp = Q->front; // 临时指针指向队头节点
		Q->front = Q->front->next; // 更新队头指针为下一个节点
		free(temp); // 释放原队头节点内存
		Q->length--;
		return TRUE; // 返回TRUE，表示成功从队列中删除了一个元素
	}
}

void ClearLQueue(LQueue* Q)
{
	if (Q == NULL)
	{
		printf("队列未创建！"); // 打印错误消息：队列未创建
		system("pause"); // 暂停程序运行，等待用户按下任意键继续
		system("cls"); // 清空屏幕
		return; // 直接返回，不执行清空队列操作
	}
	else if (Q->front == NULL)
	{
		printf("队列为空！"); // 打印错误消息：队列为空
		system("pause"); // 暂停程序运行，等待用户按下任意键继续
		system("cls"); // 清空屏幕
		return; // 直接返回，不执行清空队列操作
	}

	int clearNum = -1; // 初始化清空节点数为-1
	// 循环直到输入合法的清空节点数
	while (clearNum > Q->length || clearNum < 0)
	{
		printf("请输入清空的节点数（目前队列大小为%d）：", Q->length);
		scanf("%d", &clearNum);
		getchar();
		// 如果输入的清空节点数超过队列大小或小于0，则提示重新输入
		if (clearNum > Q->length || clearNum < 0)
		{
			printf("请输入合适的数目   ");
			system("pause"); // 暂停程序运行，等待用户按下任意键继续
			system("cls"); // 清空屏幕
		}
	}
	// 循环清空指定数量的节点
	while (clearNum--)
	{
		Node* temp = Q->front; // 临时指针指向队头节点
		Q->front = Q->front->next; // 更新队头指针为下一个节点
		free(temp); // 释放原队头节点内存
		Q->length--;
	}
}


void TraverseLQueue(LQueue* Q) {
	// 如果队列为空或未创建，则打印消息并返回
	if (Q == NULL || Q->front == NULL) {
		printf("队列为空！\n");
		return;
	}

	// 遍历队列并打印每个节点的数据
	Node* current = Q->front; // 从队头开始遍历
	printf("当前队列为： ");

	while (current != NULL) {
		void* data = current->data; // 获取当前节点的数据指针

		switch (current->type) { // 根据节点类型打印相应的数据
		case 'd':
			printf("%d -> ", *((int*)data)); // 整数类型
			break;
		case 'f':
			printf("%g -> ", *((float*)data)); // 浮点数类型
			break;
		case 'c':
			printf("%c -> ", *((char*)data)); // 字符类型
			break;
		case 's':
			printf("%s -> ", (char*)data); // 字符串类型
			break;
		default:
			printf("Unknown type -> "); // 未知类型
		}

		current = current->next; // 移动到下一个节点
	}

	printf("NULL\n"); // 打印队列末尾标识
}