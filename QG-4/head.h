#ifndef _HEAD_H_
#define _HEAD_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
//�������������ṹ�嶨��
typedef struct BSTNode
{
    int data; //����
    struct BSTNode *lchild, *rchild; //���Һ���ָ��
} BSTNode, *BSTree;
void menu();//�˵�����
void menushow();//��ʾ��������ı�������
BSTNode* CreateNode(int value);//����һ���½ڵ�
BSTree BST_Insert(BSTree root, int value);//����ڵ㵽����������
BSTree BST_Create(int *a, int n);//�����������Ĵ���
void BST_Search(BSTree T);//�����������Ĳ���
void BST_Delete(BSTree T);//�����������ڵ��ɾ��
void BST_Destroy(BSTree T);//����������������

void BST_Traverse(BSTree T);//������������ǰ��������ݹ�棩
void BST_InOrder(BSTree T);//����������������������ݹ�棩
void BST_PostOrder(BSTree T);//�����������ĺ���������ݹ�棩
void BST_PreOrder(BSTree T);//������������ǰ��������ǵݹ�棩
void BST_InOrder_NonRecursive(BSTree T);//����������������������ǵݹ�棩
void BST_PostOrder_NonRecursive(BSTree T);//�����������ĺ���������ǵݹ�棩
void BST_LevelOrder(BSTree T);//�����������Ĳ������


#endif