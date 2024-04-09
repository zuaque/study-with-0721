#include"..\Headers\BST.h"

int getNum(int* arr, char* num_c) 
{
    char temp[10]; // 临时数组，用于存储从字符串中提取的数字
    temp[0] = '\0'; // 初始化临时数组
    int j = 0; 
    int size = 0; 

    for (int i = 0; num_c[i] != '\0'; i++) 
    {
        if (num_c[i] >= '0' && num_c[i] <= '9') 
        {
            temp[j] = num_c[i]; // 将数字字符存储在临时数组中
            j++;
        }
        else {
            if (temp[0] == '\0')
                continue; // 跳过连续的非数字字符

            temp[j] = '\0'; 

            int num = atoi(temp); 
            int isDuplicate = 0; // 是否存在重复值
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
    int mid = (start + end) / 2;// 中间元素作为根节点
    NodePtr root = createNode(arr[mid]);

    // 递归构建左子树和右子树
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}


void findBST(BinarySortTreePtr Tree, int aim_num) 
{
    NodePtr temp = Tree->root; // 从根节点开始搜索
    NodePtr parent = temp; // 记录当前节点的父节点
    while (1) 
    {
        if (temp->value == aim_num) // 如果当前节点的值等于目标值
        {
            if (temp == parent) // 如果当前节点是根节点
                printf("二叉树存在该值：%d，该值位于根节点\n", temp->value);
            else // 如果当前节点不是根节点
            {
                if (temp->value < parent->value) // 如果当前节点小于父节点的值
                {
                    if (parent->right != NULL)
                        printf("二叉树存在该值：%d，该值与%d共有双亲为%d\n", temp->value, parent->right->value, parent->value);
                    else
                        printf("二叉树存在该值：%d，该值双亲为%d\n", temp->value, parent->value);
                }
                else // 如果当前节点大于父节点的值
                {
                    if (parent->left != NULL)
                        printf("二叉树存在该值：%d，该值与%d共有双亲为%d\n", temp->value, parent->left->value, parent->value);
                    else
                        printf("二叉树存在该值：%d，该值双亲为%d\n", temp->value, parent->value);
                }
            }
            system("pause");
            system("cls");
            return;
        }
        else // 如果当前节点的值不等于目标值
        {
            if (aim_num < temp->value) // 如果目标值小于当前节点的值
            {
                if (temp->left == NULL) // 如果当前节点的左子节点为空
                {
                    printf("二叉树不存在该值\n");
                    system("pause");
                    system("cls");
                    return;
                }
                parent = temp; // 更新父节点为当前节点
                temp = temp->left; // 继续搜索左子节点
            }
            else // 如果目标值大于当前节点的值
            {
                if (temp->right == NULL) // 如果当前节点的右子节点为空
                {
                    printf("二叉树不存在该值\n");
                    system("pause");
                    system("cls");
                    return;
                }
                parent = temp; // 更新父节点为当前节点
                temp = temp->right; // 继续搜索右子节点
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
            printf("该值已存在");
            return;
        }
        else if (num < temp->value)
        {
            parent = temp;//更新父节点为当前节点
            temp = temp->left;
        }
        else
        {
            parent = temp;//更新父节点为当前节点
            temp = temp->right;
        }

    }
    temp = createNode(num);
    if (num < parent->value)//遍历
        parent->left = temp;
    else
        parent->right = temp;
    printf("插入成功！");
    system("pause");
    system("cls");
}


void delTree(BinarySortTreePtr Tree, int aim_num) 
{
    NodePtr temp = Tree->root;
    NodePtr parent = NULL; 

    NodePtr delnode;//待删除的节点

    while (temp != NULL && temp->value != aim_num) 
    {
        parent = temp;//更新父节点为当前节点
        if (aim_num < temp->value)
            temp = temp->left;
        else
            temp = temp->right;
    }

  
    if (temp == NULL) 
    {
        printf("该值不存在!");
        system("pause");
        system("cls");
        return;
    }

    if (temp->left == NULL && temp->right == NULL) //如果待删除节点为叶子节点
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
    else if (temp->left != NULL && temp->right != NULL) //如果待删除节点有两个子节点
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

    else //如果待删除节点只有一个子节点
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

    printf("删除完成!");
    system("pause");
    system("cls");
}



void preorderTree0(NodePtr root) //前序
{
    if (root != NULL) 
    {
        printf("%d ", root->value);
        preorderTree0(root->left);
        preorderTree0(root->right);
    }
}



void inorderTree0(NodePtr root) //中序
{
    if (root != NULL) 
    {
        inorderTree0(root->left);
        printf("%d ", root->value);
        inorderTree0(root->right);
    }
}


void postorderTree0(NodePtr root) //后序
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
    int top = -1;//-1时表示栈为空
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
            current = current->left;//一直遍历到当前节点的最左节点
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

    NodePtr stack1[100];//操作栈
    NodePtr stack2[100];//最终顺序栈
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

void enqueue(Queue* queue, Node* data) //入队
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


Node* dequeue(Queue* queue) //出队
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



void levelTree(NodePtr root) //层次遍历
{
    if (root == NULL) 
        return;

    Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    enqueue(&queue, root); 

    while (queue.front != NULL)//循环直到队列为空
    { 
        Node* current = dequeue(&queue); 
        printf("%d ", current->value); 

        //将当前节点的左右子节点入队
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