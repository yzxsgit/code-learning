#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int get_one_hot_index(char c)
{
    c = toupper(c);
    switch (c)
    {
    case 'A':
        return 3;
    case 'T':
        return 2;
    case 'C':
        return 1;
    case 'G':
        return 0;
    default:
        return -1;
    }
}

int main()
{
    int n;
    printf("请输入要处理的序列数量：");
    scanf("%d", &n);
    printf("请输入%d段基因序列：",n);
    char **str = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        str[i] = (char *)malloc(21 * sizeof(char));
        scanf("%s", str[i]);
    }

    printf("独热码如下\n");
    for (int i = 0; i < n; i++)
    {
        int len = 0;
        while (str[i][len] != '\0')
        {
            len++;
        }

        char *one_hot = (char *)malloc((len * 4 + 1) * sizeof(char));

        for (int j = 0; j < len; j++)
        {
            int index = get_one_hot_index(str[i][j]);

            if (index >= 0 && index < 4)
            {
                for (int k = 0; k < 4; k++)
                {
                    one_hot[j * 4 + k] = (k == index) ? '1' : '0';
                }
            }
            else
            {
                for (int k = 0; k < 4; k++)
                {
                    one_hot[j * 4 + k] = '0';
                }
            }
        }
        one_hot[len * 4] = '\0';

        printf("%s\n", one_hot);

        free(one_hot);
    }

    for (int i = 0; i < n; i++)
    {
        free(str[i]);
    }
    free(str);

    return 0;
}
/*
请输入要处理的序列数量：请输入2段基因序列：↲
独热码如下
*/