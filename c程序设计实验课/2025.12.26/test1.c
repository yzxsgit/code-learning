#include <stdio.h>
#include <stdlib.h>

void Mystrcat(char *p, char *q)
{
    int i = 0, j = 0;
    while (p[i] != '\0')
    {
        i++;
    }
    while (q[j] != '\0')
    {
        p[i++] = q[j++];
    }
    p[i] = '\0';
    return;
}
int main()
{
    char *a = (char *)malloc(161 * sizeof(char));
    char *b = (char *)malloc(161 * sizeof(char));
    gets(a);
    gets(b);
    Mystrcat(a, b);
    puts(a);
    free(a);
    free(b);
    return 0;
}