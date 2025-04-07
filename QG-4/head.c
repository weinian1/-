#include "head.h"
void menu()
{
    system("cls"); //����
    int n;
    printf("����������������Ľڵ�����");
    int n1;
    scanf("%d",&n1);
    int a[n1];
    printf("����������������Ľڵ�ֵ��");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    BSTree root = BST_Create(a, n1); // ��������������
    printf("���������������ɹ���\n");
    system("pause");
    system("cls");
    printf("1-���Ҷ���������\n");
    printf("2-�������������\n");
    printf("3-ɾ�������������ڵ�\n");
    printf("4-���ٶ���������\n");
    printf("5-ǰ���������������(�ݹ��)\n");
    printf("6-��������������������ݹ�棩\n");
    printf("7-��������������������ݹ�棩\n");
    printf("8-ǰ������������������ǵݹ�棩\n");
    printf("9-��������������������ǵݹ�棩\n");
    printf("10-��������������������ǵݹ�棩\n");
    printf("11-�����������������\n");
    printf("0-�˳�\n");
    printf("ps��2,3������Ĭ�����ǰ��������\n");
    printf("���������ѡ��");
    scanf("%d", &n);
    switch (n)
    {
     case 1:BST_Search(root);     system("pause");              break; 

     case 2: 
     {
        int insert;
            printf("������Ҫ����Ľڵ�ֵ��");
            scanf("%d",&insert);
            root = BST_Insert(root, insert);
            printf("�ڵ�ֵ %d ����ɹ���\n", insert);
            printf("ǰ����������");
            BST_Traverse(root);
            system("pause");
    }                  
    break; 

    case 3: BST_Delete(root);  printf("ɾ���ɹ�\n");
    printf("ǰ����������");
    BST_Traverse(root);
    system("pause");              
    break;  

    case 4:  printf("���ٳɹ�\n");    system("pause");              break;
    case 5: BST_Traverse(root);    system("pause");              break;
    case 6: BST_InOrder(root);      system("pause");             break;
    case 7: BST_PostOrder(root);    system("pause");             break;   
    case 8:  BST_PreOrder(root);    system("pause");             break;  
    case 9: BST_InOrder_NonRecursive(root);system("pause");      break;
    case 10: BST_PostOrder_NonRecursive(root); system("pause");  break;
    case 11: BST_LevelOrder(root);      system("pause");         break;
    case 0:exit(0); 
    default:printf("�������\n");            break;
    }
    BST_Destroy(root);
} 
// ����һ���½ڵ�
BSTree CreateNode(int value) 
{
    BSTree newNode = (BSTree)malloc(sizeof(BSTNode));
    if (!newNode) 
    {
        printf("�ڴ����ʧ�ܣ�\n");
        exit(1);
    }
    newNode->data = value;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}
// ����ڵ㵽����������
BSTree BST_Insert(BSTree root, int value) 
{
    if (root == NULL) 
    {
        return CreateNode(value);
    }
    if (value < root->data) 
    {
        root->lchild = BST_Insert(root->lchild, value);
    } else if (value > root->data) 
    {
        root->rchild = BST_Insert(root->rchild, value);
    }
    return root;
}
// ��������������
BSTree BST_Create(int *a, int n) 
{
    BSTree root = NULL;
    for (int i = 0; i < n; i++) 
    {
        root = BST_Insert(root, a[i]);
    }
    return root;
}
// ���Ҷ���������
void BST_Search(BSTree T) 
{
    int key;
    printf("������Ҫ���ҵĽڵ�ֵ��");
    scanf("%d", &key);
    BSTree p = T;
    if(p == NULL)
    {
        printf("��Ϊ�գ�\n");
        return;
    }
    while (p != NULL)
    {
        if (p->data == key)
        {
            printf("�ڵ�ֵ %d �ҵ��ˣ�\n", key);
            return;
        }
        else if (key < p->data)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        } 
        if(p==NULL)
        {
            printf("�Ҳ����ýڵ�ֵ\n");
            return;
        }
    }
}

