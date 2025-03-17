#include "head.c"
int main()
{
    // 设置控制台编码为 UTF-8
    //_setmode(_fileno(stdout), _O_U8TEXT);
    //_setmode(_fileno(stdin), _O_U8TEXT);
    system("chcp 65001");
    system("mode con cols=200 lines=200");//调输出框大小
	system("color f0");//白色框框
    while(1)
    {
        menu();
    }
    return 0;
}
