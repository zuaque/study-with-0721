#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsetSort(int* arr, int size);
void MergeSort(int* arr, int left, int right);
void QuickSort(int* arr, int left, int right);
void CountSort(int* arr, int size);
void RadixCountSort(int* arr, int size);


double TimeTest1(int n, int size);//大数据
double TimeTest2(int n);//大量小数据



int getNum(int* arr, char* num_c);


void Sort_menu();
void FileMenu();


void Save(int* arr, int size);
void Read(int* arr, int size);

void ColorSort(int* arr, int size);
int FindK(int* arr, int left, int right, int k);