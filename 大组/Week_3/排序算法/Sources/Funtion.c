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
        case 0:// 交换arr[p0]和arr[p1]，并将指针向右移动
            arr[p0] ^= arr[p1];
            arr[p1] ^= arr[p0];
            arr[p0] ^= arr[p1];
            p0++;
            p1++;
            break;
        case 1:// 直接将指针向右移动
            p1++;
            break;
        case 2: // 交换arr[p1]和arr[p2]，并将p2指针向左移动
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
    int p = arr[(right + left) / 2]; // 中间值
    while (i <= j)
    {
        while (arr[i] > p) // 查找比中间值小的数
        {
            i++;
        }
        while (arr[j] < p) // 查找比中间值大的数
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

    if (left + k - 1 <= j)// 判断第k大的数是否在左半部分
    {
        return FindK(arr, left, j, k);
    }

    if (left + k - 1 >= i)// 判断第k大的数是否在右半部分
    {
        return FindK(arr, i, right, k - (i - left));
    }

    return arr[j + 1];
}
