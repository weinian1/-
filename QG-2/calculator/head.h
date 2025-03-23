#ifndef __HEAD_H__
#define __HEAD_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
////中缀表达式转后缀表达式的封装函数
//中缀，后缀表达式的存储栈
typedef struct pnode//链栈节点
{
    int data;//节点元素
    struct pnode *next;//指向下一个节点的指针
} pnode,*plinkstack;
typedef struct pstack//链栈
{
    plinkstack top;//栈顶节点指针
    int cnt;//栈的计数器
}pstack;

//链栈的基本操作
pstack* pinitstack();//初始化栈
bool pjudgeempty(pstack *s);//判断栈是否为空
void ppush(pstack *s,char p);//入栈
pnode* ppop(pstack *s);//元素出栈并返回栈顶元素
pnode *ptop(pstack *s);//获取栈顶元素数据节点

//中缀表达式转后缀表达式的函数
char result[200] = {0};//存储后缀表达式的字符数组
void putre(char p);//将字符存入result数组
int rate(char p);//判断运算符优先级
bool judgenum(char p);//判断是不是数字
bool judgeop(char p);//判断是不是运算符
bool judgeright(char p);//判断是不是右括号
bool judgeleft(char p);//判断是不是左括号
bool trans(char *s);//中缀表达式转后缀表达式,返回值为真表示转换成功

//计算后缀表达式的函数以及链栈
typedef struct qnode//这里的栈是整型栈
{
    int data;//数据
    struct qnode* next;//指针
}qnode,*qlinkstack;
typedef struct qstack
{
    qlinkstack top;//指向栈顶元素
    int cnt;//记录栈的大小
}qstack;
qstack* qinitstack();//初始化栈
bool qjudgeempty(qstack *s);//判断栈是否为空
void qpush(qstack *s,int q);//入栈
int qpop(qstack *s);//元素出栈并返回栈顶元素
void qshowlength(qstack *s);//输出栈内元素
int qtop(qstack *s);//获取栈顶元素数据节点
int express(int left,int right,char op);//op为运算符,返回运算结果
int calculate(char str[]);//计算后缀表达式



#endif