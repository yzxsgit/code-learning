#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a;
    int n;
    bool flag1 = 0, flag2 = 0;
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        a = getchar();
        // cout << a;
        if (a == 'a')
        {
            if(flag2)
            {
                puts("Yes");
                return 0;
            }
            else
            {
                flag1 = 1;
            }
        }
        else if(a == 'b')
        {
            if (flag1)
            {
                puts("Yes");
                return 0;
            }
            else
            {
                flag2 = 1;
            }
        }
        else
        {
            flag1 = flag2 = 0;
        }
    }
    puts("No");
    return 0;
}