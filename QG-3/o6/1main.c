#include <stdio.h>
void sort(int arr[],int a)
{
    int left = 0;
    int right = a-1;
    int temp;
    for(int i = 0; i < a; i++)
    {
        if(arr[i] == 0)//����0��Ԫ�ط�����ߣ�ͬʱ��������
        {
           temp = arr[left];
           arr[left] = arr[i];
           arr[i] = temp;
           left++;
        }
        else if(arr[i] == 2)      
        //����2��Ԫ�ط����ұߣ�ͬʱ�������ƣ�ע���ʱi���ƶ�����Ϊiλ��Ԫ�ػ�δ�ж�
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
    printf("���������鳤�ȣ�\n ");
    scanf("%d",&a);
    int arr[a];
    printf("����������Ԫ��(ֻ����0,1,2):\n ");
    for(int i=0;i<a;i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr,a);
    printf("����������Ϊ��\n ");
    for(int i = 0; i < a; i ++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
