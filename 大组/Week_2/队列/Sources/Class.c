#include"..\Headers\Lqueue.h"

int classElem(char* m)
{
    int n = 0; // 初始化字符串索引
    int flag_sign = 0; // 记录非数字字符的个数
    int flag_float = 0; // 记录小数点的个数

    // 如果字符串只有一个字符
    if (m[1] == '\0')
    {
        // 如果这个字符是数字，则返回1，表示整数
        if (m[0] >= '0' && m[0] <= '9')
            return 1;
        else
            return 3; // 否则返回3，表示单个字符
    }

    // 遍历整个字符串
    while (m[n] != '\0' && m[n] != '\n')
    {
        // 如果当前字符不是数字，则增加非数字字符的计数
        if (m[n] < '0' || m[n]>'9')
        {
            flag_sign++;
        }
        // 如果当前字符是小数点，则增加小数点的计数
        if (m[n] == '.')
        {
            flag_float++;
        }
        n++; // 移动到下一个字符
    }
    // 根据计数情况判断字符串类型并返回相应值
    if (flag_float == 0 && flag_sign == 0)
        return 1; // 没有小数点且没有非数字字符，返回1，表示整数
    else if (flag_float == 1 && flag_sign == 0)
        return 2; // 有一个小数点且没有非数字字符，返回2，表示浮点数
    else
        return 4; // 否则返回4，表示其他类型
}