void BST_Delete(BSTree T)//ɾ�������������ڵ�,��Ҷ�ӽڵ㣬�����ӽڵ㣬˫���ӽڵ㿼��
{
    int key;
    printf("������Ҫɾ���Ľڵ�ֵ��");
    scanf("%d", &key);
    BSTree p = T;
    BSTree parent = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            break;
        }
        parent = p;
        if (key < p->data)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        } 
    }
    if (p == NULL)
    {
        printf("�ڵ�ֵ %d �����ڣ�\n", key);
        return;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (parent == NULL)
        {
            free(p);
            T = NULL;
        }
        else if (parent->lchild == p)
        {
            parent->lchild = NULL;
        }
        else
        {
            parent->rchild = NULL;
        }
    }


    else if (p->lchild == NULL || p->rchild == NULL)
    {
        BSTree child = (p->lchild != NULL) ? p->lchild : p->rchild;
        if (parent == NULL)
        {
            free(p);
            T = child;
        }
        else if (parent->lchild == p)
        {
            parent->lchild = child;
        }
        else
        {
            parent->rchild = child;
        }
    }


    else
    {
        BSTree s = p->rchild;
        BSTree sParent = p;
        while (s->lchild != NULL)
        {
            sParent = s;
            s = s->lchild;
        }
        p->data = s->data;
        if (sParent->lchild == s)
        {
            sParent->lchild = s->rchild;
        }
        else
        {
            sParent->rchild = s->rchild;
        }
        free(s); 
    }
}
void BST_Destroy(BSTree T)//����������������
{
    
    if (T == NULL) return;
    BST_Destroy(T->lchild);
    BST_Destroy(T->rchild);
    free(T); 
}
void BST_Traverse(BSTree T)//������������ǰ��������ݹ�棩
{
    if (T == NULL) return;
    printf("%d ", T->data);
    BST_Traverse(T->lchild);
    BST_Traverse(T->rchild); 
}
void BST_InOrder(BSTree T)//����������������������ݹ�棩
{
    if (T == NULL) return;
    BST_InOrder(T->lchild);
    printf("%d ", T->data);
    BST_InOrder(T->rchild); 
}
void BST_PostOrder(BSTree T)//�����������ĺ���������ݹ�棩
{
    if (T == NULL) return;
    BST_PostOrder(T->lchild);
    BST_PostOrder(T->rchild);
    printf("%d ", T->data); 
}
//�ǵݹ����Ҫ����ջ�Ƚ�������ص���ʵ�ֱ���
void BST_PreOrder(BSTree T)//������������ǰ��������ǵݹ�棩
{
    if (T == NULL) return;
    BSTree stack[100]; 
    int top = -1; 
    stack[++top] = T; 
    while (top != -1) 
    {
        BSTree node = stack[top--];
        printf("%d ", node->data);
        if (node->rchild != NULL)
        {
            stack[++top] = node->rchild;
        }
        if (node->lchild != NULL) 
        {
            stack[++top] = node->lchild;
        }
    } 
}
void BST_InOrder_NonRecursive(BSTree T)//����������������������ǵݹ�棩
{
    if (T == NULL) return;
    BSTree stack[100]; 
    int top = -1; 
    BSTree node = T; 
    while (top != -1 || node != NULL) 
    {
        while (node != NULL) 
        {
            stack[++top] = node; 
            node = node->lchild; 
        }
        node = stack[top--]; 
        printf("%d ", node->data); 
        node = node->rchild; 
    } 
}
void BST_PostOrder_NonRecursive(BSTree T)//�����������ĺ���������ǵݹ�棩
{
    if (T == NULL) return;
    BSTree stack[100];
    int top = -1;   
    BSTree node = T;
    BSTree last = NULL;
    while (top != -1 || node != NULL)
    {
        while (node != NULL)
        {
            stack[++top] = node;
            node = node->lchild;
        }
        node = stack[top];
        if (node->rchild == NULL || node->rchild == last)
        {
            printf("%d ", node->data); 
            last = node;
            top--;
            node = NULL;
        }
        else
        {
            node = node->rchild;
        }
    }
}
//���������Ҫ���ö����Ƚ��ȳ����ص���ʵ�ֱ���
void BST_LevelOrder(BSTree T)//�����������Ĳ������
{
    if (T == NULL) return;
    BSTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front != rear)
    {
        BSTree node = queue[front++];
        printf("%d ", node->data);

        if (node->lchild != NULL)
        {
            queue[rear++] = node->lchild;
        }
        if (node->rchild != NULL)
        {
            queue[rear++] = node->rchild;
        }
    }
}