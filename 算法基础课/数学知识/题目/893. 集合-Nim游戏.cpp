#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = 1e5 + 10;
int s[N], f[M];
int k, n;
int sg(int x)
{
    if (f[x] != -1)
        return f[x];

    unordered_set<int> S;

    for (int i = 0; i < k; i++)
    {
        int sum = s[i];
        if (x >= sum)
            S.insert(sg(x - sum));
    }

    for (int i = 0;; i++)
        if (!S.count(i))
            return f[x] = i;
}
int main()
{
    memset(f, -1, sizeof f);
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> s[i];
    cin >> n;
    int res = 0;
    while (n--)
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }

    if (res)
        puts("Yes");
    else
        puts("No");

    return 0;
}