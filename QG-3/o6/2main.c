#include <stdio.h>
int Partition(int arr[], int low, int high) //从o1-o4中复制的
{
    int pivot = arr[high]; //选择最后一个元素作为基准
    int i = low - 1;       //i是小于基准的区域的最后一个元素索引
    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) //如果当前元素小于等于基准
        { 
            i++;
            //交换 arr[i] 和 arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //将基准元素放到正确的位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1; //返回基准元素的索引
}
int findk(int arr[], int low, int high, int k) {
    if (low <= high) {
        int Index = Partition(arr, low, high);

        if (Index == k - 1) 
        {// 如果索引恰好是目标位置
            return arr[Index];
        } else if (Index > k - 1)
        {// 如果索引目标位置右侧
            return findk(arr, low, Index - 1, k);
        } else 
        { // 如果索引目标位置左侧
            return findk(arr, Index + 1, high, k);
        }
    }
    return -1; // 如果越界，返回-1
}
int main()
{
    int a ;
    printf("请输入数组长度：");
    scanf("%d", &a);
    int arr[a];
    printf("请输入数组元素：");
    for (int i = 0; i < a; i++) 
    {
        scanf("%d", &arr[i]); 
    }
    int k;
    printf("请输入要查找的排位数 k:");
    scanf("%d", &k);
    if (k < 1 || k > a) 
    {
        printf("输入的 k 超出范围！\n");
        return 0;  
    }
    int result = findk(arr, 0, a - 1, k);
    printf("数组中第 %d 小的数字是：%d\n", k, result);
    return 0;
}