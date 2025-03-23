#include"head.c"
int main()
{
    stack *s;
    int a;
    s = (stack *)malloc(sizeof(stack));
    if (s == NULL) 
    {
        printf("内存分配失败,准备退出程序\n");
        exit(0);
    }
    s->top = NULL;
    s->cnt = 0;
    printf("请输入栈内元素的个数:");
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