#include <bits/stdc++.h>
using namespace std;

int a[20];
int num[20];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] != -1)
            num[a[i]]++;
    }
    bool flag = true;

    for (int i = 1; i <= n; i++)
        if(num[i] >= 2)
            flag = false;

    if(flag)
    {
        puts("Yes");
        int i = 0, p = 1;
        while(i < n)
        {
            if(num[a[i]])
                printf("%d ", a[i]);
            else
            {
                while (num[p] && p <= n)
                    p++;
                printf("%d ", p);
                num[p]++;
            }
            i++;
        }
    }
    else
        puts("No");

    return 0;
}