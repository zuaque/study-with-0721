#include"..\Headers\Sort.h"
#include <stdlib.h>
int getNum(int* arr, char* num_c)
{
    char temp[10]; // 临时数组，用于存储从字符串中提取的数字
    temp[0] = '\0'; // 初始化临时数组
    int j = 0; // 临时数组的索引
    int size = 0; // 存储在数组中的整数数量

    // 遍历输入字符串中的字符，提取数字并存储在数组中
    for (int i = 0; num_c[i] != '\0'; i++)
    {
        if (num_c[i] >= '0' && num_c[i] <= '9')
        {
            temp[j] = num_c[i]; // 将数字字符存储在临时数组中
            j++;
        }
        else
        {
            if (temp[0] == '\0')
                continue; // 跳过连续的非数字字符

            temp[j] = '\0'; // 在临时数组末尾添加字符串终止符
            arr[size] = atoi(temp); // 将临时数组中的字符串转换为整数并存储在数组中
            j = 0; // 重置临时数组的索引
            size++; // 增加存储在数组中的整数数量
        }
    }
    return size; // 返回提取并存储在数组中的整数数量
}