#include <stdio.h>
#include <stdlib.h>
void inverse(char *p);
int main()
{
    char a[80];
    gets(a);
    inverse(a);
    puts(a);
    return 0;
}
void inverse(char *p)
{
    char *q;
    char t;
    q = p;
    while (*q != '\0')
    {
        q++;
    }
    q--;
    while (p < q)
    {
        t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;
    }
    return;
}