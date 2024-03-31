#include"..\Headers\Sort.h"

void InsetSort(int* arr,int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int q = i; q > 0&&arr[q-1]>arr[q]; q--)//�����������ͷ�������ȵ�ǰֵС�����ʱ����ѭ��
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

        // �ֱ�����������ֽ�������
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        // �ϲ��������������
        int n1 = mid - left + 1;//��Ϊ��������
        int n2 = right - mid;
        int* L = (int*)malloc(n1 * sizeof(int));//������̬��С������
        int* R = (int*)malloc(n2 * sizeof(int));
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
        // �ϲ���ʱ���鵽ԭ����
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
        // ��ʣ���Ԫ�ظ��Ƶ�ԭ����
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
    int temp;//��ʱ����
    int p = arr[(right + left) / 2];//�����м��ֵ
    while (i <= j)
    {
        while (arr[i] < p)//��������һ����ѡ��ֵ�����
        {
            i++;
        }
        while (arr[j] > p)//��������һ����ѡ��ֵС����
        {
            j--;
        }
        if (i <= j)//����
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
    int max = arr[0];//�������ֵ
    int min = arr[0];//������Сֵ
    for (int i = 1; i < size;i++)//��ȡ��������ֵ����Сֵ
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
    for (int i = 0; i < size; i++)//����
        countarr[arr[i] - min]++;
    int j = 0;
    for (int i = 0; i < range; i++)//����λ��
    {
        while (countarr[i]--)
            arr[j++] = i + min;
    }
    free(countarr);
    countarr = NULL;
}

void RadixCountSort(int* arr, int size) 
{
    int max = arr[0];// �ҳ������е����ֵ����ȷ��λ��
    int min = arr[0];//�ҳ���Сֵ�����ǵ���������и���
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
    for (int i = 0; i < size; i++)//����Ԫ�ؼ�ȥ��Сֵ����������Ԫ�ر�֤����Ȼ��
    {
        arr[i] -= min;
    }

    for (int exp = 1; max / exp > 0; exp *= 10) 
    {
        int* temp = (int*)malloc(size * sizeof(int)); // �洢�����Ľ��
        int count[10] = { 0 }; // �������飬����ͳ��ÿ�����ֳ��ֵĴ���

        for (int i = 0; i < size; i++)// ͳ��ÿ�����ֳ��ֵĴ���
        {
            count[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) // ����������ת��Ϊλ�����飬����¼ÿ������������������е�λ��
        {
            count[i] += count[i - 1];
        }

        for (int i = size - 1; i >= 0; i--) // ����λ�����齫���ַ��õ������Ľ��������
        {
            temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < size; i++)// �������Ľ�����ص�ԭ����
        {
            arr[i] = temp[i];
        }
        free(temp);
    }
    for (int i = 0; i < size; i++)//ԭ�ȼ�ȥ��Сֵ���ڼӻ�ȥ
    {
        arr[i] += min;
    }


}