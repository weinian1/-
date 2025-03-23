#include "head.h"


//��ջ�Ļ�������
pstack* pinitstack()//��ʼ��ջ���ߴ���ջ
{
    pstack *s = (pstack *)malloc(sizeof(pstack));
    if(s != NULL)
    {
        s->top = NULL;
        s->cnt = 0;
    }
    return s;
}
bool pjudgeempty(pstack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if (s->cnt == 0) return true;
    else return false;
}
void ppush(pstack *s,char p)//��ջ
{
    pnode *ptemp;
    ptemp = (pnode *)malloc(sizeof(pnode));
    if (ptemp == NULL) 
    {
        printf("�ڴ����ʧ��\n");
        return;
    }
    ptemp->data = p;
    ptemp->next = s->top;
    s->top = ptemp;
    s->cnt++;
    return;
}
pnode* ppop(pstack *s)//ջ��Ԫ�س�ջ
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

pnode *ptop(pstack *s)//��ȡջ��Ԫ�����ݽڵ�
{
    if (s->top == NULL) return NULL;
    return s->top;
}


//��׺���ʽת��׺���ʽ�ĺ����ľ���ʵ��
void putre(char p)//���ַ�����result����
{
    static int i = 0;//��̬������ֻ��ʼ��һ�Σ���¼result�����±�
    result[i] = p;
    i++;
    return;
}
int rate(char p)//�ж���������ȼ�
{
    if (p == '+' || p == '-') return 1;
    if (p == '*' || p == '/') return 2;
    if (p == '(') return 0;
    if (p == ')') return 3;
    return -1;
}
bool judgenum(char p)//�ж��ǲ�������
{
    if (p >= '0' && p <= '9') return true;
    return false;
}
bool judgeop(char p)//�ж��ǲ��������
{
    if (p == '+' || p == '-' || p == '*' || p == '/') return true;
    return false;
}
bool judgeright(char p)//�ж��ǲ���������
{
    if (p == ')') return true;
    return false;
}
bool judgeleft(char p)//�ж��ǲ���������
{
    if (p == '(') return true;
    return false;
}
bool trans(char *str)//��׺���ʽת��׺���ʽ,����ֵΪ���ʾת���ɹ�
{
    pstack *s1 = pinitstack();//����һ��ջ
    int i = 0;//��¼str�����±�
    while(str[i] != '\0')
    {
        if (judgenum(str[i]))//��������֣�ֱ����� 
        {
            if(judgenum(str[i+1]))//����1Ҳ������,��ֱ�ӷ�
            {
                putre(str[i]);//����ֱ�ӷ�������(�����)
            }
            else//���治������,���һ���ո���Ϊ�ָ���
            {
                putre(str[i]);
                putre(' ');//�ÿո�����¼��λ������
            }
        }
        else if (judgeop(str[i]))//����������
        {
            if(str[i+1]=='0'&&str[i]=='/')
            {
                printf("��������Ϊ0,����ʧ��\n");//��������Ϊ0
                return false;
            }
            if (!pjudgeempty(s1))//���ջ��Ϊ��
            {
                while((!pjudgeempty(s1))&&(rate(str[i]) <= rate(ptop(s1)->data)))//���ջ��Ϊ���ҵ�ǰ��������ȼ�С�ڵ���ջ����������ȼ�
                {
                    pnode *p = ppop(s1);//ջ��Ԫ�س�ջ
                    putre(p->data);//��ջ��Ԫ�����
                    putre(' ');//�ÿո�����¼��λ������
                }
            }
            ppush(s1,str[i]);//��ǰ�������ջ
        }
        else if (judgeleft(str[i]))//�����������
        {
            ppush(s1,str[i]);//��������ջ
        }
        else if (judgeright(str[i]))//�����������
        {
            while((ptop(s1)->data != '('))//���ջ��Ԫ�ز���������
            {
                pnode *p = ppop(s1);//ջ��Ԫ�س�ջ
                putre(p->data);//��ջ��Ԫ�����
                if(pjudgeempty(s1))
                {
                    printf("ȱ��������,����ʧ��\n");//ȱ��������
                    return false;
                }
            } 
            ppop(s1);//�������ų�ջ,�������ŵ���
        }
        else
        {
            printf("����ı��ʽ���޷�ʶ����ַ�,����ʧ��\n");//����ı��ʽ����
            return false;
        }
        i++;//str�����±����
    }
    if(str[i] == '\0')//���str����������
    {
        while(!pjudgeempty(s1))//���ջ��Ϊ��
        {
            pnode *p = ppop(s1);//ջ��Ԫ�س�ջ
            if(p->data == '(')
            {
                printf("ȱ��������,����ʧ��\n");//ȱ��������
                return false;
            }
            putre(p->data);//��ջ��Ԫ�����
        }
    }
    else
    {
        printf("����û����ɣ�\n");
    }
    return true;
}


