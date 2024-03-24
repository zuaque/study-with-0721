#include"..\Headers\Lqueue.h"
#define _CRT_SECURE_NO_WARNINGS


void InitLQueue(LQueue* Q) 
{
	Q->front = NULL;  // ����ͷָ����Ϊ��
	Q->rear = NULL;   // ����βָ����Ϊ��
	Q->length = 0;    // �����г�����Ϊ 0
}


void DestoryLQueue(LQueue* Q)
{
	while (Q->front != NULL)
	{
		Node* p = Q->front;
		Q->front = Q->front->next;
		if (Q->front == NULL)
			Q->rear = NULL;

		// ��鲢�ͷŽڵ�������ռ�õ��ڴ�
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
		printf("����δ������\n"); // ��ӡ������Ϣ������δ����
		return FALSE; // ����FALSE����ʾ����ʧ��
	}
	else if (Q->front == NULL)
	{
		printf("����Ϊ�գ�\n"); // ��ӡ������Ϣ������Ϊ��
		return FALSE; // ����FALSE����ʾ����ʧ��
	}
	else
	{
		char* temp; // ��ʱָ�룬���ڴ洢��ͷԪ�ص��ַ���
		void* e = Q->front->data; // ��ȡ��ͷԪ�ص�����ָ��
		switch (Q->front->type) // ���ݶ�ͷԪ�ص����ͽ��в�ͬ�Ĵ���
		{
		case 'd':
			printf("��ͷԪ��Ϊ��%d\n", *((int*)e)); // ��ӡ��ͷԪ��Ϊ��������
			break;
		case 'f':
			printf("��ͷԪ��Ϊ��%g\n", *((float*)e)); // ��ӡ��ͷԪ��Ϊ����������
			break;
		case 'c':
			printf("��ͷԪ��Ϊ��%c\n", *((char*)e)); // ��ӡ��ͷԪ��Ϊ�ַ�����
			break;
		case 's':
			temp = (char*)e; // ����ͷԪ��ǿ��ת��Ϊ�ַ�ָ��
			if (temp != NULL)
				printf("��ͷԪ��Ϊ��%s\n", temp); // �����ͷԪ�ز�Ϊ�գ����ӡ�ַ���
			else
				printf("��ͷԪ��Ϊ���ַ�����\n"); // �����ͷԪ��Ϊ�գ����ӡ���ַ�����ʾ
			break;
		}
		return TRUE; // ����TRUE����ʾ�ɹ���ȡ����ͷԪ��
	}
}


int LengthLQueue(LQueue* Q)
{
	return (Q->length);
}


void EnLQueue(LQueue* Q, char* elem)
{
	// �����½ڵ��ڴ�
	Node* newnode = (Node*)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		printf("�ڴ����ʧ��\n"); // ��ӡ�ڴ����ʧ����Ϣ
		return; // ���أ���ʾ����ʧ��
	}

	newnode->next = NULL; // ���½ڵ��nextָ����Ϊ��

	// ����Ԫ�����ͽ��д���
	int i = classElem(elem); // ��ȡԪ������
	switch (i)
	{
	case 1: // ��������
		newnode->data = malloc(sizeof(int));
		if (newnode->data == NULL)
		{
			printf("�ڴ����ʧ��\n"); // ��ӡ�ڴ����ʧ����Ϣ
			free(newnode); // �ͷ��½ڵ��ڴ�
			return; // ���أ���ʾ����ʧ��
		}
		*((int*)newnode->data) = atoi(elem); // ���ַ���ת��Ϊ�������洢���½ڵ��data��
		newnode->type = 'd'; // �����½ڵ������Ϊ��������
		break;
	case 2: // ����������
		newnode->data = malloc(sizeof(float));
		if (newnode->data == NULL)
		{
			printf("�ڴ����ʧ��\n"); // ��ӡ�ڴ����ʧ����Ϣ
			free(newnode); // �ͷ��½ڵ��ڴ�
			return; // ���أ���ʾ����ʧ��
		}
		*((float*)newnode->data) = atof(elem); // ���ַ���ת��Ϊ���������洢���½ڵ��data��
		newnode->type = 'f'; // �����½ڵ������Ϊ����������
		break;
	case 3: // �ַ�����
		newnode->data = malloc(sizeof(char));
		if (newnode->data == NULL)
		{
			printf("�ڴ����ʧ��\n"); // ��ӡ�ڴ����ʧ����Ϣ
			free(newnode); // �ͷ��½ڵ��ڴ�
			return; // ���أ���ʾ����ʧ��
		}
		*((char*)newnode->data) = elem[0]; // ���ַ����ĵ�һ���ַ��洢���½ڵ��data��
		newnode->type = 'c'; // �����½ڵ������Ϊ�ַ�����
		break;
	case 4: // �ַ�������
		newnode->data = _strdup(elem);
		if (newnode->data == NULL)
		{
			printf("�ڴ����ʧ��\n"); // ��ӡ�ڴ����ʧ����Ϣ
			free(newnode); // �ͷ��½ڵ��ڴ�
			return; // ���أ���ʾ����ʧ��
		}
		newnode->type = 's'; // �����½ڵ������Ϊ�ַ�������
		break;
	}

	// ���½ڵ�������
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
		printf("����Ϊ�գ�"); // ��ӡ������Ϣ������Ϊ��
		system("pause"); // ��ͣ�������У��ȴ��û��������������
		system("cls"); // �����Ļ
		return FALSE; // ����FALSE����ʾ����ʧ��
	}
	else
	{
		Node* temp = Q->front; // ��ʱָ��ָ���ͷ�ڵ�
		Q->front = Q->front->next; // ���¶�ͷָ��Ϊ��һ���ڵ�
		free(temp); // �ͷ�ԭ��ͷ�ڵ��ڴ�
		Q->length--;
		return TRUE; // ����TRUE����ʾ�ɹ��Ӷ�����ɾ����һ��Ԫ��
	}
}

