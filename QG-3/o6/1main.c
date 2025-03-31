#include <stdio.h>
void sort(int arr[],int a)
{
    int left = 0;
    int right = a-1;
    int temp;
    for(int i = 0; i < a; i++)
    {
        if(arr[i] == 0)//等于0的元素放在左边，同时索引右移
        {
           temp = arr[left];
           arr[left] = arr[i];
           arr[i] = temp;
           left++;
        }
        else if(arr[i] == 2)      
        //等于2的元素放在右边，同时索引左移，注意此时i不移动，因为i位置元素还未判断
        {
           temp = arr[right];
           arr[right] = arr[i];
           arr[i] = temp;
           right--;
           i--;
        }
    }
}
int main()
{
    int a;
    printf("请输入数组长度：\n ");
    scanf("%d",&a);
    int arr[a];
    printf("请输入数组元素(只能是0,1,2):\n ");
    for(int i=0;i<a;i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr,a);
    printf("排序后的数组为：\n ");
    for(int i = 0; i < a; i ++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