//�����׺���ʽ���躯���ľ���ʵ��
qstack* qinitstack()//��ʼ��ջ
{
    qstack *s = (qstack *)malloc(sizeof(qstack));
    if(s != NULL)
    {
        s->top = NULL;
        s->cnt = 0;
    }
    return s;
}
bool qjudgeempty(qstack *s)//�ж�ջ�Ƿ�Ϊ��
{
    if(s->cnt == 0) return true;
    else return false;
}
void qpush(qstack *s,int q)//��ջ
{
    qnode *qtemp;
    qtemp = (qnode *)malloc(sizeof(qnode));
    if (qtemp == NULL) 
    {
        printf("�ڴ����ʧ��\n");
        return;
    }
    qtemp->data = q;
    qtemp->next = s->top;
    s->top = qtemp;
    s->cnt++;
    return;
}
int qpop(qstack *s)//Ԫ�س�ջ������ջ��Ԫ��
{
   if(qjudgeempty(s)) return -1;
   int q = s->top->data;
   s->top = s->top->next;
   s->cnt--; 
   return q;//���ص��������ݽڵ�
}
int qtop(qstack *s)//��ȡջ��Ԫ�����ݽڵ�
{
    if (s->top == NULL) return -1;
    return s->top->data;
}
int express(int left,int right,char op)//opΪ�����,����������
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
int calculate(char str[])//�����׺���ʽ
{
   qstack *s = qinitstack();//����һ��ջ
   int i = 0;//��¼str�����±�
   while(str[i]!= '\0')
   {
        char a[6] = {0};//���ڴ洢����
        int j = 0;//��¼a�����±�
        if (judgenum(str[i]))//��������֣�ֱ����ջ
        {
            while(judgenum(str[i]))//���������  
            {
                a[j] = str[i];
                i++;
                j++;
            }
            //��a�����е�����ת��Ϊint����
            int num = atoi(a);//����ȫ�ƣ�ASCII to integer,�����ǽ��ַ���ת��Ϊ��Ӧ������
            qpush(s,num);//������ջ
        }
        else if (judgeop(str[i]))//����������
        {
            int right = qpop(s);//ջ��Ԫ�س�ջ
            int left = qpop(s);//ջ��Ԫ�س�ջ
            int result = express(left,right,str[i]);//������
            if(result == -1) 
            {
                printf("��������Ϊ0,����ʧ��\n");//��������Ϊ0
                return -1;  
            }
            qpush(s,result);//�����ջ
        }
        else if(str[i] == ' ')//����ǿո�
        {
            i++;
            continue;
        }
        else
        {
            printf("����ı��ʽ���޷�ʶ����ַ�,����ʧ��\n");//����ı��ʽ����
            return -1;
        }
        i++;//str�����±����
   }
   if(str[i] == '\0')//���str����������
   {
        int result = qpop(s);//ջ��Ԫ�س�ջ
        return result;
   }
   return -1;
}





