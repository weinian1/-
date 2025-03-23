#include "head.h"


//对栈的基本操作
pstack* pinitstack()//初始化栈或者创建栈
{
    pstack *s = (pstack *)malloc(sizeof(pstack));
    if(s != NULL)
    {
        s->top = NULL;
        s->cnt = 0;
    }
    return s;
}
bool pjudgeempty(pstack *s)//判断栈是否为空
{
    if (s->cnt == 0) return true;
    else return false;
}
void ppush(pstack *s,char p)//入栈
{
    pnode *ptemp;
    ptemp = (pnode *)malloc(sizeof(pnode));
    if (ptemp == NULL) 
    {
        printf("内存分配失败\n");
        return;
    }
    ptemp->data = p;
    ptemp->next = s->top;
    s->top = ptemp;
    s->cnt++;
    return;
}
pnode* ppop(pstack *s)//栈顶元素出栈
{
    if (s->top == NULL) 
    {
        return NULL;
    }
    pnode *p;
    p = s->top;
    s->top = p->next;
    s->cnt--;
    return p;   
}

pnode *ptop(pstack *s)//获取栈顶元素数据节点
{
    if (s->top == NULL) return NULL;
    return s->top;
}


//中缀表达式转后缀表达式的函数的具体实现
void putre(char p)//将字符存入result数组
{
    static int i = 0;//静态变量，只初始化一次，记录result数组下标
    result[i] = p;
    i++;
    return;
}
int rate(char p)//判断运算符优先级
{
    if (p == '+' || p == '-') return 1;
    if (p == '*' || p == '/') return 2;
    if (p == '(') return 0;
    if (p == ')') return 3;
    return -1;
}
bool judgenum(char p)//判断是不是数字
{
    if (p >= '0' && p <= '9') return true;
    return false;
}
bool judgeop(char p)//判断是不是运算符
{
    if (p == '+' || p == '-' || p == '*' || p == '/') return true;
    return false;
}
bool judgeright(char p)//判断是不是右括号
{
    if (p == ')') return true;
    return false;
}
bool judgeleft(char p)//判断是不是左括号
{
    if (p == '(') return true;
    return false;
}
bool trans(char *str)//中缀表达式转后缀表达式,返回值为真表示转换成功
{
    pstack *s1 = pinitstack();//创建一个栈
    int i = 0;//记录str数组下标
    while(str[i] != '\0')
    {
        if (judgenum(str[i]))//如果是数字，直接输出 
        {
            if(judgenum(str[i+1]))//后面1也是数字,则直接放
            {
                putre(str[i]);//数字直接放入结果串(即输出)
            }
            else//后面不是数字,添加一个空格作为分隔符
            {
                putre(str[i]);
                putre(' ');//用空格来记录多位的数字
            }
        }
        else if (judgeop(str[i]))//如果是运算符
        {
            if(str[i+1]=='0'&&str[i]=='/')
            {
                printf("除数不能为0,操作失败\n");//除数不能为0
                return false;
            }
            if (!pjudgeempty(s1))//如果栈不为空
            {
                while((!pjudgeempty(s1))&&(rate(str[i]) <= rate(ptop(s1)->data)))//如果栈不为空且当前运算符优先级小于等于栈顶运算符优先级
                {
                    pnode *p = ppop(s1);//栈顶元素出栈
                    putre(p->data);//将栈顶元素输出
                    putre(' ');//用空格来记录多位的数字
                }
            }
            ppush(s1,str[i]);//当前运算符入栈
        }
        else if (judgeleft(str[i]))//如果是左括号
        {
            ppush(s1,str[i]);//左括号入栈
        }
        else if (judgeright(str[i]))//如果是右括号
        {
            while((ptop(s1)->data != '('))//如果栈顶元素不是左括号
            {
                pnode *p = ppop(s1);//栈顶元素出栈
                putre(p->data);//将栈顶元素输出
                if(pjudgeempty(s1))
                {
                    printf("缺少左括号,操作失败\n");//缺少左括号
                    return false;
                }
            } 
            ppop(s1);//将左括号出栈,两个括号抵消
        }
        else
        {
            printf("输入的表达式有无法识别的字符,操作失败\n");//输入的表达式有误
            return false;
        }
        i++;//str数组下标后移
    }
    if(str[i] == '\0')//如果str数组遍历完毕
    {
        while(!pjudgeempty(s1))//如果栈不为空
        {
            pnode *p = ppop(s1);//栈顶元素出栈
            if(p->data == '(')
            {
                printf("缺少右括号,操作失败\n");//缺少右括号
                return false;
            }
            putre(p->data);//将栈顶元素输出
        }
    }
    else
    {
        printf("遍历没有完成！\n");
    }
    return true;
}


//计算后缀表达式所需函数的具体实现
qstack* qinitstack()//初始化栈
{
    qstack *s = (qstack *)malloc(sizeof(qstack));
    if(s != NULL)
    {
        s->top = NULL;
        s->cnt = 0;
    }
    return s;
}
bool qjudgeempty(qstack *s)//判断栈是否为空
{
    if(s->cnt == 0) return true;
    else return false;
}
void qpush(qstack *s,int q)//入栈
{
    qnode *qtemp;
    qtemp = (qnode *)malloc(sizeof(qnode));
    if (qtemp == NULL) 
    {
        printf("内存分配失败\n");
        return;
    }
    qtemp->data = q;
    qtemp->next = s->top;
    s->top = qtemp;
    s->cnt++;
    return;
}
int qpop(qstack *s)//元素出栈并返回栈顶元素
{
   if(qjudgeempty(s)) return -1;
   int q = s->top->data;
   s->top = s->top->next;
   s->cnt--; 
   return q;//返回弹出的数据节点
}
int qtop(qstack *s)//获取栈顶元素数据节点
{
    if (s->top == NULL) return -1;
    return s->top->data;
}
int express(int left,int right,char op)//op为运算符,返回运算结果
{
    switch (op)
     {
        case '+':
            return left+right;
        case '-':
            return left-right;
        case '*':
            return left*right;
        case '/':
            if(right==0)
            {
                return -1;
            }
            return left/right;
        default:
            break;
     }
     return -1;
}
int calculate(char str[])//计算后缀表达式
{
   qstack *s = qinitstack();//创建一个栈
   int i = 0;//记录str数组下标
   while(str[i]!= '\0')
   {
        char a[6] = {0};//用于存储数字
        int j = 0;//记录a数组下标
        if (judgenum(str[i]))//如果是数字，直接入栈
        {
            while(judgenum(str[i]))//如果是数字  
            {
                a[j] = str[i];
                i++;
                j++;
            }
            //将a数组中的数字转换为int类型
            int num = atoi(a);//函数全称：ASCII to integer,作用是将字符串转化为相应的整数
            qpush(s,num);//数字入栈
        }
        else if (judgeop(str[i]))//如果是运算符
        {
            int right = qpop(s);//栈顶元素出栈
            int left = qpop(s);//栈顶元素出栈
            int result = express(left,right,str[i]);//计算结果
            if(result == -1) 
            {
                printf("除数不能为0,操作失败\n");//除数不能为0
                return -1;  
            }
            qpush(s,result);//结果入栈
        }
        else if(str[i] == ' ')//如果是空格
        {
            i++;
            continue;
        }
        else
        {
            printf("输入的表达式有无法识别的字符,操作失败\n");//输入的表达式有误
            return -1;
        }
        i++;//str数组下标后移
   }
   if(str[i] == '\0')//如果str数组遍历完毕
   {
        int result = qpop(s);//栈顶元素出栈
        return result;
   }
   return -1;
}





