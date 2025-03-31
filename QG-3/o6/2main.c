#include <stdio.h>
int Partition(int arr[], int low, int high) //��o1-o4�и��Ƶ�
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
int findk(int arr[], int low, int high, int k) {
    if (low <= high) {
        int Index = Partition(arr, low, high);

        if (Index == k - 1) 
        {// �������ǡ����Ŀ��λ��
            return arr[Index];
        } else if (Index > k - 1)
        {// �������Ŀ��λ���Ҳ�
            return findk(arr, low, Index - 1, k);
        } else 
        { // �������Ŀ��λ�����
            return findk(arr, Index + 1, high, k);
        }
    }
    return -1; // ���Խ�磬����-1
}
int main()
{
    int a ;
    printf("���������鳤�ȣ�");
    scanf("%d", &a);
    int arr[a];
    printf("����������Ԫ�أ�");
    for (int i = 0; i < a; i++) 
    {
        scanf("%d", &arr[i]); 
    }
    int k;
    printf("������Ҫ���ҵ���λ�� k:");
    scanf("%d", &k);
    if (k < 1 || k > a) 
    {
        printf("����� k ������Χ��\n");
        return 0;  
    }
    int result = findk(arr, 0, a - 1, k);
    printf("�����е� %d С�������ǣ�%d\n", k, result);
    return 0;
}