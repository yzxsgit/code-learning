#include <bits/stdc++.h>
using namespace std;

int num[26];
bool st[26];

int main()
{
    string s[16];
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> s[i];

    int ans = 0;
    for (int i = 0; i < 1 << n; i++)
    {
        memset(num, 0, sizeof num);
        for (int j = 0; j < n; j++)
            if(i >> j & 1)
            {
                for (auto k:s[j])
                    num[k - 'a']++;
            }
        int res = 0;
        for (int p = 0; p < 26; p++)
            if(num[p] == k)
                res++;

        ans = max(res, ans);
    }

    printf("%d\n", ans);

    return 0;
}