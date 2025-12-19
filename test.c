#include <stdio.h>
#include <string.h>

void Squeeze(char s[], char c)
{
    char res[100];
    int n = strlen(s), idx = 0;
    for (int i = 0; i < n; i++)
        if (s[i] != c)
            res[idx++] = s[i];

    for (int i = 0; i < idx; i++)
        s[i] = res[i];
    for (int i = idx; i < n; i++)
        s[i] = 0;

    return;
}
int main()
{
    char str[100];
    printf("Input a string:\n");
    gets(str);
    char a;
    printf("Input a character:\n");
    a = getchar();
    Squeeze(str, a);
    printf("Results:%s\n", str);

    return 0;
}