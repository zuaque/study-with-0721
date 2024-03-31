#include"..\Headers\Sort.h"


void ColorSort(int* arr,int size)
{
    int p0 = 0;
    int p1 = 0;
    int p2 = size - 1;

    while (p1 <= p2) 
    {
        switch (arr[p1]) 
        {
        case 0:// ����arr[p0]��arr[p1]������ָ�������ƶ�
            arr[p0] ^= arr[p1];
            arr[p1] ^= arr[p0];
            arr[p0] ^= arr[p1];
            p0++;
            p1++;
            break;
        case 1:// ֱ�ӽ�ָ�������ƶ�
            p1++;
            break;
        case 2: // ����arr[p1]��arr[p2]������p2ָ�������ƶ�
            arr[p1] ^= arr[p2];
            arr[p2] ^= arr[p1];
            arr[p1] ^= arr[p2];
            p2--;
            break;
        }
    }
}


int FindK(int* arr, int left, int right, int k)
{
    int i = left, j = right;
    int p = arr[(right + left) / 2]; // �м�ֵ
    while (i <= j)
    {
        while (arr[i] > p) // ���ұ��м�ֵС����
        {
            i++;
        }
        while (arr[j] < p) // ���ұ��м�ֵ�����
        {
            j--;
        }
        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left + k - 1 <= j)// �жϵ�k������Ƿ�����벿��
    {
        return FindK(arr, left, j, k);
    }

    if (left + k - 1 >= i)// �жϵ�k������Ƿ����Ұ벿��
    {
        return FindK(arr, i, right, k - (i - left));
    }

    return arr[j + 1];
}
