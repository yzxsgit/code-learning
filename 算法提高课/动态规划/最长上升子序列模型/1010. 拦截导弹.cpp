#include <iostream>

using namespace std;
const int N = 1e3 + 10;
int f[N], q[N];
int a[N];
int main()
{
    int n = 1;
    while (cin >> a[n])
        n++;
    n -= 1;
    int res = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if(a[i] <= a[j])
                f[i] = max(f[i], f[j] + 1);
        res = max(res, f[i]);

        int k = 0;
        while (k < cnt && q[k] < a[i])
            k++;
        if(cnt == k)
            q[cnt++] = a[i];
        else
            q[k] = a[i];
    }
    printf("%d\n%d\n", res, cnt);
    return 0;
}