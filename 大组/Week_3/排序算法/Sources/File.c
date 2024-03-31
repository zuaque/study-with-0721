#include"..\Headers\Sort.h"

void Save(int* arr, int size) 
{
    FILE* file = fopen("Data.txt", "w");
    if (file == NULL) {
        perror("文件打开失败");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

void Read(int* arr, int size) 
{
    FILE* file = fopen("Data.txt", "r");
    if (file == NULL) {
        perror("文件打开失败");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) 
    {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}