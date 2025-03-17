#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<windows.h>
//#include <io.h>
//#include <fcntl.h>
typedef struct node_1 {
    int data;
    struct node_1* next;
} Listnode_1;//单链表结构体
typedef struct node_2 {
    struct node_2* pre;
    int data;
    struct node_2* next; 
}Listnode_2;//双向链表结构体
void menu();//菜单界面函数
void menu1();//单链表操作
void menu2();//双向链表操作
void createlist_1();//菜单界面调用的创建单链表函数
void createlist_2();//菜单界面调用的创建双向链表函数
void exchangeN();//菜单界面调用的单链表奇偶调换函数
void findMidN();//菜单界面调用的单链表寻找中间节点函数
void judgecircle_1();//菜单界面调用的判断单链表是否有环函数
void judgecircle_2();//菜单界面调用的判断双向链表是否有环函数
void reversal_1();//菜单界面调用的单链表反转函数
void reversal_2();//菜单界面调用的双向链表反转函数
void checknode_1();//菜单界面调用的查看单链表的函数
void checknode_2();//菜单界面调用的查看双向链表的函数
void circle_1();//菜单界面调用的创建单链表环的函数
void circle_2();//菜单界面调用的创建双向链表环的函数
Listnode_1* findnode(Listnode_1* root,int n);//寻找节点函数
void deleteN(Listnode_1** root,int n);//删除节点函数
void deletelist(Listnode_1** root);//删除整个链表函数
Listnode_1* createN(Listnode_1* data);//创建链表节点的函数
void addnode(Listnode_1** root,Listnode_1* data);//增加节点到链表尾部的函数
void printN(Listnode_1* root);//打印链表的函数