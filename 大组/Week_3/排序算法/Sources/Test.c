#include"..\Headers\Sort.h"


double TimeTest1(int n,int size)
{
	clock_t start;
	clock_t end;
	srand(time(NULL));//引入时间数据
	int* arr = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % (size + 1);
	}
	switch (n)
	{
	case 1:
		start = clock();
		InsetSort(arr, size);
		end = clock();
		break;
	case 2:
		start = clock();
		MergeSort(arr, 0, size - 1);
		end = clock();
		break;
	case 3:
		start = clock();
		QuickSort(arr, 0, size - 1);
		end = clock();
		break;
	case 4:
		start = clock();
		CountSort(arr, size);
		end = clock();
		break;
	case 5:
		start = clock();
		RadixCountSort(arr, size);
		end = clock();
		break;
	}
	double cost_time = ((double)(end - start)) / CLOCKS_PER_SEC;
	return (cost_time);
}

double TimeTest2(int n)
{
	clock_t start, end;
	double cost_time = 0;
	srand(time(NULL));//引入时间数据
	int arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = rand() % (101);
	}
	for (int i = 0; i < 100000; i++)
	{
		switch (n)
		{
		case 1:
			start = clock();
			InsetSort(arr, 100);
			end = clock();
			break;
		case 2:
			start = clock();
			MergeSort(arr, 0, 99);
			end = clock();
			break;
		case 3:
			start = clock();
			QuickSort(arr, 0, 99);
			end = clock();
			break;
		case 4:
			start = clock();
			CountSort(arr, 100);
			end = clock();
			break;
		case 5:
			start = clock();
			RadixCountSort(arr, 100);
			end = clock();
			break;
		}
		cost_time+= ((double)(end - start)) / CLOCKS_PER_SEC;
	}
	return (cost_time);
}