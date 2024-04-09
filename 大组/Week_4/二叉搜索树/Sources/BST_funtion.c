#include"..\Headers\BST.h"

int getNum(int* arr, char* num_c) 
{
    char temp[10]; // ��ʱ���飬���ڴ洢���ַ�������ȡ������
    temp[0] = '\0'; // ��ʼ����ʱ����
    int j = 0; 
    int size = 0; 

    for (int i = 0; num_c[i] != '\0'; i++) 
    {
        if (num_c[i] >= '0' && num_c[i] <= '9') 
        {
            temp[j] = num_c[i]; // �������ַ��洢����ʱ������
            j++;
        }
        else {
            if (temp[0] == '\0')
                continue; // ���������ķ������ַ�

            temp[j] = '\0'; 

            int num = atoi(temp); 
            int isDuplicate = 0; // �Ƿ�����ظ�ֵ
            for (int k = 0; k < size; k++) 
            {
                if (arr[k] == num) 
                {
                    isDuplicate = 1;
                    break;
                }
            }

    
            if (!isDuplicate) 
            {
                arr[size] = num; 
                size++; 
            }

            j = 0; 
        }
    }
    return size; 
}


NodePtr createNode(int value) 
{
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode != NULL) 
    {
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}


NodePtr sortedArrayToBST(int* arr, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;// �м�Ԫ����Ϊ���ڵ�
    NodePtr root = createNode(arr[mid]);

    // �ݹ鹹����������������
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}


void findBST(BinarySortTreePtr Tree, int aim_num) 
{
    NodePtr temp = Tree->root; // �Ӹ��ڵ㿪ʼ����
    NodePtr parent = temp; // ��¼��ǰ�ڵ�ĸ��ڵ�
    while (1) 
    {
        if (temp->value == aim_num) // �����ǰ�ڵ��ֵ����Ŀ��ֵ
        {
            if (temp == parent) // �����ǰ�ڵ��Ǹ��ڵ�
                printf("���������ڸ�ֵ��%d����ֵλ�ڸ��ڵ�\n", temp->value);
            else // �����ǰ�ڵ㲻�Ǹ��ڵ�
            {
                if (temp->value < parent->value) // �����ǰ�ڵ�С�ڸ��ڵ��ֵ
                {
                    if (parent->right != NULL)
                        printf("���������ڸ�ֵ��%d����ֵ��%d����˫��Ϊ%d\n", temp->value, parent->right->value, parent->value);
                    else
                        printf("���������ڸ�ֵ��%d����ֵ˫��Ϊ%d\n", temp->value, parent->value);
                }
                else // �����ǰ�ڵ���ڸ��ڵ��ֵ
                {
                    if (parent->left != NULL)
                        printf("���������ڸ�ֵ��%d����ֵ��%d����˫��Ϊ%d\n", temp->value, parent->left->value, parent->value);
                    else
                        printf("���������ڸ�ֵ��%d����ֵ˫��Ϊ%d\n", temp->value, parent->value);
                }
            }
            system("pause");
            system("cls");
            return;
        }
        else // �����ǰ�ڵ��ֵ������Ŀ��ֵ
        {
            if (aim_num < temp->value) // ���Ŀ��ֵС�ڵ�ǰ�ڵ��ֵ
            {
                if (temp->left == NULL) // �����ǰ�ڵ�����ӽڵ�Ϊ��
                {
                    printf("�����������ڸ�ֵ\n");
                    system("pause");
                    system("cls");
                    return;
                }
                parent = temp; // ���¸��ڵ�Ϊ��ǰ�ڵ�
                temp = temp->left; // �����������ӽڵ�
            }
            else // ���Ŀ��ֵ���ڵ�ǰ�ڵ��ֵ
            {
                if (temp->right == NULL) // �����ǰ�ڵ�����ӽڵ�Ϊ��
                {
                    printf("�����������ڸ�ֵ\n");
                    system("pause");
                    system("cls");
                    return;
                }
                parent = temp; // ���¸��ڵ�Ϊ��ǰ�ڵ�
                temp = temp->right; // �����������ӽڵ�
            }
        }
    }
}


void insetTree(BinarySortTreePtr Tree, int num)
{
    NodePtr temp = Tree->root;
    NodePtr parent = temp;
    if (temp == NULL) 
    {
        Tree->root = createNode(num);
        return;
    }
    while (temp != NULL)
    {
        if (num == temp->value)
        {
            printf("��ֵ�Ѵ���");
            return;
        }
        else if (num < temp->value)
        {
            parent = temp;//���¸��ڵ�Ϊ��ǰ�ڵ�
            temp = temp->left;
        }
        else
        {
            parent = temp;//���¸��ڵ�Ϊ��ǰ�ڵ�
            temp = temp->right;
        }

    }
    temp = createNode(num);
    if (num < parent->value)//����
        parent->left = temp;
    else
        parent->right = temp;
    printf("����ɹ���");
    system("pause");
    system("cls");
}


