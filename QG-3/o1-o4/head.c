#include"head.h"
void menu()//菜单函数定义
{
  system("cls");
  printf("1--不同大数据量排序函数性能测试\n");
  printf("2--大量小数据量排序函数性能测试\n");
  printf("0--退出程序\n");
  printf("请输入你的选择：\n");
  int n;
  scanf("%d", &n);
  switch (n) 
  {
  case 1:   menul();     break; // 不同大数据量排序函数性能测试
  case 2:   menus();      break; // 大量小数据量排序函数性能测试
  case 0:                exit(0);
  default:       printf("输入错误，请重新输入\n");    break;  
  }
}
void menul()//大数据量菜单函数定义
{
    while(1)
    {
        system("cls");
        int arr[200000] = {0};
        int t,a;// 数组长度，由用户选择
        printf("请选择测试数据的规模：\n");
        printf("1--10000个0-99999之间的随机数\n");
        printf("2--50000个0-99999之间的随机数\n");
        printf("3--200000个0-99999之间的随机数\n");
        printf("输入0返回上一级菜单\n");
        scanf("%d", &t);
        switch (t) { // 根据用户选择的规模设置数组长度和随机数范围
        case 1:     a = 10000;      break;
        case 2:     a = 50000;      break;
        case 3:     a = 200000;     break;
        case 0:     return;
        default:  printf("输入错误，请重新输入\n"); return;  
        }
        srand((unsigned)time(NULL)); //设置随机数种子
        for (int i = 0; i < a; i++) 
        {
            arr[i] = rand() % 100000; //生成随机数，范围为 0 到 99999
        }
        fc(arr, a); // 将生成的数据写入文件中
        system("cls");
        printf("1--使用插入排序法处理数据\n");
        printf("2--使用归并排序法处理数据\n");
        printf("3--使用快速排序法处理数据\n");
        printf("4--使用计数排序法处理数据\n");
        printf("5--使用基数计数法排序法处理数据\n");
        printf("请输入你要进行的操作\n");
        printf("输入0返回上一级菜单\n");
        
        int n;
        scanf("%d", &n);
        switch (n) 
        {
            case 1: InsertSort(arr,a);          break;
            case 2: MergeSort(arr, a);          break;
            case 3: QuickSort(arr, a);          break;
            case 4: CountSort(arr, a);          break;
            case 5: RadixCountSort(arr, a);     break;
            case 0:        return;
            default:        printf("输入错误，请重新输入\n");        break;
        }
    }  
}
// void print(int arr[], int n)//打印数组函数定义
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
void fr(int arr[], int n)
{
     //从文件中读取数据到数组中
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL)
    { 
        printf("无法打开文件\n");
        return;
    }
    for (int i = 0; i < n; i++) 
    { 
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
}
void fc(int arr[], int n)
{
    //将数组中的数据写入文件中
    FILE* fp = fopen("data.txt", "w");
    if (fp == NULL)
    { 
        printf("无法打开文件\n"); 
        return; 
    }
    for (int i = 0; i < n; i++)
    { 
        fprintf(fp, "%d ", arr[i]);
    } 
    fclose(fp);
}
void InsertSort(int arr[], int n)//插入排序函数定义
{
    fr(arr, n);
    if(arr==NULL||n<=1)// 数组为空或只有一个元素时，不需要排序直接返回
    {
        if(arr==NULL) printf("请先在文件中创建测试数据\n");//提高健壮性，防止学长测试老是有bug
        return;
    }
    clock_t start, end; // 定义起始时间和结束时间变量
    start = clock(); // 记录起始时间
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];//当前要插入的元素
        int j = i - 1;
        //将已排序部分的元素向后移动，直到找到插入位置
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // 将当前元素插入到正确位置
        arr[j + 1] = key;
    }
    end = clock(); // 记录结束时间
    printf("插入排序算法耗时：%ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    fc(arr, n);
    system("pause");
}
void Merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1; // 左子数组的大小
    int n2 = right - mid;    // 右子数组的大小
    // 创建左右临时数组
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    // 将数据复制到临时数组
    for (int i = 0; i < n1; i++) 
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) 
    {
        R[j] = arr[mid + 1 + j];
    }
    // 合并两个临时数组到原数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) 
        {
            arr[k] = L[i];
            i++;
        } 
        else 
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // 复制剩余的元素
    while (i < n1) 
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    // 释放临时数组
    free(L);
    free(R);
}
void MergeSortRecursive(int arr[], int left, int right) //归并排序递归函数定义
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2; //计算中间点
        MergeSortRecursive(arr, left, mid); //递归排序左子数组
        MergeSortRecursive(arr, mid + 1, right); //递归排序右子数组
        Merge(arr, left, mid, right); //合并两个子数组
    }
}
void MergeSort(int arr[], int n)//归并排序函数定义
{
    fr(arr, n); //从文件中读取数据
    if (arr == NULL || n <= 1) //数组为空或只有一个元素时，不需要排序
    { 
        if (arr == NULL) printf("请先在文件中创建测试数据\n");
        return;
    }
    clock_t start, end; //定义起始时间和结束时间变量
    start = clock(); //记录起始时间
    MergeSortRecursive(arr, 0, n - 1); //调用递归归并排序
    end = clock(); //记录结束时间
    printf("归并排序算法耗时：%ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    fc(arr, n); //将排序后的数据写入文件
    system("pause");
}
// 快速排序的分区函数
int Partition(int arr[], int low, int high) 
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
//快速排序的递归函数
void QuickSortRecursive(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = Partition(arr, low, high); //获取分区索引
        QuickSortRecursive(arr, low, pi - 1);  //递归排序左子数组
        QuickSortRecursive(arr, pi + 1, high); //递归排序右子数组
    }
}
//快速排序的主函数
void QuickSort(int arr[], int n) 
{
    fr(arr, n); //从文件中读取数据
    if (arr == NULL || n <= 1) 
    { //数组为空或只有一个元素时，不需要排序
        if (arr == NULL) printf("请先在文件中创建测试数据\n");
        return;
    }
    clock_t start, end; //定义起始时间和结束时间变量
    start = clock(); //记录起始时间
    QuickSortRecursive(arr, 0, n - 1); //调用递归快速排序
    end = clock(); //记录结束时间
    printf("快速排序算法耗时：%ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    fc(arr, n); //将排序后的数据写入文件
    system("pause");
}
void CountSort(int arr[], int n) 
{
    fr(arr, n); //从文件中读取数据
    if (arr == NULL || n <= 1) //数组为空或只有一个元素时，不需要排序
    { 
        if (arr == NULL) printf("请先在文件中创建测试数据\n");
        return;
    }
    clock_t start, end; //定义起始时间和结束时间变量
    start = clock(); //记录起始时间
    //找到数组中的最大值和最小值
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    int range = max - min + 1; //计算范围
    int *count = (int *)calloc(range, sizeof(int)); //创建计数数组并初始化为0
    if (count == NULL) 
    {
        printf("内存分配失败\n");
        return;
    }
    //统计每个元素的出现次数
    for (int i = 0; i < n; i++) 
    {
        count[arr[i] - min]++;
    }
    //根据计数数组重新填充原数组
    int index = 0;
    for (int i = 0; i < range; i++) 
    {
        while (count[i] > 0) 
        {
            arr[index++] = i + min;
            count[i]--;
        }
    }
    free(count); //释放计数数组的内存
    end = clock(); //记录结束时间
    printf("计数排序算法耗时：%ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    fc(arr, n); //将排序后的数据写入文件
    system("pause");
}
void RadixCountSort(int arr[], int n) //基数排序函数定义
{
    fr(arr, n); // 从文件中读取数据
    if (arr == NULL || n <= 1) // 数组为空或只有一个元素时，不需要排序
    { 
        if (arr == NULL) printf("请先在文件中创建测试数据\n");
        return;
    }
    clock_t start, end; // 定义起始时间和结束时间变量
    start = clock(); // 记录起始时间
    // 找到数组中的最大值
    int max = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max) max = arr[i];
    }
    // 基数排序的核心逻辑
    int exp = 1; // 从个位开始排序
    int *output = (int *)malloc(n * sizeof(int)); // 临时数组用于存储排序结果
    if (output == NULL) 
    {
        printf("内存分配失败\n");
        return;
    }
    while (max / exp > 0) 
    {
        int count[10] = {0}; // 计数数组，用于统计每一位数字的出现次数
        // 统计每一位数字的出现次数
        for (int i = 0; i < n; i++) 
        {
            count[(arr[i] / exp) % 10]++;
        }
        // 累加计数数组，计算每个数字的最终位置
        for (int i = 1; i < 10; i++) 
        {
            count[i] += count[i - 1];
        }
        // 根据计数数组，将元素放入正确的位置
        for (int i = n - 1; i >= 0; i--) 
        {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        // 将排序结果复制回原数组
        for (int i = 0; i < n; i++) 
        {
            arr[i] = output[i];
        }
        exp *= 10; // 处理下一位
    }
    free(output); // 释放临时数组的内存
    end = clock(); // 记录结束时间
    printf("基数排序算法耗时：%ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    fc(arr, n); // 将排序后的数据写入文件
    system("pause");
}
void menus()//大量小数据量菜单函数定义
{
    while (1)
    {
        system("cls"); 
        printf("请选择要测试的排序算法：\n");
        printf("1--插入排序\n");
        printf("2--归并排序\n");
        printf("3--快速排序\n");
        printf("4--计数排序\n");
        printf("5--基数排序\n");
        printf("输入0返回上一级菜单\n");
        printf("PS:大量小数据量的排序真的很慢，请耐心等待\n");
        int n;
        scanf("%d", &n);
        int arr[100]; //定义一个大小为100的数组
        int it = 100000; //排序次数
        clock_t start1, end1; //定义起始时间和结束时间变量
        start1 = clock(); //记录起始时间
        for (int i = 0; i < it; i++) 
        {
            // 生成随机数据
            for (int j = 0; j < 100; j++) 
            {
                arr[j] = rand() % 1000; // 生成范围为0到999的随机数
            }
            // 根据用户选择调用对应的排序算法
            switch (n) 
            {
                case 1: InsertSort1(arr, 100); break;
                case 2: MergeSort1(arr, 100); break;
                case 3: QuickSort1(arr, 100); break;
                case 4: CountSort1(arr, 100); break;
                case 5: RadixCountSort1(arr, 100); break;
                case 0: return;
                default: 
                    printf("输入错误，请重新输入\n");system("pause");break;
            }
        }
        end1 = clock(); // 记录结束时间
        // 输出排序结果和总耗时
        printf("排序算法 %d 在 100 个数据 * 100000 次排序下的总耗时：%ldms\n", n, (end1 - start1) * 1000 / CLOCKS_PER_SEC);
        system("pause");
    }
}
void InsertSort1(int arr[], int n)//插入排序函数定义
{
    fr(arr, n);
    if(arr==NULL||n<=1)// 数组为空或只有一个元素时，不需要排序直接返回
    {
        if(arr==NULL) printf("请先在文件中创建测试数据\n");//提高健壮性，防止学长测试老是有bug
        return;
    }
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];//当前要插入的元素
        int j = i - 1;
        //将已排序部分的元素向后移动，直到找到插入位置
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // 将当前元素插入到正确位置
        arr[j + 1] = key;
    }
    fc(arr, n);
}
void MergeSort1(int arr[], int n)//归并排序函数定义
{
    fr(arr, n); //从文件中读取数据
    if (arr == NULL || n <= 1) //数组为空或只有一个元素时，不需要排序
    { 
        if (arr == NULL) printf("请先在文件中创建测试数据\n");
        return;
    }
    MergeSortRecursive(arr, 0, n - 1); //调用递归归并排序
    fc(arr, n); //将排序后的数据写入文件
}
//快速排序的主函数
void QuickSort1(int arr[], int n) 
{
    fr(arr, n); //从文件中读取数据
    if (arr == NULL || n <= 1) 
    { //数组为空或只有一个元素时，不需要排序
        if (arr == NULL) printf("请先在文件中创建测试数据\n");
        return;
    }
    QuickSortRecursive(arr, 0, n - 1); //调用递归快速排序
    fc(arr, n); //将排序后的数据写入文件
}
void CountSort1(int arr[], int n) 
{
    fr(arr, n); //从文件中读取数据
    if (arr == NULL || n <= 1) //数组为空或只有一个元素时，不需要排序
    { 
        if (arr == NULL) printf("请先在文件中创建测试数据\n");
        return;
    }
    //找到数组中的最大值和最小值
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    int range = max - min + 1; //计算范围
    int *count = (int *)calloc(range, sizeof(int)); //创建计数数组并初始化为0
    if (count == NULL) 
    {
        printf("内存分配失败\n");
        return;
    }
    //统计每个元素的出现次数
    for (int i = 0; i < n; i++) 
    {
        count[arr[i] - min]++;
    }
    //根据计数数组重新填充原数组
    int index = 0;
    for (int i = 0; i < range; i++) 
    {
        while (count[i] > 0) 
        {
            arr[index++] = i + min;
            count[i]--;
        }
    }
    free(count); //释放计数数组的内存
    fc(arr, n); //将排序后的数据写入文件
}
void RadixCountSort1(int arr[], int n) //基数排序函数定义
{
    fr(arr, n); // 从文件中读取数据
    if (arr == NULL || n <= 1) // 数组为空或只有一个元素时，不需要排序
    { 
        if (arr == NULL) printf("请先在文件中创建测试数据\n");
        return;
    }
    // 找到数组中的最大值
    int max = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max) max = arr[i];
    }
    // 基数排序的核心逻辑
    int exp = 1; // 从个位开始排序
    int *output = (int *)malloc(n * sizeof(int)); // 临时数组用于存储排序结果
    if (output == NULL) 
    {
        printf("内存分配失败\n");
        return;
    }
    while (max / exp > 0) 
    {
        int count[10] = {0}; // 计数数组，用于统计每一位数字的出现次数
        // 统计每一位数字的出现次数
        for (int i = 0; i < n; i++) 
        {
            count[(arr[i] / exp) % 10]++;
        }
        // 累加计数数组，计算每个数字的最终位置
        for (int i = 1; i < 10; i++) 
        {
            count[i] += count[i - 1];
        }
        // 根据计数数组，将元素放入正确的位置
        for (int i = n - 1; i >= 0; i--) 
        {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        // 将排序结果复制回原数组
        for (int i = 0; i < n; i++) 
        {
            arr[i] = output[i];
        }
        exp *= 10; // 处理下一位
    }
    free(output); // 释放临时数组的内存
    fc(arr, n); // 将排序后的数据写入文件
}