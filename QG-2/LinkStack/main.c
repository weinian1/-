#include"head.c"
int main()
{
    stack *s;
    int a;
    s = (stack *)malloc(sizeof(stack));
    if (s == NULL) 
    {
        printf("�ڴ����ʧ��,׼���˳�����\n");
        exit(0);
    }
    s->top = NULL;
    s->cnt = 0;
    printf("������ջ��Ԫ�صĸ���:");
    scanf("%d",&a);
    while(a--)
    {
        push(s);
    }
    while(1)
    {
        menu(s);
    }
    return 0;
}