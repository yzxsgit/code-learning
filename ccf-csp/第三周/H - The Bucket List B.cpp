#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, a[N];
int main()
{
    cin >> n;
    int maxx = 0;
    while (n--)
    {
        int s, t, b;
        cin >> s >> t >> b;
        a[s] += b;
        a[t + 1] -= b;
        maxx = max(t,maxx);
    }

    for (int i = 1; i <= maxx; i++)
        a[i] += a[i - 1];
    int ans = 0;
    for (int i = 1; i <= maxx; i++)
        ans = max(a[i], ans);

    printf("%d", ans);
    
    return 0;
}