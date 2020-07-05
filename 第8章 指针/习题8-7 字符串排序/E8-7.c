#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[5][80]; //二维数组保存5个字符串
    int i, j;

    for (i = 0; i < 5; i++)
    {
        scanf("%s", str[i]); //输入5个字符串
    }

    for (i = 0; i < 4; i++)
    {
        int index = i;
        for (j = i + 1; j < 5; j++)
        {
            if (strcmp(str[index], str[j]) > 0)
            {
                index = j;
            }
        }
        if (i != index)
        {
            char t[80];
            strcpy(t, str[index]); //交换字符串
            strcpy(str[index], str[i]);
            strcpy(str[i], t);
        }
    }

    printf("After sorted:\n");
    for (i = 0; i < 5; i++)
    {
        puts(str[i]);
    }

    return 0;
}