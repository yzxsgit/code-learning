#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];
bool flag[N];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int ans = 0;
    int i = 1, j = 1;
    while (i <= n && j <= n)
    {
        if (!flag[a[j]])
        {
            flag[a[j]] = true;
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {
            flag[a[i]] = false;
            i++;
        }
    }

    printf("%d\n", ans);

    return 0;
}