#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    for (int i = 1; i <= 16;i++)
    {
        a = getchar() - 48;
        if(!(i%2)&&a == 1)
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}