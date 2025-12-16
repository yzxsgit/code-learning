#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];
int n, m, x;

int main()
{
    scanf("%d%d%d", &n, &m, &x);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        while (a[i] + b[j] > x)
            j--;
        while (a[i] + b[j] < x )
            i++;
        if(a[i] + b[j] == x)
            break;
    }

    printf("%d %d\n", i, j);

    return 0;
}