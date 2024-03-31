#include"..\Headers\Sort.h"

void InsetSort(int* arr,int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int q = i; q > 0&&arr[q-1]>arr[q]; q--)//如果遍历到开头或遇到比当前值小或等于时结束循环
		{
			int temp = arr[q - 1];
			arr[q - 1] = arr[q];
			arr[q] = temp;
		}
	}
}

void MergeSort(int* arr, int left, int right)
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;

        // 分别对左右两部分进行排序
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        // 合并已排序的两部分
        int n1 = mid - left + 1;//分为左右两边
        int n2 = right - mid;
        int* L = (int*)malloc(n1 * sizeof(int));//建立动态大小的数组
        int* R = (int*)malloc(n2 * sizeof(int));
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
        // 合并临时数组到原数组
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
        // 将剩余的元素复制到原数组
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

        free(L);
        free(R);
        L = NULL;
        R = NULL;
    }

}

void QuickSort(int* arr, int left, int right)
{
    int i = left, j = right;
    int temp;//临时变量
    int p = arr[(right + left) / 2];//数组中间的值
    while (i <= j)
    {
        while (arr[i] < p)//遍历到第一个比选定值大的数
        {
            i++;
        }
        while (arr[j] > p)//遍历到第一个比选定值小的数
        {
            j--;
        }
        if (i <= j)//交换
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j)
    {
        QuickSort(arr, left, j);
    }
    if (right > i)
    {
        QuickSort(arr, i, right);
    }
}


void CountSort(int* arr, int size)
{
    int max = arr[0];//数组最大值
    int min = arr[0];//数组最小值
    for (int i = 1; i < size;i++)//获取数组的最大值及最小值
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int range = max - min + 1;
    int* countarr = (int*)malloc(range * sizeof(int));
    for (int i = 0; i < range; i++) 
    {
        countarr[i] = 0;
    }
    for (int i = 0; i < size; i++)//计数
        countarr[arr[i] - min]++;
    int j = 0;
    for (int i = 0; i < range; i++)//更改位置
    {
        while (countarr[i]--)
            arr[j++] = i + min;
    }
    free(countarr);
    countarr = NULL;
}

void RadixCountSort(int* arr, int size) 
{
    int max = arr[0];// 找出数组中的最大值，以确定位数
    int min = arr[0];//找出最小值，考虑到数组可能有负数
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    for (int i = 0; i < size; i++)//所有元素减去最小值，数组所有元素保证是自然数
    {
        arr[i] -= min;
    }

    for (int exp = 1; max / exp > 0; exp *= 10) 
    {
        int* temp = (int*)malloc(size * sizeof(int)); // 存储排序后的结果
        int count[10] = { 0 }; // 计数数组，用于统计每个数字出现的次数

        for (int i = 0; i < size; i++)// 统计每个数字出现的次数
        {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) // 将计数数组转换为位置数组，即记录每个数字在排序后数组中的位置
        {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; i >= 0; i--) // 根据位置数组将数字放置到排序后的结果数组中
        {
            temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < size; i++)// 将排序后的结果返回到原数组
        {
            arr[i] = temp[i];
        }
        free(temp);
    }
    for (int i = 0; i < size; i++)//原先减去最小值现在加回去
    {
        arr[i] += min;
    }


}