void ClearLQueue(LQueue* Q)
{
	if (Q == NULL)
	{
		printf("����δ������"); // ��ӡ������Ϣ������δ����
		system("pause"); // ��ͣ�������У��ȴ��û��������������
		system("cls"); // �����Ļ
		return; // ֱ�ӷ��أ���ִ����ն��в���
	}
	else if (Q->front == NULL)
	{
		printf("����Ϊ�գ�"); // ��ӡ������Ϣ������Ϊ��
		system("pause"); // ��ͣ�������У��ȴ��û��������������
		system("cls"); // �����Ļ
		return; // ֱ�ӷ��أ���ִ����ն��в���
	}

	int clearNum = -1; // ��ʼ����սڵ���Ϊ-1
	// ѭ��ֱ������Ϸ�����սڵ���
	while (clearNum > Q->length || clearNum < 0)
	{
		printf("��������յĽڵ�����Ŀǰ���д�СΪ%d����", Q->length);
		scanf("%d", &clearNum);
		getchar();
		// ����������սڵ����������д�С��С��0������ʾ��������
		if (clearNum > Q->length || clearNum < 0)
		{
			printf("��������ʵ���Ŀ   ");
			system("pause"); // ��ͣ�������У��ȴ��û��������������
			system("cls"); // �����Ļ
		}
	}
	// ѭ�����ָ�������Ľڵ�
	while (clearNum--)
	{
		Node* temp = Q->front; // ��ʱָ��ָ���ͷ�ڵ�
		Q->front = Q->front->next; // ���¶�ͷָ��Ϊ��һ���ڵ�
		free(temp); // �ͷ�ԭ��ͷ�ڵ��ڴ�
		Q->length--;
	}
}


void TraverseLQueue(LQueue* Q) {
	// �������Ϊ�ջ�δ���������ӡ��Ϣ������
	if (Q == NULL || Q->front == NULL) {
		printf("����Ϊ�գ�\n");
		return;
	}

	// �������в���ӡÿ���ڵ������
	Node* current = Q->front; // �Ӷ�ͷ��ʼ����
	printf("��ǰ����Ϊ�� ");

	while (current != NULL) {
		void* data = current->data; // ��ȡ��ǰ�ڵ������ָ��

		switch (current->type) { // ���ݽڵ����ʹ�ӡ��Ӧ������
		case 'd':
			printf("%d -> ", *((int*)data)); // ��������
			break;
		case 'f':
			printf("%g -> ", *((float*)data)); // ����������
			break;
		case 'c':
			printf("%c -> ", *((char*)data)); // �ַ�����
			break;
		case 's':
			printf("%s -> ", (char*)data); // �ַ�������
			break;
		default:
			printf("Unknown type -> "); // δ֪����
		}

		current = current->next; // �ƶ�����һ���ڵ�
	}

	printf("NULL\n"); // ��ӡ����ĩβ��ʶ
}