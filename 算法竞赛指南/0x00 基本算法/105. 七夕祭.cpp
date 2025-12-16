#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[N], b[N];
ll c[N];
int n, m, t;
ll get(int *a,int n)
{
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += a[i];
    ans /= n;
    for (int i = 1; i <= n; i++)
        a[i] -= ans;
    c[1] = 0;
    for (int i = 2; i <= n; i++)
        c[i] = c[i - 1] + a[i];
    sort(c + 1, c + 1 + n);
    int mid = c[n / 2 + 1];
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += abs(c[i] - mid);
    return sum;
}

int main()
{
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < t; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x]++, b[y]++;
    }
    if (t % n && t % m)
        printf("impossible\n");
    else if (!(t % n) && t % m)
        printf("row %lld\n", get(a, n));
    else if (t % n && !(t % m))
        printf("column %lld\n", get(b, m));
    else
        printf("both %lld\n", get(a, n) + get(b, m));

    return 0;
}