void delTree(BinarySortTreePtr Tree, int aim_num) 
{
    NodePtr temp = Tree->root;
    NodePtr parent = NULL; 

    NodePtr delnode;//��ɾ���Ľڵ�

    while (temp != NULL && temp->value != aim_num) 
    {
        parent = temp;//���¸��ڵ�Ϊ��ǰ�ڵ�
        if (aim_num < temp->value)
            temp = temp->left;
        else
            temp = temp->right;
    }

  
    if (temp == NULL) 
    {
        printf("��ֵ������!");
        system("pause");
        system("cls");
        return;
    }

    if (temp->left == NULL && temp->right == NULL) //�����ɾ���ڵ�ΪҶ�ӽڵ�
    {
        delnode = temp;
        if (parent == NULL) 
            Tree->root = NULL;
        else if (parent->left == temp)
            parent->left = NULL;
        else
            parent->right = NULL;
        free(delnode);
    }
    else if (temp->left != NULL && temp->right != NULL) //�����ɾ���ڵ��������ӽڵ�
    {
        delnode = temp;
        parent = temp;
        temp = temp->right;
        while (temp->left != NULL) 
        {
            parent = temp;
            temp = temp->left;
        }
        delnode->value = temp->value;
        if (parent == delnode) 
            parent->right = temp->right;
        else
            parent->left = temp->right;
        free(temp);
    }

    else //�����ɾ���ڵ�ֻ��һ���ӽڵ�
    {
        NodePtr child = (temp->left != NULL) ? temp->left : temp->right;
        if (parent == NULL) 
            Tree->root = child;
        else if (parent->left == temp)
            parent->left = child;
        else
            parent->right = child;
        free(temp);
    }

    printf("ɾ�����!");
    system("pause");
    system("cls");
}



void preorderTree0(NodePtr root) //ǰ��
{
    if (root != NULL) 
    {
        printf("%d ", root->value);
        preorderTree0(root->left);
        preorderTree0(root->right);
    }
}



void inorderTree0(NodePtr root) //����
{
    if (root != NULL) 
    {
        inorderTree0(root->left);
        printf("%d ", root->value);
        inorderTree0(root->right);
    }
}


void postorderTree0(NodePtr root) //����
{
    if (root != NULL) 
    {
        postorderTree0(root->left);
        postorderTree0(root->right);
        printf("%d ", root->value);
    }
}


void preorderTree1(NodePtr root) 
{
    if (root == NULL)
        return;

    NodePtr stack[100];
    int top = -1;//-1ʱ��ʾջΪ��
    stack[++top] = root;

    while (top != -1) 
    {
        NodePtr current = stack[top--];
        printf("%d ", current->value);

        if (current->right != NULL)
            stack[++top] = current->right;
        if (current->left != NULL)
            stack[++top] = current->left;
    }
}

void inorderTree1(NodePtr root) 
{
    if (root == NULL)
        return;

    NodePtr stack[100];
    int top = -1;
    NodePtr current = root;

    while (current != NULL || top != -1) 
    {
        while (current != NULL) 
        {
            stack[++top] = current;
            current = current->left;//һֱ��������ǰ�ڵ������ڵ�
        }

        current = stack[top--];
        printf("%d ", current->value);

        current = current->right;
    }
}


void postorderTree1(NodePtr root) 
{
    if (root == NULL)
        return;

    NodePtr stack1[100];//����ջ
    NodePtr stack2[100];//����˳��ջ
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;

    while (top1 != -1) 
    {
        NodePtr current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL)
            stack1[++top1] = current->left;
        if (current->right != NULL)
            stack1[++top1] = current->right;
    }

    while (top2 != -1) 
    {
        NodePtr current = stack2[top2--];
        printf("%d ", current->value);
    }
}

void enqueue(Queue* queue, Node* data) //���
{
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newNode == NULL) 
    {
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) 
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}


Node* dequeue(Queue* queue) //����
{
    if (queue->front == NULL) 
    {
        return NULL;
    }
    QueueNode* temp = queue->front;
    Node* data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) 
    {
        queue->rear = NULL;
    }
    free(temp);
    return data;
}



void levelTree(NodePtr root) //��α���
{
    if (root == NULL) 
        return;

    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    enqueue(&queue, root); 

    while (queue.front != NULL)//ѭ��ֱ������Ϊ��
    { 
        Node* current = dequeue(&queue); 
        printf("%d ", current->value); 

        //����ǰ�ڵ�������ӽڵ����
        if (current->left != NULL) 
        {
            enqueue(&queue, current->left);
        }
        if (current->right != NULL) 
        {
            enqueue(&queue, current->right);
        }
    }
}