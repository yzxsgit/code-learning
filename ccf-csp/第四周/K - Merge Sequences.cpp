#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], A[N], B[N], cnt;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            A[i++] = ++cnt;
        else
            B[j++] = ++cnt;
    }

    while (i < n)
        A[i++] = ++cnt;
    while (j < m)
        B[j++] = ++cnt;

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    puts("");
    for (int i = 0; i < m; i++)
        printf("%d ", B[i]);

    return 0;
}