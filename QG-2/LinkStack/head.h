#ifndef __HEAD_H__
#define __HEAD_H__
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
typedef struct node
{
    int data;//�ڵ�Ԫ��
    struct node *next;//ָ����һ���ڵ��ָ��
} node,*linkstack;
typedef struct stack
{
    linkstack top;//ջ���ڵ�ָ��
    int cnt;//ջ�ļ�����
} stack;
void initstack(stack *s);//��ʼ��ջ
void judgeempty(stack *s);//�ж�ջ�Ƿ�Ϊ��
void push(stack *s);//��ջ
void pop(stack *s);//��ջ
void showlength(stack *s);//���ջ��Ԫ�ظ�����Ԫ������
void menu(stack *s);//�˵�����
#endif