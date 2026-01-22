#include <stdio.h>

int GCD(int a,int b)
{
    return a % b ? GCD(b, a % b) : b;
}

int LCM(int a, int b)
{
    return a * b / GCD(a, b);
}

int main()
{
    int a, b;
    printf("Input a,b:");
    scanf("%d,%d", &a, &b);
    printf("MinCommonMultiple = %d", LCM(a, b));
    return 0;
}