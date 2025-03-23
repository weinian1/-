#include "head.h"
void initstack(stack *s)//初始化栈
{
    s->top = NULL;
    s->cnt = 0;
    printf("栈初始化成功\n");
    return;
}
void judgeempty(stack *s)//判断栈是否为空
{
    if (s->cnt == 0) printf("栈为空\n");
    else printf("栈不为空\n");
}
void push(stack *s)//入栈
{
    node *p;
    int e;
    printf("请输入入栈元素:");
    scanf("%d",&e);
    p = (node *)malloc(sizeof(node));
    if (p == NULL) 
    {
        printf("内存分配失败\n");
        return;
    }
    p->data = e;
    p->next = s->top;
    s->top = p;
    s->cnt++;
    printf("入栈成功\n");
}
void pop(stack *s)//栈顶元素出栈
{
    if (s->top == NULL) 
    {
        printf("栈为空,无法出栈\n");// 栈为空,无法出栈,直接返回
        return;
    }
    node *p;
    int e;
    p = s->top;
    e = p->data;
    s->top = p->next;
    s->cnt--;
    free(p);//释放栈顶节点内存
    printf("出栈成功,出栈元素为:%d\n",e);
}
void showlength(stack *s)//输出栈内元素个数及元素内容
{
    printf("栈内有%d个元素\n",s->cnt);
    int i = s->cnt;
    node *p;
    p = s->top;
    printf("栈内元素为:");
    while(i--)
    {
        printf("%d ",p->data);
        p= p->next;
    }
    printf("\n");
}
void menu(stack *s)//菜单
{
    system("cls");
    printf("1.初始化栈\n");
    printf("2.判断栈是否为空\n");
    printf("3.入栈\n");
    printf("4.出栈\n");
    printf("5.输出栈内元素个数及内容\n");
    printf("6.退出\n");
    printf("请输入:");
    
    int a;
    scanf("%d",&a);
    switch (a)
    {
    case 1:     initstack(s);    system("pause");      break;
    case 2:     judgeempty(s);   system("pause");      break;
    case 3:     push(s);         system("pause");      break;
    case 4:     pop(s);       system("pause");      break;
    case 5:     showlength(s);   system("pause");      break;
    case 6:     exit(0);          system("pause");     break;
    default:    printf("输入错误,准备退出程序\n"); system("pause");exit(0); 
    }
}