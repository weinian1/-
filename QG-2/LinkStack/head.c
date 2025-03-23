#include "head.h"
void initstack(stack *s)//��ʼ��ջ
{
    s->top = NULL;
    s->cnt = 0;
    printf("ջ��ʼ���ɹ�\n");
    return;
}
void judgeempty(stack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if (s->cnt == 0) printf("ջΪ��\n");
    else printf("ջ��Ϊ��\n");
}
void push(stack *s)//��ջ
{
    node *p;
    int e;
    printf("��������ջԪ��:");
    scanf("%d",&e);
    p = (node *)malloc(sizeof(node));
    if (p == NULL) 
    {
        printf("�ڴ����ʧ��\n");
        return;
    }
    p->data = e;
    p->next = s->top;
    s->top = p;
    s->cnt++;
    printf("��ջ�ɹ�\n");
}
void pop(stack *s)//ջ��Ԫ�س�ջ
{
    if (s->top == NULL) 
    {
        printf("ջΪ��,�޷���ջ\n");// ջΪ��,�޷���ջ,ֱ�ӷ���
        return;
    }
    node *p;
    int e;
    p = s->top;
    e = p->data;
    s->top = p->next;
    s->cnt--;
    free(p);//�ͷ�ջ���ڵ��ڴ�
    printf("��ջ�ɹ�,��ջԪ��Ϊ:%d\n",e);
}
void showlength(stack *s)//���ջ��Ԫ�ظ�����Ԫ������
{
    printf("ջ����%d��Ԫ��\n",s->cnt);
    int i = s->cnt;
    node *p;
    p = s->top;
    printf("ջ��Ԫ��Ϊ:");
    while(i--)
    {
        printf("%d ",p->data);
        p= p->next;
    }
    printf("\n");
}
void menu(stack *s)//�˵�
{
    system("cls");
    printf("1.��ʼ��ջ\n");
    printf("2.�ж�ջ�Ƿ�Ϊ��\n");
    printf("3.��ջ\n");
    printf("4.��ջ\n");
    printf("5.���ջ��Ԫ�ظ���������\n");
    printf("6.�˳�\n");
    printf("������:");
    
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
    default:    printf("�������,׼���˳�����\n"); system("pause");exit(0); 
    }
}