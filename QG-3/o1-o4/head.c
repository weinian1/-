#include"head.h"
void menu()//�˵���������
{
  system("cls");
  printf("1--��ͬ�����������������ܲ���\n");
  printf("2--����С���������������ܲ���\n");
  printf("0--�˳�����\n");
  printf("���������ѡ��\n");
  int n;
  scanf("%d", &n);
  switch (n) 
  {
  case 1:   menul();     break; // ��ͬ�����������������ܲ���
  case 2:   menus();      break; // ����С���������������ܲ���
  case 0:                exit(0);
  default:       printf("�����������������\n");    break;  
  }
}
void menul()//���������˵���������
{
    while(1)
    {
        system("cls");
        int arr[200000] = {0};
        int t,a;// ���鳤�ȣ����û�ѡ��
        printf("��ѡ��������ݵĹ�ģ��\n");
        printf("1--10000��0-99999֮��������\n");
        printf("2--50000��0-99999֮��������\n");
        printf("3--200000��0-99999֮��������\n");
        printf("����0������һ���˵�\n");
        scanf("%d", &t);
        switch (t) { // �����û�ѡ��Ĺ�ģ�������鳤�Ⱥ��������Χ
        case 1:     a = 10000;      break;
        case 2:     a = 50000;      break;
        case 3:     a = 200000;     break;
        case 0:     return;
        default:  printf("�����������������\n"); return;  
        }
        srand((unsigned)time(NULL)); //�������������
        for (int i = 0; i < a; i++) 
        {
            arr[i] = rand() % 100000; //�������������ΧΪ 0 �� 99999
        }
        fc(arr, a); // �����ɵ�����д���ļ���
        system("cls");
        printf("1--ʹ�ò������򷨴�������\n");
        printf("2--ʹ�ù鲢���򷨴�������\n");
        printf("3--ʹ�ÿ������򷨴�������\n");
        printf("4--ʹ�ü������򷨴�������\n");
        printf("5--ʹ�û������������򷨴�������\n");
        printf("��������Ҫ���еĲ���\n");
        printf("����0������һ���˵�\n");
        
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
            default:        printf("�����������������\n");        break;
        }
    }  
}
// void print(int arr[], int n)//��ӡ���麯������
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
void fr(int arr[], int n)
{
     //���ļ��ж�ȡ���ݵ�������
    FILE* fp = fopen("data.txt", "r");
    if (fp == NULL)
    { 
        printf("�޷����ļ�\n");
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
    //�������е�����д���ļ���
    FILE* fp = fopen("data.txt", "w");
    if (fp == NULL)
    { 
        printf("�޷����ļ�\n"); 
        return; 
    }
    for (int i = 0; i < n; i++)
    { 
        fprintf(fp, "%d ", arr[i]);
    } 
    fclose(fp);
}
void InsertSort(int arr[], int n)//��������������
{
    fr(arr, n);
    if(arr==NULL||n<=1)// ����Ϊ�ջ�ֻ��һ��Ԫ��ʱ������Ҫ����ֱ�ӷ���
    {
        if(arr==NULL) printf("�������ļ��д�����������\n");//��߽�׳�ԣ���ֹѧ������������bug
        return;
    }
    clock_t start, end; // ������ʼʱ��ͽ���ʱ�����
    start = clock(); // ��¼��ʼʱ��
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];//��ǰҪ�����Ԫ��
        int j = i - 1;
        //�������򲿷ֵ�Ԫ������ƶ���ֱ���ҵ�����λ��
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // ����ǰԪ�ز��뵽��ȷλ��
        arr[j + 1] = key;
    }
    end = clock(); // ��¼����ʱ��
    printf("���������㷨��ʱ��%ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    fc(arr, n);
    system("pause");
}
void Merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1; // ��������Ĵ�С
    int n2 = right - mid;    // ��������Ĵ�С
    // ����������ʱ����
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    // �����ݸ��Ƶ���ʱ����
    for (int i = 0; i < n1; i++) 
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) 
    {
        R[j] = arr[mid + 1 + j];
    }
    // �ϲ�������ʱ���鵽ԭ����
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
    // ����ʣ���Ԫ��
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
    // �ͷ���ʱ����
    free(L);
    free(R);
}
void MergeSortRecursive(int arr[], int left, int right) //�鲢����ݹ麯������
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2; //�����м��
        MergeSortRecursive(arr, left, mid); //�ݹ�������������
        MergeSortRecursive(arr, mid + 1, right); //�ݹ�������������
        Merge(arr, left, mid, right); //�ϲ�����������
    }
}
void MergeSort(int arr[], int n)//�鲢����������
{
    fr(arr, n); //���ļ��ж�ȡ����
    if (arr == NULL || n <= 1) //����Ϊ�ջ�ֻ��һ��Ԫ��ʱ������Ҫ����
    { 
        if (arr == NULL) printf("�������ļ��д�����������\n");
        return;
    }
    clock_t start, end; //������ʼʱ��ͽ���ʱ�����
    start = clock(); //��¼��ʼʱ��
    MergeSortRecursive(arr, 0, n - 1); //���õݹ�鲢����
    end = clock(); //��¼����ʱ��
    printf("�鲢�����㷨��ʱ��%ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    fc(arr, n); //������������д���ļ�
    system("pause");
}
// ��������ķ�������
int Partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; //ѡ�����һ��Ԫ����Ϊ��׼
    int i = low - 1;       //i��С�ڻ�׼����������һ��Ԫ������
    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) //�����ǰԪ��С�ڵ��ڻ�׼
        { 
            i++;
            //���� arr[i] �� arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //����׼Ԫ�طŵ���ȷ��λ��
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1; //���ػ�׼Ԫ�ص�����
}
//��������ĵݹ麯��
void QuickSortRecursive(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = Partition(arr, low, high); //��ȡ��������
        QuickSortRecursive(arr, low, pi - 1);  //�ݹ�������������
        QuickSortRecursive(arr, pi + 1, high); //�ݹ�������������
    }
}
//���������������
void QuickSort(int arr[], int n) 
{
    fr(arr, n); //���ļ��ж�ȡ����
    if (arr == NULL || n <= 1) 
    { //����Ϊ�ջ�ֻ��һ��Ԫ��ʱ������Ҫ����
        if (arr == NULL) printf("�������ļ��д�����������\n");
        return;
    }
    clock_t start, end; //������ʼʱ��ͽ���ʱ�����
    start = clock(); //��¼��ʼʱ��
    QuickSortRecursive(arr, 0, n - 1); //���õݹ��������
    end = clock(); //��¼����ʱ��
    printf("���������㷨��ʱ��%ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    fc(arr, n); //������������д���ļ�
    system("pause");
}
void CountSort(int arr[], int n) 
{
    fr(arr, n); //���ļ��ж�ȡ����
    if (arr == NULL || n <= 1) //����Ϊ�ջ�ֻ��һ��Ԫ��ʱ������Ҫ����
    { 
        if (arr == NULL) printf("�������ļ��д�����������\n");
        return;
    }
    clock_t start, end; //������ʼʱ��ͽ���ʱ�����
    start = clock(); //��¼��ʼʱ��
    //�ҵ������е����ֵ����Сֵ
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    int range = max - min + 1; //���㷶Χ
    int *count = (int *)calloc(range, sizeof(int)); //�����������鲢��ʼ��Ϊ0
    if (count == NULL) 
    {
        printf("�ڴ����ʧ��\n");
        return;
    }
    //ͳ��ÿ��Ԫ�صĳ��ִ���
    for (int i = 0; i < n; i++) 
    {
        count[arr[i] - min]++;
    }
    //���ݼ��������������ԭ����
    int index = 0;
    for (int i = 0; i < range; i++) 
    {
        while (count[i] > 0) 
        {
            arr[index++] = i + min;
            count[i]--;
        }
    }
    free(count); //�ͷż���������ڴ�
    end = clock(); //��¼����ʱ��
    printf("���������㷨��ʱ��%ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    fc(arr, n); //������������д���ļ�
    system("pause");
}
void RadixCountSort(int arr[], int n) //��������������
{
    fr(arr, n); // ���ļ��ж�ȡ����
    if (arr == NULL || n <= 1) // ����Ϊ�ջ�ֻ��һ��Ԫ��ʱ������Ҫ����
    { 
        if (arr == NULL) printf("�������ļ��д�����������\n");
        return;
    }
    clock_t start, end; // ������ʼʱ��ͽ���ʱ�����
    start = clock(); // ��¼��ʼʱ��
    // �ҵ������е����ֵ
    int max = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max) max = arr[i];
    }
    // ��������ĺ����߼�
    int exp = 1; // �Ӹ�λ��ʼ����
    int *output = (int *)malloc(n * sizeof(int)); // ��ʱ�������ڴ洢������
    if (output == NULL) 
    {
        printf("�ڴ����ʧ��\n");
        return;
    }
    while (max / exp > 0) 
    {
        int count[10] = {0}; // �������飬����ͳ��ÿһλ���ֵĳ��ִ���
        // ͳ��ÿһλ���ֵĳ��ִ���
        for (int i = 0; i < n; i++) 
        {
            count[(arr[i] / exp) % 10]++;
        }
        // �ۼӼ������飬����ÿ�����ֵ�����λ��
        for (int i = 1; i < 10; i++) 
        {
            count[i] += count[i - 1];
        }
        // ���ݼ������飬��Ԫ�ط�����ȷ��λ��
        for (int i = n - 1; i >= 0; i--) 
        {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        // �����������ƻ�ԭ����
        for (int i = 0; i < n; i++) 
        {
            arr[i] = output[i];
        }
        exp *= 10; // ������һλ
    }
    free(output); // �ͷ���ʱ������ڴ�
    end = clock(); // ��¼����ʱ��
    printf("���������㷨��ʱ��%ldms\n", (end - start) * 1000 / CLOCKS_PER_SEC);
    fc(arr, n); // ������������д���ļ�
    system("pause");
}
void menus()//����С�������˵���������
{
    while (1)
    {
        system("cls"); 
        printf("��ѡ��Ҫ���Ե������㷨��\n");
        printf("1--��������\n");
        printf("2--�鲢����\n");
        printf("3--��������\n");
        printf("4--��������\n");
        printf("5--��������\n");
        printf("����0������һ���˵�\n");
        printf("PS:����С��������������ĺ����������ĵȴ�\n");
        int n;
        scanf("%d", &n);
        int arr[100]; //����һ����СΪ100������
        int it = 100000; //�������
        clock_t start1, end1; //������ʼʱ��ͽ���ʱ�����
        start1 = clock(); //��¼��ʼʱ��
        for (int i = 0; i < it; i++) 
        {
            // �����������
            for (int j = 0; j < 100; j++) 
            {
                arr[j] = rand() % 1000; // ���ɷ�ΧΪ0��999�������
            }
            // �����û�ѡ����ö�Ӧ�������㷨
            switch (n) 
            {
                case 1: InsertSort1(arr, 100); break;
                case 2: MergeSort1(arr, 100); break;
                case 3: QuickSort1(arr, 100); break;
                case 4: CountSort1(arr, 100); break;
                case 5: RadixCountSort1(arr, 100); break;
                case 0: return;
                default: 
                    printf("�����������������\n");system("pause");break;
            }
        }
        end1 = clock(); // ��¼����ʱ��
        // ������������ܺ�ʱ
        printf("�����㷨 %d �� 100 ������ * 100000 �������µ��ܺ�ʱ��%ldms\n", n, (end1 - start1) * 1000 / CLOCKS_PER_SEC);
        system("pause");
    }
}
void InsertSort1(int arr[], int n)//��������������
{
    fr(arr, n);
    if(arr==NULL||n<=1)// ����Ϊ�ջ�ֻ��һ��Ԫ��ʱ������Ҫ����ֱ�ӷ���
    {
        if(arr==NULL) printf("�������ļ��д�����������\n");//��߽�׳�ԣ���ֹѧ������������bug
        return;
    }
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];//��ǰҪ�����Ԫ��
        int j = i - 1;
        //�������򲿷ֵ�Ԫ������ƶ���ֱ���ҵ�����λ��
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        // ����ǰԪ�ز��뵽��ȷλ��
        arr[j + 1] = key;
    }
    fc(arr, n);
}
void MergeSort1(int arr[], int n)//�鲢����������
{
    fr(arr, n); //���ļ��ж�ȡ����
    if (arr == NULL || n <= 1) //����Ϊ�ջ�ֻ��һ��Ԫ��ʱ������Ҫ����
    { 
        if (arr == NULL) printf("�������ļ��д�����������\n");
        return;
    }
    MergeSortRecursive(arr, 0, n - 1); //���õݹ�鲢����
    fc(arr, n); //������������д���ļ�
}
//���������������
void QuickSort1(int arr[], int n) 
{
    fr(arr, n); //���ļ��ж�ȡ����
    if (arr == NULL || n <= 1) 
    { //����Ϊ�ջ�ֻ��һ��Ԫ��ʱ������Ҫ����
        if (arr == NULL) printf("�������ļ��д�����������\n");
        return;
    }
    QuickSortRecursive(arr, 0, n - 1); //���õݹ��������
    fc(arr, n); //������������д���ļ�
}
void CountSort1(int arr[], int n) 
{
    fr(arr, n); //���ļ��ж�ȡ����
    if (arr == NULL || n <= 1) //����Ϊ�ջ�ֻ��һ��Ԫ��ʱ������Ҫ����
    { 
        if (arr == NULL) printf("�������ļ��д�����������\n");
        return;
    }
    //�ҵ������е����ֵ����Сֵ
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    int range = max - min + 1; //���㷶Χ
    int *count = (int *)calloc(range, sizeof(int)); //�����������鲢��ʼ��Ϊ0
    if (count == NULL) 
    {
        printf("�ڴ����ʧ��\n");
        return;
    }
    //ͳ��ÿ��Ԫ�صĳ��ִ���
    for (int i = 0; i < n; i++) 
    {
        count[arr[i] - min]++;
    }
    //���ݼ��������������ԭ����
    int index = 0;
    for (int i = 0; i < range; i++) 
    {
        while (count[i] > 0) 
        {
            arr[index++] = i + min;
            count[i]--;
        }
    }
    free(count); //�ͷż���������ڴ�
    fc(arr, n); //������������д���ļ�
}
void RadixCountSort1(int arr[], int n) //��������������
{
    fr(arr, n); // ���ļ��ж�ȡ����
    if (arr == NULL || n <= 1) // ����Ϊ�ջ�ֻ��һ��Ԫ��ʱ������Ҫ����
    { 
        if (arr == NULL) printf("�������ļ��д�����������\n");
        return;
    }
    // �ҵ������е����ֵ
    int max = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max) max = arr[i];
    }
    // ��������ĺ����߼�
    int exp = 1; // �Ӹ�λ��ʼ����
    int *output = (int *)malloc(n * sizeof(int)); // ��ʱ�������ڴ洢������
    if (output == NULL) 
    {
        printf("�ڴ����ʧ��\n");
        return;
    }
    while (max / exp > 0) 
    {
        int count[10] = {0}; // �������飬����ͳ��ÿһλ���ֵĳ��ִ���
        // ͳ��ÿһλ���ֵĳ��ִ���
        for (int i = 0; i < n; i++) 
        {
            count[(arr[i] / exp) % 10]++;
        }
        // �ۼӼ������飬����ÿ�����ֵ�����λ��
        for (int i = 1; i < 10; i++) 
        {
            count[i] += count[i - 1];
        }
        // ���ݼ������飬��Ԫ�ط�����ȷ��λ��
        for (int i = n - 1; i >= 0; i--) 
        {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        // �����������ƻ�ԭ����
        for (int i = 0; i < n; i++) 
        {
            arr[i] = output[i];
        }
        exp *= 10; // ������һλ
    }
    free(output); // �ͷ���ʱ������ڴ�
    fc(arr, n); // ������������д���ļ�
}