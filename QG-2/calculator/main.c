#include"head.c"
int main()
{
    char str[200];
    printf("请输入中缀表达式:");
    gets(str);
    int num = trans(str);
    if(num)
    {
        printf("中缀表达式转换为后缀表达式成功,后缀表达式为:%s\n",result);
        int result1 = calculate(result);
        printf("后缀表达式计算结果为:%d\n",result1);
    }
    else if(!num)
    {
        printf("中缀表达式转换为后缀表达式失败\n");
    }
    return 0;
}