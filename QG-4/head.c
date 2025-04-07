#include "head.h"
void menu()
{
    system("cls"); //清屏
    int n;
    printf("请输入二叉排序树的节点数：");
    int n1;
    scanf("%d",&n1);
    int a[n1];
    printf("请输入二叉排序树的节点值：");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    BSTree root = BST_Create(a, n1); // 创建二叉排序树
    printf("二叉排序树创建成功！\n");
    system("pause");
    system("cls");
    printf("1-查找二叉排序树\n");
    printf("2-插入二叉排序树\n");
    printf("3-删除二叉排序树节点\n");
    printf("4-销毁二叉排序树\n");
    printf("5-前序遍历二叉排序树(递归版)\n");
    printf("6-中序遍历二叉排序树（递归版）\n");
    printf("7-后序遍历二叉排序树（递归版）\n");
    printf("8-前序遍历二叉排序树（非递归版）\n");
    printf("9-中序遍历二叉排序树（非递归版）\n");
    printf("10-后序遍历二叉排序树（非递归版）\n");
    printf("11-层序遍历二叉排序树\n");
    printf("0-退出\n");
    printf("ps：2,3操作后默认输出前序遍历结果\n");
    printf("请输入你的选择：");
    scanf("%d", &n);
    switch (n)
    {
     case 1:BST_Search(root);     system("pause");              break; 

     case 2: 
     {
        int insert;
            printf("请输入要插入的节点值：");
            scanf("%d",&insert);
            root = BST_Insert(root, insert);
            printf("节点值 %d 插入成功！\n", insert);
            printf("前序遍历结果：");
            BST_Traverse(root);
            system("pause");
    }                  
    break; 

    case 3: BST_Delete(root);  printf("删除成功\n");
    printf("前序遍历结果：");
    BST_Traverse(root);
    system("pause");              
    break;  

    case 4:  printf("销毁成功\n");    system("pause");              break;
    case 5: BST_Traverse(root);    system("pause");              break;
    case 6: BST_InOrder(root);      system("pause");             break;
    case 7: BST_PostOrder(root);    system("pause");             break;   
    case 8:  BST_PreOrder(root);    system("pause");             break;  
    case 9: BST_InOrder_NonRecursive(root);system("pause");      break;
    case 10: BST_PostOrder_NonRecursive(root); system("pause");  break;
    case 11: BST_LevelOrder(root);      system("pause");         break;
    case 0:exit(0); 
    default:printf("输入错误\n");            break;
    }
    BST_Destroy(root);
} 
// 创建一个新节点
BSTree CreateNode(int value) 
{
    BSTree newNode = (BSTree)malloc(sizeof(BSTNode));
    if (!newNode) 
    {
        printf("内存分配失败！\n");
        exit(1);
    }
    newNode->data = value;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    return newNode;
}
// 插入节点到二叉排序树
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
// 创建二叉排序树
BSTree BST_Create(int *a, int n) 
{
    BSTree root = NULL;
    for (int i = 0; i < n; i++) 
    {
        root = BST_Insert(root, a[i]);
    }
    return root;
}
// 查找二叉排序树
void BST_Search(BSTree T) 
{
    int key;
    printf("请输入要查找的节点值：");
    scanf("%d", &key);
    BSTree p = T;
    if(p == NULL)
    {
        printf("树为空！\n");
        return;
    }
    while (p != NULL)
    {
        if (p->data == key)
        {
            printf("节点值 %d 找到了！\n", key);
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
            printf("找不到该节点值\n");
            return;
        }
    }
}

void BST_Delete(BSTree T)//删除二叉排序树节点,分叶子节点，单孩子节点，双孩子节点考虑
{
    int key;
    printf("请输入要删除的节点值：");
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
        printf("节点值 %d 不存在！\n", key);
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
void BST_Destroy(BSTree T)//二叉排序树的销毁
{
    
    if (T == NULL) return;
    BST_Destroy(T->lchild);
    BST_Destroy(T->rchild);
    free(T); 
}
void BST_Traverse(BSTree T)//二叉排序树的前序遍历（递归版）
{
    if (T == NULL) return;
    printf("%d ", T->data);
    BST_Traverse(T->lchild);
    BST_Traverse(T->rchild); 
}
void BST_InOrder(BSTree T)//二叉排序树的中序遍历（递归版）
{
    if (T == NULL) return;
    BST_InOrder(T->lchild);
    printf("%d ", T->data);
    BST_InOrder(T->rchild); 
}
void BST_PostOrder(BSTree T)//二叉排序树的后序遍历（递归版）
{
    if (T == NULL) return;
    BST_PostOrder(T->lchild);
    BST_PostOrder(T->rchild);
    printf("%d ", T->data); 
}
//非递归版主要利用栈先进后出的特点来实现遍历
void BST_PreOrder(BSTree T)//二叉排序树的前序遍历（非递归版）
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
void BST_InOrder_NonRecursive(BSTree T)//二叉排序树的中序遍历（非递归版）
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
void BST_PostOrder_NonRecursive(BSTree T)//二叉排序树的后序遍历（非递归版）
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
//层序遍历主要利用队列先进先出的特点来实现遍历
void BST_LevelOrder(BSTree T)//二叉排序树的层序遍历
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