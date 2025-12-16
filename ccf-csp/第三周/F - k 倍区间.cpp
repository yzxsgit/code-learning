#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long a[N], c[N] = {1};
int n, k;
long long ans;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] = (a[i] + a[i - 1]) % k;
        c[a[i]]++;
    }
    for (int i = 0; i < k; i++)
        ans += c[i] * (c[i] - 1) / 2;
    cout << ans << endl;

    return 0;
}