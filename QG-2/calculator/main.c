#include"head.c"
int main()
{
    char str[200];
    printf("��������׺���ʽ:");
    gets(str);
    int num = trans(str);
    if(num)
    {
        printf("��׺���ʽת��Ϊ��׺���ʽ�ɹ�,��׺���ʽΪ:%s\n",result);
        int result1 = calculate(result);
        printf("��׺���ʽ������Ϊ:%d\n",result1);
    }
    else if(!num)
    {
        printf("��׺���ʽת��Ϊ��׺���ʽʧ��\n");
    }
    return 0;
}