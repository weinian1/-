#ifndef __HEAD_H__
#define __HEAD_H__
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
typedef struct node
{
    int data;//节点元素
    struct node *next;//指向下一个节点的指针
} node,*linkstack;
typedef struct stack
{
    linkstack top;//栈顶节点指针
    int cnt;//栈的计数器
} stack;
void initstack(stack *s);//初始化栈
void judgeempty(stack *s);//判断栈是否为空
void push(stack *s);//入栈
void pop(stack *s);//出栈
void showlength(stack *s);//输出栈内元素个数及元素内容
void menu(stack *s);//菜单函数
#endif