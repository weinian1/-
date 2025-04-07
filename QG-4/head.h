#ifndef _HEAD_H_
#define _HEAD_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//二叉排序树结点结构体定义
typedef struct BSTNode
{
    int data; //数据
    struct BSTNode *lchild, *rchild; //左右孩子指针
} BSTNode, *BSTree;
void menu();//菜单函数
void menushow();//显示操作结果的遍历函数
BSTNode* CreateNode(int value);//创建一个新节点
BSTree BST_Insert(BSTree root, int value);//插入节点到二叉排序树
BSTree BST_Create(int *a, int n);//二叉排序树的创建
void BST_Search(BSTree T);//二叉排序树的查找
void BST_Delete(BSTree T);//二叉排序树节点的删除
void BST_Destroy(BSTree T);//二叉排序树的销毁

void BST_Traverse(BSTree T);//二叉排序树的前序遍历（递归版）
void BST_InOrder(BSTree T);//二叉排序树的中序遍历（递归版）
void BST_PostOrder(BSTree T);//二叉排序树的后序遍历（递归版）
void BST_PreOrder(BSTree T);//二叉排序树的前序遍历（非递归版）
void BST_InOrder_NonRecursive(BSTree T);//二叉排序树的中序遍历（非递归版）
void BST_PostOrder_NonRecursive(BSTree T);//二叉排序树的后序遍历（非递归版）
void BST_LevelOrder(BSTree T);//二叉排序树的层序遍历


#endif