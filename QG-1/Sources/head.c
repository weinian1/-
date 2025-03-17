#include"head.h"
void menu()//菜单界面函数
{
    system("cls");//清屏
	printf("----------感谢您的使用----------\n");
	printf("1  - 创建单链表\n");
	printf("2  - 创建双向链表\n");
	printf("3  - 退出系统\n");
	printf("请选择：");
	int n;
	scanf("%d",&n);
	switch(n)
	{
		case 1 :	menu1();    system("pause");	break;
		case 2 :	menu2();	system("pause");	break;
        case 3 :    exit(0);
		default:    printf("您的输入不合法，为您终止程序"); 
		system("pause");
		exit(0); 
	}
}
void menu1()//单链表操作
{
	Listnode_1* list1 = NULL;
    Listnode_1 temp1;
    int n;
    printf("请输入链表节点数: ");
    scanf("%d", &n);
    int i; 
    for( i = 0; i < n; i++) {
        printf("请输入第 %d 个节点的数据: ", i + 1);
        scanf("%d", &temp1.data);
        addnode(&list1, &temp1);
    }
	printN(list1);
    printf("单链表创建成功！\n");
	system("pause");
	system("cls");//清屏
	printf("1  - 单链表奇偶调换\n");
	printf("2  - 单链表寻找中间节点\n");
	printf("3  - 判断单链表是否成环\n");
	printf("4 - 单链表反转\n");
	printf("5 - 使已有的单链表成环\n");
	int n1;
	scanf("%d",&n1);
	switch(n1)
	{
		case 1 :	exchangeN(list1);    system("pause");	break;
		case 2 :	findMidN(list1);     system("pause");	break;
		case 3 :	judgecircle_1(list1);system("pause");	break;
		case 4 :	reversal_1(list1);   system("pause");	break;
		case 5 :	circle_1(list1,&temp1);     system("pause");	break;
		default:    printf("您的输入不合法，为您终止程序");
		system("pause");exit(0);
	}
}
void menu2()//双向链表操作
{
	Listnode_2* head = NULL;
    Listnode_2* tail = NULL;
    int n;
    printf("请输入双向链表节点数: ");
    scanf("%d", &n);
    int i;
    for ( i = 0; i < n; i++) {
        Listnode_2* newNode = (Listnode_2*)malloc(sizeof(Listnode_2));
        if (newNode == NULL) {
            printf("内存分配失败！\n");
            return;
        }
        printf("请输入第 %d 个节点的数据: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->pre = NULL;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }
    // 打印双向链表
    Listnode_2* current = head;
    printf("双向链表数据：\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    printf("双向链表创建成功！\n");
	system("pause");
	system("cls");//清屏
	printf("1  - 判断双向链表是否成环\n");
	printf("2 - 双向链表反转\n");
	printf("3 - 使已有的双向链表成环\n");
	int n2;
	scanf("%d",&n2);
	switch(n2)
	{
		case 1 :	judgecircle_2(head,tail);system("pause");	break;
		case 2 :	reversal_2(head,tail);   system("pause");	break;
		case 3 :	circle_2(head,tail);     system("pause");	break;
		default:    printf("您的输入不合法，为您终止程序");
		system("pause");exit(0);
	}
}
Listnode_1* findnode(Listnode_1* root,int n)//寻找节点函数
{
    if(n < 0) return NULL;
	if(root == NULL) return NULL;
	if(n == 0) return root;
	int i = 0;
	for(; i < n; i++)
	{
		if(root == NULL) return NULL;
		root = root->next ;
	}
	return root;
}
void deleteN(Listnode_1** root,int n)//删除节点函数
{
    if(root == NULL) return;
	if(*root == NULL) return;
	if(n < 0) return;
	Listnode_1* del = *root;
	Listnode_1* delpret = NULL;
	if(n == 0)
	{
		*root = del->next;
		free(del);
		return;
	}	
	delpret = findnode(*root,n-1);
	del = delpret->next;
	if(del == NULL) return;
	delpret->next = del->next;
	free(del);
	// del的前一个next指针指向del的下一个节点 
}
void deletelist(Listnode_1** root)//删除整个链表函数
{
    while(1)
	{
		if(*root == NULL) return;
		deleteN(root,0);
	}
}
Listnode_1* createN(Listnode_1* data)//创建链表节点的函数
{
    if(data == NULL) return NULL;
	Listnode_1* new = (Listnode_1*)malloc(sizeof(Listnode_1));
	if(new == NULL) return NULL;
	new->next       = NULL;
	//粘贴传进来的数据 
	new->data = data->data; 
	return new;
}
void addnode(Listnode_1** root,Listnode_1* data)//增加节点到链表尾部的函数
{
	if(root == NULL) return;
	if(*root == NULL) //传入空链表 
	{
		*root = createN(data);
		return;
	}
	Listnode_1* temp = *root;
	//让temp指向最后一个节点
	while(temp->next) temp = temp->next ;
	//把新结点添加到 temp后面
	temp->next = createN(data);
	return; 
}
void printN(Listnode_1* root)//打印链表的函数
{
    system("cls");
	if(root == NULL) return;
	while(root)
	{
		printf("%d-> ",root->data);
		root = root->next;	
	}
    printf("NULL\n");
	return;
}
void exchangeN(Listnode_1* list1)//菜单界面调用的单链表奇偶调换函数
{
    // 交换奇偶节点
    if (list1 == NULL || list1->next == NULL)
    {
        printf("链表节点不足，无法交换！\n");
        return;
    }
    Listnode_1* prev = NULL;
    Listnode_1* current = list1;
    Listnode_1* next = NULL;
    while (current != NULL && current->next != NULL)
    {
        next = current->next;
        current->next = next->next;
        next->next = current;

        if (prev == NULL)
        {
            list1 = next;
        }
        else
        {
            prev->next = next;
        }

        prev = current;
        current = current->next;
    }
    // 打印交换后的链表
    printN(list1);
    // 释放内存
    deletelist(&list1);
    printf("单链表奇偶调换成功！\n");
}
void findMidN(Listnode_1* list1)//菜单界面调用的单链表寻找中间节点函数
{
    if (list1 == NULL)
    {
        printf("链表为空，无法找到中间节点！\n");
        return;
    }
    Listnode_1* slow = list1;
    Listnode_1* fast = list1;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("中间节点的数据是: %d\n", slow->data);
    // 释放内存
    deletelist(&list1);
}
void judgecircle_1(Listnode_1* list1)//菜单界面调用的判断单链表是否成环函数
{
    Listnode_1* slow = list1;
    Listnode_1* fast = list1;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            printf("单链表已成环！\n");
            deletelist(&list1);
            return;
        }
    }
    printf("单链表未成环！\n");
    deletelist(&list1);
}
void judgecircle_2(Listnode_2* head,Listnode_2* tail)//菜单界面调用的判断双向链表是否有环函数
{
    if (head == NULL)
    {
        printf("双向链表为空，无法判断是否成环！\n");
        return;
    }
    Listnode_2* slow = head;
    Listnode_2* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            printf("双向链表已成环！\n");
            // 释放内存
            Listnode_2* current = head;
            while (current != NULL) {
                Listnode_2* temp = current;
                current = current->next;
                free(temp);
            }
            return;
        }
    }
    printf("双向链表未成环！\n");
    // 释放内存
    Listnode_2* current = head;
    while (current != NULL) {
        Listnode_2* temp = current;
        current = current->next;
        free(temp);
    }
}
void reversal_1(Listnode_1* list)//菜单界面调用的单链表反转函数
{
    if (list == NULL)
    {
        printf("链表为空，无法反转！\n");
        return;
    }
    Listnode_1* prev = NULL;
    Listnode_1* current = list;
    Listnode_1* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list = prev;
    // 打印反转后的链表
    printN(list);
    // 释放内存
    deletelist(&list);
    printf("单链表反转成功！\n");
}
void reversal_2(Listnode_2* head,Listnode_2* tail)//菜单界面调用的双向链表反转函数
{
    if (head == NULL)
    {
        printf("双向链表为空，无法反转！\n");
        return;
    }
    Listnode_2* current = head;
    Listnode_2* temp = NULL;
    // 反转双向链表
    while (current != NULL)
    {
        temp = current->pre;
        current->pre = current->next;
        current->next = temp;
        current = current->pre;
    }
    if (temp != NULL)
    {
        head = temp->pre;
    }
    // 打印反转后的双向链表
    current = head;
    printf("反转后的双向链表数据：\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    // 释放内存
    current = head;
    while (current != NULL) {
        Listnode_2* temp = current;
        current = current->next;
        free(temp);
    }
    printf("双向链表反转成功！\n");
}
void circle_1(Listnode_1*list1,Listnode_1* temp1 )//菜单界面调用的创建单链表环的函数
{
	temp1->next = list1;
	printf("单链表已成环！\n");
}
void circle_2(Listnode_2* head,Listnode_2* tail)//菜单界面调用的创建双向链表环的函数
{
	tail->next = head;
	printf("双向链表已成环！\n");
}
