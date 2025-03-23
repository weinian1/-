#ifndef __HEAD_H__
#define __HEAD_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
////��׺���ʽת��׺���ʽ�ķ�װ����
//��׺����׺���ʽ�Ĵ洢ջ
typedef struct pnode//��ջ�ڵ�
{
    int data;//�ڵ�Ԫ��
    struct pnode *next;//ָ����һ���ڵ��ָ��
} pnode,*plinkstack;
typedef struct pstack//��ջ
{
    plinkstack top;//ջ���ڵ�ָ��
    int cnt;//ջ�ļ�����
}pstack;

//��ջ�Ļ�������
pstack* pinitstack();//��ʼ��ջ
bool pjudgeempty(pstack *s);//�ж�ջ�Ƿ�Ϊ��
void ppush(pstack *s,char p);//��ջ
pnode* ppop(pstack *s);//Ԫ�س�ջ������ջ��Ԫ��
pnode *ptop(pstack *s);//��ȡջ��Ԫ�����ݽڵ�

//��׺���ʽת��׺���ʽ�ĺ���
char result[200] = {0};//�洢��׺���ʽ���ַ�����
void putre(char p);//���ַ�����result����
int rate(char p);//�ж���������ȼ�
bool judgenum(char p);//�ж��ǲ�������
bool judgeop(char p);//�ж��ǲ��������
bool judgeright(char p);//�ж��ǲ���������
bool judgeleft(char p);//�ж��ǲ���������
bool trans(char *s);//��׺���ʽת��׺���ʽ,����ֵΪ���ʾת���ɹ�

//�����׺���ʽ�ĺ����Լ���ջ
typedef struct qnode//�����ջ������ջ
{
    int data;//����
    struct qnode* next;//ָ��
}qnode,*qlinkstack;
typedef struct qstack
{
    qlinkstack top;//ָ��ջ��Ԫ��
    int cnt;//��¼ջ�Ĵ�С
}qstack;
qstack* qinitstack();//��ʼ��ջ
bool qjudgeempty(qstack *s);//�ж�ջ�Ƿ�Ϊ��
void qpush(qstack *s,int q);//��ջ
int qpop(qstack *s);//Ԫ�س�ջ������ջ��Ԫ��
void qshowlength(qstack *s);//���ջ��Ԫ��
int qtop(qstack *s);//��ȡջ��Ԫ�����ݽڵ�
int express(int left,int right,char op);//opΪ�����,����������
int calculate(char str[]);//�����׺���ʽ



#endif